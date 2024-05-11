#include "mpsc/ring.hpp"

namespace examples
{
namespace mpsc
{

char* Ring::normalizePtr(char* ptr)
{
    return ptr < m_end ? ptr : ptr - capacity();
}

char* Ring::acquireReadBlock(std::size_t length)
{
    auto size = static_cast<std::ptrdiff_t>(length);
    while (true)
    {
        auto old_rptr = m_rptr.load(std::memory_order_consume);
        while (m_used.load(std::memory_order_consume) < size)
            ;  // spin until success

        auto new_rptr = normalizePtr(old_rptr + size);

        m_used.fetch_sub(size);
        if (m_rptr.compare_exchange_strong(old_rptr, new_rptr))
        {
            return old_rptr;  // committed
        }

        m_used.fetch_add(size, std::memory_order_relaxed);
    }
}

}  // namespace mpsc
}  // namespace examples

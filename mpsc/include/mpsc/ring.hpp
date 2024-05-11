/*******************************************************************************
 * Copyright (C) 2022 Timon Reich
 *
 * C++ examples library
 *
 * License notes see LICENSE.txt
 ******************************************************************************/

#ifndef __EXAMPLES_MPSC_RING_HPP__
#define __EXAMPLES_MPSC_RING_HPP__

#include <atomic>
#include <cstdint>

namespace examples
{
namespace mpsc
{
class Ring
{
  public:
    Ring(std::uint32_t capacity)
        : m_capacity(capacity)
    {
    }

    const std::uint32_t capacity() const
    {
        return m_capacity;
    }

  protected:
    char* normalizePtr(char* ptr);
    char* acquireReadBlock(std::size_t length);

  private:
    std::uint32_t m_capacity;
    char* m_begin;
    char* m_end;

    // clang-format off
    alignas(64)
    std::atomic<std::uint32_t> m_used;

    alignas(64)
    std::atomic<std::uint32_t> m_free;

    alignas(64)
    std::atomic<char*> m_rbuf;
    std::atomic<char*> m_rptr;

    alignas(64)
    std::atomic<char*> m_wbuf;
    std::atomic<char*> m_wptr;
    // clang-format on
};

}  // namespace mpsc
}  // namespace examples

#endif  // __EXAMPLES_MPSC_RING_HPP__

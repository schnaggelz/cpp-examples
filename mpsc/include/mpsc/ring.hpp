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
template<typename T>
class Ring
{
  public:
    Ring() 
        : m_head(0)
        , m_tail(0)
    {
    }

  private:
    struct Node
    {
        T data;
        std::atomic<Node*> next;
    };

    typedef char pad[64];

    pad m_pad0;
    std::atomic<std::uint32_t> m_head;

    pad m_pad1;
    std::atomic<std::uint32_t> m_tail;
};

}  // namespace mpsc
}  // namespace examples

#endif  // __EXAMPLES_MPSC_RING_HPP__
/*******************************************************************************
 * Copyright (C) 2022 Timon Reich
 *
 * C++ examples library
 *
 * License notes see LICENSE.txt
 ******************************************************************************/

#ifndef __EXAMPLES_OBSERVER_DISPATCHER_HPP__
#define __EXAMPLES_OBSERVER_DISPATCHER_HPP__

#include <array>
#include <cstdint>

#include "callback/callable.hpp"

namespace examples
{
namespace observer
{

template <typename T, std::uint32_t MaxSlots>
class Dispatcher
{
    using Callable = examples::callbacks::Callable<void(const examples::observer::Event<T>&)>;

  public:
    bool subscribe(T type, const Callable& callable)
    {
        if (m_current_idx >= MaxSlots)
        {
            return false;
        }

        m_slots[m_current_idx] = callable;
        m_current_idx ++;

        return true;
    };

    void dispatch(Event<T>& event)
    {
        // Loop though all observers. If the event is not handled yet we continue to process it.
        for (auto&& slot : m_slots)
        {
            if (!event.isHandled())
            {
                slot(event);
            }
        }
    };

  private:
    std::array<Callable, MaxSlots> m_slots;
    std::uint32_t m_current_idx = 0;
};

}  // namespace observer
}  // namespace examples

#endif  // __EXAMPLES_OBSERVER_DISPATCHER_HPP__
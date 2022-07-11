/*******************************************************************************
 * Copyright (C) 2022 Timon Reich
 *
 * C++ examples library
 *
 * License notes see LICENSE.txt
 ******************************************************************************/

#ifndef __EXAMPLES_OBSERVER_DISPATCHER_HPP__
#define __EXAMPLES_OBSERVER_DISPATCHER_HPP__

#include "observer/event.hpp"

#include "callback/callable.hpp"

#include <array>
#include <cstdint>
#include <tuple>

namespace examples
{
namespace observer
{

template <typename EventTypeT, std::uint32_t MaxSlots>
class Dispatcher
{
  public:
    using Callable = examples::callbacks::Callable<void(const examples::observer::Event<EventTypeT>&)>;

    Dispatcher() = default;

    bool subscribe(EventTypeT type, const Callable& callable)
    {
        if (m_current_idx >= MaxSlots)
        {
            return false;
        }

        m_slots[m_current_idx] = std::make_pair(type, callable);
        m_current_idx++;

        return true;
    };

    void dispatch(Event<EventTypeT>& event)
    {
        for (const auto& slot : m_slots)
        {
            if (!event.isHandled())
            {
                const auto& callable = std::get<1>(slot);

                if (callable)
                {
                    callable(event);
                }
            }
        }
    };

  private:
    std::array<std::pair<EventTypeT, Callable>, MaxSlots> m_slots;
    std::uint32_t m_current_idx = 0;
};

}  // namespace observer
}  // namespace examples

#endif  // __EXAMPLES_OBSERVER_DISPATCHER_HPP__
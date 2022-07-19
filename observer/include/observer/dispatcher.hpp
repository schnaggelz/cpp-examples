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
#include <tuple>
#include <type_traits>

#include "callback/callable.hpp"
#include "observer/event.hpp"

namespace examples
{
namespace observer
{

template <typename EventT, std::uint32_t MaxSlots>
class Dispatcher
{
    using EventType = typename EventT::Type;

    static_assert(std::is_enum<EventType>::value, "EventType must be an enumeration");
    static_assert(std::is_base_of<Event<EventType>, EventT>::value, "EventT must deribed from Event<EventType>");

  public:
    using Callable = examples::callbacks::Callable<void(const EventT&)>;

    Dispatcher() = default;

    bool subscribe(EventType type, const Callable& callable)
    {
        if (m_current_idx >= MaxSlots)
        {
            return false;
        }

        m_slots[m_current_idx] = std::make_pair(type, callable);
        m_current_idx++;

        return true;
    };

    void dispatch(const EventT& event)
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
    std::array<std::pair<EventType, Callable>, MaxSlots> m_slots;
    std::uint32_t m_current_idx = 0;
};

}  // namespace observer
}  // namespace examples

#endif  // __EXAMPLES_OBSERVER_DISPATCHER_HPP__
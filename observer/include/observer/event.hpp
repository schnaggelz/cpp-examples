/*******************************************************************************
 * Copyright (C) 2022 Timon Reich
 *
 * C++ examples library
 *
 * License notes see LICENSE.txt
 ******************************************************************************/

#ifndef __EXAMPLES_OBSERVER_EVENT_HPP__
#define __EXAMPLES_OBSERVER_EVENT_HPP__

namespace examples
{
namespace observer
{

template <typename T>
class Event
{
   public:
    using Type = T;

    Event(const T& type) : m_type(type)
    {
    }

    const Type& getType() const
    {
        return m_type;
    }

   private:
    const Type m_type;
    bool m_handled;
};

}  // namespace observer
}  // namespace examples

#endif  // __EXAMPLES_OBSERVER_EVENT_HPP__
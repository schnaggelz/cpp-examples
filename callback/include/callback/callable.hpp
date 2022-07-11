/*******************************************************************************
 * Copyright (C) 2022 Timon Reich
 *
 * Exampls library
 *
 * License notes see LICENSE.txt
 ******************************************************************************/

#ifndef __EXAMPLES_CALLABLE_HPP__
#define __EXAMPLES_CALLABLE_HPP__

#include <utility>

namespace examples
{
namespace callbacks
{
template <typename ReturnT, typename... ParamTs>
class Callable
{
    using Function = ReturnT (*)(void* object, ParamTs...);

  public:
    Callable(void* object, ParamTs... params)
      : m_function()
      , m_object(object)
    {
    }

    ReturnT operator()(ParamTs... args) const
    {
        return (*m_function)(m_object, std::forward<ParamTs>(args)...);
    }

    operator bool() const
    {
        return (m_function != nullptr && m_object != nullptr);
    }

  private:
    Function m_function = nullptr;
    void* m_object = nullptr;
};

}  // namespace callbacks
}  // namespace examples

#endif  // __EXAMPLES_CALLABLE_HPP__
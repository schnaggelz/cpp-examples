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

template <typename T>
class Callable;

template <typename ReturnT, typename... ParamTs>
class Callable<ReturnT(ParamTs...)>
{
    using Stub = ReturnT (*)(void* object, ParamTs...);

  public:
    ///@brief Default constructors for usage within containers
    constexpr Callable()
    {
    }

    constexpr Callable(const Callable& other) = default;

    ///@brief Call the calllable
    ///@param args Function arguments (see ParamTs)
    ///@return Function return value (see ReturnT)
    ReturnT operator()(ParamTs... args) const
    {
        return (*m_stub)(m_object, std::forward<ParamTs>(args)...);
    }

    ///@brief Check if the callable is valid
    ///@return True if valid
    constexpr operator bool() const
    {
        return m_stub != nullptr && m_object != nullptr;
    }

    ///@brief Create callable from instance and method
    ///@param instance Call context object
    ///@return Function return value (see ReturnT)
    template <typename ObjectT, ReturnT (ObjectT::*Method)(ParamTs...)>
    static constexpr Callable create(ObjectT& object)
    {
        return Callable((void*)(&object), createMethodStub<ObjectT, Method>);
    }

  private:
    constexpr Callable(void* object, Stub stub)
        : m_object(object),
          m_stub(stub)
    {
    }

    template <typename ObjectT, ReturnT (ObjectT::*Method)(ParamTs...)>
    static constexpr ReturnT createMethodStub(void* object, ParamTs... params)
    {
        ObjectT* object_ptr = static_cast<ObjectT*>(object);
        return (object_ptr->*Method)(std::forward<ParamTs>(params)...);
    }

  private:
    void* m_object = nullptr;
    Stub m_stub = nullptr;
};

}  // namespace callbacks
}  // namespace examples

#endif  // __EXAMPLES_CALLABLE_HPP__
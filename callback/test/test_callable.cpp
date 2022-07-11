#include "callback/callable.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <optional>
#include <type_traits>

struct TestFixture : testing::Test
{
};

struct Class1
{
    struct Data
    {
        int i = 1;
    };

    void function1()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    void function2(int i)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    void function3(Data d)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    bool function4(Data d)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        return true;
    }
};

TEST_F(TestFixture, Sandbox)
{
    Class1 o1;

    auto c1 = examples::callbacks::Callable<void(void)>::create<Class1, &Class1::function1>(o1);

    c1();

    auto c2 = examples::callbacks::Callable<void(int)>::create<Class1, &Class1::function2>(o1);

    c2(1);

    auto c3 = examples::callbacks::Callable<void(Class1::Data)>::create<Class1, &Class1::function3>(o1);

    Class1::Data d3;
    c3(d3);

    auto c4 = examples::callbacks::Callable<bool(Class1::Data)>::create<Class1, &Class1::function4>(o1);

    Class1::Data d4;
    bool r = c4(d4);
    EXPECT_FALSE(!r);
}

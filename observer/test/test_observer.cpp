#include <gtest/gtest.h>


class Notification1
{

};

class Notification2
{

};

class Notification3
{

};

template <typename NotificationT>
class Observer
{

};

template <template <typename> class T, typename... Args>
class for_each_class : T<Args>...
{
};

template class for_each_class<Observer, Notification1, Notification2, Notification3>;

struct TestFixture : testing::Test
{

};

TEST_F(TestFixture, X)
{
    Observer<Notification1> o1;
}
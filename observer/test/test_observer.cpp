#include <gtest/gtest.h>

#include <typeindex>

struct TestFixture : testing::Test
{
};

template <typename T>
struct Event
{
    using Type = T;

    Event(T type) : m_type(type)
    {
    }

    Type m_type;
    bool m_handled;
};

enum class ChannelOfferEventType
{
    OFFER,
    STOP_OFFER,
    UNDEFINED
};

enum class ChannelSubscriptionEventType
{
    SUBSCRIBE,
    UNSIBSCRIBE,
    UNDEFINED
};

class ChannelOfferEvent : public Event<ChannelOfferEventType>
{
    ChannelOfferEvent() : Event<ChannelOfferEventType>(ChannelOfferEventType::UNDEFINED){};
    virtual ~ChannelOfferEvent() = default;
};

class ChannelSubscriptionEvent : public Event<ChannelSubscriptionEventType>
{
    ChannelSubscriptionEvent() : Event<ChannelSubscriptionEventType>(ChannelSubscriptionEventType::UNDEFINED){};
    virtual ~ChannelSubscriptionEvent() = default;
};

template <typename T>
struct Dispatcher
{
    using SlotType = std::function<void(const Event<T>&)>; // replace by heap free alternative

    SlotType m_slot;
};

class Observer
{
    void handle(const Event<ChannelOfferEventType>& event)
    {
        if (event.m_type == ChannelOfferEventType::OFFER)
        {

        }
    }
};

TEST_F(TestFixture, Sandbox)
{
    Dispatcher<ChannelOfferEventType> dispatcher1;
    
}
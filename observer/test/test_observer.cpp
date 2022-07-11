#include <gtest/gtest.h>

#include <typeindex>

#include "observer/event.hpp"
#include "observer/dispatcher.hpp"

struct TestFixture : testing::Test
{
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

class ChannelOfferEvent : public examples::observer::Event<ChannelOfferEventType>
{
    ChannelOfferEvent() : Event<ChannelOfferEventType>(ChannelOfferEventType::UNDEFINED){};
    virtual ~ChannelOfferEvent() = default;
};

class ChannelSubscriptionEvent : public examples::observer::Event<ChannelSubscriptionEventType>
{
    ChannelSubscriptionEvent()
        : examples::observer::Event<ChannelSubscriptionEventType>(ChannelSubscriptionEventType::UNDEFINED){};
    virtual ~ChannelSubscriptionEvent() = default;
};

template <typename T>
struct Dispatcher
{
    using SlotType = std::function<void(const examples::observer::Event<T>&)>;  // replace by heap free alternative

    SlotType m_slot;
};

class Observer
{
    void handle(const examples::observer::Event<ChannelOfferEventType>& event)
    {
        if (event.getType() == ChannelOfferEventType::OFFER) {
        }
    }
};

TEST_F(TestFixture, Sandbox)
{
    Dispatcher<ChannelOfferEventType> dispatcher1;
}

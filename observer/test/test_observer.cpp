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

struct ChannelOfferEvent : public examples::observer::Event<ChannelOfferEventType>
{
    ChannelOfferEvent() : Event<ChannelOfferEventType>(ChannelOfferEventType::UNDEFINED){};
    virtual ~ChannelOfferEvent() = default;
};

struct Observer
{
    void handle(const examples::observer::Event<ChannelOfferEventType>& event)
    {
        if (event.getType() == ChannelOfferEventType::OFFER) {
        }
    }
};

TEST_F(TestFixture, Sandbox)
{
    using ChannelOfferEventDispatcher = examples::observer::Dispatcher<ChannelOfferEventType, 2>;

    ChannelOfferEventDispatcher dispatcher1;

    Observer observer;

    dispatcher1.subscribe(ChannelOfferEventType::OFFER, ChannelOfferEventDispatcher::Callable::create<Observer, &Observer::handle>(observer));

    ChannelOfferEvent e1;
    dispatcher1.dispatch(e1);
}

/*******************************************************************************
 * Copyright (C) 2022 Timon Reich
 *
 * C++ examples library
 *
 * License notes see LICENSE.txt
 ******************************************************************************/

#include "observer/dispatcher.hpp"
#include "observer/event.hpp"

#include <gtest/gtest.h>

#include <typeindex>
#include <iostream>

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
    ChannelOfferEvent(ChannelOfferEventType type)
        : Event<ChannelOfferEventType>(type){};

    virtual ~ChannelOfferEvent() = default;

    int data{42};
};

struct Observer
{
    void handle(const ChannelOfferEvent& event)
    {
        if (event.getType() == ChannelOfferEventType::OFFER)
        {
            std::cout << "Received ChannelOfferEvent with data '" << event.data << "'" << std::endl;
        }
    }
};

TEST_F(TestFixture, Sandbox)
{
    using ChannelOfferEventDispatcher = examples::observer::Dispatcher<ChannelOfferEvent, 2>;

    ChannelOfferEventDispatcher dispatcher1;

    Observer observer;

    dispatcher1.subscribe(ChannelOfferEventType::OFFER,
                          ChannelOfferEventDispatcher::Callable::create<Observer, &Observer::handle>(observer));

    ChannelOfferEvent e1{ChannelOfferEventType::OFFER};
    dispatcher1.dispatch(e1);
}

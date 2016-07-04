#pragma once

#include <gtest\gtest.h>
#include <chrono>
#include <memory>
#include "Trade\trade.h"
#include "Trade\SimpleTrade.h"

class TradeTest : public ::testing::Test
{
public:
	TradeTest()
	{
		timestamp_ = std::chrono::system_clock::now();
		quantity_ = 5;
		price_ = 12;
		type_ = simplestock::Trade::TradeType::Buy;
		trade_ = std::make_unique<simplestock::SimpleTrade>(quantity_, price_, type_, timestamp_);
	}

	~TradeTest()
	{
	}

public:
	std::shared_ptr<simplestock::Trade> trade_;
	std::chrono::system_clock::time_point timestamp_;
	int quantity_;
	double price_;
	simplestock::Trade::TradeType type_;
};


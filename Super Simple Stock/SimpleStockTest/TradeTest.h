// This class is used to test Trade functionality
// Tests are organised using google test fixtures
// each test fixture is verifying method provided by Trade class
#pragma once

#include <gtest\gtest.h>
#include <chrono>
#include <memory>
#include "Trade\trade.h"

class TradeTest : public ::testing::Test
{
public:
	TradeTest()
	{
		//details of Trade
		timestamp_ = std::chrono::system_clock::now();
		quantity_ = 5;
		price_ = 12;
		type_ = simplestock::Trade::TradeType::Buy;
		trade_.reset(new simplestock::Trade(quantity_, price_, type_, timestamp_));
	}

	~TradeTest()
	{
	}

public:
	std::unique_ptr<simplestock::Trade> trade_;
	std::chrono::system_clock::time_point timestamp_;
	int quantity_;
	double price_;
	simplestock::Trade::TradeType type_;
};

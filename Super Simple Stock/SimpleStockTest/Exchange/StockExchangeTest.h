#pragma once

#include <gtest\gtest.h>
#include <memory>
#include "Mocks.h"
#include "Stock\Stock.h"
#include "Exchange\StockExchange.h"

class StockExchangeTest : public ::testing::Test
{
public:
	StockExchangeTest() : exchange_("GBCE")
	{
		auto mock = std::make_shared<StockMock>();
		EXPECT_CALL(*mock, getStockSymbol())
			.WillRepeatedly(Return(std::string("TEA")));

		stocks_.emplace_back(mock);
	}

public:
	simplestock::StockExchange exchange_;
	std::vector<std::shared_ptr<simplestock::Stock>> stocks_;
};


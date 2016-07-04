// This class is used to test stock exchange functionality
// Tests are organised using google test fixtures
// each test fixture is verifying method provided by StockExchange class
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
		//mock Stock object and set the expectation
		auto mock = std::make_shared<StockMock>();
		EXPECT_CALL(*mock, getStockSymbol())
			.WillRepeatedly(Return(std::string("TEA")));

		//keep list of stocks created
		stocks_.emplace_back(mock);
	}

public:
	simplestock::StockExchange exchange_;
	std::vector<std::shared_ptr<simplestock::Stock>> stocks_;
};

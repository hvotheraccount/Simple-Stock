// This class is used to test Stock service functionality
// Tests are organised using google test fixtures
// each test fixture is verifying method provided by StockService class
#pragma once

#include <gtest\gtest.h>
#include "Mocks.h"
#include "Stock\Stock.h"

class StockServiceTest : public ::testing::Test
{
public:
	StockServiceTest()
	{
		stock_ = std::make_shared<simplestock::Stock>(stockMock_);
		exchange_ = std::make_shared<simplestock::StockExchange>(exchangeMock_);
	}

	void SetUp()
	{
		EXPECT_CALL(stockMock_, getStockSymbol())
			.WillRepeatedly(Return(std::string("TEA")));
		exchange_->registerStock(stock_);
		EXPECT_CALL(exchangeMock_, getStock("TEA"))
			.WillRepeatedly(Return(stock_));
	}

public:
	StockExchangeMock exchangeMock_;
	StockMock stockMock_;
	std::shared_ptr<simplestock::Stock> stock_;
	std::shared_ptr<simplestock::StockExchange> exchange_;
};

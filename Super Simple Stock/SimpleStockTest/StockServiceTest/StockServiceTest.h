#pragma once

#include <gtest\gtest.h>
#include "..\Mocks.h"
#include "Stock\Stock.h"

class StockServiceTest : public ::testing::Test
{
public:
	StockServiceTest() : stockMock_(std::make_shared<StockMock>()), exchangeMock_(std::make_shared<StockExchangeMock>())
	{
		stock_ = stockMock_;
		exchange_ = exchangeMock_;
	}

	void SetUp()
	{
		EXPECT_CALL(*stockMock_, getStockSymbol())
			.WillRepeatedly(Return(std::string("TEA")));
		exchange_->registerStock(stock_);
		EXPECT_CALL(*exchangeMock_, getStock("TEA"))
			.WillRepeatedly(Return(stock_));
	}


public:
	std::shared_ptr<StockExchangeMock> exchangeMock_;
	std::shared_ptr<StockMock> stockMock_;
	std::shared_ptr<simplestock::Stock> stock_;
	std::shared_ptr<simplestock::StockExchange> exchange_;
	
	
};
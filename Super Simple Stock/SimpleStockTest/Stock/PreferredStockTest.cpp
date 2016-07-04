#include "Stock\PreferredStock.h"
#include "PreferredStockTest.h"

TEST_F(PreferredStockTest, dividendYieldTest)
{
	EXPECT_EQ(20.0, stock_->calculateDividendYield(10));
}

TEST_F(PreferredStockTest, peRatioTest)
{
	EXPECT_EQ(0.5, stock_->calculatePERatio(10));
}

TEST_F(PreferredStockTest, stockSymbolTest)
{
	EXPECT_EQ("GIN", stock_->getStockSymbol());
}

TEST_F(PreferredStockTest, calculateVWStockPriceTest)
{	
	simplestock::Trade t1(5, 10, simplestock::Trade::TradeType::Buy, std::chrono::system_clock::now());
	simplestock::Trade t2(5, 10, simplestock::Trade::TradeType::Buy, std::chrono::system_clock::now());
	stock_->recordTrade(t1);
	stock_->recordTrade(t2);
	EXPECT_EQ(10.0, stock_->calculateVWStockPrice());
}
#include "Stock\PreferredStock.h"
#include "Stock\PreferredStockTest.h"
#include "Trade\SimpleTrade.h"

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
	auto t1(std::make_shared<simplestock::SimpleTrade>(5, 10, simplestock::Trade::TradeType::Buy, std::chrono::system_clock::now()));
	auto t2(std::make_shared<simplestock::SimpleTrade>(5, 10, simplestock::Trade::TradeType::Buy, std::chrono::system_clock::now()));
	stock_->recordTrade(t1);
	stock_->recordTrade(t2);
	EXPECT_EQ(10.0, stock_->calculateVWStockPrice());
}

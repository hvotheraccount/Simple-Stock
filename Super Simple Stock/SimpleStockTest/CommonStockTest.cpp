#include "Stock\CommonStock.h"
#include "Stock\CommonStockTest.h"
#include "Exceptions\Exceptions.h"
#include "Stock\Stock.h"
#include "Trade\Trade.h"
#include "Trade\SimpleTrade.h"


TEST_F(CommonStockTest, dividendYieldTest)
{
	EXPECT_EQ(0.0, stock_->calculateDividendYield(10));
}

TEST_F(CommonStockTest, peRatioTest)
{
	try
	{
		stock_->calculatePERatio(10);
	}
	catch (simplestock::DivideByZeroException& err)
	{
		EXPECT_EQ(err.what(), "tried to divide by zero");
	}
}

TEST_F(CommonStockTest, stockSymbolTest)
{
	EXPECT_EQ("TEA", stock_->getStockSymbol());
}

TEST_F(CommonStockTest, calculateVWStockPriceTest)
{
	auto t1(std::make_shared<simplestock::SimpleTrade>(5, 10, simplestock::Trade::TradeType::Buy, std::chrono::system_clock::now()));
	auto t2(std::make_shared<simplestock::SimpleTrade>(5, 10, simplestock::Trade::TradeType::Buy, std::chrono::system_clock::now()));
	stock_->recordTrade(t1);
	stock_->recordTrade(t2);
	EXPECT_EQ(10.0, stock_->calculateVWStockPrice());
}

#include "Stock\CommonStock.h"
#include "StockExchangeTest.h"

TEST_F(StockExchangeTest, getStockTest)
{
	exchange_.registerStock(stocks_[0]);
	auto p = exchange_.getStock("TEA");
	assert(p != nullptr);
}

TEST_F(StockExchangeTest, getStocksTest)
{
	exchange_.registerStock(stocks_[0]);
	EXPECT_EQ(1, exchange_.getStocks().size());
}

#include <gtest\gtest.h>
#include "StockService\SimpleStockService.h"
#include "StockServiceTest.h"


TEST_F(StockServiceTest, getDividendYieldTest)
{	
	EXPECT_CALL(*stockMock_, calculateDividendYield(1.0))
		.WillOnce(Return(10.0));
	
	simplestock::SimpleStockService service(*exchange_);
	double dividendYield = service.getDividendYield("TEA", 1.0);
	EXPECT_EQ(10.0, dividendYield);
}

TEST_F(StockServiceTest, getPERatioTest)
{
	EXPECT_CALL(*stockMock_, calculatePERatio(1.0))
		.WillOnce(Return(10.0));

	simplestock::SimpleStockService service(*exchange_);
	double peRatio = service.getPERatio("TEA", 1.0);
	EXPECT_EQ(10.0, peRatio);
}


TEST_F(StockServiceTest, getVWStockPriceTest)
{
	EXPECT_CALL(*stockMock_, calculateVWStockPrice())
		.WillOnce(Return(0.0));

	simplestock::SimpleStockService service(*exchange_);
	double price = service.getVWStockPrice("TEA");
	EXPECT_EQ(0.0, price);
}


TEST_F(StockServiceTest, calculateGBCEAllShareIndexTest)
{	
	EXPECT_CALL(*stockMock_, calculateVWStockPrice())
		.WillOnce(Return(2.0));

	std::vector<std::shared_ptr<simplestock::Stock>> stocks{ stockMock_};
	EXPECT_CALL(*exchangeMock_, getStocks())
		.WillRepeatedly(Return(stocks));

	simplestock::SimpleStockService service(*exchange_);
	double price = service.calculateGBCEAllShareIndex();
	EXPECT_EQ(2.0, price);
}

// test class to test each function provided by Trade class
#include "Trade\TradeTest.h"

TEST_F(TradeTest, priceTest)
{
	EXPECT_EQ(price_, trade_->getSharePrice());
}

TEST_F(TradeTest, quantityTest)
{
	EXPECT_EQ(quantity_, trade_->getTradeQuantity());
}

TEST_F(TradeTest, timestampTest)
{
	EXPECT_EQ(timestamp_, trade_->getRecordTime());
}

TEST_F(TradeTest, typeTest)
{
	EXPECT_EQ(type_, trade_->getTradeType());
}
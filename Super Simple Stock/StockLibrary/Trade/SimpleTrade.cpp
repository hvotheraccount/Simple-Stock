//implementation of SimpleTrade class
#include "SimpleTrade.h"

namespace simplestock
{
	SimpleTrade::SimpleTrade(int quantity, double sharePrice, TradeType type, std::chrono::system_clock::time_point timestamp) : quantity_(quantity), price_(sharePrice), tradeType_(type), timestamp_(timestamp)
	{
	}

	double SimpleTrade::getTotalTradePrice()
	{
		return price_ * quantity_;
	}

	double SimpleTrade::getSharePrice()
	{
		return price_;
	}

	int SimpleTrade::getTradeQuantity()
	{
		return quantity_;
	}

	std::chrono::system_clock::time_point SimpleTrade::getRecordTime()
	{
		return timestamp_;
	}

	Trade::TradeType SimpleTrade::getTradeType()
	{
		return tradeType_;
	}
}
// Trade details class
#pragma once

#include "..\stdafx.h"
#include <chrono>
#include "Trade.h"

namespace simplestock
{
	class SimpleTrade : public Trade
	{
	public:

		//constructor
		EXPORT SimpleTrade(int quantity, double sharePrice, TradeType type, std::chrono::system_clock::time_point timestamp);

		EXPORT double getTotalTradePrice();
		EXPORT double getSharePrice();
		EXPORT int getTradeQuantity();
		EXPORT std::chrono::system_clock::time_point getRecordTime();
		EXPORT TradeType getTradeType();

	private:
		int quantity_;
		double price_;
		TradeType tradeType_;
		std::chrono::system_clock::time_point timestamp_;
	};
}

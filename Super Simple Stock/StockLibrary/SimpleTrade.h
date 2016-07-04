// Trade details class
#pragma once

#include "..\stdafx.h"
#include <chrono>

namespace simplestock
{
	class Trade
	{
	public:
		enum class EXPORT TradeType
		{
			Buy,
			Sell
		};

		//constructor
		EXPORT Trade(int quantity, double sharePrice, TradeType type, std::chrono::system_clock::time_point timestamp);

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
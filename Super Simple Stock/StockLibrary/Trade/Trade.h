// Trade interface
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

		EXPORT virtual ~Trade() {}
		EXPORT virtual double getTotalTradePrice() = 0;
		EXPORT virtual double getSharePrice() = 0;
		EXPORT virtual int getTradeQuantity() = 0;
		EXPORT virtual std::chrono::system_clock::time_point getRecordTime() = 0;
		EXPORT virtual TradeType getTradeType() = 0;
	};
}
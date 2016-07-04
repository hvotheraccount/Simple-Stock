// Interface for implementing Stock types
#pragma once

#include "..\stdafx.h"
#include <memory>
#include <string>
#include "..\Trade\Trade.h"

namespace simplestock
{
	//pure virtual class as a stock interface
	class EXPORT Stock
	{
	public:
		enum class StockType
		{
			Common,
			Preferred
		};

		virtual ~Stock() {};
		virtual double calculateDividendYield(double price) = 0;
		virtual double calculatePERatio(double price) = 0;
		virtual std::string getStockSymbol() const = 0;
		virtual void recordTrade(std::shared_ptr<Trade> trade) = 0;
		virtual double calculateVWStockPrice() = 0;
	};
}
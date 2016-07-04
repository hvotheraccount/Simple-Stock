// Interface class of pure virtual functions for Stock Service
#pragma once

#include <chrono>
#include <string>
#include "..\Trade\Trade.h"

namespace simplestock
{
	class EXPORT StockService
	{
	public:
		virtual ~StockService() {}
		virtual double getDividendYield(const std::string& stockSymbol, double price) = 0;
		virtual double getPERatio(const std::string& stockSymbol, double price) = 0;
		virtual void recordTrade(const std::string& stockSymbol, int quantity, double price, Trade::TradeType type, std::chrono::system_clock::time_point timestamp) = 0;
		virtual double getVWStockPrice(const std::string& stockSymbol) = 0;
		virtual double calculateGBCEAllShareIndex() = 0;
	};
}
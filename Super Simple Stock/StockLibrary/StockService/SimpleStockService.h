// Main class exposing stock service functionality
#pragma once

#include "..\StockService\StockService.h"
#include "..\Exchange\StockExchange.h"

namespace simplestock
{
	class SimpleStockService : public StockService
	{
	public:
		EXPORT SimpleStockService(const StockExchange& exchange);
		EXPORT double getDividendYield(const std::string& stockSymbol, double price);
		EXPORT double getPERatio(const std::string& stockSymbol, double price);
		EXPORT void recordTrade(const std::string& stockSymbol, int quantity, double price, Trade::TradeType type, std::chrono::system_clock::time_point timestamp);
		EXPORT double getVWStockPrice(const std::string& stockSymbol);
		EXPORT double calculateGBCEAllShareIndex();

	private:
		StockExchange exchange_;
	};
}
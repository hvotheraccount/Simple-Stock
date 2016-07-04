#include "..\stdafx.h"
#include <chrono>
#include "SimpleStockService.h"
#include "..\Stock\Stock.h"
#include "..\Trade\SimpleTrade.h"

namespace simplestock
{
	SimpleStockService::SimpleStockService(const StockExchange& exchange) : exchange_(exchange)
	{
	}

	double SimpleStockService::getDividendYield(const std::string& stockSymbol, double price)
	{
		auto stock = exchange_.getStock(stockSymbol);
		return stock ? stock->calculateDividendYield(price) : 0;
	}

	double SimpleStockService::getPERatio(const std::string& stockSymbol, double price)
	{
		auto stock = exchange_.getStock(stockSymbol);
		return stock ? stock->calculatePERatio(price) : 0;
	}

	void SimpleStockService::recordTrade(const std::string& stockSymbol, int quantity, double price, Trade::TradeType type, std::chrono::system_clock::time_point timestamp)
	{
		auto stock = exchange_.getStock(stockSymbol);
		auto t(std::make_shared<SimpleTrade>(quantity, price, type, timestamp));
		if (stock)
			stock->recordTrade(t);
	}

	double SimpleStockService::getVWStockPrice(const std::string& stockSymbol)
	{
		auto stock = exchange_.getStock(stockSymbol);
		return stock ? stock->calculateVWStockPrice() : 0;
	}

	double SimpleStockService::calculateGBCEAllShareIndex()
	{
		return exchange_.calculateAllShareIndex();
	}
}

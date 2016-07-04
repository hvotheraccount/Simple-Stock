#include "StockExchange.h"

namespace simplestock
{
	StockExchange::StockExchange()
	{
	}

	StockExchange::StockExchange(const std::string& name) : name_(name)
	{
	}

	// maintain the stock entry
	void StockExchange::registerStock(std::shared_ptr<Stock> stock)
	{
		std::string symbol(stock->getStockSymbol());
		auto it = stocks_.find(symbol);
		if (it == stocks_.end())
		{
			stocks_[symbol] = stock;
		}
	}

	std::shared_ptr<Stock> StockExchange::getStock(const std::string& stockSymbol)
	{
		auto it = stocks_.find(stockSymbol);
		if (it != stocks_.end())
			return it->second;

		return nullptr;
	}

	std::vector<std::shared_ptr<Stock>> StockExchange::getStocks()
	{
		std::vector<std::shared_ptr<Stock>> listOfStocks;
		for (auto it : stocks_)
			listOfStocks.emplace_back(it.second);

		return listOfStocks;
	}

	// calculate GBCE all share index
	double StockExchange::calculateAllShareIndex()
	{
		double product = 1;
		for (auto it : stocks_)
			product *= it.second->calculateVWStockPrice();

		double exp = 1.0 / stocks_.size();
		return std::pow(product, exp);
	}

	// remve the stock entry
	void StockExchange::unregisterStock(std::shared_ptr<Stock> stock)
	{
		stocks_.erase(stock->getStockSymbol());
	}
}

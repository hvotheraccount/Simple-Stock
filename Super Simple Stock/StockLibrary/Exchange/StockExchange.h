// Exchange functionality
// User can register/unregister stocks from the exchange
// Also can retrieve individual or list of stocks
#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include "..\Stock\Stock.h"

namespace simplestock
{
	class StockExchange
	{
	public:
		EXPORT StockExchange();
		EXPORT StockExchange(const std::string& name);
		EXPORT void registerStock(std::shared_ptr<Stock> stock);
		EXPORT std::shared_ptr<Stock> getStock(const std::string& stockSymbol);
		EXPORT std::vector<std::shared_ptr<Stock>> getStocks();
		EXPORT double calculateAllShareIndex();
		EXPORT void unregisterStock(std::shared_ptr<Stock> stock);

	private:
		std::string name_;
		std::unordered_map<std::string, std::shared_ptr<Stock>> stocks_;
	};
}

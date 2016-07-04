// Abstract class providing some of the common functionality for type of Stocks
// Common implemenation for stocks should be added here so that would be available for all derived classes
#pragma once

#include "..\stdafx.h"
#include <string>
#include <vector>
#include "..\Stock\Stock.h"
#include "..\Trade\Trade.h"

namespace simplestock
{
	class AbstractStock : public Stock
	{
	public:
		EXPORT AbstractStock(const std::string& stockSymbol, double lastDividend, double parValue);
		EXPORT virtual ~AbstractStock() {}

		//this method would be implemented by derived classes to provide their own calculation
		EXPORT virtual double calculateDividendYield(double price) = 0;

		EXPORT double calculatePERatio(double price);
		EXPORT std::string getStockSymbol() const;
		EXPORT void recordTrade(std::shared_ptr<Trade> trade);
		EXPORT double calculateVWStockPrice();

	protected:
		std::string symbol_;
		double lastDividend_;
		double parValue_;
		std::vector<std::shared_ptr<Trade>> trades_;

	private:
		std::vector<std::shared_ptr<Trade>> getLastFifteenMinutesTrades();
	};
}

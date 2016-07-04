#include "AbstractStock.h"
#include "..\Exceptions\Exceptions.h"

namespace simplestock
{
	// constructor
	AbstractStock::AbstractStock(const std::string& stockSymbol, double lastDividend, double parValue) :
		symbol_(stockSymbol),
		lastDividend_(lastDividend),
		parValue_(parValue)
	{
	}

	// PE ratio = price / dividend
	double AbstractStock::calculatePERatio(double price)
	{
		if (!price)
			throw DivideByZeroException();
		return price / this->calculateDividendYield(price);
	}

	// e.g. "TEA"
	std::string AbstractStock::getStockSymbol() const
	{
		return symbol_;
	}

	// make a trade entry
	void AbstractStock::recordTrade(std::shared_ptr<Trade> trade)
	{
		trades_.emplace_back(trade);
	}

	// Volume Weighted Stock Price = (sum of trade price * quantity) / sum of quantity
	double AbstractStock::calculateVWStockPrice()
	{
		std::vector<std::shared_ptr<Trade>> recentTrades = getLastFifteenMinutesTrades();
		double totalPrice = 0, totalQuantity = 0;
		for (auto t : recentTrades)
		{
			totalPrice += (t->getSharePrice() * t->getTradeQuantity());
			totalQuantity += t->getTradeQuantity();
		}

		if (!totalQuantity)
			throw DivideByZeroException();

		return totalPrice / totalQuantity;
	}

	// last 15 minutes trades
	std::vector<std::shared_ptr<Trade>> AbstractStock::getLastFifteenMinutesTrades()
	{
		std::vector<std::shared_ptr<Trade>> recentTrades;
		for (auto t : trades_)
		{
			if (t->getRecordTime() > (t->getRecordTime() - std::chrono::seconds(900)))
			{
				recentTrades.emplace_back(t);
			}
		}
		return recentTrades;
	}
}
#include "CommonStock.h"
#include "..\Exceptions\Exceptions.h"

namespace simplestock
{
	CommonStock::CommonStock() :
		AbstractStock("", 0, 0)
	{
	}

	CommonStock::CommonStock(const std::string& stockSymbol, double lastDividend, double parValue) :
		AbstractStock(stockSymbol, lastDividend, parValue)
	{
	}

	CommonStock::~CommonStock()
	{
	}

	double CommonStock::calculateDividendYield(double price)
	{
		if (!price)
			throw DivideByZeroException();

		return lastDividend_ / price;
	}
}

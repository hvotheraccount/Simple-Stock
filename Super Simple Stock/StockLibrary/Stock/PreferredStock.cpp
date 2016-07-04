#include "PreferredStock.h"
#include "..\Exceptions\Exceptions.h"

namespace simplestock
{
	PreferredStock::PreferredStock(const std::string& stockSymbol, double lastDividend, double parValue, double fixedDividend) :
		AbstractStock(stockSymbol, lastDividend, parValue),
		fixedDividend_(fixedDividend)
	{
	}

	PreferredStock::~PreferredStock()
	{
	}

	double PreferredStock::calculateDividendYield(double price)
	{
		if (!price)
			throw DivideByZeroException();

		return (fixedDividend_ * parValue_) / price;
	}
}
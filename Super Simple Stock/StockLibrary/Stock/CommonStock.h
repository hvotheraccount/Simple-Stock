// Derived class from AbstractStock
// Provides custom implemenation for dividend yield method
#pragma once

#include "..\stdafx.h"
#include "..\Stock\AbstractStock.h"

namespace simplestock
{
	class CommonStock : public AbstractStock
	{
	public:
		EXPORT CommonStock();
		EXPORT CommonStock(const std::string& stockSymbol, double lastDividend, double parValue);
		EXPORT ~CommonStock();
		EXPORT double calculateDividendYield(double price);
	};
}
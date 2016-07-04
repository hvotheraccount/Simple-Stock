// Derived class from AbstractStock
// Provides custom implemenation for dividend yield method
#pragma once

#include "..\stdafx.h"
#include "..\Stock\AbstractStock.h"

namespace simplestock
{
	class PreferredStock : public AbstractStock
	{
	public:
		EXPORT PreferredStock(const std::string& stockSymbol, double lastDividend, double parValue, double fixedDividend);
		EXPORT ~PreferredStock();
		EXPORT double calculateDividendYield(double price);

	private:
		double fixedDividend_;
	};
}
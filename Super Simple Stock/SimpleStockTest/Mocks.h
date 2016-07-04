// This class is used to provide mock objects
// Couple of mock objects are created using gmock framework
#pragma once

#include <gmock\gmock.h>
#include <memory>
#include "Stock\Stock.h"
#include "Exchange\StockExchange.h"

using ::testing::Return;
class StockMock : public simplestock::Stock
{
public:
	MOCK_CONST_METHOD0(getStockSymbol, std::string());
	MOCK_METHOD1(calculateDividendYield, double(double));
	MOCK_METHOD1(calculatePERatio, double(double));
	MOCK_METHOD1(recordTrade, void(std::shared_ptr<simplestock::Trade>));
	MOCK_METHOD0(calculateVWStockPrice, double());
};

class StockExchangeMock : public simplestock::StockExchange
{
public:
	MOCK_METHOD1(registerStock, void(std::shared_ptr<simplestock::Stock>));
	MOCK_METHOD1(getStock, std::shared_ptr<simplestock::Stock>(const std::string&));
	MOCK_METHOD0(getStocks, std::vector<std::shared_ptr<simplestock::Stock>>());
	MOCK_METHOD0(calculateAllShareIndex, double());
	MOCK_METHOD1(unregisterStock, void(std::shared_ptr<simplestock::Stock>));
};

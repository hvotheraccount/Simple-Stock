#pragma once

#include <gtest\gtest.h>
#include <memory>

class CommonStockTest : public ::testing::Test
{
public:
	CommonStockTest()
	{
		lastDividend_ = 0;
		parValue_ = 100;
		stock_.reset(new simplestock::CommonStock("TEA", lastDividend_, parValue_));
	}

	~CommonStockTest()
	{
	}

public:
	std::unique_ptr<simplestock::Stock> stock_;
	double lastDividend_, parValue_;
};


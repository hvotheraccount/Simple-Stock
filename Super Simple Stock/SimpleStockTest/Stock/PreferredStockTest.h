#pragma once

#include <gtest\gtest.h>
#include <memory>

class PreferredStockTest : public ::testing::Test
{
public:
	PreferredStockTest()
	{
		lastDividend_ = 0;
		parValue_ = 100;
		fixedDividend_ = 2;
		stock_.reset(new simplestock::PreferredStock("GIN", lastDividend_, parValue_, fixedDividend_));
	}

	~PreferredStockTest()
	{
	}

public:
	std::unique_ptr<simplestock::Stock> stock_;
	double lastDividend_, parValue_, fixedDividend_;
};



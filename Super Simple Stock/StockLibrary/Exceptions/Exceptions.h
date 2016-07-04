#pragma once

#include "..\stdafx.h"
#include <stdexcept>

namespace simplestock
{
	class DivideByZeroException : public std::runtime_error
	{
	public:
		DivideByZeroException() : std::runtime_error("tried to divide by zero") {}
	};
}
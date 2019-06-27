#pragma once
#include "Value.h"
class IntValue : public Value
{
public:
	IntValue();
	IntValue(String);
	String getType();
};
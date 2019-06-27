#pragma once
#include "Value.h"

class FractionalValue : public Value
{
public:
	FractionalValue();
	FractionalValue(String);
	String getType();
};
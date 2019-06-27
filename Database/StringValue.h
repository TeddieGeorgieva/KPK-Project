#pragma once
#include "Value.h"

class StringValue : public Value
{
public:
	StringValue();
	StringValue(const String&);
	String getType();
};
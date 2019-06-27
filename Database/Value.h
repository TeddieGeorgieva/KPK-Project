#pragma once
#include "String.h"
class Value
{
	String val;
public:
	Value();
	Value(String value);
	String getValue();
	virtual String getType() = 0;
	static Value* factory(String, String);
};

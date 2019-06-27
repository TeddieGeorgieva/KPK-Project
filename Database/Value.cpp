#include "stdafx.h"
#include "Value.h"
#include "String.h"
#include "IntValue.h"
#include "FractionalValue.h"
#include "StringValue.h"
Value::Value()
{
	String val;
}
Value::Value(String value)
{
	this->val = value;
}
String Value::getValue()
{
	return val;
}
Value* Value::factory(String type, String value)
{
	if (type == String("Int")) return new IntValue(value);
	if (type == String("Fractional")) return new FractionalValue(value);
	if (type == String("String")) return new StringValue(value);
}
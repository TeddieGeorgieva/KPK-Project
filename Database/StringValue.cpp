#include "stdafx.h"
#include "StringValue.h"

StringValue::StringValue() : Value()
{

}
StringValue::StringValue(const String& val) : Value(val) {}
String StringValue::getType()
{
	return String("String");
}
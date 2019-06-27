#include "stdafx.h"
#include "IntValue.h"

IntValue::IntValue() : Value()
{

}
IntValue::IntValue(String val) : Value(val) {}
String IntValue::getType()
{
	return String("Int");
}
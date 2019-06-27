#include "stdafx.h"
#include "FractionalValue.h"

FractionalValue::FractionalValue() : Value()
{

}
FractionalValue::FractionalValue(String val) : Value(val) {}
String FractionalValue::getType()
{
	return String("Fractional");
}
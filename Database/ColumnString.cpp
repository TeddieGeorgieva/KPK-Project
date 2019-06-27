#include "stdafx.h"
#include "ColumnString.h"

ColumnString::ColumnString() :Column() {};
ColumnString::ColumnString(String name) : Column(name, type) {};
String ColumnString::getType()
{
	return "String";
}
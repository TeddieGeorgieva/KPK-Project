#pragma once
#include "Column.h"

class ColumnString : public Column
{
public:
	ColumnString();
	ColumnString(String name);
	String getType();
};
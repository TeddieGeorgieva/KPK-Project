#pragma once
#include "Column.h"

class FractionalNum : public Column
{
public:
	FractionalNum();
	FractionalNum(String name);
	String getType() const;
};
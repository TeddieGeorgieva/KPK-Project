#pragma once
#include "Column.h"
#include "String.h"

class Int : public Column
{
public:
	Int(); 
	Int(String); 
	String getType()const;
};


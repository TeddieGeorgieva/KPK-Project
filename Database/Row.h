#pragma once
#include "Vector.h"
#include "Value.h"

class Row
{
	Vector<Value*> values;
public:
	Row();
	Row(Vector<Value*> values);
	Vector<Value*>& getValues();
};
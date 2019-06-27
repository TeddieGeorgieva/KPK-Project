#include "stdafx.h"
#include "FractionalNum.h"


FractionalNum::FractionalNum() : Column() {};
FractionalNum::FractionalNum(String name) : Column(name, type) {};

String FractionalNum:: getType() const
{
	return "Fractional Number";
}
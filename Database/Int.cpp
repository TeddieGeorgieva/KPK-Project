#include "stdafx.h"
#include "Int.h"

Int :: Int() : Column() {};
Int :: Int(String name):Column(name, type) {};

String Int:: getType()const
{
	return "Int";
}

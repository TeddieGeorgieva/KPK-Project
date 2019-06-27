#pragma once
#include "String.h"
class Column
{
protected:
	String type;
	String name;
public:
	Column();
	Column(const String& type, const  String& name);
	String getName() const;
	String getType() const;
};
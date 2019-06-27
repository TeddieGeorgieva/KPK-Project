#include "stdafx.h"
#include "Column.h"


Column::Column()
{
	String type;
	String name;
}
Column::Column(const String& type,const  String& name)
{
	this->type = type;
	this->name = name;
}
String Column::getName()const
{
	return this->name;
}
String Column::getType() const 
{
	return this->type;
}
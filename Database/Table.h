#pragma once
#include "Vector.h"
#include "Column.h"
#include "Row.h"
#include <fstream>

class Table
{

	String name;
	Vector<Column*> columns;
	Vector<Row> rows;

public:
	Table();
	Table(Vector<Column*>, Vector<Row>, String);
	String getName() const;
	void setName(const String&);
	void saveColumns(ostream&);
	void saveRows(ostream&);
	Vector<Column*>& getColumns()
	{
		return this->columns;
	}
	Vector<Row>& getRows()
	{
		return this->rows;		
	}
};
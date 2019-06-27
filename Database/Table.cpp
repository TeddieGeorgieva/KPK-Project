#include "stdafx.h"
#include "Table.h"

String Table::getName() const
{
	return this->name;
}
void Table::saveColumns(ostream& file)
{
	size_t size = columns.getSize();
	file << size << endl;
	for (int i = 0; i < size; i++)
	{
		file << columns[i]->getName() << " " << columns[i]->getType() << endl;
	}
}
void Table::saveRows(ostream& file)
{
	size_t rowsize = rows.getSize();
	size_t columnSize = columns.getSize();
	file << rowsize << endl;
	for (int i = 0; i < rowsize; i++)
	{
		for (size_t j = 0; j < columnSize; j++)
		{
			file << rows[i].getValues()[j]->getValue() << " ";
		}
		file << endl;
	}
}
Table::Table()
{
	String name;
	String type;
	Vector<Column*> columns;
	Vector<Row*> rowS;
}
Table::Table(Vector<Column*> cols, Vector<Row> rows, String name)
{
	this->name = name;
	this->columns = cols;
	this->rows = rows;
}
void Table::setName(const String& name)
{
	this->name = name;
}

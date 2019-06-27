#include "stdafx.h"
#include "Tables.h"
#include <fstream>
#include "String.h"

void Tables::load(const char* fileName)
{
	String tableName;
	String tempName;
	String tempType;
	ifstream file(fileName);
	if (file.is_open())
	{
		file >> tableName;
		size_t columnsNum;
		file >> columnsNum;
		Vector<Column*> cols;
		for (int i = 0; i < columnsNum; i++)
		{
			file >> tempName;
			file >> tempType;
			Column * col = new Column(tempType, tempName);
			cols.add(col);
		}
		size_t rowsNum;
		file >> rowsNum;
		Vector<Row> rows;
		String tempStrValue;
		for (int i = 0; i < rowsNum; i++)
		{
			Row tempRow;
			for (int j = 0; j < columnsNum; j++)
			{
				file >> tempStrValue;
				Value* tempvalue = Value::factory(cols[j]->getType(), tempStrValue);
				tempRow.getValues().add(tempvalue);
			}
			rows.add(tempRow);
		}
		Table newTable(cols, rows, tableName);
		size_t tablesSize = tables.getSize();
		tables.add(newTable);
		file.close();
	}
}

void Tables::showTables(std::ostream& os)
{
	size_t tablesLength = tables.getSize();
	if (tablesLength == 0)
	{
		os << "No tables" << endl;
		return;
	}
	for (int i = 0; i < tablesLength; i++)
	{
		os << tables[i].getName() << endl;
	}
	
}

Table* Tables::findByName(const String& name)
{
	size_t size = tables.getSize();
	for (int i = 0; i < size; i++)
	{
		if (tables[i].getName() == name)
		{
			return &tables[i];
		}
	}
	return nullptr;
}
void Tables::save(const String& tableName)
{
	Table* table = this->findByName(tableName);
	if (table != nullptr)
	{
		ofstream file("Table.txt");
		file << table->getName() << endl;
		table->saveColumns(file);
		table->saveRows(file);
	}
	else  throw std::invalid_argument("received negative value");
}
void Tables::addColumn(const String& tableName, const String& name, const String& type)
{
	Table * tb = findByName(tableName);
	
	if (tb != nullptr)
	{
		
		Column* newCol = new Column(type, name);
		tb->getColumns().add(newCol);
		size_t sizeRows = tb->getRows().length();
		for (size_t i = 0; i < sizeRows; i++)
		{
			Value* tempvalue = Value::factory(type, String("NULL"));
			tb->getRows()[i].getValues().add(tempvalue);
		}
	}
	else cout << "No such table" << endl;
}
void Tables:: describe(const String& tablename)
{
	Table * tb = findByName(tablename);
	if (tb != nullptr)
	{
		size_t columnNum = tb->getColumns().getSize();
		for (size_t i = 0; i < columnNum; i++)
		{
			cout << tb->getColumns()[i]->getName() << " " << tb->getColumns()[i]->getType() << endl;

		}
	}
	else cout << "No such table" << endl;
}
void Tables::print(const String& tablename, ostream& os)
{
	Table * tb = findByName(tablename);
	if (tb != nullptr)
	{
		size_t columnSize = tb->getColumns().getSize();
		size_t rowsSize = tb->getRows().getSize();
		os << tb->getName() << endl;
		for (size_t i = 0; i < rowsSize; i++)
		{
			for (size_t j = 0; j < columnSize; j++)
			{
				os << tb->getRows()[i].getValues()[j]->getValue() << " ";
			}
			os << endl;
		}
	}
	else os << "No such table" << endl;

}
void Tables::select(size_t colNum, const String& searchVal, const String& tablename)
{
	Table * tb = findByName(tablename);
	if (tb != nullptr)
	{
		size_t colsCount = tb->getColumns().getSize();
		if (colsCount < colNum)
		{
			cout << "Invalid column number" << endl;
			return;
		}
		size_t rowsCount = tb->getRows().getSize();
		cout << "Select results:" << endl;
		for (size_t i = 0; i < rowsCount; i++)
		{
			if (tb->getRows()[i].getValues()[colNum]->getValue() == searchVal)
			{
				for (size_t j = 0; j < colsCount; j++)
				{
					cout << tb->getRows()[i].getValues()[j]->getValue() << " ";
				}
				cout << endl;
			}
		}

	}
	else cout << "No such table" << endl;
}
void Tables::rename(const String& tablename, const String& newName)
{
	Table * tb = findByName(tablename);
	Table * tb2 = findByName(newName);
	if (tb != nullptr && tb2 == nullptr)
	{
		tb->setName(newName);
	}
	else cout << "No such table" << endl;
}
void Tables::count(const String& tablename, size_t colNum, const String& searchVal)
{
	Table * tb = findByName(tablename);
	if (tb != nullptr)
	{
		size_t colsCount = tb->getColumns().getSize();
		if (colsCount < colNum)
		{
			cout << "Invalid column number" << endl;
			return;
		}
		size_t rowsCount = tb->getRows().getSize();
		size_t numRows = 0;
		for (size_t i = 0; i < rowsCount; i++)
		{
			if (tb->getRows()[i].getValues()[colNum]->getValue() == searchVal)
			{
				numRows++;
			}
		}
		cout << numRows << endl;
	}
	else cout << "No such table" << endl;
}
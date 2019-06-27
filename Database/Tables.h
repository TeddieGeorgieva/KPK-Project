#pragma once
#include "Vector.h"
#include "Table.h"
#include "String.h"

class Tables
{
	Vector<Table> tables;
	Table* findByName(const String&);
public:
	void load(const char*);
	void showTables(std::ostream&);
	void describe(const String&);
	void save(const String& table);
	void addColumn(const String& , const String& , const String&);
	void print(const String& tablename, ostream& os);
	void select(size_t, const String&, const String&);
	void rename(const String&, const String&);
	void count(const String&, size_t, const String&);
};
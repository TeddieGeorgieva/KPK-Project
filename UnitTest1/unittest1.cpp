#include "stdafx.h"
#include "CppUnitTest.h"
#include <cassert>
#include "../Database/Table.h"
#include "../Database/Vector.h"
#include "../Database/Column.h"
#include "../Database/Row.h"
#include "../Database/Value.h"
#include "../Database/IntValue.h"
#include "../Database/Tables.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDatabase
{		
	TEST_CLASS(TestTable)
	{
	public:
		
		TEST_METHOD(CheckIfSaveColumnsSavesSuccessfully)
		{
			// Setup

			int expectedSize = 1;
			std::string expectedName("testColumn");
			std::string expectedType("Int");
			
			Column* column = new Column(expectedType.c_str(), expectedName.c_str());
			Vector<Column*> cols = Vector<Column*>();
			Vector<Row> rows;
			cols.add(column);
			String name = String("tableName");
			Table table = Table(cols, rows, name);
			
			
			//Action
			std::stringstream os;
			table.saveColumns(os);
			
			// Assert
			int actualSize;
			std::string actualName;
			std::string actualType;
			os >> actualSize;
			os >> actualName;
			os >> actualType;
			delete column;
			Assert::AreEqual(expectedSize, actualSize);
			Assert::AreEqual(expectedName, actualName);
			Assert::AreEqual(expectedType, actualType);
		}

		TEST_METHOD(CheckIfSaveRowsSavesSuccessfully)
		{
			// Setup

			int expectedSize = 1;
			std::string columnName("testColumn");
			std::string columnType("Int");
			std::string expectedValue("123");

			Column* column = new Column(columnType.c_str(), columnName.c_str());
			Vector<Column*> cols = Vector<Column*>();
			Value* v = new IntValue(expectedValue.c_str());
			Vector<Value*> values;
			values.add(v);
			Vector<Row> rows;
			Row row1(values);
			rows.add(row1);
			cols.add(column);
			String name = String("tableName");
			Table table = Table(cols, rows, name);


			//Action
			std::stringstream os;
			table.saveRows(os);

			// Assert
			int actualSize;
			std::string actualValue;
			std::string actualType;
			os >> actualSize;
			os >> actualValue;
			delete column;
			delete v;
			Assert::AreEqual(expectedSize, actualSize);
			Assert::AreEqual(expectedValue, actualValue);
		}

	};

	TEST_CLASS(TestTables)
	{
	public:

		TEST_METHOD(CheckIfLoadLoadsSuccessfully)
		{
			// Setup
			int expectedColSize = 3;
			std::string columnName("name");
			std::string columnType("String");
			std::string columnName2("age");
			std::string columnType2("Int");
			std::string columnName3("money");
			std::string columnType3("Fractional");
			
			
			int expectedRowSize = 4;
			std::string row11("gosho");
			std::string row12("20");
			std::string row13("20.00");
			
			std::string row21("pesho");
			std::string row22("21");
			std::string row23("21.00");

			std::string row31("tosho");
			std::string row32("22");
			std::string row33("22.00");

			std::string row41("gosho");
			std::string row42("22");
			std::string row43("20.00");

			
			Vector<Column*> cols = Vector<Column*>();
			Value* v11 = new IntValue(row11.c_str());
			Value* v12 = new IntValue(row12.c_str());
			Value* v13 = new IntValue(row13.c_str());

			Value* v21 = new IntValue(row21.c_str());
			Value* v22 = new IntValue(row22.c_str());
			Value* v23 = new IntValue(row23.c_str());

			Value* v31 = new IntValue(row31.c_str());
			Value* v32 = new IntValue(row32.c_str());
			Value* v33 = new IntValue(row33.c_str());

			Value* v41 = new IntValue(row41.c_str());
			Value* v42 = new IntValue(row42.c_str());
			Value* v43 = new IntValue(row43.c_str());

			Vector<Row> rows;
			
			Vector<Value*> values;
			values.add(v11);
			values.add(v12);
			values.add(v13);			
			Row row1(values);
			rows.add(row1);

			Vector<Value*> values2;
			values.add(v21);
			values.add(v22);
			values.add(v23);
			Row row2(values2);
			rows.add(row2);


			Vector<Value*> values3;
			values.add(v31);
			values.add(v32);
			values.add(v33);
			Row row3(values3);
			rows.add(row3);
			
			Vector<Value*> values4;
			values.add(v41);
			values.add(v42);
			values.add(v43);
			Row row4(values4);
			rows.add(row4);

			Column* column = new Column(columnType.c_str(), columnName.c_str());
			Column* column2 = new Column(columnType2.c_str(), columnName2.c_str());
			Column* column3 = new Column(columnType3.c_str(), columnName3.c_str());

			cols.add(column);
			cols.add(column2);
			cols.add(column3);
			std::string name("people");
			Table table = Table(cols, rows, name.c_str());

			Tables t;
			t.load("../Database/people.txt");

			//Action

			// Assert
			
			delete column;
			delete column2;
			delete column3;

			delete v11;
			delete v12;
			delete v13;
			delete v21;
			delete v22;
			delete v23;
			delete v31;
			delete v32;
			delete v33;
			delete v41;
			delete v42;
			delete v43;

			std::stringstream ss;
			t.print(name.c_str(), ss);
			std::string actualTableName;
			std::string actualVal11;
			std::string actualVal12;
			std::string actualVal13;
			std::string actualVal21;
			std::string actualVal22;
			std::string actualVal23;
			std::string actualVal31;
			std::string actualVal32;
			std::string actualVal33;
			std::string actualVal41;
			std::string actualVal42;
			std::string actualVal43;

			ss >> actualTableName;

			ss >> actualVal11;
			ss >> actualVal12;
			ss >> actualVal13;

			ss >> actualVal21;
			ss >> actualVal22;
			ss >> actualVal23;

			ss >> actualVal31;
			ss >> actualVal32;
			ss >> actualVal33;

			ss >> actualVal41;
			ss >> actualVal42;
			ss >> actualVal43;

			Assert::AreEqual(name, actualTableName);
			Assert::AreEqual(row11, actualVal11);
			Assert::AreEqual(row12, actualVal12);
			Assert::AreEqual(row13, actualVal13);
			Assert::AreEqual(row21, actualVal21);
			Assert::AreEqual(row22, actualVal22);
			Assert::AreEqual(row23, actualVal23);
			Assert::AreEqual(row31, actualVal31);
			Assert::AreEqual(row32, actualVal32);
			Assert::AreEqual(row33, actualVal33);
			Assert::AreEqual(row41, actualVal41);
			Assert::AreEqual(row42, actualVal42);
			Assert::AreEqual(row43, actualVal43);
			
		}
		TEST_METHOD(ShowTablesShouldWorkProperlyWheTableExists)
		{
			// Setup
			Tables t;
			t.load("../Database/people.txt");
			std::stringstream ss;
			t.showTables(ss);
			std::string expected("people");
			std::string actual;
			ss >> actual;
			Assert::AreEqual(actual, expected);
		}
		TEST_METHOD(ShowTablesShouldWorkProperlyWhenTableNotExist)
		{
			// Setup
			Tables t;
			std::stringstream ss;
			t.showTables(ss);
			std::string expected("No tables");
			std::string actual;
			std::string holder;
			ss >> holder;
			actual += holder;
			ss >> holder;
			actual += " ";
			actual += holder;
			Assert::AreEqual(expected, actual);
		}
	};
}

#include "MySQLRequestRow.h"

MySQLRequestRow::MySQLRequestRow(const MySQLRequestRow& row) 
	: m_Result(row.m_Result), m_MySQLRow(row.m_MySQLRow)
{
}

MySQLRequestRow::MySQLRequestRow()
	: m_Result(nullptr), m_MySQLRow(nullptr)
{
}

MySQLRequestRow::MySQLRequestRow(MySQLRequestRow&& moveItem)
{
	m_Result = moveItem.m_Result;
	m_MySQLRow = moveItem.m_MySQLRow;

	moveItem.m_Result = nullptr;
	moveItem.m_MySQLRow = nullptr;
}

MySQLRequestRow& MySQLRequestRow::operator=(MySQLRequestRow& moveItem)
{
	m_Result = moveItem.m_Result;
	m_MySQLRow = moveItem.m_MySQLRow;

	moveItem.m_Result = nullptr;
	moveItem.m_MySQLRow = nullptr;
}

MySQLRequestRow::MySQLRequestRow(MYSQL_RES *result)
	: m_Result(result),  m_MySQLRow(mysql_fetch_row(m_Result))
{
}

MySQLRequestRow& MySQLRequestRow::operator++()
{
	m_MySQLRow = mysql_fetch_row(m_Result);
	return *this;
}

MySQLRequestRow MySQLRequestRow::operator++(int) 
{
	MySQLRequestRow tmp(*this); 
	operator++(); 
	return tmp;
}

bool MySQLRequestRow::operator==(const MySQLRequestRow& rhs) 
{
	return m_MySQLRow == rhs.m_MySQLRow;
}

bool MySQLRequestRow::operator!=(const MySQLRequestRow& rhs) 
{
	return m_MySQLRow != rhs.m_MySQLRow;
}

char* MySQLRequestRow::operator[](int index)
{

	return m_MySQLRow[index];
}
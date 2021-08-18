// ReviewClasses.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
// TODO: Reference additional headers your program requires here.
struct Sales_data
{
	//constructor added 
	Sales_data() = default;
	Sales_data(const std::string &s):bookNo(s){}
	Sales_data(const std::string &s,unsigned n, double p):
		bookNo(s),unit_sold(n),revenue(p*n){}
	Sales_data(std::istream&);

	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price()const;
	std::string bookNo;
	unsigned unit_sold = 0.0;
	double revenue = 0.0;
};
//non member sales_data interface function 
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
void showImplementation();
void copyAndAssign();
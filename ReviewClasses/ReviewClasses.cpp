// ReviewClasses.cpp : Defines the entry point for the application.
//

#include "ReviewClasses.hpp"
int main()
{
	std::cout << "Hello classes" << std::endl;
	return 0;
}
double Sales_data::avg_price()const { //const member function 
	if (unit_sold) {
		return revenue / unit_sold;
	}
	else {
		return 0;
	}
}
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	unit_sold += rhs.unit_sold;
	revenue += rhs.revenue;
	return *this;
}
std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.unit_sold >> price;
	item.revenue = price * item.unit_sold;
	return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.unit_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs; //copy data member from lhs into sum 
	sum.combine(rhs);//add data members from rhs into sum 
	return sum;
}

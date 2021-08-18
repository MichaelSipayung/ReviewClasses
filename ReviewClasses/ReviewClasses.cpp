// ReviewClasses.cpp : Defines the entry point for the application.
//

#include "ReviewClasses.hpp"
int main()
{
	std::cout << "Hello classes" << std::endl;
	//showImplementation();
	copyAndAssign();
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
void showImplementation() {
	Sales_data total;
	if (read(std::cin, total)) {
		Sales_data trans;
		while (read(std::cin,trans))
		{
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else {
		std::cerr << "No data  ?!" << std::endl;
	}
}
Sales_data::Sales_data(std::istream& is) {
	read(is, *this);//read will read the transaction from is into the this object 
}
void copyAndAssign() {
	Sales_data medanSales; //call default constructor
	Sales_data jakartaSales("ox-Math", 12, 98.90);
	//copy 
	medanSales = jakartaSales;
	std::cout << "copy assignment " << std::endl;
	std::cout << "isbn number\t: " << medanSales.isbn() << std::endl;
	std::cout << "Total reveneu\t:" << medanSales.revenue << std::endl;
	std::cout << "total unit \t: " << medanSales.unit_sold << std::endl;
}
//next line for access control

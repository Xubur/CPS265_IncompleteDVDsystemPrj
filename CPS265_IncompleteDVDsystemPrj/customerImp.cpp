#include <iostream>
#include <string>
#include "customer.h"

using namespace std;
 
//Code Goes Here ****************************
//Method implementations

CustomerType::CustomerType() {
	PersonType::setName("", "");
	custAcctNo = 0;
};
CustomerType::CustomerType(string first, string last, int acctNo) {
	PersonType::setName(first, last);
	custAcctNo = acctNo;
};

void CustomerType::print() {
	cout << custAcctNo << " " << PersonType::getFirstName() << " " << PersonType::getLastName << " Number of rentals: "
		<< getNoOfRentals << endl;
};

void CustomerType::setCustInfo(string first, string last, int acctNo) {
	PersonType::setName(first, last);
	custAcctNo = acctNo;
};

bool CustomerType::rentDVD(string name) {

};

bool CustomerType::returnDVD(string name) {

};

int CustomerType::getNoOfRentals() {
	return rentedDVDTree.treeNodeCount();
};

int CustomerType::getAcctNo() {
	return custAcctNo;
};

void CustomerType::printRentedDVD() {

};

bool CustomerType::operator==(const CustomerType& right) const {
	return(custAcctNo == right.custAcctNo);
}

bool CustomerType::operator!=(const CustomerType& right) const {
	return(custAcctNo != right.custAcctNo);
}

bool CustomerType::operator<=(const CustomerType& right) const {
	return(custAcctNo <= right.custAcctNo);
}

bool CustomerType::operator<(const CustomerType& right) const {
	return(custAcctNo < right.custAcctNo);
}

bool CustomerType::operator>=(const CustomerType& right) const {
	return(custAcctNo >= right.custAcctNo);
}

bool CustomerType::operator>(const CustomerType& right) const {
	return(custAcctNo > right.custAcctNo);
}



//*******************************************


ostream& operator<<(ostream& os,  CustomerType& cust)
{
	os << cust.custAcctNo << " " << cust.getFirstName()
	   << " " << cust.getLastName()
	   << " " << cust.rentedDVDTree.treeNodeCount() << endl;

	return os;
} 


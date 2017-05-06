#include <iostream>
#include <string>
#include "customerType.h"

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
	cout << custAcctNo << " " << PersonType::getFirstName() << " " << PersonType::getLastName() << " Number of rentals: "
		<< getNoOfRentals() << endl;
};

void CustomerType::setCustInfo(string first, string last, int acctNo) {
	PersonType::setName(first, last);
	custAcctNo = acctNo;
};

bool CustomerType::rentDvd(string name) {
	return rentedDvdTree.insert(name);
};

bool CustomerType::returnDvd(string name) {
	return rentedDvdTree.deleteNode(name);
};

int CustomerType::getNoOfRentals() {
	return rentedDvdTree.treeNodeCount();
};

int CustomerType::getAcctNo() {
	return custAcctNo;
};

void CustomerType::printRentedDvd() {
	rentedDvdTree.inorderTraversal();
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
	   << " " << cust.rentedDvdTree.treeNodeCount() << endl;

	return os;
} 


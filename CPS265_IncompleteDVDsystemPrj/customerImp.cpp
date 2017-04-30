#include <iostream>
#include <string>
#include "customer.h"

using namespace std;
 
//Code Goes Here ****************************
//Method implementations


//*******************************************


ostream& operator<<(ostream& os,  CustomerType& cust)
{
	os << cust.custAcctNo << " " << cust.getFirstName()
	   << " " << cust.getLastName()
	   << " " << cust.rentedDVDTree.treeNodeCount() << endl;

	return os;
} 


 
#ifndef H_customerListType
#define H_customerListType
 
#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "customer.h"

using namespace std;

class CustomerBTreeType:public BSearchTreeType<CustomerType>
{
public:
	bool custSearchId(int id) {          //improvement still needed
		nodeType<CustomerType> *location;
		bool found;

		found = searchCust(id, found, location);
		return found;

		}
	
	bool custReturnDVD(int id, string title) {


	   }
	bool custRentDVD(int id, string title);
	int  custGetNoOfRentals(int id);

	void rentedDVDsInfo();

private:
	bool searchCust(int id, bool& found,
		nodeType<CustomerType>* &current) {


	}

	void inorderRentedDVDInfo(nodeType<CustomerType>* p);
	// Function to do an inorder traversal and print
	// rented DVD information

};
 
#endif
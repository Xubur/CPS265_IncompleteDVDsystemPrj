 
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
		nodeType<CustomerType> *current;
		bool found = false;

		searchCust(id, found, current);
		return found;

		}
	
	bool custReturnDVD(int id, string title) {
		nodeType<CustomerType> *current;
		bool found = false;

		if (searchCust(id, found, current)) {
			current->info.returnDVD(title);
		}
		return found;

	   }
	bool custRentDVD(int id, string title) {
		nodeType<CustomerType> *current;
		bool found = false;

		if (searchCust(id, found, current)) {
			current->info.rentDVD(title);
		}
		return found;
	}
	int  custGetNoOfRentals(int id) {
		nodeType<CustomerType> *current;
		bool found = false;
		int rentals = 0;

		if (searchCust(id, found, current)) {
			
		}
	}

	void rentedDVDsInfo() {
	
	}

private:
	bool searchCust(int id, bool& found,
		nodeType<CustomerType>* &current) {
		nodeType<CustomerType> *current;
		bool found = false;

		if (root == nullptr)
			cout << "Cannot search an empty tree." << endl;
		else
		{
			current = root;

			while (current != nullptr && !found)
			{
				if (current->info.getAcctNo == id)
					found = true;
				else if (current->info.getAcctNo > id)
					current = current->lLink;
				else
					current = current->rLink;
			}//end while
		}//end else

		return found;

	}

	void inorderRentedDVDInfo(nodeType<CustomerType>* p) {
		// Function to do an inorder traversal and print
		// rented DVD information

	}


};
 
#endif
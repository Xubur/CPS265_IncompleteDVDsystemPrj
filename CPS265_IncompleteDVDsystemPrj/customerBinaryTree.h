
#ifndef H_customerListType
#define H_customerListType

#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "customerType.h"

using namespace std;

class CustomerBTreeType :public BinarySearchTree<CustomerType>
{
public:
	bool custSearchId(int id)
	{          //improvement still needed
		nodeType<CustomerType> *current;
		bool found = false;

		searchCust(id, found, current);
		if (!found)
			cout << "We couldn't find a customer with the id " << id << endl;
		return found;

	}

	bool custReturnDvd(int id, string title)
	{
		nodeType<CustomerType> *current;
		bool found = false;

		if (searchCust(id, found, current))
		{				// Validate Customer ID
			if (current->info.returnDvd(title))				// If returnDvd is successful (dvd exists and was returned)
			{
				return true;
			}
			else
			{
				cout << "Failed to return " << title << ". See the above message." << endl;
			}
		}
		return false;


	}
	bool custRentDvd(int id, string title)
	{
		nodeType<CustomerType> *current;
		bool found = false;

		if (searchCust(id, found, current))
		{
			if (current->info.rentDvd(title))
				return true;
			else
				cout << "Failed to rent dvd. See message above." << endl;
		}
		else
		{
			cout << "Customer ID not found." << endl;
		}
		return false;
	}
	int  custGetNoOfRentals(int id)
	{
		nodeType<CustomerType> *current;
		bool found = false;
		int rentals = 0;

		if (searchCust(id, found, current))
		{
			rentals = current->info.getNoOfRentals();
		} return rentals;
	}

	void rentedDvdsInfo(int id)
	{
		nodeType<CustomerType> *current;
		bool found = false;


		if (searchCust(id, found, current))
		{
			if (current->info.getNoOfRentals() > 0)
			{
				inorderRentedDvdInfo(current);
			}
			else
			{
				cout << "No current rentals." << endl;
			}
		}

	}

private:
	bool searchCust(int id, bool& found,
		nodeType<CustomerType>* &current)
	{
		nodeType<CustomerType> *indexNode;
		found = false;

		if (root == nullptr)
			cout << "Cannot search an empty tree." << endl;
		else
		{
			indexNode = root;

			while (indexNode != nullptr && !found)
			{
				if (indexNode->info.getAcctNo() == id)
				{
					found = true;
					current = indexNode;
				}
				else if (indexNode->info.getAcctNo() > id)
					indexNode = indexNode->lLink;
				else
					indexNode = indexNode->rLink;
			}//end while
		}//end else


		return found;
	}

	void inorderRentedDvdInfo(nodeType<CustomerType>* p)
	{
		// Function to do an inorder traversal and print
		// rented DVD information
		p->info.printRentedDvd();

	}


};

#endif
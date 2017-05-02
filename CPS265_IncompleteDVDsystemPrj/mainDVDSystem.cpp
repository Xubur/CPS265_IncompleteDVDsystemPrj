#include <iostream>
#include <fstream>
#include "DvdType.h"
#include "DVDBinaryTree.h"
#include "customer.h"
#include "customerBinaryTree.h"

using namespace std;

void createDVDList(ifstream& infile,
	DVDBinaryTree& dvdList);
void createCustomerList(ifstream& infile,
	CustomerBTreeType& custList);
void displayMenu();

int main()
{
	
	int choice;
	CustomerType cust;
	CustomerBTreeType custList;
	DVDBinaryTree dvdList;
	ifstream custinfile;
	ifstream dvdinfile;
	string dvdTitle;
	string dummy;
	int custID;
	
	displayMenu();
	cout << "Enter choice: ";
	cin >> choice;
	
	cout << endl;

	while (choice != 9)
	{
		cout << " Choice: " << choice << endl;
		switch (choice)
		{
		case 1:
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			break;
		case 2:
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			break;
		case 3:
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			break;
		case 4:
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			cout << "Enter customer id: " << endl;
			cin >> custID;
			getline(cin, dummy);

			break;
		default:
			cout << "Invalid selection." << endl;
		}

		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;
		
		cout << endl;
	}//end while

	return 0;
}



void displayMenu()
{
	cout << "Select one of the following:" << endl;
	cout << "1: To check whether the store carries a "
		<< "particular DVD." << endl;
	cout << "2: To check out a DVD." << endl;
	cout << "3: To check in a DVD." << endl;
	cout << "4: To check whether a particular DVD is "
		<< "in stock." << endl;
	cout << "5: To print only the titles of all the DVDs."
		<< endl;
	cout << "6: To print a list of all the DVDs." << endl;
	cout << "7: Print a list of customers." << endl;
	cout << "8: Print a list of DVDs rented by a customer." << endl;
	cout << "9: To exit" << endl;
}

void createCustomerList(ifstream& infile,
	CustomerBTreeType& custList) {

	string custFileName = "custDat.txt";
	string temp;
	int i = 0;

	while (!infile.eof()) {

		string lastname;
		string firstname;
		int accnum;

		getline(infile, temp);
		while (temp[i] != ' ') {
			firstname[i] = temp[i];
			i++;
		}
		i++;
		while (temp[i] != ' ') {
			lastname[i] = temp[i];
			i++;
		}
		i++;
		accnum = temp[i];

		CustomerType tempcust(firstname, lastname, accnum);
		custList.insert(tempcust);
	}
}




#include <iostream>
#include <fstream>
#include "dvdType.h"
#include "dvdBinaryTree.h"
#include "customerType.h"
#include "customerBinaryTree.h"

using namespace std;

void createDVDList(ifstream& infile,
	DvdBinaryTree& dvdList);
void createCustomerList(ifstream& infile,
	CustomerBTreeType& custList);
void displayMenu();

int main()
{
	
	int choice;
	CustomerType cust;
	CustomerBTreeType custList;
	DvdBinaryTree dvdList;
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
		case 1:   //check if the dvd is carried
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			if (dvdList.dvdSearch(dvdTitle)) {
				cout << "That DVD is carried." << endl;
			}
			else {
				cout << "That DVD is not carried." << endl;
			}
			break;
		case 2:   //check out a dvd
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			dvdList.dvdCheckOut(dvdTitle);
			break;
		case 3:    //check in a dvd
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			dvdList.dvdCheckIn(dvdTitle);
			break;
		case 4:    //check if the dvd is currently available
			cout << "Enter the title: ";
			getline(cin, dvdTitle);
			if (dvdList.isDvdAvailable(dvdTitle)) {
				cout << "That DVD is currently available." << endl;
			}
			else {
				cout << "That DVD is not currently available." << endl;
			}
			break;
		case 5:    //print only the titles of all dvds
			dvdList.inorderTraversal();
			
			break;
		case 6:   //print a list of all dvds
			
			break;
		case 7:  //print a list of customers
			custList.inorderTraversal();
			break;
		case 8:  //print a list of the dvds rented by a customer
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
	CustomerBTreeType& custList) {                      //unfinished

	string custFileName = "custDat.txt";
	string lastname;
	string firstname;
	int accnum;

	infile >> firstname >> lastname >> accnum;
	while (!infile.eof()) {


		CustomerType tempcust(firstname, lastname, accnum);
		custList.insert(tempcust);
		infile >> firstname >> lastname >> accnum;
	}
}

void createDVDList(ifstream& infile,
	DvdBinaryTree& dvdList) {                      //also unfinished
	string dvdFileName = "dvdDat.txt";
	string dummy;
	string title;
	string star1;
	string star2;
	string producer;
	string director;
	string productionCo;
	int stock;


	while (!infile.eof()) {
		getline(cin, title);
		getline(cin, star1);
		getline(cin, star2);
		getline(cin, producer);
		getline(cin, director);
		getline(cin, productionCo);
		infile >> stock;
		getline(cin, dummy);

		DvdType tempDVD(title, star1, star2, producer, director, productionCo, stock);
		dvdList.insert(tempDVD);
	}




}




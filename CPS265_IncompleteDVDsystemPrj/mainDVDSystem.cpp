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
	string custFileName = "custDat.txt";
	ifstream dvdinfile;
	string dvdFileName = "dvdDat.txt";
	string dvdTitle;
	string dummy;
	int custID;

	system("mode 650");

	custinfile.open(custFileName.c_str());
	if (custinfile.fail())
	{
		cout << "Unable to open the file: custDat.txt" << endl;
		exit(1);
	}

	dvdinfile.open(dvdFileName.c_str());
	if (dvdinfile.fail())
	{
		cout << "Unable to open the file: dvdDat.txt" << endl;
		exit(1);
	}

	createDVDList(dvdinfile, dvdList);
	createCustomerList(custinfile, custList);

	displayMenu();
	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;

	while (choice != 9)
	{
		switch (choice)
		{
		case 1:   //check if the dvd is carried -- Working
			system("cls");
			system("color 02");
			cout << R"(
  .-.                    ___                                                   
 /    \  .-.            (   )                                       .-.        
 | .`. ;( __)___ .-.  .-.| |    .---.   ___ .-. .-.   .--. ___  ___( __).--.   
 | |(___(''"(   )   \/   \ |   / .-, \ (   )   '   \ /    (   )(   (''"/    \  
 | |_    | | |  .-. |  .-. |  (__) ; |  |  .-.  .-. |  .-. | |  | | | |  .-. ; 
(   __)  | | | |  | | |  | |    .'`  |  | |  | |  | | |  | | |  | | | |  | | | 
 | |     | | | |  | | |  | |   / .'| |  | |  | |  | | |  | | |  | | | |  |/  | 
 | |     | | | |  | | |  | |  | /  | |  | |  | |  | | |  | | |  | | | |  ' _.' 
 | |     | | | |  | | '  | |  ; |  ; |  | |  | |  | | '  | ' '  ; ' | |  .'.-. 
 | |     | | | |  | ' `-'  /  ' `-'  |  | |  | |  | '  `-' /\ `' /  | '  `-' / 
(___)   (___(___)(___`.__,'   `.__.'_. (___)(___)(___`.__.'  '_.'  (___`.__.' 
)";
			cout << "Enter the title: " << endl;
			cin.ignore();
			getline(cin, dvdTitle);
			cout << "We got: " << dvdTitle << endl;
			if (dvdList.dvdSearch(dvdTitle))
			{
				cout << "That DVD is carried." << endl;
			}
			else
			{
				cout << "That DVD is not carried." << endl;
			}
			cout << endl;
			break;
		case 2:   //check out a dvd -- Working
			system("cls");
			system("color 09");
			cout << R"(
            ___                   ___                                    ___         
           (   )                 (   )                                  (   )        
      .--.  | | .-.  .--.   .--.  | |   ___                .--. ___  ___ | |_        
     /    \ | |/   \/    \ /    \ | |  (   )              /    (   )(   (   __)      
 .-.|  .-. ;|  .-. |  .-. |  .-. ;| |  ' /     .------.  |  .-. | |  | | | |    .-.  
(   |  |(___| |  | |  | | |  |(___| |,' /     (________) | |  | | |  | | | | __(   ) 
 `-'|  |    | |  | |  |/  |  |    | .  '.                | |  | | |  | | | |(   `-'  
 .-.|  | ___| |  | |  ' _.|  | ___| | `. \               | |  | | |  | | | | | |.-.  
(   |  '(   | |  | |  .'.-|  '(   | |   \ \              | '  | | |  ; ' | ' | (   ) 
 `-''  `-' || |  | '  `-' '  `-' || |    \ .             '  `-' ' `-'  / ' `-' ;`-'  
     `.__,'(___)(___`.__.' `.__,'(___ ) (___)             `.__.' '.__.'   `.__.    
)";
			cout << "Enter customer id: ";
			cin >> custID;
			if (custList.custSearchId(custID))
			{
				cout << "Enter the title: " << endl;
				cin.ignore();
				getline(cin, dvdTitle);
				if (dvdList.dvdSearch(dvdTitle))				/// if dvd exists
				{
					if (dvdList.isDvdAvailable(dvdTitle))		/// if dvd is available
					{
						if (custList.custRentDvd(custID, dvdTitle)) /// if adding the dvd was successful
						{
							dvdList.dvdCheckOut(dvdTitle);
							cout << endl;
						}
					}
					else
					{
						cout << "Sorry, you have already rented " << dvdTitle << "\n" << endl;
					}
				}
			}
			else
			{												///custID not found...
				cout << "Sorry, we couldn't find a customer with the id: " << custID << "\n" << endl;
			}
			break;
		case 3:    //check in a dvd -- Working
			system("cls");
			system("color 0D");
			cout << R"(

            ___                   ___                                      
           (   )                 (   )                    .-.              
      .--.  | | .-.  .--.   .--.  | |   ___              ( __)___ .-.      
     /    \ | |/   \/    \ /    \ | |  (   )             (''"(   )   \     
 .-.|  .-. ;|  .-. |  .-. |  .-. ;| |  ' /     .------.   | | |  .-. ..-.  
(   |  |(___| |  | |  | | |  |(___| |,' /     (________)  | | | |  | (   ) 
 `-'|  |    | |  | |  |/  |  |    | .  '.                 | | | |  | |`-'  
 .-.|  | ___| |  | |  ' _.|  | ___| | `. \                | | | |  | |.-.  
(   |  '(   | |  | |  .'.-|  '(   | |   \ \               | | | |  | (   ) 
 `-''  `-' || |  | '  `-' '  `-' || |    \ .              | | | |  | |`-'  
     `.__,'(___)(___`.__.' `.__,'(___ ) (___)            (___(___)(___)    
)";
			cout << "Enter customer id: ";
			cin >> custID;
			if (custList.custSearchId(custID))
			{
				cout << "Enter the title: " << endl;
				cin.ignore();
				getline(cin, dvdTitle);
				if (dvdList.dvdSearch(dvdTitle))
				{
					if (custList.custReturnDvd(custID, dvdTitle))
					{
						dvdList.dvdCheckIn(dvdTitle);
						cout << endl;
					}
					else
					{
						cout << "Sorry you have already returned " << dvdTitle << "\n" << endl;      /// Dvd not found in rented tree (already returned)
					}
				}
				else				/// Dvd doesn't exist in our list of dvds
				{
					cout << "Sorry we don't carry that dvd." << endl;
				}
			}
			else
			{ ///custID not found...
				cout << "Sorry, we couldn't find a customer with the id: " << custID << "\n" << endl;
			}
			break;
		case 4:    //check if the dvd is currently available -- Working
			system("cls");
			system("color 0A");
			cout << R"(
        ___                   ___                                    ___       ___        ___     ___              
       (   )                 (   )                               .-.(   )     (   )   .-.(   ).-.(   )             
  .--.  | | .-.  .--.   .--.  | |   ___     .---. ___  ___ .---.( __)| |  .---.| |.-.( __)| |( __)| |_   ___  ___  
 /    \ | |/   \/    \ /    \ | |  (   )   / .-, (   )(   / .-, (''")| | / .-, | /   (''")| |(''"(   __)(   )(   ) 
|  .-. ;|  .-. |  .-. |  .-. ;| |  ' /    (__) ; || |  | (__) ; || | | |(__) ; |  .-. | | | | | | | |    | |  | |  
|  |(___| |  | |  | | |  |(___| |,' /       .'`  || |  | | .'`  || | | |  .'`  | |  | | | | | | | | | ___| |  | |  
|  |    | |  | |  |/  |  |    | .  '.      / .'| || |  | |/ .'| || | | | / .'| | |  | | | | | | | | |(   | '  | |  
|  | ___| |  | |  ' _.|  | ___| | `. \    | /  | || |  | | /  | || | | || /  | | |  | | | | | | | | | | |'  `-' |  
|  '(   | |  | |  .'.-|  '(   | |   \ \   ; |  ; |' '  ; ; |  ; || | | |; |  ; | '  | | | | | | | | ' | | `.__. |  
'  `-' || |  | '  `-' '  `-' || |    \ .  ' `-'  | \ `' /' `-'  || | | |' `-'  ' `-' ;| | | | | | ' `-' ; ___ | |  
 `.__,'(___)(___`.__.' `.__,'(___ ) (___) `.__.'_.  '_.' `.__.'_(___(___`.__.'_.`.__.(___(___(___) `.__. (   )' |  
                                                                                                          ; `-' '  
                                                                                                           .__.' 
)";
			cout << "Enter the title: " << endl;
			cin.ignore();
			getline(cin, dvdTitle);
			if (dvdList.isDvdAvailable(dvdTitle))
			{
				cout << "That DVD is currently available." << endl;
			}
			cout << endl;
			break;
		case 5:    //print only the titles of all dvds -- Working
			system("cls");
			system("color 0d");
			cout << R"(
        ___ ___   ___        ___    ___                     
       (   (   ) (   )   .-.(   )  (   )                    
  .---. | | | |   | |_  ( __)| |_   | | .--.     .--.       
 / .-, \| | | |  (   __)(''"(   __) | |/    \  /  _  \      
(__) ; || | | |   | |    | | | |    | |  .-. ;. .' `. ;.-.  
  .'`  || | | |   | | ___| | | | ___| |  | | || '   | (   ) 
 / .'| || | | |   | |(   | | | |(   | |  |/  |_\_`.(___`-'  
| /  | || | | |   | | | || | | | | || |  ' _.(   ). '. .-.  
; |  ; || | | |   | ' | || | | ' | || |  .'.-.| |  `\ (   ) 
' `-'  || | | |   ' `-' ;| | ' `-' ;| '  `-' /; '._,' '`-'  
`.__.'_(___(___)   `.__.(___) `.__.(___`.__.'  '.___.'      
                                                          
)";
			dvdList.dvdPrintTitle();
			break;
		case 6:   //print a list of all dvds -- Working
			system("cls");
			system("color 0f");
			cout << R"(
        ___ ___       ___            ___              
       (   (   )     (   )          (   )             
  .---. | | | |    .-.| |___  ___ .-.| |   .--.       
 / .-, \| | | |   /   \ (   )(   /   \ | /  _  \      
(__) ; || | | |  |  .-. || |  | |  .-. |. .' `. ;.-.  
  .'`  || | | |  | |  | || |  | | |  | || '   | (   ) 
 / .'| || | | |  | |  | || |  | | |  | |_\_`.(___`-'  
| /  | || | | |  | |  | || |  | | |  | (   ). '. .-.  
; |  ; || | | |  | '  | |' '  ; | '  | || |  `\ (   ) 
' `-'  || | | |  ' `-'  / \ `' /' `-'  /; '._,' '`-'  
`.__.'_(___(___)  `.__,'   '_.'  `.__,'  '.___.'    
)";
			dvdList.inorderTraversal();
			break;
		case 7:  //print a list of customers -- Working
			system("cls");
			system("color 0c");
			cout << R"(
                                  ___                                                                     
                                 (   )                                                                    
  .--.     ___  ___      .--.     | |_       .--.    ___ .-. .-.     .--.    ___ .-.        .--.          
 /    \   (   )(   )   /  _  \   (   __)    /    \  (   )   '   \   /    \  (   )   \     /  _  \         
|  .-. ;   | |  | |   . .' `. ;   | |      |  .-. ;  |  .-.  .-. ; |  .-. ;  | ' .-. ;   . .' `. ;   .-.  
|  |(___)  | |  | |   | '   | |   | | ___  | |  | |  | |  | |  | | |  | | |  |  / (___)  | '   | |  (   ) 
|  |       | |  | |   _\_`.(___)  | |(   ) | |  | |  | |  | |  | | |  |/  |  | |         _\_`.(___)  `-'  
|  | ___   | |  | |  (   ). '.    | | | |  | |  | |  | |  | |  | | |  ' _.'  | |        (   ). '.    .-.  
|  '(   )  | |  ; '   | |  `\ |   | ' | |  | '  | |  | |  | |  | | |  .'.-.  | |         | |  `\ |  (   ) 
'  `-' |   ' `-'  /   ; '._,' '   ' `-' ;  '  `-' /  | |  | |  | | '  `-' /  | |         ; '._,' '   `-'  
 `.__,'     '.__.'     '.___.'     `.__.    `.__.'  (___)(___)(___) `.__.'  (___)         '.___.'         
                                                                                                         
)";
			custList.inorderTraversal();
			cout << endl;
			break;
		case 8:  //print a list of the dvds rented by a customer -- Working
			system("cls");
			system("color 06");
			cout << R"(
                                 ___                    ___         ___                  ___              
                                (   )                  (   )       (   )                (   )             
 ___ .-.      .--.    ___ .-.    | |_       .--.     .-.| |      .-.| |   ___  ___    .-.| |      .--.    
(   )   \    /    \  (   )   \  (   __)    /    \   /   \ |     /   \ |  (   )(   )  /   \ |    /  _  \   
 | ' .-. ;  |  .-. ;  |  .-. .   | |      |  .-. ; |  .-. |    |  .-. |   | |  | |  |  .-. |   . .' `. ;  
 |  / (___) |  | | |  | |  | |   | | ___  |  | | | | |  | |    | |  | |   | |  | |  | |  | |   | '   | |  
 | |        |  |/  |  | |  | |   | |(   ) |  |/  | | |  | |    | |  | |   | |  | |  | |  | |   _\_`.(___) 
 | |        |  ' _.'  | |  | |   | | | |  |  ' _.' | |  | |    | |  | |   | |  | |  | |  | |  (   ). '.   
 | |        |  .'.-.  | |  | |   | ' | |  |  .'.-. | '  | |    | '  | |   ' '  ; '  | '  | |   | |  `\ |  
 | |        '  `-' /  | |  | |   ' `-' ;  '  `-' / ' `-'  /    ' `-'  /    \ `' /   ' `-'  /   ; '._,' '  
(___)        `.__.'  (___)(___)   `.__.    `.__.'   `.__,'      `.__,'      '_.'     `.__,'     '.___.'   
                                                                                                        
)";
			cout << "Enter customer id: " << endl;
			cin >> custID;
			if (custList.custSearchId(custID))
			{
				custList.rentedDvdsInfo(custID);
			}
			else
			{
				cout << "Customer not found." << endl;
			}
			cout << endl;
			break;
		default:
			system("cls");
			system("color f4");
			cout << "\a" << R"(
 ________  ___   __    __   __   ________   __        ________  ______       ______   ______   _________  ________  ______   ___   __      
/_______/\/__/\ /__/\ /_/\ /_/\ /_______/\ /_/\      /_______/\/_____/\     /_____/\ /_____/\ /________/\/_______/\/_____/\ /__/\ /__/\    
\__.::._\/\::\_\\  \ \\:\ \\ \ \\::: _  \ \\:\ \     \__.::._\/\:::_ \ \    \:::_ \ \\:::_ \ \\__.::.__\/\__.::._\/\:::_ \ \\::\_\\  \ \   
   \::\ \  \:. `-\  \ \\:\ \\ \ \\::(_)  \ \\:\ \       \::\ \  \:\ \ \ \    \:\ \ \ \\:(_) \ \  \::\ \     \::\ \  \:\ \ \ \\:. `-\  \ \  
   _\::\ \__\:. _    \ \\:\_/.:\ \\:: __  \ \\:\ \____  _\::\ \__\:\ \ \ \    \:\ \ \ \\: ___\/   \::\ \    _\::\ \__\:\ \ \ \\:. _    \ \ 
  /__\::\__/\\. \`-\  \ \\ ..::/ / \:.\ \  \ \\:\/___/\/__\::\__/\\:\/.:| |    \:\_\ \ \\ \ \      \::\ \  /__\::\__/\\:\_\ \ \\. \`-\  \ \
  \________\/ \__\/ \__\/ \___/_(   \__\/\__\/ \_____\/\________\/ \____/_/     \_____\/ \_\/       \__\/  \________\/ \_____\/ \__\/ \__\/
                                                                                                                                           
)";
			cout << "Invalid selection." << endl;
			system("start chrome.exe http://www.nyan.cat/original");
			break;
		}
		system("pause");
		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;
	}//end while

	return 0;
}



void displayMenu()
{
	system("cls");
	system("color 0B");
	cout << R"(
     ___            ___                           ___           ___         ___  
    (   )          (   )                         (   )         (   )       (   ) 
  .-.| |___  ___ .-.| |   ___ .-.    .--. ___ .-. | |_    .---. | |   .--.  | |  
 /   \ (   )(   /   \ |  (   )   \  /    (   )   (   __) / .-, \| | /  _  \ | |  
|  .-. || |  | |  .-. |   | ' .-. ;|  .-. |  .-. .| |   (__) ; || |. .' `. ;| |  
| |  | || |  | | |  | |   |  / (___|  | | | |  | || | ___ .'`  || || '   | || |  
| |  | || |  | | |  | |   | |      |  |/  | |  | || |(   / .'| || |_\_`.(___| |  
| |  | || |  | | |  | |   | |      |  ' _.| |  | || | | | /  | || (   ). '. | |  
| '  | |' '  ; | '  | |   | |      |  .'.-| |  | || ' | ; |  ; || || |  `\ ||_|  
' `-'  / \ `' /' `-'  /   | |      '  `-' | |  | |' `-' ' `-'  || |; '._,' '.-.  
 `.__,'   '_.'  `.__,'   (___)      `.__.(___)(___)`.__.`.__.'_(___)'.___.'(   ) 
                                                                            '-' 
        )";
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
	CustomerBTreeType& custList)
{                      //Working


	string lastname;
	string firstname;
	int accnum;

	infile >> firstname >> lastname >> accnum;
	while (infile.peek() != EOF)
	{


		CustomerType tempcust(firstname, lastname, accnum);
		custList.insert(tempcust);
		infile >> firstname >> lastname >> accnum;
	}
	CustomerType tempcust(firstname, lastname, accnum);
	custList.insert(tempcust);
}

void createDVDList(ifstream& infile,
	DvdBinaryTree& dvdList)
{                      //Working

	string dummy;
	string title;
	string star1;
	string star2;
	string producer;
	string director;
	string productionCo;
	int stock;


	while (infile.peek() != EOF)
	{
		getline(infile, title);
		getline(infile, star1);
		getline(infile, star2);
		getline(infile, producer);
		getline(infile, director);
		getline(infile, productionCo);
		infile >> stock;
		getline(infile, dummy);

		DvdType tempDVD;
		tempDVD.setDvdInfo(title, star1, star2, producer, director, productionCo, stock);
		dvdList.insert(tempDVD);
	}




}




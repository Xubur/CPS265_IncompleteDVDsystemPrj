 //dvdBinaryTree.h
//***********************************************************
// class dvdBinaryTree
// This class extends the class BSearchTreeType to create
// a Dvd list. 
//***********************************************************

#ifndef H_DVDBinaryTree
#define H_DVDBinaryTree
 
#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "dvdType.h"

using namespace std;

class dvdBinaryTree:public BSearchTreeType<dvdType>
{
public:
    bool dvdSearch(string title);
      //Function to search the list to see whether a
      //particular title, specified by the parameter title,
      //is in the store.
      //Postcondition: Returns true if the title is found,
      //               and false otherwise.

    bool isDvdAvailable(string title);
      //Function to determine whether a copy of a particular 
      //DVD is in the store.
      //Postcondition: Returns true if at least one copy of 
      //               the DVD specified by title is in the 
      //               store,and false otherwise.

    void dvdCheckIn(string title);
      //Function to check in a DVD returned by a customer
      //Postcondition: copiesInStock is incremented by one.

    void dvdCheckOut(string title);
      //Function to check out a DVD, that is, rent a DVD.
      //Postcondition: copiesInStock is decremented by one.

    bool dvdCheckTitle(string title) const;
      //Function to determine whether a particular DVD is in
      //the store.
      //Postcondition: Returns true if the DVD’s title is
      //               the same as title, and false otherwise.

    void dvdUpdateInStock(string title, int num);
      //Function to update the number of copies of a DVD
      //by adding the value of the parameter num. The 
      //parameter title specifies the name of the DVD for
      //which the number of copies is to be updated.
      //Postcondition: copiesInStock = copiesInStock + num;

    void dvdSetCopiesInStock(string title, int num);
      //Function to reset the number of copies of a DVD.
      //The parameter title specifies the name of the DVD
      //for which the number of copies is to be reset, and 
      //the parameter num specifies the number of copies.
      //Postcondition: copiesInStock = num;

    void dvdPrintTitle() const;
      //Function to print the titles of all the DVDs in 
      //the store.

private:
    void searchDvdList(string title, bool& found,
                         nodeType<dvdType>* &current) const;
      //This function searches the DVD list for a 
      //particular DVD, specified by the parameter title. 
      //If the DVD is found, the parameter found is set to 
      //true, otherwise false; the parameter current points  
      //to the node containing the DVD.

    void inorderTitle(nodeType<dvdType> *p)  const;
      //This function prints the titles of all the DVDs
      //in stock. 
};

#endif
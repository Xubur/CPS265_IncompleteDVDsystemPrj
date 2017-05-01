#include <iostream>
#include <string>
#include "DvdType.h"

using namespace std;

DvdType::DvdType(
	string title = "",
	string star1 = "",
	string star2 = "",
	string producer = "",
	string director = "",
	string productionCo = "",
	int setInStock = 0)
{
	setDVDInfo(title, star1, star2, producer, director, productionCo, setInStock);
}

int DvdType::getNoOfCopiesInStock() const
{
	return copiesInStock;
}

void DvdType::setCopiesInStock(int numCopies)
{
	copiesInStock = numCopies;
}

void DvdType::checkOut()
{
	copiesInStock--;
}

void DvdType::checkIn()
{
	copiesInStock++;
}

void DvdType::printTitle() const
{
	cout << "Title: " << dvdTitle << endl;

}

bool DvdType::checkTitle(string check)
{
	return check == dvdTitle;
}

void DvdType::updateInStock(int updateNum)
{
	copiesInStock += updateNum;
}

string DvdType::getTitle() const
{
	return dvdTitle;
}

void DvdType::printInfo() const
{
	cout << endl;
	cout << "DVD Title: " << dvdTitle << endl;
	cout << "Stars: " << movieStar1 << " and " << movieStar2 << endl;
	cout << "Producer: " << movieProducer << endl;
	cout << "Director: " << movieDirector << endl;
	cout << "Production Company: " << movieProductionCo << endl;
	cout << "Copies in stock: " << copiesInStock << endl;
}
ostream& operator<< (ostream& osObject, const DvdType& dvd)
{
	osObject << endl;
	osObject << "DVD Title: " << dvd.dvdTitle << endl;
	osObject << "Stars: " << dvd.movieStar1 << " and "
		<< dvd.movieStar2 << endl;
	osObject << "Producer: " << dvd.movieProducer << endl;
	osObject << "Director: " << dvd.movieDirector << endl;
	osObject << "Production Company: "
		<< dvd.movieProductionCo << endl;
	osObject << "Copies in stock: " << dvd.copiesInStock
		<< endl;
	osObject << "_____________________________________"
		<< endl;

	return osObject;
}



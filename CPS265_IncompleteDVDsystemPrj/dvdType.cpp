#include <iostream>
#include <string>
#include "dvdType.h"

using namespace std;

dvdType::dvdType(string title, string star1,
	string star2, string producer,
	string director, string productionCo,
	int setInStock)
{
	setDvdInfo(title, star1, star2, producer, director, productionCo, setInStock);
}


int dvdType::getNoOfCopiesInStock() const
{
	return copiesInStock;
}

void dvdType::setCopiesInStock(int numCopies)
{
	copiesInStock = numCopies;
}

void dvdType::checkOut()
{
	copiesInStock--;
}

void dvdType::checkIn()
{
	copiesInStock++;
}

void dvdType::printTitle() const
{
	cout << "Title: " << dvdTitle << endl;

}

bool dvdType::checkTitle(string check)
{
	return check == dvdTitle;
}

void dvdType::updateInStock(int updateNum)
{
	copiesInStock += updateNum;
}

string dvdType::getTitle() const
{
	return dvdTitle;
}

void dvdType::printInfo() const
{
	cout << endl;
	cout << "DVD Title: " << dvdTitle << endl;
	cout << "Stars: " << movieStar1 << " and " << movieStar2 << endl;
	cout << "Producer: " << movieProducer << endl;
	cout << "Director: " << movieDirector << endl;
	cout << "Production Company: " << movieProductionCo << endl;
	cout << "Copies in stock: " << copiesInStock << endl;
}

bool dvdType::operator==(const dvdType& otherDvd) const
{
	if (otherDvd.getTitle() != getTitle())
		return false;
	if (otherDvd.movieStar1 != movieStar1)
		return false;
	if (otherDvd.movieStar2 != movieStar2)
		return false;
	if (otherDvd.movieProducer != movieProducer)
		return false;
	if (otherDvd.movieDirector != movieDirector)
		return false;
	if (otherDvd.movieProductionCo != movieProductionCo)
		return false;
	return true;
}

bool dvdType::operator!=(const dvdType& otherDvd) const
{
	if (otherDvd.getTitle() == getTitle())
		return false;
	if (otherDvd.movieStar1 == movieStar1)
		return false;
	if (otherDvd.movieStar2 == movieStar2)
		return false;
	if (otherDvd.movieProducer == movieProducer)
		return false;
	if (otherDvd.movieDirector == movieDirector)
		return false;
	if (otherDvd.movieProductionCo == movieProductionCo)
		return false;
	return true;
}

bool dvdType::operator<(const dvdType& otherDvd) const
{
	if (otherDvd.getTitle() > dvdTitle)
		return true;
	else
		return false;
}

bool dvdType::operator<=(const dvdType& otherDvd) const
{
	if (otherDvd.getTitle() >= dvdTitle)
		return true;
	else
		return false;
}

bool dvdType::operator>(const dvdType& otherDvd) const
{
	if (otherDvd.getTitle() < dvdTitle)
		return true;
	else
		return false;
}

bool dvdType::operator>=(const dvdType& otherDvd) const
{
	if (otherDvd.getTitle() <= dvdTitle)
		return true;
	else
		return false;
}

ostream& operator<< (ostream& osObject, const dvdType& dvd)
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



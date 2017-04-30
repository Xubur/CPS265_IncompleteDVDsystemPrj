#include <iostream>
#include <string>
#include "DvdType.h"

using namespace std;
 
//Code Goes Here ****************************
//Method implementations


//*******************************************

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



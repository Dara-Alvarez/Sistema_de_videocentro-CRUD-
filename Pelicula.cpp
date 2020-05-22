//
// Created by Dara on 21/05/2020.
//

# include  <iostream>
# include  <cstring>
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula() {

}

Pelicula::Pelicula(char title[100], char film_director[100], int year, char gnere[100], char producer[100], int minutes)
{
    strcpy(this->title,title);
    strcpy(this->film_director,film_director);
    this->year=year;
    strcpy(this->gnere,gnere);
    strcpy(this->producer,producer);
    this->minutes=minutes;
}

void Pelicula::toString()
{
    cout<<"Titulo: "<< this->title<<endl;
    cout<<"Director: "<< this->film_director<<endl;
    cout<<"Annio: "<<this->year<<endl;
    cout<<"Genero: "<< this->gnere<<endl;
    cout<<"Productora: "<< this->producer<<endl;
    cout<<"Minutos: "<< this->minutes<<endl;
}

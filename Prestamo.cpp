//
// Created by Dara on 21/05/2020.
//

#include <iostream>
# include  <cstring>
#include "Prestamo.h"

using namespace std;

Prestamo::Prestamo() {

}

Prestamo::Prestamo(int user, int movie, char date_loan[100])
{
    this->user=user;
    this->movie=movie;
    strcpy(this->date_loan,date_loan);
    this->status=1;//prestamo activo
}

int Prestamo::get_user() {
    return this->user;
}

int Prestamo::get_movie() {
    return this->movie;
}

int Prestamo::get_status() {
    return this->status;
}

void Prestamo::restore(char date_restore[100])
{
    strcpy(this->date_restore,date_restore);
    this->status=0;
}

void Prestamo::toString()
{
    cout<<"Fecha del prestamo:"<<this->date_loan<<endl;

    if(this->status==1)
    {
        cout<<"Estado del prestamo: Ocupado"<<endl;
    } else
    {
        cout<<"Estado del prestamo: Devuelto"<<endl;
        cout<<"Fecha de devolucion:"<< this->date_restore<<endl;
    }

}



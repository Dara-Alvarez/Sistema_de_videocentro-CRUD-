//
// Created by Dara on 21/05/2020.
//

# include  <iostream>
# include  <cstring>
#include "Usuario.h"

using namespace std;

Usuario::Usuario() {

}

Usuario::Usuario(char name[100], int age)
{
    strcpy(this->name,name);
    this->age=age;
}

void Usuario::toString()
{
    cout<<"Nombre: "<< this->name<<endl;
    cout<<"Edad: "<< this->age<<endl;
}



//
// Created by Dara on 21/05/2020.
//

#ifndef U6_T7_CLASS_SISTEMA_VIDEOCENTRO_PELICULA_H
#define U6_T7_CLASS_SISTEMA_VIDEOCENTRO_PELICULA_H


class Pelicula
{
private:
    char title[100];
    char film_director[100];
    int year;
    char gnere[100];
    char producer[100];
    int minutes;

public:
    Pelicula();
    Pelicula(char[100],char[100],int,char[100],char[100],int);

    void toString();


};


#endif //U6_T7_CLASS_SISTEMA_VIDEOCENTRO_PELICULA_H

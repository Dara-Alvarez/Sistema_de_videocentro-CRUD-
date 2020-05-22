//
// Created by Dara on 21/05/2020.
//

#ifndef U6_T7_CLASS_SISTEMA_VIDEOCENTRO_PRESTAMO_H
#define U6_T7_CLASS_SISTEMA_VIDEOCENTRO_PRESTAMO_H


class Prestamo
{
private:
    int user;
    int movie;
    char date_loan[100];
    char date_restore[100];
    int status=0; //prestamo inactivo

public:
    Prestamo();
    Prestamo(int,int,char[100]);

    int get_user();
    int get_movie();
    int get_status();

    void restore(char[]);

    void toString();

};


#endif //U6_T7_CLASS_SISTEMA_VIDEOCENTRO_PRESTAMO_H

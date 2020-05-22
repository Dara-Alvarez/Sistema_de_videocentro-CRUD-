//
// Created by Dara on 21/05/2020.
//

#ifndef U6_T7_CLASS_SISTEMA_VIDEOCENTRO_USUARIO_H
#define U6_T7_CLASS_SISTEMA_VIDEOCENTRO_USUARIO_H


class Usuario
{

private:
    char name[100];
    int age;

public:
    Usuario();
    Usuario(char[100],int);

    void toString();

};


#endif //U6_T7_CLASS_SISTEMA_VIDEOCENTRO_USUARIO_H

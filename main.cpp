#include <iostream>
# include  <cstring>
#include "Usuario.h"
#include "Pelicula.h"
#include "Prestamo.h"

using namespace std;

//opcion que controla los menus
int op=0;

//Contadores
int user_C=0;
int movie_C=0;
int loan_C=0;

char date_restore[100];

Usuario usuarios[10];
Pelicula peliculas[10];
Prestamo prestamos[100];


void menu()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"      M E N U  P R I N C I P A L      "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"                                      "<<endl;
    cout<<"      1.Administrar usuarios          "<<endl;
    cout<<"      2.Administrar peliculas         "<<endl;
    cout<<"      3.Administrar prestamos         "<<endl;
    cout<<"                                      "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>op;

    cout<<endl;
}

void menu_user()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"        Administrar usuarios          "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"            1.Registrar               "<<endl;
    cout<<"            2.Editar                  "<<endl;
    cout<<"            3.Consultar               "<<endl;
    cout<<"            4.Eliminar                "<<endl;
    cout<<"            5.Menu principal          "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>op;

    cout<<endl;
}

void menu_movie()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"         Administrar peliculas        "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"            1.Registrar               "<<endl;
    cout<<"            2.Editar                  "<<endl;
    cout<<"            3.Consultar               "<<endl;
    cout<<"            4.Eliminar                "<<endl;
    cout<<"            5.Menu principal          "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>op;

    cout<<endl;
}

void menu_loan()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"        Administrar prestamos         "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"         1.Realizar prestamo          "<<endl;
    cout<<"         2.Devolver pelicula          "<<endl;
    cout<<"         3.Consultar prestamo         "<<endl;
    cout<<"         4.Menu principal             "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>op;

    cout<<endl;
}

void all_movies(Pelicula pelicula[10],int movie_C)
{
    cout<<"--------------------------------------"<<endl;
    cout<<"             Peliculas                "<<endl;
    for (int i = 0; i < movie_C; ++i)
    {
        cout<<"Pelicula "<<i<<endl;
        peliculas[i].toString();
    }
    cout<<"--------------------------------------"<<endl;
}

Usuario register_user()
{
    char name[100];
    int age;

    cout<<"Nombre:"<<endl;
    cin>>name;
    cout<<"Edad:"<<endl;
    cin>>age;

    return Usuario(name,age);
}


Pelicula register_movie()
{
    char title[100];
    char film_director[100];
    int year;
    char gnere[100];
    char producer[100];
    int minutes;

    cout<<"Titulo:"<<endl;
    cin>>title;
    cout<<"Director:"<<endl;
    cin>>film_director;
    cout<<"Annio:"<<endl;
    cin>>year;
    cout<<"Genero:"<<endl;
    cin>>gnere;
    cout<<"Productora:"<<endl;
    cin>>producer;
    cout<<"Minutos:"<<endl;
    cin>>minutes;

    return Pelicula(title,film_director,year,gnere,producer,minutes);
}

Prestamo register_loan(int movie)
{
    int user;
    char date_loan[100];

    cout<<"Numero de usuario"<<endl;
    cin>>user;
    cout<<"Fecha de prestamo"<<endl;
    cin>>date_loan;

    return Prestamo(user,movie,date_loan);
}


int main()
{
    //Banderas
    bool flag=true;
    bool flag_user= true;
    bool flag_movie= true;
    bool flag_loan= true;
    bool temp=true;

    //Numero del arreglo
    int num=0;

    //Encabezado
    cout<<endl;
    cout<<"      V I D E O    C E N T R O       "<<endl;
    //Encabezado

    while (flag)
    {
        menu();

        flag_user= true;
        flag_movie= true;
        flag_loan= true;

        switch (op)
        {
            case 1:
                //Administrar usuario

                while(flag_user)
                {
                    menu_user();

                    switch (op)
                    {
                        case 1:
                            //Registrar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"          Registrar usuario           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            usuarios[user_C]=register_user();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Registro exitoso          "<<endl;
                            cout<<"--------------------------------------"<<endl;
                            cout<<"Numero de usuario:"<<user_C<<endl;

                            user_C++;

                            break;

                        case 2:
                            //Editar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"             Editar usuario           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de usuario:";
                            cin>>num;

                            cout<<"--------------------------------------"<<endl;
                            usuarios[num].toString();
                            cout<<"--------------------------------------"<<endl;
                            usuarios[num]=register_user();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"             Usuario editado          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 3:
                            //Consultar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"          Consultar usuario           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de usuario:";
                            cin>>num;

                            usuarios[num].toString();

                            cout<<"--------Informacion de prestamo-------"<<endl;

                            for(int i=0;i<loan_C;i++)
                            {
                                if(prestamos[i].get_user()==num)
                                {
                                    //Imprime detalles de la pelicula
                                    peliculas[prestamos[num].get_user()].toString();
                                    //Imprime detalles del prestamo
                                    prestamos[i].toString();
                                }
                            }

                            break;

                        case 4:
                            //Eliminar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Eliminar usuario          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de usuario:";
                            cin>>num;

                            //Validar que no se puedan eliminar usuarios que tengan prestamos
                            if(prestamos->get_status()==1 and prestamos->get_user()==num)
                            {
                                cout<<"No se puede eliminar el usuario"<<endl;
                                cout<<"Tiene una pelicula prestada"<<endl;
                            } else
                            {
                                usuarios[num]=Usuario();

                                cout<<"--------------------------------------"<<endl;
                                cout<<"           Usuario eliminado          "<<endl;
                                cout<<"--------------------------------------"<<endl;
                            }

                            break;

                        case 5:
                            //Menu principal
                            flag_user= false;
                            break;
                    }
                }
                break;


            case 2:
                //Administrar peliculas

                while(flag_movie)
                {
                    menu_movie();

                    switch (op)
                    {
                        case 1:
                            //Registrar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"          Registrar pelicula          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            peliculas[movie_C]=register_movie();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Registro exitoso          "<<endl;
                            cout<<"--------------------------------------"<<endl;
                            cout<<"Numero de la pelicula:"<<movie_C<<endl;

                            movie_C++;

                            break;

                        case 2:
                            //Editar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Editar pelicula           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de la pelicula:";
                            cin>>num;

                            cout<<"--------------------------------------"<<endl;
                            peliculas[num].toString();
                            cout<<"--------------------------------------"<<endl;
                            peliculas[num]=register_movie();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Pelicula editada          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 3:
                            //Consultar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"          Consultar pelicula          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de la pelicula:";
                            cin>>num;

                            peliculas[num].toString();

                            cout<<"--------Informacion de prestamo-------"<<endl;
                            for(int i=0;i<loan_C;i++)
                            {
                                if(prestamos[i].get_movie()==num)
                                {
                                    //imprime el detalle del usuario
                                    usuarios[prestamos[num].get_user()].toString();
                                    //imprime el detalle del prestamo
                                    prestamos[i].toString();
                                }
                            }

                            break;

                        case 4:
                            //Eliminar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"           Eliminar pelicula          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de la pelicula:";
                            cin>>num;

                            //Validar que no se puedan eliminar peliculas prestadas
                            if(prestamos->get_status()==1 and prestamos->get_movie()==num)
                            {
                                cout<<"La pelicula esta prestada"<<endl;
                                cout<<"No se puede eliminar"<<endl;

                            } else
                            {
                                peliculas[num]=Pelicula();

                                cout<<"--------------------------------------"<<endl;
                                cout<<"           Pelicula eliminada         "<<endl;
                                cout<<"--------------------------------------"<<endl;
                            }

                            break;

                        case 5:
                            //Menu principal
                            flag_movie= false;
                            break;
                    }
                }
                break;

            case 3:
                //Administrar prestamos

                while(flag_loan)
                {
                    menu_loan();

                    switch (op)
                    {
                        case 1:
                            //Realizar prestamo
                            cout<<"--------------------------------------"<<endl;
                            cout<<"                Prestamo              "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            all_movies(peliculas,movie_C);

                            cout<<"Numero de la pelicula:";
                            cin>>num;

                            temp= true;

                            for (int i = 0; i <loan_C ; ++i)
                            {
                                //Si entra al if la pelicula esta prestado
                                if(num==prestamos[i].get_movie() and prestamos[i].get_status()==1)
                                {
                                    temp=false;
                                }
                            }

                            if(temp==true) //si nunca entro al if la pelicula no esta prestado
                            {
                                prestamos[loan_C]=register_loan(num);

                                cout<<"--------------------------------------"<<endl;
                                cout<<"            Prestamo exitoso          "<<endl;
                                cout<<"--------------------------------------"<<endl;
                                cout<<"Numero de prestamo:"<<loan_C<<endl;

                                loan_C++;

                            } else{
                                cout<<"La pelicula ya esta prestado"<<endl;
                            }

                            break;

                        case 2:
                            //Devolucion
                            cout<<"--------------------------------------"<<endl;
                            cout<<"              Devolucion              "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de prestamo:";
                            cin>>num;

                            cout<<"--------------------------------------"<<endl;
                            peliculas[prestamos[num].get_movie()].toString();
                            cout<<"--------------------------------------"<<endl;

                            cout<<"--------------------------------------"<<endl;
                            prestamos[num].toString();
                            cout<<"--------------------------------------"<<endl;


                            if (prestamos[num].get_status()==1)
                            {
                                cout<<"Fecha de devolucion:"<<endl;
                                cin>>date_restore;

                                prestamos[num].restore(date_restore);

                                cout<<"--------------------------------------"<<endl;
                                cout<<"          Devolucion exitosa          "<<endl;
                                cout<<"--------------------------------------"<<endl;
                            } else
                            {
                                cout<<"El prestamo ha finalizado anteriormente"<<endl;
                            }

                            break;

                        case 3:
                            //Consultar prestamo
                            cout<<"--------------------------------------"<<endl;
                            cout<<"         Consultar prestamo           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de prestamo:";
                            cin>>num;

                            cout<<"--------------------------------------"<<endl;
                            usuarios[prestamos[num].get_user()].toString();
                            cout<<"--------------------------------------"<<endl;

                            cout<<"--------------------------------------"<<endl;
                            peliculas[prestamos[num].get_movie()].toString();
                            cout<<"--------------------------------------"<<endl;

                            cout<<"--------------------------------------"<<endl;
                            prestamos[num].toString();
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 4:
                            //Menu principal
                            flag_loan= false;
                            break;
                    }

                }

                break;

        }

    }
    return 0;
}

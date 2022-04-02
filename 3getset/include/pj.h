#ifndef PJ_H
#define PJ_H

/*
En este archivo siempre declararemos las funciones a utilizar
*/

#include <iostream>
using namespace std;

class PJ {
    string nombre;
    string tipo;
    float fuerza;
    int salud;

public:


    PJ();
    PJ(const string &nombre, const string &tipo, float fuerza, int salud);

    /*funcion set asigna informacion, recibira como parametro
    lo que deseamos asignarle a una variable
    */
    void setNombre(const string &v);

    /*
    Nuestras funciones seran definidas publicamente ya que tendremos que 
    acceder desde fuera
    */

    //funcion get lee informacion, por lo tanto no recibe parametros
    string getNombre();
    //<tipo de dato> get<Nombre de clase>();
};

#endif // PJ_H

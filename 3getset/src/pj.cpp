#include "pj.h"

/*
Dentro del archivo '.cpp' realizaremos la implementación 
de las funciones, codificaremos sus comportamientos
*/

/*
SET siempre recibirá <algo>
GET siempre retornará <algo>
*/

PJ::PJ()
{
    /*
    nombre = "-";
    tipo = "-";
    fuerza = 0.0;
    salud = 0;
    */
}

PJ::PJ(const string &nombre, const string &tipo, float fuerza, int salud)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->fuerza = fuerza;
    this->salud =salud;
}

void PJ::setNombre(const string &v)
{
    nombre = v;
}
//como solo obtiene, la funcion es void

string PJ::getNombre()
{
    return nombre;
}
//al regresar información, tendremos que especificar el tipo de dato

//Aqui realizaremos la asignacion de datos de las funciones con set


//la funcion get nos regresa una copia de la informacion que deseamos leer


/*PJ:~PJ()
{
    //dtor
}*/

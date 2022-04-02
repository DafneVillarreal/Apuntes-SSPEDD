#include <iostream>
#include "personaje.h"

using namespace std;

Personaje :: Personaje() //constructor de clase
//<clase a la que pertenece> :: <nombre del metodo/funcion>
{

}

Personaje :: Personaje (const string &nombre, const string &tipo, float fuerza, int salud)
{
    this ->nombre = nombre;
    this ->tipo = tipo;
    this ->fuerza = fuerza;
    this ->salud = salud;

/*
Forma 2 de hacer un constructor, usado por Echauri

nombre = "-";
tipo = "-";
fuerza = 0.0;
salud = 0;
*/
}
#include <iostream>
#include "lista_estatica.h"
#include "persona.h"

using namespace std;

/*
LISTA ESTATICA

clase que administrara lo que suceda con una coleccion de datos

sera hecha como plantilla, como un caso generico con todos los posibles
casos

T [capacity]        >> el tipo de dato T sera reemplazado por
persona [capacity]     el que se usara
char [capacity]


ListaEstatica <T> lista;            //clase plantilla
ListaEstatica <int> numeros;        //uso de clase plantilla

size_t  ||  entero sin signo, toda la memoria reservada para negativos
        ||  tambien sera usada en positivos, todos los valores son positivos


Para que se pueda usar como plantilla debemos realizar la definicion e
implentacion dentro de nuestro archivo <.h>, es una restriccion de
compilacion
*/

int main()
{
    //persona pe;

    ListaEstatica <int> numeros;
    //por omision quedo en 1000 elementos, indicados en <.h>

    ListaEstatica <char> letras (50);
    //lista con parametro de 50 espacios

    ListaEstatica <persona> pe;

    numeros.push_front(5);
    numeros.push_front (85);
    numeros.push_back (655);
    numeros.push_back (88787);
    numeros.insert (0, 58);
    numeros.insert (4, 84);


    cout <<"numeros.empty() : " <<numeros.empty () <<endl
         //observamos que valor retorna la funcion booleana
         <<"numeros.full() : " <<numeros.full() <<endl
         <<"numeros.size() : " <<numeros.size() <<endl
         <<"numeros.front() : " <<numeros.front() <<endl
         <<"numeros.back() : " <<numeros.back() <<endl <<endl;

    cout <<"pe.empty() : " <<pe.empty () <<endl
         <<"pe.full() : " <<pe.full() <<endl
         <<"pe.size() : " <<pe.size() <<endl <<endl;

    for (size_t i (0); i < numeros.size(); ++i)
    {
        cout << numeros[i] <<" ";
    }
    cout <<endl;



    return 0;
}

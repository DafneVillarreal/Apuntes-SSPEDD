#include <iostream>
#include "videojuego.h"

using namespace std;

/*
La sobrecarga de operadores es la capacidad de que los operadores
de un lenguaje de programacion modifiquen su comportamiento,
realizando funciones diferentes a las ya establecidas segun su
lenguaje de programacion

------------------------------------------------------------------
Operadores que podemos sobrecargar
------------------------------------------------------------------
+       -      *        /           %           ^
&       |      ~        !           .           =
<       >      <=       >=          ++          --
<<      >>      ==      !=          &&          ||
+=      -=     /=       %=          ^=          &=
|=      *=     <<=      >>=         []          ()
->      ->*    new      new[]       delete      delete[]
------------------------------------------------------------------

estructura de una funcion de sobrecarga

friend ostream& operator << (ostream &out, const personaje &p)
{ <comportamiento de sobrecarga>

    return out;
    }


friend istream& opertator >>(istream &in, personaje &p)
{ <comportamiento de sobrecarga>

    return in;
    }
-------------------------------------------------------------------
fiend <tipo de objeto a regresar>& operator <<( <clase base del operador> &out, const <informacion que vamos a extaer o usar> &v)
*/

/*COMPILAR TODOS LOS ARCHIVOS DESDE TERMINAL

g++ *.cpp -o main.exe

una vez generado el .exe, llamaremos al archivo para ejecutarlo

./main

*/

int main()
{
    videojuego vj;
    personaje p1;
    personaje p2;

    /*p.setNombre("Chimichurri");
    p.setTipo("Gato gordo");
    p.setFuerza(10.2);
    p.setSalud(100);*/

    //cin >>p1 >>p2;

    vj>> p1;
    vj <<p1;

    //vj.agregar(p1);
    //vj.agregar(p2);
    //vj.mostrar();
    //esta funcion esta llamando a la sobrecarga hecha en
    //el header personaje

    //cout << p;


    return 0;
}

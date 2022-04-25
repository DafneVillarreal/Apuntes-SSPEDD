#include <iostream>
#include "arreglo.h"

using namespace std;

/*
Los templates son plantillas que nos permiten una programacion
mas generica con cualquier tipo de dato
*/

int main()
{

    arreglo <int> arre;

    for (size_t i = 0; i< 10; i++)
        //<arre.size> nos indicara el tamaño del arreglo
        //para no checar ni mas ni menos datos
    {
        arre.insertar_final(i);
    }

    for (size_t i = 0; i< arre.size(); i++)
    {
        //imprime el primer arreglo de numeros
        cout <<arre[i] <<" ";
    }

    cout <<endl;

    arre.insertar(100, 2);

    for (size_t i = 0; i< arre.size(); i++)
    {
        //imprime los numeros despues de insertar el numero 100
        //en una posicion valida ya indicada, en este caso, <2>
        cout <<arre[i] <<" ";
    }

    /*
    Para que una posicion sea valida debe contener informacion ya escrita,
    de estar vacia sera considerada invalida
    */

    cout <<endl;

    arre.eliminar_inicio();
    for (size_t i = 0; i< arre.size(); i++)
    {
        cout <<arre[i] <<" ";
    }
    cout <<endl;

    arre.eliminar_final();
    for (size_t i = 0; i< arre.size(); i++)
    {
        cout <<arre[i] <<" ";
    }
    cout <<endl;

    //eliminamos la posicion 5, considerando que el conteo
    //comienza desde 0
    arre.eliminar(5);
    for (size_t i = 0; i< arre.size(); i++)
    {
        cout <<arre[i] <<" ";
    }
    cout <<endl;




    return 0;
}

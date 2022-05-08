#include <iostream>
#include "lsl.h"

using namespace std;

/*
Creamos un nodo para la lista, y la lista, la cual es una coleccion
de nodos, los cuales estan enlazados entre si

a diferencia de la lista estatica, ahora trabajamos con memoria
dinamica, iremos reservando memoria del heap en tiempo de ejecucion

se crearan nodos y se iran enlazando a los nodos que ya tenemos

como una secuencia de cosas enlazadas, unidas por un apuntador

Dentro del nodo tendremos el dato y el apuntador

    | NodeLSL                    |
    |                            |
    | data: T                    |
    | next: shared_ptr <NodeLSL> |

Los nodos entiendase como bloques, una seccion tendra loa datos
y otra seccion contara con un apuntador


    |           |   |
    |   data    | * |
    |           |   |

Las listas son colecciones de estos bloques, el apuntador del final
servira para unir con los siguientes bloques

en LSL, la memoria ya no es continua, podrian estar en cualquier
lugar de la memoria, por lo tanto necesitamos un apuntador para que
nuestros bloques de informacion se encuentren "ligados", sabremos que
son parte de la listas por los apuntadores, ellos nos diran cuales son
los siguientes elementos

   < shared_ptr <NodeLSL> >
"apuntador crudo" o apuntadores inteligentes, a partir de c++11
contamos con apuntadores inteligentes, los cuales nos quitan tareas
como liberar memoria, si una direccion de memoria no esta siendo
apuntada por algun apuntador, la liberara automaticamente

*/

int main()
{
    LSL <char> l;

        cout <<"empty (): " <<l.empty() <<endl
              <<"size (): " <<l.size() <<endl <<endl;

    l.push_front ('b');
    l.push_front ('a');
    l.push_back ('d');

    l.insert (2, 'c');

    //l.erase(2);

    //l.pop_back ();

    //l.clear();

    l.push_back ('c');
    //l.remove ('c');

    cout <<"empty (): " <<l.empty() <<endl
         <<"size (): " <<l.size() <<endl
         <<"front (): " <<l.front() <<endl
         <<"back (): " <<l.back() <<endl <<endl;

    for (size_t i (0); i <l.size(); ++i)
    {
        cout <<l[i] <<" ";
    }

return 0;
}

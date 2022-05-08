#ifndef LSL_H
#define LSL_H
#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

/*
operador ' -> ' funciona para acceder a atributos a traves de
punteros

ejemplo:
    (*nd).A = 10;
          ==
    nd -> A = 10;
*/

template <typename T>
class LSL
{
    private:
        struct NodeLSL //nodo y apuntador
        {
            T data;
            shared_ptr<NodeLSL> next;

            NodeLSL (const T &elem, shared_ptr <NodeLSL> n = nullptr) : data (elem), next (n)
            //Nombre apuntador (paso de informacion, definicion de apuntador, tipo de dato del apuntador, identificador de este e inicializacion
            {
                //ya fue inicializado en la declaracion de funcion
            }
            //constructor del nodo
            //por omision, el segundo valor lo toma como null
            //<elem> es el elemento que se agregara
            //<n> puntero al siguiente elemento
            //NodeLSL (33); Crea nodo con el valor 33 y el siguiente elemento apunta a null
            //NodeLSL (33, nextNode); Nuevo nodo con valor 33 y apunta al siguiente nodo
        };

        size_t list_size;
        shared_ptr<NodeLSL> list_front;
        shared_ptr<NodeLSL> list_back;

    public:
        LSL ()
        {
            list_size = 0;
            list_front = nullptr;
            list_back = nullptr;
        }

        virtual ~LSL()
        {
            clear ();
            /*
            Para eliminar la lista la solucion mas facil
            es llamar a la funcion clear
            */
        }

        bool empty () const;
        size_t size () const;
        void push_front (const T &element);
        void push_back (const T &element);
        const T& front () const;
        const T& back () const;
        void pop_front ();
        void pop_back ();
        void insert (size_t position, const T &element);
        void erase (size_t position);
        void clear ();
        void remove (const T &element);
        T& operator [] (size_t position);
};

template <typename T>
bool  LSL <T> ::empty () const
{
    return list_size == 0;
}

template <typename T>
size_t LSL <T> ::size () const
{
    return list_size;
}

template <typename T>
void LSL <T> ::push_front (const T &element)
{
/*
Si en una lista vacia creamos un nodo, ese primer nodo sera
el primero y el ultimo de la lista

< list_front > apunta al frente de la lista

< list_back > apunta al final de la lista
*/
    if (empty())
    {
        list_front = make_shared <NodeLSL> (element); //construir apuntador
        list_back = list_front;                       //inteligente

    }
    else
    {
        shared_ptr <NodeLSL> temp = make_shared <NodeLSL> (element, list_front);
        list_front = temp;
    }
    ++list_size;
}

template <typename T>
void LSL <T> :: push_back (const T &element)
{
    if (empty())
    {
        list_front = make_shared <NodeLSL> (element);
        list_back = list_front;
    }
    else
    {
        shared_ptr<NodeLSL> temp = make_shared <NodeLSL> (element);
        list_back -> next = temp;
        list_back = temp;
    }
    ++list_size;
}

template <typename T>
const T& LSL<T>::front () const
{
    if (empty())
    {
        throw runtime_error ("Error. No puedes obtener el frente de una lista vacia");
    }

    return list_front -> data;
}

template <typename T>
const T& LSL <T> :: back () const
{
    if (empty ())
    {
        throw runtime_error ("Error. No puedes obtener el final de una lista vacia");
    }

    return list_back -> data;
}

template <typename T>
void LSL <T> :: pop_front ()
{
    if (empty())
    {
        throw runtime_error ("No puedes eliminar elementos de una lista vacia");
    }
    //para un pop solo debemos desligar el nodo de la lista
    if (size () == 1)
    {
        list_front = nullptr;
        list_back = nullptr;
    }
    else
    {
        list_front = list_front -> next; //para no perder informacion
        /*
        en caso de haber mas de un elemento solo debemos
        desplazar el inicio de la lista al siguiente nodo
        al no tener apuntadores y estos ser inteligentes,
        automaticamente se librara ese espacio en memoria
        */
    }
    --list_size;

    /*
    Podria ser list_front -> next = nullptr;
    pero usaremos la re difinicion para no perder informacion

    El nodo que estaba al frente lo desplazamos hacia la < T >
    o < next >, es suficiente para lograr la eliminacion
    */
}

template <typename T>
void LSL <T> :: pop_back ()
{
/*

*/
    if (empty())
    {
        //lista vacia
        throw runtime_error ("No puedes eliminar elementos de una lista vacia");
    }

    if (size () == 1)
    {
        //1 elemento en la lista
        list_front = nullptr;
        list_back = nullptr;
    }

    else
    {
        /*
        mas de un elemento en la lista

        para eso debemos recorrer todos los elementos de la lista
        como estas listas no cuentan con apuntadores hacia atras,
        tendremos que recorrer hasta el penultimo, hacer que ese
        nodo apunte a la nada, reasignar el list_back y dejar que
        los apuntadores inteligentes liberen ese espacio en memoria

        recorremos hasta list_back -1 o != list_back;
        */

        shared_ptr <NodeLSL> temp = list_front;

        while (temp -> next != list_back)
        {
            temp = temp -> next;
        }
        temp -> next = nullptr;
        //el siguiente de temp apuntara a null
        list_back = temp;
        //re definimos el final a lo que se guardo en temp
    }
    --list_size;
}

template <typename T>
void LSL <T> ::insert (size_t position, const T &element)
{
//insertar en cualquier posicion

    if (empty() )
    {
        throw runtime_error ("Espacio no valido, la lista se encuentra vacia");
    }

    else if (position > size())
    {
        throw range_error ("Estas intentando insertar en una posicion invalida");
    }

    else if (position == 0)
    {
        push_front (element);
    }

    else if (position == size() )
    {
        push_back (element);
    }

    else
    {
        /*
        para agregar un nuevo nodo tenemos que recorrer el arreglo
        y detenernos uno antes para crear el nuevo nodo y ligarlo
        */

        shared_ptr <NodeLSL> temp = list_front;
        for (size_t i (0); i < position-1; ++i)
        {
            temp = temp -> next;
            //el nuevo nodo debe apuntar al siguiente Y
        }
    shared_ptr <NodeLSL> nuevo_nodo = make_shared <NodeLSL> (element, temp -> next);
    //creamos nuevo nodo con la informacion correspondiente
    temp -> next = nuevo_nodo;
    //apuntaremos al nuevo nodo y aumentamos el tam de la lista
    ++list_size;
    }
}

template <typename T>
void LSL <T> :: erase (size_t position)
{
/*
Para eliminar tenemos que recorrer la lista uno a uno hasta llegar a uno
antes y desenlazarlo para que automaticamente se liberen sus espacios en
memoria
*/
    if (empty() )
    {
        throw runtime_error ("No puedes eliminar elementos de una lista vacia");
    }

    if (position >= size())
    {
        throw range_error ("Intentas eliminar datos de una posicion no valida");
    }

    if (position == 0)
    {
        pop_front ();
    }

    else if (position == size() -1)
    {
        pop_back ();
    }

    else
    {
        shared_ptr <NodeLSL> temp = list_front;
        for (size_t i(0); i <position-1; ++i)
        {
            temp = temp ->next;
        }
        temp ->next = temp ->next ->next;

        /*
        el apuntador se saltara el nodo que queremos eliminar,
        por eso hacemos dos saltos "next"
        */
         --list_size;
    }
}

template <typename T>
void LSL <T>::clear()
{
    //para eliminar una lista, bastara con eliminar uno a uno
    //con pop front en un ciclo

    while (!empty())
    {
        pop_front();
    }
}

template <typename T>
void LSL <T> :: remove (const T &element)
{
    //eliminaremos todas las veces que aparezca un dato en
    //la lista

    if (empty())
    {
        throw runtime_error ("No puedes eliminar elementos de una lista vacia");
    }

    else
    {
        T data; //recibimos dato que queremos eliminar
        size_t i = 0;
        shared_ptr <NodeLSL> temp = list_front;

        while (temp != nullptr) //recorremos mientras no lleguemos al final de la lista
        {
            data = temp -> data;
            temp = temp -> next;
            if (element == data)
            {
                erase (i);
                --i;
                //tenemos que retroceder para que ningun
                //nodo quede sin revisar, se modificara la
                //posicion de cada uno al hacer eliminaciones
            }
            ++i;
        }
    }
}

template <typename T>
T& LSL <T> :: operator [] (size_t position)
{
    //sobrecarga de operadores para que nos permita acceder a
    //los elementos en la posicion [x], ya que las listas no
    //reconocen ese operador
    if (empty ())
    {
        throw runtime_error ("La lista se encuentra vacia");
    }
    else if (position >= size ())
    {
        throw range_error ("Intentas acceder a una posicion no valida");
    }

    //sobreviviendo a los posibles errores de la lista, creamos nuestro apuntador
    //temporar para recorrer nuestra lista
    shared_ptr <NodeLSL> temp = list_front;
    for (size_t i (0); i <position; ++i)
    {
        temp = temp -> next;
    }
    return temp -> data;
}

#endif // LSL_H

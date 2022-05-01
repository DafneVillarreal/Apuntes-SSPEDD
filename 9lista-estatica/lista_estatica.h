#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H
#include <iostream>
#include <stdexcept>    //nos permite tener excepciones
                        //indicando posibles errores, como posiciones
                        //no validas, evitando que el programa no truene

using namespace std;

    template <typename T>
  //plantilla <tipodato T>

class ListaEstatica
{
  private:
      static const size_t CAPACITY = 1000;
      //conjunto de datos de clase administradora para arreglo
      T elements [CAPACITY]; //la T se reemplaza en tiempo de ejecucion
      size_t index; //cantidad de elementos guardados, como un indice
                    //y posicion del siguiente elemento
      size_t containerSize; //cantidad de elementos con los que iniciara la lista, por ejemplo 100/1000

  public:
      ListaEstatica (size_t n = CAPACITY)
      {
          if (n > CAPACITY)
          {
              throw invalid_argument ("Has llegado a limite de elementos en esta lista");
              //lanzamos una excepcion para no tronar el programa
              //parte de la funcion stdexcept
              //<throw> <invalid_argument> <("mensaje de error");>
              //lanzar argumento_invalido ("mensaje");
              //terminara la ejecucion de nuestro programa
          }

          index = 0;
          containerSize = n;
      }

      bool empty () const; //constante para que no cambie el valor, regresa valor logico
      bool full () const;
      size_t size () const;
      void push_front (const T &element);
      void push_back (const T &element);
      const T &front () const;
      const T &back () const;
      void pop_front ();
      void pop_back ();
      void insert (size_t position, const T &element);
      void erase (size_t position);

      /*
      para acceder a elementos con corchetes debemos
      sobrecargar los operadores ya que la lista privada
      no lo reconoce
      */
      T& operator [] (size_t position);
      void clear();
      void remove (const T& v);
      //elimina todos los elementos que tengan el mismo valor
      //eliminar incurrencias de un valor especifico (?)
};

template <typename T>
bool ListaEstatica <T> :: empty() const  //nos dira si la lista esta vacia
{
    return index == 0; //retorna positivo si index es igual a 0
    //ya que solo regresara verdadero o falso
}

template <typename T>
bool ListaEstatica <T> :: full() const //checa si la lista esta llena
{
    return index == containerSize; //retorna si index es igual que el limite
    //container fue el limite especificado para la lista
}

template <typename T>
size_t ListaEstatica <T> :: size () const //tamaño de la lista, cuantos elementos lleva
{
   return index; //ya que index es nuestro contador, el nos dira el tamaño
                 //acutal de nuestra lista
}

template <typename T>
void ListaEstatica <T> :: push_front (const T &element)
{
    if (full())
    {
        throw runtime_error ("Lista llena, no podemos ingresar mas datos");
        //error en tiempo de ejecucion
    }

    for (size_t i (index); i > 0; i--)
        /*
        iniciamos en index, en el ultimo espacio vacio, comenzara
        copiando los elementos un lugar antes [i-1], si index esta en
        la posicion 4, comenzara copiando la informacion del elemento 3,
        y asi ira reduciendo su contador hasta llegar a la posicion 1, la
        cual obtendra la informacion del elemento 0, ya que este ha sido respaldado
        podemos proceder a sobreescribir informacion en su lugar
        */
    {
        elements [i] = elements [i-1];
    }

    elements [0] = element;
    ++index;
}

template <typename T>
void ListaEstatica <T> :: push_back (const T &element)
{
   if (full())
    {
        throw runtime_error ("Lista llena, no podemos ingresar mas datos");
    }

    elements [index] = element;
    ++index;
}

template <typename T>
const T &ListaEstatica <T>::front () const //regresa primer elemento de la lista
{
    if (empty())
    {
    throw runtime_error ("No hay elementos en la lista");
    }
    return elements [0];
}

template <typename T>
const T &ListaEstatica <T>::back () const //regresa ultimo elemento de la lista
{
     if (empty())
        {
        throw runtime_error ("No hay elementos en la lista");
        }
    return elements [index-1];
    //ya que index es el espacio vacio siguiente
}

template <typename T>
void ListaEstatica <T> :: pop_front() //eliminar al frente
{
    if (empty())
    {
        throw runtime_error ("vacio, no podemos eliminar nada");
    }

    for (size_t i (index); i > 0; i--)
    {
        elements[i] = elements [i-1];
    }

    --index;

    //movimos todos los elementos a la izquierda
}

template <typename T>
void ListaEstatica <T> :: pop_back()
{
    if (empty())
    {
        throw runtime_error ("vacio, no podemos eliminar nada");
    }

    --index;
}

template <typename T>
void ListaEstatica <T> ::insert (size_t position, const T &element)
{
    if (full())
    {
        throw runtime_error ("Lista llena, no podemos ingresar mas datos");
    }

    if (position > size())
    {
        throw runtime_error ("intentas ingresar en una posicion invalida");
    }

    if (position == size ())
    {
        push_back (element);
    }

    for (size_t i (index); i > position; --i)
    {
        elements [i] = elements [i-1];
    }
    elements [position] = element;

    //igual que un push_front pero en lugar de
    //empezar en 0, puede ser en cualquier posicion valida
    //indicada
}

template <typename T>
void ListaEstatica <T> :: erase (size_t position)
{
    if (empty())
    {
        throw runtime_error ("vacio, no podemos eliminar nada");
    }

    if (position >= size())
    {
       throw runtime_error ("estas intentando eliminar desde una posicion invalida");
    }

    if (position == size() -1)
    {
        pop_back();
    }

    else
    {
        for (size_t i (position); i < index; i++)
        {
            elements [i] = elements [i+1];
        }
        --index;
    }
}

template <typename T>
T& ListaEstatica <T> :: operator [] (size_t position)
//indicamos que re definiremos los operadores
{
    if (empty())
    {
        throw runtime_error ("intentas obtener informacion de una lista vacia");
    }

    if (position >= size())
    {
        throw runtime_error ("intentas obtener informacion de una posicion no valida");
    }

    return elements[position];
    //en caso de encontrar [], nos retornara el elemento
}

template <typename T>
void ListaEstatica <T> :: clear ()
{
        index = 0;
}

template <typename T>
void ListaEstatica <T> :: remove (const T &v)
{
    size_t i (0);

    if (empty())
    {
        throw runtime_error ("vacio, no podemos eliminar nada");
    }

    /*
    no se recomienda usar el ciclo for ya que al ir
    eliminando datos, puede haber problema con las declaraciones
    */

    while (i < size() )
    {
        if (elements [i] == v)
        {
            erase (i);
            --i;
            /*
            cada que borramos regresamos 1 para evaluar
            todos los espacios en memoria, es para volver a
            evaluar todos los espacios que han recibido cambios,
            evaluar la nueva informacion
            */

        }
        ++i;
    }
}

#endif // LISTA_ESTATICA_H

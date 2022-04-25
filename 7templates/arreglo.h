#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>

using namespace std;

template <class T>
//clase template con tipo de dato generico
class arreglo
{
    public:
        arreglo();
        virtual ~arreglo();
        //en memoria dinamica es importante el uso del destructor
        void insertar_final (const T &v);
        void insertar_inicio (const T &v);
        size_t size();
        size_t insertar (const T &v, size_t p);

        int operator [] (size_t p)
        {
           return arre [p];
        }

        void eliminar_final();
        void eliminar_inicio();
        void eliminar(size_t p);

    protected:

    private:
            T *arre;
            size_t tam;
            size_t cont;
            //tipo de dato sin signo (?)
            const static size_t MAX = 4;
            //solo podemos incializar variables en nuestro archivo .h
            //si estas son constantes y estaticas, no es buena practica poner
            //numeros en la declaracion de arreglo
            void expandir();
};

 template <class T>
    arreglo <T>::arreglo()
{
    arre = new T [MAX];
    cont = 0;
    tam = MAX;
};

template <class T>
arreglo <T>::~arreglo()
{
    delete [] arre;
};

template <class T>
void arreglo <T>::insertar_final (const T &v)
{
    if (cont==tam)
    {
        expandir ();
    }

    arre[cont] = v;
    cont++;
}

template <class T>
void arreglo <T>::insertar_inicio (const T &v)
{
    if (cont == tam )
    {
        expandir ();
    }

    for (size_t i =cont; i > 0; i--)
    {
        arre [i] = arre [i-1];
    }

    arre [0] = v;
    cont ++;
}

template <class T>
void arreglo <T>::expandir()
{
    T *nuevo = new T[tam+MAX];

    for (size_t i = 0; i < cont; i++)
    {
        nuevo [i] = arre [i];
    }

    delete [] arre;

    arre = nuevo;
    tam = tam + MAX;
}

template <class T>
size_t arreglo <T>:: insertar (const T &v, size_t p)
{
    if (p >= cont )
    {
        cout << "Posicion no valida" <<endl;
        //return;
    }
    if (cont == tam)
    {
        expandir ();
    }

    for (size_t i = cont; i > p; i-- )
    {
        arre [i] = arre [i-1];
    }

    arre [p] = v;
    cont ++;
}

template <class T>
void arreglo <T>::eliminar_final()
{
    if (cont == 0)
    {
        cout << "El arreglo esta vacio" <<endl;
        //return;
    }
    //como el contador es la ultima posicion vacia,
    //lo unico que haremos sera decrementar el contador al
    //ultimo espacio en memoria ocupado y sobreescribir la
    //informacion para que esta sea eliminada

    cont --;
    //decremento para sobreescribir
}

template <class T>
void arreglo <T>::eliminar_inicio()
{
    if (cont == 0)
    {
        cout << "El arreglo esta vacio" <<endl;
        //return;
    }

/*
En el caso del primer elemento, tampoco sera eliminado, solo
sera reescrito con la informacion, recorreremos todos los elementos
de la lista hacia la izquierda, "aplastando" al primero con el segundo
elemento del arreglo
*/

    if (cont == 0)
    {
        cout << "El arreglo esta vacio" <<endl;
        //return;
    }

    for (size_t i = 0; i < cont-1; i++)
    {
        arre[i] = arre[i+1];
    }

        cont --;
}

template <class T>
void arreglo <T>::eliminar(size_t p)
{
//Eliminacion en cualquier posicion valida

    if (cont == 0)
    {
        cout << "El arreglo esta vacio" <<endl;
        //return;
    }

    for (size_t i = p; i < cont-1; i++)
        //iniciamos en p, se ha mandado como parametro de
        //funcion para indicar que posicion eliminaremos
    {
        arre[i] = arre[i+1];
    }

        cont --;
}

template <class T>
size_t arreglo <T>::size()
{
    return cont;
}

#endif // ARREGLO_H

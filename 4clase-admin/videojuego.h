#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include "personaje.h"

/*
No fue necesario llamar <iostream> ni especificar las entradas y salidas std
ya que al llamar a <personaje.h> incluimos esas lineas de codigo
*/

class videojuego
{
    public:
        virtual ~videojuego();
        videojuego();
        void agregar(const personaje &v);
        //esta funcion es el "setter" de una clase
        //ingresar personajes
        void mostrar ();
        //hara el trabajo de un "getter"
        //"sacar" personajes

    protected:
        //no es común usar <protected>

    private:
        personaje arreglo [5];
        int cont; //no podemos inicializar varibales en los .h
        /*
        Otra opcion de contador es size_t, bueno para iterar en
        arreglos, es un entero sin signo, siempre comienza en 0.
        El limite de este tipo de dato depende de la arquitectura,
        32 o 64 bits
        */
};

#endif // VIDEOJUEGO_H

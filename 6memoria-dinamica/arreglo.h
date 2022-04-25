#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>

using namespace std;

class arreglo
{
    public:
        arreglo();
        virtual ~arreglo();
        //en memoria dinamica es importante el uso del destructor
        void insertar_final (int v);
        void insertar_inicio (int v);

        int operator [] (size_t p)
        {
           return arre [p];
        }

        size_t size();

    protected:

    private:
            int *arre;
            size_t tam;
            size_t cont;
            //tipo de dato sin signo (?)
            const static size_t MAX = 4;
            //solo podemos incializar variables en nuestro archivo .h
            //si estas son constantes y estaticas, no es buena practica poner
            //numeros en la declaracion de arreglo
            void expandir();
};

#endif // ARREGLO_H

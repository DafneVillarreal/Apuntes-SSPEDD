#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H


#include "personaje.h"


class videojuego
{
    public:
        videojuego();
        virtual ~videojuego();
        void agregar(const personaje &v);
        void mostrar ();

        friend videojuego& operator<<(videojuego &v, const personaje &p)
        {
            v.agregar(p);

            return v;
        }

    protected:

    private:
        personaje arreglo [5];
        int cont;
};

#endif // VIDEOJUEGO_H

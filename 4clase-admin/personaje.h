#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
using namespace std;

class personaje
{
    public:
        personaje();
        personaje(const string &nombre, const string &tipo, float fuerza, int salud);
        virtual ~personaje();
        void setNombre(const string &v);
        string getNombre ();
        void setTipo (const string &v);
        string getTipo ();
        void setFuerza(float v);
        float getFuerza ();
        void setSalud (int v);
        int getSalud ();

    protected:

    private:
        string nombre;
        string tipo;
        float fuerza;
        int salud;
};

#endif // PERSONAJE_H

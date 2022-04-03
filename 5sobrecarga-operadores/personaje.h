#ifndef PERSONAJE_H
#define PERSONAJE_H


#include <iostream>
#include <iomanip> //biblioteca para acomodar texto

using namespace std;

class personaje
{
    public:
        personaje();
        virtual ~personaje();
        void setNombre(const string &v);
        string getNombre ();
        void setTipo (const string &v);
        string getTipo ();
        void setFuerza(float v);
        float getFuerza ();
        void setSalud (int v);
        int getSalud ();

        /*
        La palabra 'friend' rompe el encapsulamiento de informacion,
        todos los objetos que se encuentren dentro de esta clase podran
        acceder a los atributos privados
        */

        friend ostream& operator <<(ostream &out, const personaje &p)
        {
            out <<left; //justificado
            out <<setw(16) <<p.nombre;
                //set width o ancho
            out <<setw(16) <<p.tipo;
                //espacio en caracteres de la palabra + espacios sobrantes
                //que son tomados como espacios en blanco
            out <<setw(8) <<p.fuerza;
            out <<setw(16) <<p.salud;

            return out;
        }

        // ostream: Output STREAM <-> Flujo de salida

        friend istream& operator >>(istream &in, personaje &p)
        {
            cout <<"Nombre: ";
            getline (cin, p.nombre);


            cout <<"Tipo: ";
            getline (cin, p.tipo);

            cout <<"Fuerza: ";
            cin >>p.fuerza;

            cout <<"Salud: ";
            cin >>p.salud;
            cin.ignore();

            return in;
        }
        // istream: Input STREAM <-> Flujo de entrada

    protected:

    private:
        string nombre;
        string tipo;
        float fuerza;
        int salud;
};

#endif // PERSONAJE_H

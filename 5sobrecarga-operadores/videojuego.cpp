#include "videojuego.h"

videojuego::videojuego()
{
    cont = 0;
}

void videojuego::agregar(const personaje &v) {
    if (cont < 5) {
        arreglo [cont] = v;
        cont ++;
    }
    else {
        cout << "El arreglo esta lleno" <<endl;
    }
}

void videojuego::mostrar() {

cout <<left
    <<setw(16) <<"Nombre"
    <<setw(16) <<"Tipo"
    <<setw(8) <<"Fuerza"
    <<setw(16) <<"Salud"
    <<endl <<endl;

    for (int i=0; i<cont; i++){
        personaje &p = arreglo [i];

        cout <<p;

        /*cout <<"Nombre: " <<p.getNombre() <<endl
            <<"Tipo: " <<p.getTipo() <<endl
            <<"Fuerza: " <<p.getFuerza() <<endl
            <<"Salud: " <<p.getSalud () <<endl;*/
    }
}


videojuego::~videojuego()
{
    //dtor
}

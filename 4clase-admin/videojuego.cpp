#include "videojuego.h"

videojuego::videojuego () {
    cont = 0;
    //aqui inicializamos el contador de personajes
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
    for (int i=0; i<cont; i++){
        personaje &p = arreglo [i];
        /*
        p tiene hace un paso por referencia y obtiene la informacion
        del arreglo
        */

        //cout << "Nombre: " <<arreglo[i].getNombre() <<endl;
        //impresion de datos sin el paso por referencia

        cout <<"Nombre: " <<p.getNombre() <<endl
            <<"Tipo: " <<p.getTipo() <<endl
            <<"Fuerza: " <<p.getFuerza() <<endl
            <<"Salud: " <<p.getSalud () <<endl;
    }
}


videojuego::~videojuego()
{
    //dtor
}

#include <iostream>
#include "videojuego.h"
/*
Podemos solo incluir <videojuego.h>, ya que en ese archivo
esta incluyendo a <personaje.h>, ahorraremos lineas de codigo
*/

using namespace std;

int main()
{
videojuego vj;
personaje p;

p.setNombre("Chimichurri");
p.setTipo("Gato gordo");
p.setFuerza(10.2);
p.setSalud(100);

vj.agregar(p); //clase administradora agregando al personaje ya declarado
vj.mostrar(); //imprime todos los personajes registrados

    return 0;
}

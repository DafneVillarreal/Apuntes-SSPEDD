#include <iostream>
#include "pj.h"

using namespace std;

/*
Para mandar y recibir parametros privados usaremos las funciones
get y set

gracias a funciones como el setter, no dependeremos del constrcutor, 
pudiendo modificar la informacion del objeto en cualquier momento
*/

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
NOTA IMPORTANTE:
NO es conveniente recibir datos por referencia a menos de que
estos vayan a ser modificados a lo largo de la ejecución
- - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

int main()
{
    PJ p02 = PJ();
    PJ p03 = PJ("daf", "rata", 20.1, 25);
    PJ p04; //llama a la funcion, sin necesidad de poner =PJ();
    p04.setNombre("llama");
    cout << p04.getNombre();

    return 0;
}

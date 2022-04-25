#include <iostream>
#include "arreglo.h"

using namespace std;


void modificar (int *a);
// &<variable> paso por referencia, estas no almacenan la
//direccion de memoria
// *<variable> puntero, variable que recibe una direccion de memoria

int main()
{
    int a = 12;

    cout <<a <<endl;
    //imprime el contenido de la variable

    cout <<&a <<endl <<endl;
    //&<variable> retorna un puntero con la direccion de memoria

    /*
    Un puntero es una variable que almacena la direccion de memoria
    solicitada, nos permite manipular la informacion directamente
    en su lugar de memoria
    */

    modificar(&a);
    //al mandar la funcion es necesario indicar la direccion de
    //memoria con &<variable> para que el apuntador sepa la direccion

    cout <<a <<endl;
    cout <<&a <<endl <<endl;

    /*
    RESERVA DE MEMORIA CON PUNTEROS
    */

    int *b = nullptr;
    //declaracion de puntero vacío que almacenara un entero,
    //un puntero nulo o direccion 0 es una direccion invalida,
    //lo almacena y bloquea el SO por cuestiones de seguridad

    b = new int[100];
    //ahora b esta reservando el espacio en memoria necesario para
    //almacenar 100 datos de tipo entero

    cout <<"b es un puntero, por lo tanto su contenido es: " <<b <<endl
    //puntero == variable que almacena direccion de memoria
    <<"mientras que *b es una direccion de memoria nueva, por lo tanto, nos imprime basura: " <<*b <<endl <<endl;

     delete [] b;
    //si reservamos memoria desde una funcion, es importante liberarla
    //ya que seguiremos ocupandola y nadie podra acceder a ella

    arreglo ar;
    ar.insertar_final(15);
    ar.insertar_final(5);
    ar.insertar_final(1);
    ar.insertar_final(20);
   // arreglo.insertar_final(4);

   for (size_t i = 0; i <ar.size(); i++)
   {
       cout <<ar[i] <<"  ";
   }

    return 0;
}

void modificar (int *a) {

/*
En este caso, queremos aumentar el contenido de la variable 'a'
generalmente lo definiriamos como
a = a + 1;
pero en la definicion de funcion hicimos que a sea un puntero,
o sea, una variable que almacena una direccion de memoria, entonces,
si realizamos el aumento de esa manera, solo modificaremos la
direccion de memoria y no el contenido de la variable

la manera correcta seria la siguiente
*/

*a = *a +1;

/*
Accedimos a la direccion de memoria y modificamos su contenido
*/
}

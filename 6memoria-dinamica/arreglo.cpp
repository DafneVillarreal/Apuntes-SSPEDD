#include "arreglo.h"

arreglo::arreglo()
{
    arre = new int [MAX];
    cont = 0;
    //posicion en la cual comenzaremos a insertar
    tam = MAX;
    //tamaño total del arreglo
}

arreglo::~arreglo()
{
    //liberamemos la memoria reservada
    delete [] arre;
}

void arreglo::expandir()
{
    int *nuevo = new int[tam+MAX];
    //crea un nuevo arreglo temporal e iremos copiando
    //los elementos del arreglo viejo al nuevo

    for (size_t i = 0; i < cont; i++)
        //solo se hara revision hasta contador ya que estara ubicado
        //en la ultima posicion del arreglo
    {
        nuevo [i] = arre [i];
    }
    //una vez que toda la informacion se ha copiado correctamente,
    //tenemos que liberar los espacios en memoria del viejo arreglo
    //y enlazar los nuevos como si fueran el arreglo original

    delete [] arre;
    arre = nuevo;
    //tanto arre como nuevo son punteros, asi que,
    //lo que se han copiado son las direcciones en memoria
    tam = tam + MAX;
}

void arreglo::insertar_final (int v)
{
//cuando el arreglo este lleno, este se expandira

    if (cont==tam)
    {
        expandir ();
    }

    arre[cont] = v;
    cont++;
}

void arreglo::insertar_inicio (int v)
{
    //mismo proceso de expansion
    //en este metodo siempre se insertara en el inicio del arreglo
    //(posicion 0), para eso, siempre tendremos que recorrer
    //todos los elementos hacia la derecha

    //la ventaja es que siempre seran almacenados de forma consecutiva

    if (cont == tam )
    {
        expandir ();
    }

    for (size_t i =cont; i > 0; i--)
    //como iniciamos desde el final e iremos en cuenta regresiva
    //haremos un for contrario a los habituales
    {
        arre [i] = arre [i-1];
    }

    arre [0] = v;
    cont ++;
}

size_t arreglo::size()
{
    return cont;
}

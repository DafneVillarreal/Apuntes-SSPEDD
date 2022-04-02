//clases en C++

#include <iostream>
using namespace std;

/*
Dentro de <nombre>.cpp tendremos la implementación de la clase
mientras que en <nombre>.h la definición de la clase
*/

/*
struct 
    {
        char nombre [20];
        char tipo[20];
        float fuerza;
        int salud;
    }personajes[5];
*/

    class Personaje { 
        string nombre;
        string tipo;        //los datos por default son privados
        float fuerza;
        int salud;
    /*
    El concepto de clase es similar a las estructuras, 
    pero implementaremos conceptos de POO, como la encapsulación 
    de datos y los arreglos de caracteres son definidos son 'string'
    */
        public: 
            Personaje (){};
            //constructor sin parámetros
            //para compilarlo y no haga nada solo pondremos las llaves
            Personaje (const string &nombre, const string &tipo, float fuerza, int salud);
            //constructor con parámetros

    /*
    A diferencia de una estructura contamos con las restricciones de 
    encapsulación, como <private>, <public> & <protected>
    */
    };

int main () {

    //Personaje pj1= Personaje();
    //Personaje pj2= Personaje("Fruti lupi", "zombie", 100.0, 500);


    return 0;
}
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
using namespace std;

class Personaje 
{
    string nombre;
    string tipo;
    float fuerza; 
    int salud;

public:
    Personaje();
    Personaje(const string &nombre, //se manda como referencia para no crear copias
              const string &tipo,   //constante para que la informacion no se modifique 
              float fuerza,
              int salud);
};


#endif
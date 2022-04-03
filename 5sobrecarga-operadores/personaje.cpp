#include "personaje.h"

personaje::personaje()
{
    nombre = "-";
    tipo = "-";
    fuerza = 0.0;
    salud = 0;
}

void personaje::setNombre(const string &v) {
    nombre = v;
}

string personaje::getNombre() {
    return nombre;
}

void personaje::setTipo(const string &v) {
    tipo = v;
}

string personaje::getTipo() {
    return tipo;
}

void personaje::setFuerza(float v) {
    fuerza = v;
}

float personaje::getFuerza() {
    return fuerza;
}

void personaje::setSalud (int v) {
    salud = v;
}

int personaje::getSalud() {
    return salud;
}

personaje::~personaje()
{
    //dtor
}

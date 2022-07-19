#include "barco.h"

Barco::Barco()
{

}

int Barco::getTamanio() const
{
    return tamanio;
}

void Barco::setTamanio(int newTamanio)
{
    tamanio = newTamanio;
}

char Barco::getOrientacion() const
{
    return orientacion;
}

void Barco::setOrientacion(char newOrientacion)
{
    orientacion = newOrientacion;
}

bool Barco::explotado()
{
    //true - false
}



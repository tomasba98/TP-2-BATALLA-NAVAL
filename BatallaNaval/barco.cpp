#include "barco.h"

Barco::Barco()
{

}

char Barco::getNum() const
{
    return num;
}

void Barco::setNum(char newNum)
{
    num = newNum;
}

int Barco::getY() const
{
    return Y;
}

void Barco::setY(int newY)
{
    Y = newY;
}



int Barco::getX() const
{
    return X;
}

void Barco::setX(int newX)
{
    X = newX;
}


int Barco::getVida() const
{
    return vida;
}

void Barco::setVida(int newVida)
{
    vida = newVida;
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
    if (vida=0){
        return true;
    }
    //true - false
}



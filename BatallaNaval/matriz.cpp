#include "matriz.h"

Matriz::Matriz()
{

}

int Matriz::getFilas() const
{
    return filas;
}

void Matriz::setFilas(int newFilas)
{
    filas = newFilas;
}

int Matriz::getColumnas() const
{
    return columnas;
}

void Matriz::setColumnas(int newColumnas)
{
    columnas = newColumnas;
}

void Matriz::crear_matriz()
{
        this->matriz= new int*[this->filas];

        for(int i=0;i<this->filas;i++){
           this->matriz[i]=new int[this->columnas];
        }
}



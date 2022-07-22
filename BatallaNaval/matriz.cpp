#include "matriz.h"
#include <iostream>

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
        for(int i=0;i<this->filas;i++){
            for(int j=0;j<this->columnas;j++){
                this->matriz[i][j]= 0;
            }

        }
}

void Matriz::mostrar_matriz()
{
    for(int i=0;i<this->filas;i++){
        for(int j=0;j<this->columnas;j++){
            std::cout<<this->matriz[i][j]<<" ";
        }std::cout<<std::endl;

    }
}

void Matriz::agregar_barco(Barco *barco)
{
    int tamanio = barco->getTamanio();
    char orientacion = barco->getOrientacion();
    int x = barco->getX();
    int y = barco->getY();

    switch(orientacion){
    case 'H':
        //posicion X HORIZONAL
            for (int i=0;i<tamanio;i++){
            this->matriz[y][i] = 1;
           };
        break;
    case 'V':
        //posicion X VERTICAL
            for (int i=0;i<tamanio;i++){
            this->matriz[i][x] = 1;
    };
        break;
    }



}



#ifndef MATRIZ_H
#define MATRIZ_H
#include "barco.h"

class Matriz
{
private:
    int **matriz;
    int filas = 5;
    int columnas = 5;
public:
    Matriz();
    int getFilas() const;
    void setFilas(int newFilas);
    int getColumnas() const;
    void setColumnas(int newColumnas);
    void crear_matriz();
    void mostrar_matriz();
    void agregar_barco(Barco *barco);
};

#endif // MATRIZ_H

#ifndef MATRIZ_H
#define MATRIZ_H
#include "barco.h"

class Matriz
{
private:
    char **matriz;
    int tamanioMatriz = 10;

public:
    Matriz();

    void crear_matriz();
    void mostrar_matriz();
    void agregar_barco(Barco *barco);
    int getTamanioMatriz() const;
    void setTamanioMatriz(int newTamanioMatriz);
};

#endif // MATRIZ_H

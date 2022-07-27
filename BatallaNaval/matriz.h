#ifndef MATRIZ_H
#define MATRIZ_H
#include "barco.h"
#include <vector>

class Matriz
{
private:
    char **matriz;
    int tamanioMatriz = 10;
    std::vector <Barco> cantBarcos;

public:
    Matriz();

    void crear_matriz();
    void mostrar_matriz();
    void agregar_barco(Barco *barco);
    int getTamanioMatriz() const;
    void setTamanioMatriz(int newTamanioMatriz);
    bool lugarDisponible(int, int, int, char);
    int disparar(int, int);
    void moverLancha();
};

#endif // MATRIZ_H

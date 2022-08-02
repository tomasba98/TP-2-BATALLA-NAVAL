#ifndef MATRIZ_H
#define MATRIZ_H
#include "barco.h"
//#include <vector>
#include "VectorDinamico.h"

class Matriz
{
private:
    char **matriz;
    int tamanioMatriz = 10;
    VectorDinamico <Barco> cantBarcos;
//    std::list <Barco> totalBarcos;

public:
    Matriz();

    void chequearVector();
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

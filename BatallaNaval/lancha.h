#ifndef LANCHA_H
#define LANCHA_H
#include "barco.h"
#include "matriz.h"

class Lancha : public Barco
{
public:
    Lancha();

    void moverse(Matriz &_tablero);
};

#endif // LANCHA_H

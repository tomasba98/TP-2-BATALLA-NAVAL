#ifndef MENU_H
#define MENU_H
#include "crucero.h"
#include "matriz.h"
#include "barco.h"
#include "portaaviones.h"
#include "destructor.h"
#include "lancha.h"
#include "submarino.h"
#include <stdlib.h>
#include <vector>


class Menu
{
private:
    bool gameOver;
    Matriz tablero1;    //user
    Matriz tablero2;    //ia
    Matriz tableroParaDisparar;    //user
    //Matriz tablero2ParaDisparar;    //ia
    std::vector <Barco*> Barcos;


public:
    Menu();
    void agregarAleatorios(Matriz &tb, Barco *barco);
    void agregarManual(Matriz &tb, Barco *barco);
    void dispararBot(Matriz &tb);
    void jugar();
    void crearBarcos(int );
    void copiarTableroParaDisparar(Matriz &,int , int );
    void cleanWindows();
};

#endif // MENU_H

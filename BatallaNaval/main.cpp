#include <iostream>
#include "crucero.h"
#include "matriz.h"
#include "barco.h"

using namespace std;

int main()
{

    //CREAR TABLERO
    Matriz tablero;

    tablero.crear_matriz();
    tablero.mostrar_matriz();

    //CREAR CRUCERO
    Barco *crucero1 = new Crucero;
    crucero1->setX(1);
    crucero1->setY(2);
    crucero1->setOrientacion('H');

    //cout<<crucero1->getTamanio();

    tablero.agregar_barco(crucero1);

    cout<<endl;
    tablero.mostrar_matriz();

    return 0;
}

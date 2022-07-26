#include <iostream>
#include "crucero.h"
#include "matriz.h"
#include "barco.h"
#include "portaaviones.h"
#include "destructor.h"

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
    crucero1->setOrientacion('V');

    //CREAR PORTAAVIONES
    Barco *portaaviones1 = new Portaaviones;
    portaaviones1->setX(5);
    portaaviones1->setY(2);
    portaaviones1->setOrientacion('H');

    //CREAR DESTRUCTOR
    Barco *destructor1 = new Destructor;
    destructor1->setX(6);
    destructor1->setY(6);
    destructor1->setOrientacion('H');


    tablero.agregar_barco(crucero1);
    tablero.agregar_barco(portaaviones1);
    tablero.agregar_barco(destructor1);

    cout<<endl;
    tablero.mostrar_matriz();



    return 0;
}

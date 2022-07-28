#include <iostream>
#include "crucero.h"
#include "matriz.h"
#include "barco.h"
#include "portaaviones.h"
#include "destructor.h"
#include "lancha.h"

using namespace std;

int main()
{

    //CREAR TABLERO
    Matriz tablero;

    tablero.crear_matriz();
    tablero.mostrar_matriz();


    //CREAR CRUCERO
    Barco *crucero1 = new Crucero;
    crucero1->setX(2);
    crucero1->setY(4);
    crucero1->setOrientacion('V');

    //CREAR PORTAAVIONES
    Barco *portaaviones1 = new Portaaviones;
    portaaviones1->setX(5);
    portaaviones1->setY(2);
    portaaviones1->setOrientacion('H');

    //CREAR DESTRUCTOR
    Barco *destructor1 = new Destructor;
    destructor1->setX(5);
    destructor1->setY(6);
    destructor1->setOrientacion('H');


    //CREAR LANCHA
    Barco *lancha1 = new Lancha;
    lancha1->setX(5);
    lancha1->setY(6);
    lancha1->setOrientacion('V');

    //CREAR LANCHA
    /*Barco *lancha2 = new Lancha;
    lancha1->setX(8);
    lancha1->setY(4);
    lancha1->setOrientacion('V');*/

    //AGREGAR BARCOS
    tablero.agregar_barco(crucero1);
    tablero.agregar_barco(portaaviones1);
    //tablero.agregar_barco(destructor1);
    tablero.agregar_barco(lancha1);
    //tablero.agregar_barco(lancha2);


    cout<<endl;
    tablero.mostrar_matriz();

    tablero.disparar(2,4);
    tablero.disparar(2,5);
    tablero.disparar(2,6);

    tablero.moverLancha();


    cout<<endl;
    tablero.mostrar_matriz();




    return 0;
}

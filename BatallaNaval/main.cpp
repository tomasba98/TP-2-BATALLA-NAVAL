#include <iostream>
#include "crucero.h"
#include "matriz.h"
#include "barco.h"
#include "portaaviones.h"
#include "destructor.h"
#include "lancha.h"
#include "submarino.h"
#include <cstdlib>

using namespace std;

void agregarAleatorios(Matriz &tb, Barco *barco);
void agregarManual(Matriz &tb, Barco *barco);

int main()
{
    srand(time(NULL));

   //CREAR TABLEROS
    Matriz tablero1;    //user
    Matriz tablero2;    //ia

    Matriz tablero1ParaDisparar;    //user
    Matriz tablero2ParaDisparar;    //ia

    //CREAR BARCOS
    Barco *crucero1 = new Crucero;
    Barco *portaaviones1 = new Portaaviones;
    Barco *destructor1 = new Destructor;
    Barco *lancha1 = new Lancha;
    Barco *submarino1 = new Submarino;

    char respuestaAleatorio;

    bool gameOver = false;

    while(!gameOver){
        tablero1.crear_matriz();
        tablero1.mostrar_matriz();

        cout<<endl;

        tablero2.crear_matriz();
        tablero2.mostrar_matriz();

        cout<<"Desea agregar aleatoriamente los barcos? (S/N): ";
        cin>>respuestaAleatorio;

        if(respuestaAleatorio == 'S' || respuestaAleatorio == 's'){
            agregarAleatorios(tablero1,crucero1);
            agregarAleatorios(tablero1,portaaviones1);
            agregarAleatorios(tablero1,destructor1);
            agregarAleatorios(tablero1,lancha1);
            agregarAleatorios(tablero1,submarino1);
        }else if(respuestaAleatorio == 'N' || respuestaAleatorio == 'n'){
            agregarManual(tablero1,crucero1);
            tablero1.mostrar_matriz();
            agregarManual(tablero1,portaaviones1);
            tablero1.mostrar_matriz();
            agregarManual(tablero1,destructor1);
            tablero1.mostrar_matriz();
            agregarManual(tablero1,lancha1);
            tablero1.mostrar_matriz();
            agregarManual(tablero1,submarino1);
        }

        cout<<endl;
        tablero1.mostrar_matriz();

        system("pause");
    }

    /*

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
    portaaviones1->setX(1);
    portaaviones1->setY(9);
    portaaviones1->setOrientacion('H');

    //CREAR DESTRUCTOR
    Barco *destructor1 = new Destructor;
    destructor1->setX(5);
    destructor1->setY(6);
    destructor1->setOrientacion('H');


    //CREAR LANCHA
    Barco *lancha1 = new Lancha;
    lancha1->setX(8);
    lancha1->setY(3);
    lancha1->setOrientacion('V');

    //CREAR LANCHA
    Barco *lancha2 = new Lancha;
    lancha1->setX(8);
    lancha1->setY(1);
    lancha1->setOrientacion('H');

    //CREAR SUBMARINO
    Barco *Submarino1 = new Submarino;
    Submarino1->setX(4);
    Submarino1->setY(2);
    Submarino1->setOrientacion('H');

    //AGREGAR BARCOS
    tablero.agregar_barco(crucero1);
    tablero.agregar_barco(portaaviones1);
    tablero.agregar_barco(destructor1);
    tablero.agregar_barco(lancha1);
    tablero.agregar_barco(lancha2);
    tablero.agregar_barco(Submarino1);


    cout<<endl;
    tablero.mostrar_matriz();


    */

    return 0;
}
void agregarAleatorios(Matriz &tb, Barco *barco){
   int i = 0;
   int cantBarcos = 5;
   char orientacionChar;

   int x = rand()%10+1;
   int y = rand()%10+1;
   int orientacion = rand()%1;

   if(orientacion == 0){
       orientacionChar = 'V';
   }else{
       orientacionChar = 'H';
   }

   while(!tb.lugarDisponible(x,y,barco->getTamanio(),orientacion)){
       x = rand()%10+1;
       y = rand()%10+1;
       orientacion = rand()%1;

       if(orientacion == 0){
           orientacionChar = 'V';
       }else {
           orientacionChar = 'H';
       }
   }

   barco->setX(x);
   barco->setY(y);
   barco->setOrientacion(orientacionChar);
   tb.agregar_barco(barco);
}
void agregarManual(Matriz &tb, Barco *barco){
    int x,y;
    char orientacion;
    cout<<"\nIngrese posiciones para el barco '"<<barco->getNombre()<<"' \nTamanio: "<<barco->getTamanio()<<endl;
    cout<<"posicion x: ";cin>>x;
    cout<<"posicion y: ";cin>>y;
    cout<<"orientacion H/V: ";cin>>orientacion;


    while(!tb.lugarDisponible(x,y,barco->getTamanio(),orientacion)){
        cout<<"\n\nNO SE PUEDE ESA POSICION"<<endl;
        cout<<"\nIngrese nuevas posiciones para el barco "<<barco->getNombre()<<" \nTamanio: "<<barco->getTamanio()<<endl;
        cout<<"posicion x: ";cin>>x;
        cout<<"posicion y: ";cin>>y;
        cout<<"orientacion H/V: ";cin>>orientacion;
    }
    barco->setX(x);
    barco->setY(y);
    barco->setOrientacion(orientacion);
    tb.agregar_barco(barco);
}

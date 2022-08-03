#include <iostream>
#include <cstdlib>

#include "matriz.h"

#include "crucero.h"
#include "barco.h"
#include "submarino.h"
#include "portaaviones.h"
#include "destructor.h"
#include "lancha.h"


using namespace std;

void agregarAleatorios(Matriz &tb, Barco* barco){
   int i = 0;
   int cantBarcos = 5;
   char orientacionChar;

   while(i < cantBarcos){
       int x = rand()%10+1;
       int y = rand()%10+1;
       int orientacion = rand()%1;

       if(orientacion == 0){
           orientacionChar = 'V';
       }else{
           orientacionChar = 'H';
       }

       if(tb.lugarDisponible(x, y, 3, orientacionChar)){
           barco->setX(x);
           barco->setY(y);
           barco->setOrientacion(orientacionChar);
            tb.agregar_barco(barco);
            i++;
       }

   }
}

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
    crucero1->setOrientacion('V');
    crucero1->setX(1);
    crucero1->setY(2);

//    Barco *destructor1 = new Destructor;

//    Barco *portaAviones1 = new Portaaviones;

//    Barco *submarino1 = new Submarino;

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
            agregarAleatorios(tablero1, crucero1);
//            agregarAleatorios(tablero1, destructor1);
//            agregarAleatorios(tablero1, portaAviones1);
//            agregarAleatorios(tablero1, submarino1);

             tablero1.mostrar_matriz();
        }else{
            cout<<"intente de nuevo";
        }



        system("pause");
    }

//    tablero1.crear_matriz();
//    tablero1.mostrar_matriz();


//    //CREAR CRUCERO
//    Barco *crucero1 = new Crucero;
//    crucero1->setX(2);
//    crucero1->setY(4);
//    crucero1->setOrientacion('V');

//    //CREAR PORTAAVIONES
//    Barco *portaaviones1 = new Portaaviones;
//    portaaviones1->setX(5);
//    portaaviones1->setY(2);
//    portaaviones1->setOrientacion('H');

//    //CREAR DESTRUCTOR
//    Barco *destructor1 = new Destructor;
//    destructor1->setX(5);
//    destructor1->setY(6);
//    destructor1->setOrientacion('H');


//    //CREAR LANCHA
//    Barco *lancha1 = new Lancha;
//    lancha1->setX(5);
//    lancha1->setY(6);
//    lancha1->setOrientacion('V');

//    //CREAR LANCHA
//    /*Barco *lancha2 = new Lancha;
//    lancha1->setX(8);
//    lancha1->setY(4);
//    lancha1->setOrientacion('V');*/

//    //AGREGAR BARCOS
//    tablero.agregar_barco(crucero1);
//    tablero.agregar_barco(portaaviones1);
//    //tablero.agregar_barco(destructor1);
//    tablero.agregar_barco(lancha1);
//    //tablero.agregar_barco(lancha2);


//    cout<<endl;
//    tablero.mostrar_matriz();

//    tablero.disparar(2,4);
//    tablero.disparar(2,5);
//    tablero.disparar(2,6);


//    tablero.moverLancha();


//    cout<<endl;
//    tablero.mostrar_matriz();
//    tablero.moverLancha();


//    cout<<endl;
//    tablero.mostrar_matriz();
//    tablero.moverLancha();


//    cout<<endl;
//    tablero.mostrar_matriz();
//    tablero.moverLancha();




    return 0;
}

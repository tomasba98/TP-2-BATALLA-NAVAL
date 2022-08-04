#include "menu.h"

using namespace std;

Menu::Menu()
{
    gameOver = false;
    tablero1.crear_matriz();
    tablero2.crear_matriz();
    tableroParaDisparar.crear_matriz();

}

void Menu::jugar()
{
    while(!gameOver){

        int cant;
        cout<<"Elija cantidad de Barcos: ";
        cin>>cant;
        this->crearBarcos(5);
        char respuestaAleatorio;

        cout<<"Desea agregar aleatoriamente los barcos? (S/N): ";
        cin>>respuestaAleatorio;


        Barco *crucero = new Crucero;
        Barco *portaaviones = new Portaaviones;
        Barco *destructor = new Destructor;
        Barco *lancha = new Lancha;
        Barco *submarino = new Submarino;

        if(respuestaAleatorio == 'S' || respuestaAleatorio == 's'){
           /* for(Barco *b : this->Barcos){
                agregarAleatorios(this->tablero1,b);
                agregarAleatorios(this->tablero2,b);
            }*/
            agregarAleatorios(this->tablero1,crucero);
            agregarAleatorios(this->tablero1,portaaviones);
            agregarAleatorios(this->tablero1,destructor);
            agregarAleatorios(this->tablero1,lancha);
            agregarAleatorios(this->tablero1,submarino);

            agregarAleatorios(this->tablero2,crucero);
            agregarAleatorios(this->tablero2,portaaviones);
            agregarAleatorios(this->tablero2,destructor);
            agregarAleatorios(this->tablero2,lancha);
            agregarAleatorios(this->tablero2,submarino);


        }else if(respuestaAleatorio == 'N' || respuestaAleatorio == 'n'){
           /* for(Barco b : this->Barcos){
                agregarManual(this->tablero1,b);
                agregarManual(this->tablero2,b);
            }*/
            agregarManual(this->tablero1,crucero);
            agregarManual(this->tablero1,portaaviones);
            agregarManual(this->tablero1,destructor);
            agregarManual(this->tablero1,lancha);
            agregarManual(this->tablero1,submarino);
        }

        while(tablero1.getNumBarcos()!=0 && tablero2.getNumBarcos()!=0){
            int x,y;
            cout<<"\nDISPARE"<<endl;
            cout<<"x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;

            this->tablero2.disparar(x,y);

            if(tablero2.matrizHit()){
                 this->tableroParaDisparar.modificarMatriz(x,y,'X');
            }else{
                this->tableroParaDisparar.modificarMatriz(x,y,'O');
            }
            this->dispararBot(this->tablero1);
            cout<<endl;
            cout<<"TABLERO DISPARAR"<<endl;
            this->tableroParaDisparar.mostrar_matriz();
            cout<<"TABLERO 1"<<endl;
            tablero1.mostrar_matriz();
            cout<<endl;
        }


        system("pause");
    }
}

void Menu::agregarAleatorios(Matriz &tb, Barco *barco)
{
    char orientacionChar;
    int x;
    int y;
    int orientacion;

    do{
        x = rand()%9+1;
        y = rand()%9+1;
        orientacion = rand()%2;

        if(orientacion == 1){
            orientacionChar = 'V';
        }else{
            orientacionChar = 'H';
        }

    }while(!tb.lugarDisponible(x,y,barco->getTamanio(),orientacionChar));

    barco->setX(x);
    barco->setY(y);
    barco->setOrientacion(orientacionChar);
    tb.agregar_barco(barco);

}

void Menu::agregarManual(Matriz &tb, Barco *barco)
{
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

void Menu::dispararBot(Matriz &tb)
{
    int x = rand()%9+1;
    int y = rand()%9+1;

    tb.disparar(x,y);

}

void Menu::crearBarcos(int cant)
{
    int tipo = 0;

    Barco *crucero = new Crucero;
    Barco *portaaviones = new Portaaviones;
    Barco *destructor = new Destructor;
    Barco *lancha = new Lancha;
    Barco *submarino = new Submarino;

    for(int i=0;i<cant;i++){
        //tipo = rand()% cant;
        tipo = i;
        switch(tipo){

        case 0:
            this->Barcos.push_back(*(crucero));
            break;
        case 1:
            this->Barcos.push_back(*(portaaviones));
            break;
        case 2:
            this->Barcos.push_back(*(destructor));
            break;
        case 3:
            this->Barcos.push_back(*(lancha));
            break;
        case 4:
            this->Barcos.push_back(*(submarino));
            break;
        }

    }
}

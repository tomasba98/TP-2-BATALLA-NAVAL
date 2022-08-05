#include "menu.h"
#include <iomanip>

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
        this->crearBarcos(cant);
        char respuestaAleatorio;

        cout<<"Desea agregar aleatoriamente los barcos? (S/N): ";
        cin>>respuestaAleatorio;


        if(respuestaAleatorio == 'S' || respuestaAleatorio == 's'){
            for(Barco *b : this->Barcos){
                agregarAleatorios(this->tablero1,b);
                agregarAleatorios(this->tablero2,b);
            }


        }else if(respuestaAleatorio == 'N' || respuestaAleatorio == 'n'){
            for(Barco *b : this->Barcos){
                agregarManual(this->tablero1,b);
                agregarManual(this->tablero2,b);
            }
        }

        while(tablero1.getNumBarcos()!=0 && tablero2.getNumBarcos()!=0){
            this->cleanWindows();
            cout<<"          MONITOR SHOTS"<<endl;
            this->tableroParaDisparar.mostrar_matriz();
            cout<<endl;
            cout<<"          TABLERO USER"<<endl;
            tablero1.mostrar_matriz();
            tablero1.mostrarFlota();
            cout<<endl;

            int x,y;
            cout<<"\nDISPARE"<<endl;
            cout<<"x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;

            this->tablero2.disparar(x,y);

            //            cout<<"          TABLERO 2"<<endl;
            //            tablero2.mostrar_matriz();
            //            tablero2.mostrarFlota();
            //            cout<<endl;

            this->copiarTableroParaDisparar(tablero2,x,y);


            cout<<endl<<"DISPARO IA:";
            this->dispararBot(this->tablero1);
            cout<<endl;
            cout<<"          MONITOR SHOTS"<<endl;
            this->tableroParaDisparar.mostrar_matriz();
            cout<<endl;
            cout<<"          TABLERO USER"<<endl;
            tablero1.mostrar_matriz();
            tablero1.mostrarFlota();
            cout<<endl;
        }

        if(tablero1.getNumBarcos()==0 && tablero2.getNumBarcos()==0){
            cout<<endl;
            cout<<"\nEMPATE!!\nLOS 2 SON MUY BUENOS!!!\n.";
        }

        if(tablero1.getNumBarcos()==0){
            cout<<endl;
            cout<<"\nGAME OVER!!\nGANO IA!!!\n.";
        }
        if(tablero2.getNumBarcos()==0){
            cout<<endl;
            cout<<"\nWIN!!\nGANASTE PAPA!!!\n.";
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
        tipo = rand()% cant;
        tipo = i;
        switch(tipo){

        case 0:
            this->Barcos.push_back(crucero);
            break;
        case 1:
            this->Barcos.push_back(portaaviones);
            break;
        case 2:
            this->Barcos.push_back(destructor);
            break;
        case 3:
            this->Barcos.push_back(lancha);
            break;
        case 4:
            this->Barcos.push_back(submarino);
            break;
        }

    }
}

void Menu::copiarTableroParaDisparar(Matriz &tb2,int x, int y)
{

//    for(int i=1;i<tb2.getTamanioMatriz();i++){
//        for(int j=1;i<tb2.getTamanioMatriz();j++){
//            this->tableroParaDisparar.modificarMatriz(x,y,'~');
//            if(tb2.getChar(i,j)=='X'){
//                this->tableroParaDisparar.modificarMatriz(x,y,'X');
//            }
//            if(tb2.getChar(i,j)=='O'){
//                this->tableroParaDisparar.modificarMatriz(x,y,'O');
//            }
//        }
//    }

    if(tablero2.matrizHit()){
        this->tableroParaDisparar.modificarMatriz(x,y,'X');
    }else{
        this->tableroParaDisparar.modificarMatriz(x,y,'O');
    }
}

void Menu::cleanWindows()
{
#ifdef _WIN32
    std::system("cls");
#elif __unix__
    std::system("clear");
#endif
}

#include "matriz.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include<time.h>

Matriz::Matriz()
{

}


int Matriz::getTamanioMatriz() const
{
    return tamanioMatriz;
}

void Matriz::setTamanioMatriz(int newTamanioMatriz)
{
    tamanioMatriz = newTamanioMatriz;
}

bool Matriz::lugarDisponible(int posX, int posY, int tamanio, char orientacion)
{
     bool disponibilidad = true;
     //int restoY = posY-(tamanio/2);
     //int restoX = posX-(tamanio/2);
     int tamanioMatr = this->getTamanioMatriz();



     switch(orientacion){
     case 'H':
         //posicion X HORIZONAL
             for (int i=0;i<tamanio;i++){
                 if((!((posX+i>0) && (posX+i<tamanioMatr))) || (matriz[posY][posX+i] != '~'))
                     disponibilidad = false;
            }
         break;
     case 'V':
         //posicion X VERTICAL
             for (int i=0;i<tamanio;i++){
                 if((matriz[posY+i][posX] != '~') || (!((posY+i>0) && (posY+i<tamanioMatr))))
                     disponibilidad = false;
              }
        break;
     }

     return disponibilidad;
}

int Matriz::disparar(int x, int y)
{

    if((x>0 && x<this->tamanioMatriz) && (y>0 && y<this->tamanioMatriz)){
        char caract = this->matriz[y][x];
        //int posVec = 0;
        switch(caract){
        case '~':
            this->matriz[y][x] = 'O';
            break;
        case '1':
            this->matriz[y][x] = 'X';
            for (Barco b : this->cantBarcos){
                    if(b.getNum()=='1'){
                        b.hit();
                        if(b.explotado()){
                            //this->cantBarcos.erase(b); ELIMINAR CRUCERO DEL VECTOR
                        }
                    }
            }

            break;
        case '3':
            this->matriz[y][x] = 'X';
            for (Barco b : this->cantBarcos){
                    if(b.getNum()=='3'){
                        b.hit();
                    }
            }

            break;
        case '4':
            this->matriz[y][x] = 'X';
            for (Barco b : this->cantBarcos){
                    if(b.getNum()=='4'){
                        b.hit();
                    }
            }

            break;
        case '5':
            this->matriz[y][x] = 'X';
            for (Barco b : this->cantBarcos){
                    if(b.getNum()=='5'){
                        b.hit();
                    }
            }

            break;
        case '7':
            this->matriz[y][x] = 'X';
            for (Barco b : this->cantBarcos){
                    if(b.getNum()=='7'){
                        b.hit();
                    }
            }

            break;
        }

    }
}

void Matriz::moverLancha()
{
    srand(time(NULL));

    bool sePudo = true;

    for (Barco b : this->cantBarcos){

        if(b.getTamanio()==1){

    while(sePudo){

            //int posMovimiento = rand()%(4);
            int posMovimiento = 2;

            switch(posMovimiento){
             case 0:
                //ARRIBA
                if(this->lugarDisponible(b.getX(), b.getY()-1, b.getTamanio(), 'V')){
                    this->matriz[b.getY()][b.getX()]= '~';
                    b.setY(b.getY()-1);
                    b.setOrientacion('V');
                    this->matriz[b.getY()][b.getX()]= '1';
                }
                sePudo = false;
                break;
            case 1:
                //ABAJO
                if(this->lugarDisponible(b.getX(), b.getY()+1, b.getTamanio(), 'V')){
                    this->matriz[b.getY()][b.getX()]= '~';
                    b.setY(b.getY()+1);
                    b.setOrientacion('V');
                    this->matriz[b.getY()][b.getX()]= '1';
                }
                sePudo = false;
               break;
            case 2:
                //IZQUIERDA
                if(this->lugarDisponible(b.getX()-1, b.getY(), b.getTamanio(), 'H')){
                    this->matriz[b.getY()][b.getX()]= '~';
                    b.setX(b.getX()-1);
                    b.setOrientacion('H');
                    this->matriz[b.getY()][b.getX()]= '1';
                }
                sePudo = false;
               break;
            case 3:
                //DERECHA
                if(this->lugarDisponible(b.getX()+1, b.getY(), b.getTamanio(), 'H')){
                    this->matriz[b.getY()][b.getX()]= '~';
                    b.setX(b.getX()+1);
                    b.setOrientacion('H');
                    this->matriz[b.getY()][b.getX()]= '1';
                }
                sePudo = false;
               break;
             }
           }
        }
    }
}




void Matriz::crear_matriz(){
        //CREAR MATRIZ
    this->matriz= new char*[this->tamanioMatriz];
    for(int i=0;i<this->tamanioMatriz;i++){
       this->matriz[i]=new char[this->tamanioMatriz];
    }

    //BORDES
    int A = 64;
    int num = 48;
    for(int i=0;i<this->tamanioMatriz;i++){
        //this->matriz[i][0]= A;    LETRAS
        this->matriz[i][0]= num;
        this->matriz[0][i]= num;
        A +=1;
        num+=1;
    }

    //RELLENAR " - "
    for(int i=1;i<this->tamanioMatriz;i++){
        for(int j=1;j<this->tamanioMatriz;j++){
            this->matriz[i][j]= '~';
        }

    }

}

void Matriz::mostrar_matriz()
{
    for(int i=0;i<this->tamanioMatriz;i++){
        for(int j=0;j<this->tamanioMatriz;j++){
            std::cout<<std::setw(3)<<this->matriz[i][j];
        }std::cout<<std::endl;

    }
}

void Matriz::agregar_barco(Barco *barco)
{
    //si no hay barcos en esa pos:-
    if(lugarDisponible(barco->getX(), barco->getY(), barco->getTamanio(), barco->getOrientacion())){
        int tamanio = barco->getTamanio();
        char orientacion = barco->getOrientacion();
        int x = barco->getX();
        int y = barco->getY();
        //int restoY = y-(tamanio/2);
        //int restoX = x-(tamanio/2);

        switch(orientacion){
        case 'H':
            //posicion X HORIZONAL
                for (int i=0;i<tamanio;i++){
                this->matriz[y][i+x] = barco->getNum();
               }
            break;
        case 'V':
            //posicion Y VERTICAL
                for (int i=0;i<tamanio;i++){
                this->matriz[i+y][x] = barco->getNum();
        }
            break;
        }


        this->cantBarcos.push_back(*(barco));


        //en el caso de que haya algun barco en es pos:
    }else{
        std::cout<<"\nEl barco no se pudo agregar porque hay otro barco en la misma pos"<<std::endl;
    }

}



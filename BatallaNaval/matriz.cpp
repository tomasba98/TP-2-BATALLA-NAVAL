#include "matriz.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>




Matriz::Matriz()
{
    this->numBarcos=0;
}

int Matriz::getNumBarcos() const
{
    return numBarcos;
}

void Matriz::setNumBarcos(int newNumBarcos)
{
    numBarcos = newNumBarcos;
}

bool Matriz::matrizHit()
{
    return this->hit;
}

void Matriz::modificarMatriz(int x, int y, char c)
{
    this->matriz[y][x]= c;
}
void Matriz::mostrarFlota()
{
    std::cout<<"\n   Barcos en flota: \n";
    for (Barco b : this->cantBarcos){
        std::cout<<std::setw(12)<<b.getNombre()<<"  -> "<<std::setw(7)<<"Life: "<<b.getVida()<<"/"<<b.getTamanio()<<std::endl;
    }
}


char Matriz::submarinoHit()
{
    return this->submarinoHitChar;
}



void Matriz::chequearVector()
{
    std::cout<<"\nBarcos en flota: \n";
    for (Barco b : this->cantBarcos){
        std::cout<<b.getNombre()<<std::endl;
    }
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
    int tamanioMatr = this->getTamanioMatriz();
    int tamanioX = posX+tamanio;
    int tamanioY = posY+tamanio;


    if(((posX>0) && (posX<tamanioMatr-1)) && ((posY>0) && (posY<tamanioMatr-1))){
        switch(orientacion){
        case 'H':
            if(tamanioX<tamanioMatr){
                if(matriz[posY][posX-1] == '~' && matriz[posY][tamanioX] == '~'){
                    for (int i=0;i<tamanio;i++){
                        if(matriz[posY][posX+i] != '~'){
                            return false;
                        }
                    }
                    for (int i=0;i<tamanio;i++){
                        if((matriz[posY-1][posX+i] != '~')||(matriz[posY+1][posX+i] != '~')){
                            return false;
                        }
                    }
                }else{
                    return false;
                }
                return true;
            }else{
                return false;
            }
            break;
        case 'V':
            if(tamanioY<tamanioMatr){
                if(matriz[posY-1][posX] == '~' && matriz[tamanioY][posX] == '~'){
                    for (int i=0;i<tamanio;i++){
                        if(matriz[posY+i][posX] != '~'){
                            return false;
                        }
                        for (int i=0;i<tamanio;i++){
                            if((matriz[posY+i][posX-1] != '~')||(matriz[posY+i][posX+1] != '~')){
                                return false;
                            }
                        }
                    }
                }else{
                    return false;
                }
                return true;
            }else{
                return false;
            }
            break;
        }
    }else{
        return false;
    }


}

int Matriz::disparar(int x, int y)
{

    if((x>0 && x<this->tamanioMatriz) && (y>0 && y<this->tamanioMatriz)){
        char caract = this->matriz[y][x];

        switch(caract){
        case '~':
            this->matriz[y][x] = 'O';
            this->hit = false;
            this->submarinoHitChar = 'K';
            std::cout<<"\nShot Agua!\n";
            break;
        case '1':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (Barco &b : this->cantBarcos){
                if(b.getNum()=='1'){
                    b.hit();
                    if(b.explotado()){
                        this->eliminarBarco(b);
                    }
                }
            }

            break;
        case '3':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (Barco &b : this->cantBarcos){
                if(b.getNum()=='3'){
                    b.hit();
                    if(b.explotado()){
                        this->eliminarBarco(b);
                    }
                }
            }

            break;
        case '4':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (Barco &b : this->cantBarcos){
                if(b.getNum()=='4'){
                    b.hit();
                    if(b.explotado()){
                        this->eliminarBarco(b);
                    }
                }
            }

            break;
        case '5':
            this->matriz[y][x] = 'X';
            this->hit = true;
            this->submarinoHitChar = 'K';
            for (Barco &b : this->cantBarcos){
                if(b.getNum()=='5'){
                    b.hit();
                    if(b.explotado()){
                        this->eliminarBarco(b);
                    }
                }
            }

            break;
        case '7':
            this->hit = true;
            for (Barco &b : this->cantBarcos){
                if(b.getNum()=='7'){
                    char orientacion = b.getOrientacion();
                    switch(orientacion){
                    case 'H':
                        if(this->matriz[y][x-1]=='7'&&this->matriz[y][x+1]=='7'){
                            this->submarinoHitChar = 'H';
                            b.setVida(0);
                            b.hit();
                            this->matriz[y][x]='X';
                            this->matriz[y][x-1]='X';
                            this->matriz[y][x+1]='X';
                            b.explotado();
                            this->eliminarBarco(b);
                        }else{
                            b.hit();
                            if(b.explotado()){
                                this->eliminarBarco(b);
                            }
                            this->matriz[y][x] = 'X';
                        }

                        break;
                    case 'V':
                        if(this->matriz[y-1][x]=='7'&&this->matriz[y+1][x]=='7'){
                            this->submarinoHitChar = 'V';
                            b.setVida(0);
                            b.hit();
                            this->matriz[y][x]='X';
                            this->matriz[y-1][x]='X';
                            this->matriz[y+1][x]='X';
                            b.explotado();
                            this->eliminarBarco(b);
                        }else{
                            b.hit();
                            if(b.explotado()){
                                this->eliminarBarco(b);
                            }
                            this->matriz[y][x] = 'X';
                        }

                        break;
                    }

                }

            }

            break;
        }

    }
    this->moverLancha();
}

bool Matriz::lugarLancha(int posX, int posY, int tamanio, char orientacion)
{

    int tamanioMatr = this->getTamanioMatriz();
    int tamanioX = posX+tamanio;
    int tamanioY = posY+tamanio;

    if(((posX>0) && (posX<tamanioMatr)) && ((posY>0) && (posY<tamanioMatr))){
        switch(orientacion){
        case 'H':
            if(tamanioX<=tamanioMatr){
                for (int i=0;i<tamanio;i++){
                    if((matriz[posY][posX+i] != '~')){
                        return false;
                    }
                }
            }else{
                return false;
            }

            return true;
            break;
        case 'V':
            if(tamanioY<=tamanioMatr){
                for (int i=0;i<tamanio;i++){
                    if((matriz[posY+i][posX] != '~')){
                        return false;
                    }
                }
            }else{
                return false;
            }
            return true;
            break;
        }
    }else{
        return false;
    }
}

void Matriz::moverLancha()
{
    bool sePudo = true;

    for (Barco &b : this->cantBarcos){

        if(b.getTamanio()==1){

            while(sePudo){

                int posMovimiento = rand()%(4);

                switch(posMovimiento){
                case 0:
                    //ARRIBA
                    if(this->lugarLancha(b.getX(), b.getY()-1, b.getTamanio(), 'V')){
                        this->matriz[b.getY()][b.getX()]= '~';
                        b.setY(b.getY()-1);
                        b.setOrientacion('V');
                        this->matriz[b.getY()][b.getX()]= '1';
                        sePudo = false;
                    }
                    break;
                case 1:
                    //ABAJO
                    if(this->lugarLancha(b.getX(), b.getY()+1, b.getTamanio(), 'V')){
                        this->matriz[b.getY()][b.getX()]= '~';
                        b.setY(b.getY()+1);
                        b.setOrientacion('V');
                        this->matriz[b.getY()][b.getX()]= '1';
                        sePudo = false;
                    }
                    break;
                case 2:
                    //IZQUIERDA
                    if(this->lugarLancha(b.getX()-1, b.getY(), b.getTamanio(), 'H')){
                        this->matriz[b.getY()][b.getX()]= '~';
                        b.setX(b.getX()-1);
                        b.setOrientacion('H');
                        this->matriz[b.getY()][b.getX()]= '1';
                        sePudo = false;
                    }
                    break;
                case 3:
                    //DERECHA
                    if(this->lugarLancha(b.getX()+1, b.getY(), b.getTamanio(), 'H')){
                        this->matriz[b.getY()][b.getX()]= '~';
                        b.setX(b.getX()+1);
                        b.setOrientacion('H');
                        this->matriz[b.getY()][b.getX()]= '1';
                        sePudo = false;
                    }
                    break;
                }
            }
        }
    }
}

void Matriz::eliminarBarco(Barco b)
{   std::vector <Barco> aux;

    for (Barco a : this->cantBarcos){
        if(a.getNum()!=b.getNum()){
            aux.push_back(a);
        }
    }
    this->cantBarcos = aux;
    this->numBarcos--;
}




void Matriz::crear_matriz(){
    //CREAR MATRIZ
    this->matriz= new char*[this->tamanioMatriz];
    for(int i=0;i<this->tamanioMatriz;i++){
        this->matriz[i]=new char[this->tamanioMatriz];
    }

    //BORDES
        int A = 64;
        char num = 48;
        char num2Ble = 48;

        for(int i=0;i<this->tamanioMatriz;i++){
//            this->matriz[i][0]= A;  LETRAS
//            A +=1;
            if(num > 57){
                this->matriz[0][i] = char(num2Ble);
                this->matriz[i][0] = char(num2Ble);
                this->matriz[0][10] = 'X';
                this->matriz[10][0] = 'X';
                num2Ble += 1;
            }else{
                this->matriz[i][0]= num;
                this->matriz[0][i]= num;

                num+=1;
            }
        }


    //RELLENAR " ~ "
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
    this->numBarcos++;
}



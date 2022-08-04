#ifndef MATRIZ_H
#define MATRIZ_H
#include "barco.h"
#include <vector>
#include <iostream>

class Matriz
{
private:
    char **matriz;
    int tamanioMatriz = 10;
    int numBarcos;
    std::vector <Barco> cantBarcos;
    bool hit;

public:
    Matriz();

    void chequearVector();
    void crear_matriz();
    void mostrar_matriz();
    void agregar_barco(Barco *barco);
    int getTamanioMatriz() const;
    void setTamanioMatriz(int newTamanioMatriz);
    bool lugarDisponible(int, int, int, char);
    int disparar(int, int);
    void moverLancha();
    void eliminarBarco(Barco b);
    int getNumBarcos() const;
    void setNumBarcos(int newNumBarcos);
    bool matrizHit();
    void modificarMatriz(int,int,char);

     /*friend char  operator[] (int num){
          assert(num>=0 && num<size);   //prueba si num est  en el rango
          return (ptr[num]);
    }

     friend std::ostream&  operator[] (std::ostream& os,Matriz& obj){
              this->obj[//prueba si num est  en el rango
           return (ptr[num]);
     }*/
};

#endif // MATRIZ_H

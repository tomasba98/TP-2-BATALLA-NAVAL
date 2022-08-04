#ifndef MAPA_H
#define MAPA_H
#include "matriz.h"

class Mapa
{
private:
    Matriz Tablero;
public:
    Mapa();


    //    posicion X HORIZONAL

    //              if(((posX>0) && (posX+tamanio<tamanioMatr)) && ((posY>0) && (posY+tamanio<tamanioMatr))){
    //                for (int i=0;i<tamanio;i++){
    //                    if((matriz[posY][posX+i] != '~')){
    //                        disponibilidad = false;
    //                        //return false;
    //                    }
    //                }
    //             }

        //posicion X

    //             for (int i=0;i<tamanio;i++){
    //                 if((!((posX+i>0) && (posX+i<tamanioMatr))) || (matriz[posY][posX+i] != '~'))
    //                     disponibilidad = false;
    //            }

        //posicion X VERTICAL

        //         if(((posY>0) && (posY+tamanio<tamanioMatr)) && ((posX>0) && (posX+tamanio<tamanioMatr))){
        //            for (int i=0;i<tamanio;i++){
        //                if((matriz[posY+i][posX] != '~')){
        //                    disponibilidad = false;
        //                    //return false;
        //                }
        //            }
        //         }
        //posicion X VERTICAL

    //             for (int i=0;i<tamanio;i++){
    //                 if((!((posY+i>0) && (posY+i<tamanioMatr))) || (matriz[posY+i][posX] != '~'))
    //                     disponibilidad = false;
    //              }
};

#endif // MAPA_H

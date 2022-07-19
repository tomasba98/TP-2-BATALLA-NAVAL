#ifndef BARCO_H
#define BARCO_H


class Barco
{
private:
    //int vida;
    int tamanio;
    char orientacion;

public:
    Barco();
    int getTamanio() const ;
    void setTamanio(int );
    char getOrientacion() const ;
    void setOrientacion(char) ;
    virtual bool explotado();
};

#endif // BARCO_H

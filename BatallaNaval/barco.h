#ifndef BARCO_H
#define BARCO_H


class Barco
{
private:
    char num;
    int tamanio;
    char orientacion;
    int vida;
    int X;
    int Y;

public:
    Barco();
    int getTamanio() const ;
    void setTamanio(int );
    char getOrientacion() const ;
    void setOrientacion(char) ;
    int getVida() const;
    void setVida(int newVidas);    
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    char getNum() const;
    void setNum(char newNum);

    virtual bool explotado();
};

#endif // BARCO_H

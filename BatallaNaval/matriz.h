#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
private:
    int **matriz;
    int filas;
    int columnas;
public:
    Matriz();
    int getFilas() const;
    void setFilas(int newFilas);
    int getColumnas() const;
    void setColumnas(int newColumnas);
    void crear_matriz();

};

#endif // MATRIZ_H

#include <iostream>
#include<time.h>
#include "menu.h"

int main()
{
    srand(time(NULL));

    Menu Juego;
    Juego.jugar();

    return 0;
}


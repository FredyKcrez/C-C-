#include "Punto.h"

int Punto::leerX() const
{
    return x;
}

int Punto::leerY() const
{
    return y;
}

void Punto::fijarX(int valorX)
{
     x = valorX;
}

void Punto::fijarY(int valorY)
{
     y = valorY;
}

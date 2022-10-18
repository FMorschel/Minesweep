#include "Offset.hpp"
#include <cstdlib>
#include <time.h>

Offset::Offset()
{
    x = 0;
    y = 0;
}

Offset::Offset(int x, int y)
{
    this->x = x;
    this->y = y;
}

Offset::Offset(bool aleatorio)
{
    if (aleatorio)
    {
        srand(time(NULL));
        x = rand() % 10;
        y = rand() % 10;
    } else {
        x = 0;
        y = 0;
    }
}

int Offset::getX()
{
    return x;
}

int Offset::getY()
{
    return y;
}

bool Offset::estaDentro(Offset offset, Offset referencia)
{
    bool xValido = entre(x, referencia.getX(), referencia.getX() + offset.getX());
    if (!xValido) return false;
    bool yValido = entre(y, referencia.getY(), referencia.getY() + offset.getY());
    return xValido && yValido;
}

bool Offset::operator >(Offset offset)
{
    return (x > offset.x && y > offset.y);
}

bool Offset::operator <(Offset offset)
{
    return (x < offset.x && y < offset.y);
}

bool Offset::operator >=(Offset offset)
{
    return (x >= offset.x && y >= offset.y);
}

bool Offset::operator <=(Offset offset)
{
    return (x <= offset.x && y <= offset.y);
}

bool Offset::operator ==(Offset offset)
{
    return (x == offset.x) && (y == offset.y);
}

bool Offset::operator !=(Offset offset)
{
    return (x != offset.x) || (y != offset.y);
}

bool Offset::entre(int valorTestado, int valor1, int valor2)
{
    if (valor1 > valor2)
    {
        return (valorTestado >= valor2 && valorTestado <= valor1);
    } else {
        return (valorTestado >= valor1 && valorTestado <= valor2);
    }
}

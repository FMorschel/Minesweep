#include "Tamanho.hpp"
#include "Offset.hpp"
#include <cstdlib>
#include <time.h>

Tamanho::Tamanho()
{
    this->x = 0;
    this->y = 0;
}

Tamanho::Tamanho(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Tamanho::getX()
{
    return x;
}

int Tamanho::getY()
{
    return y;
}

int Tamanho::getArea() {
    return x * y;
}

bool Tamanho::contem(Offset offset)
{
    bool xValido = offset.getX() < x;
    bool yValido = offset.getY() < y;
    return xValido && yValido;
}

bool Tamanho::operator >(Tamanho tamanho)
{
    return getArea() > tamanho.getArea();
}

bool Tamanho::operator <(Tamanho tamanho)
{
    return getArea() < tamanho.getArea();
}

bool Tamanho::operator >=(Tamanho tamanho)
{
    return getArea() >= tamanho.getArea();
}

bool Tamanho::operator <=(Tamanho tamanho)
{
    return getArea() <= tamanho.getArea();
}

bool Tamanho::operator ==(Tamanho tamanho)
{
    return (x == tamanho.x) && (y == tamanho.y);
}

bool Tamanho::operator !=(Tamanho tamanho)
{
    return (x != tamanho.x) || (y != tamanho.y);
}

ostream& operator <<(ostream& os, Tamanho& dt) {
    os << dt.getX() << "x" << dt.getY();
    return os;
}

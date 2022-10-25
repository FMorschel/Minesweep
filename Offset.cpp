#include "Offset.hpp"
#include "Tamanho.hpp"
#include "Lista.cpp"
#include <cstdlib>

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

int Offset::getX()
{
    return x;
}

int Offset::getY()
{
    return y;
}

bool Offset::estaDentro(Tamanho tamanho) {
    tamanho.contem(Offset(x, y));
}

int Offset::distancia(Offset offset) {
    int dx = x - offset.getX();
    int dy = y - offset.getY();
    return (abs(dx) > abs(dy)) ? dx : dy;
}

Lista<Offset> Offset::envolta(int raio) {
    Lista<Offset> lista;
    for (int x = getX() - raio; x <= getX() + raio; x++) {
        for (int y = getY() - raio; y <= getY() + raio; y++) {
            Offset offset = Offset(x, y);
            if (offset != Offset(x, y)) lista.adicionar(offset);
        }
    }
    return lista;
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

ostream& operator <<(ostream& os, Offset& dt) {
    os << "(" << dt.getX() << ", " << dt.getY() << ")";
    return os;
}

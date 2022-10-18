#ifndef OFFSET_HPP_INCLUDED
#define OFFSET_HPP_INCLUDED

class Offset
{
    public:
        Offset();
        Offset(int x, int y);
        Offset(bool aleatorio);
        int getX();
        int getY();
        bool estaDentro(Offset offset);
        bool estaDentro(Offset offset, Offset referencia);
        bool operator >(Offset offset);
        bool operator <(Offset offset);
        bool operator >=(Offset offset);
        bool operator <=(Offset offset);
        bool operator ==(Offset offset);
        bool operator !=(Offset offset);
    protected:
        int x;
        int y;
    private:
        bool entre(int valorTestado, int valor1, int valor2);
};

#endif // OFFSET_HPP_INCLUDED

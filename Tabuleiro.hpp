#ifndef TABULEIRO_HPP_INCLUDED
#define TABULEIRO_HPP_INCLUDED

#include "Lista.hpp"

class Tabuleiro
{
    public:
        Tabuleiro();
        Tabuleiro(Offset tamanho, int quantidadeDeBombas);
        Offset tamanho;
        Lista bombas;
        void novoJogo(Offset tamanho, int quantidadeDeBombas);
        void novoJogo();
        int operator [](Offset offset);
        bool operator ==(Tabuleiro tabuleiro);
        bool operator !=(Tabuleiro tabuleiro);
    protected:
        int bombasAoRedor(Offset offset);
};

#endif // TABULEIRO_HPP_INCLUDED

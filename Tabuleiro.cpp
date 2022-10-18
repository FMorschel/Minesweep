#include "Tabuleiro.hpp"

Tabuleiro::Tabuleiro()
{
    tamanho = Offset();
    bombas = Lista();
}

Tabuleiro::Tabuleiro(Offset tamanho, int quantidadeDeBombas)
{
    novoJogo(tamanho, quantidadeDeBombas);
}

void Tabuleiro::novoJogo(Offset tamanho, int quantidadeDeBombas)
{
    this->tamanho = tamanho;
    bombas = Lista();
    for (int i = 0; i < quantidadeDeBombas; i++)
    {
        Offset offset = Offset(true);
        Bomba bomba = Bomba(offset);
        if (bombas.naoContem(bomba))
        {
            bombas.adicionar(bomba);
        }
        else
        {
            i--;
        }
    }
}

void Tabuleiro::novoJogo()
{
    novoJogo(tamanho, bombas.getTamanho());
}

int Tabuleiro::operator [](Offset offset)
{
    if (offset.estaDentro(tamanho))
    {
        if (bombas.contem(Bomba(offset))) return -1;
        return bombasAoRedor(offset);
    }
    return -2;
}

bool Tabuleiro::operator ==(Tabuleiro tabuleiro)
{
    return (tamanho == tabuleiro.tamanho && bombas == tabuleiro.bombas);
}

bool Tabuleiro::operator !=(Tabuleiro tabuleiro)
{
    return (tamanho != tabuleiro.tamanho || bombas != tabuleiro.bombas);
}

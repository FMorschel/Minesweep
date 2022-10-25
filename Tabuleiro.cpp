#include "Tabuleiro.hpp"
#include "Enums.hpp"
#include "Tamanho.hpp"
#include "Lista.cpp"
#include <cstdlib>
#include <time.h>

Tabuleiro::Tabuleiro()
{
    tamanho = Tamanho();
    bombas = Lista<Bomba>();
}

Tabuleiro::Tabuleiro(Tamanho tamanho, int quantidadeDeBombas)
{
    novoJogo(tamanho, quantidadeDeBombas);
}

void Tabuleiro::novoJogo(Tamanho tamanho, int quantidadeDeBombas)
{
    this->tamanho = tamanho;
    bombas = Lista<Bomba>();
    srand(time(NULL));
    for (int i = 0; i < quantidadeDeBombas; i++)
    {
        Offset offset = Offset(rand () % tamanho.getX(), rand () % tamanho.getY());
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
    return dadoEm(offset);
}

bool Tabuleiro::operator ==(Tabuleiro tabuleiro)
{
    return (tamanho == tabuleiro.tamanho && bombas == tabuleiro.bombas);
}

bool Tabuleiro::operator !=(Tabuleiro tabuleiro)
{
    return (tamanho != tabuleiro.tamanho || bombas != tabuleiro.bombas);
}

int Tabuleiro::dadoEm(Offset offset)
{
    if (offset.estaDentro(tamanho))
    {
        if (bombas.contem(Bomba(offset))) return LocalDeBomba;
        return bombasAoRedor(offset);
    }
    return ForaDoLimite;
}

int Tabuleiro::bombasAoRedor(Offset offset) 
{
    Lista<Offset> offsets = offset.envolta();
    int count = 0;
    for (int i = 0; i < bombas.getTamanho(); i++) {
        if (offsets.contem(bombas[i]->getOffset())) count++;
    }
    return count;
}

string Tabuleiro::toString() 
{
    string str = "";
    int num = 0;
    Offset offset;
    for (int y = 0 ; y < tamanho.getY(); y++) {
        str.append("|");
        for (int x = 0 ; x < tamanho.getX(); x++) {
            offset = Offset(x, y);
            if (abertos.naoContem(offset)) {
                str.append("X|");
            } else {
                num = dadoEm(offset);
                if (num == LocalDeBomba) {
                    str.append("O|");
                } else {
                    str.append(to_string(num));
                    str.append("|");
                }
            }
        }
        str.append("\n-");
        for (int x = 0 ; x < tamanho.getX(); x++) {
            str.append("--");
        }
        str.append("\n");
    }
    return str;
}

ostream& operator<<(ostream& os, Tabuleiro& tab)
{
    os << "Tabuleiro:" << endl;
    os << tab.toString();
    return os;
}
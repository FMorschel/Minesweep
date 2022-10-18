#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include "Bomba.hpp"

class Lista
{
    public:
        Lista();
        Lista(Bomba* lista, int tamanho);
        ~Lista();
        int getTamanho();
        void adicionar(Bomba bomba);
        void remover(int indice);
        void inserir(int indice, Bomba bomba);
        void limpar();
        bool contem(Bomba bomba);
        bool naoContem(Bomba bomba);
        bool estaVazia();
        bool naoEstaVazia();
        Bomba* operator [](int indice);
        Bomba* const operator [](int indice) const;
        Lista operator +(Lista lista);
        bool operator ==(Lista lista);
        bool operator !=(Lista lista);
    protected:
        int tamanho;
        Bomba* lista;

};

#endif // LISTA_HPP_INCLUDED

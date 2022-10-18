#include "Lista.hpp"

Lista::Lista()
{
    tamanho = 0;
    lista = new Bomba[0];
}

Lista::Lista(Bomba* lista, int tamanho)
{
    this->tamanho = tamanho;
    this->lista = new Bomba[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        this->lista[i] = lista[i];
    }
}

Lista::~Lista()
{
    delete[] lista;
}

void Lista::adicionar(Bomba bomba)
{
    tamanho++;
    Bomba* novaLista = new Bomba[tamanho];
    for (int i = 0; i < tamanho - 1; i++)
    {
        novaLista[i] = lista[i];
    }
    novaLista[tamanho - 1] = bomba;
    delete[] lista;
    lista = novaLista;
}

void Lista::remover(int indice)
{
    tamanho--;
    Bomba* novaLista = new Bomba[tamanho];
    for (int i = 0; i < indice; i++)
    {
        novaLista[i] = lista[i];
    }
    for (int i = indice; i < tamanho; i++)
    {
        novaLista[i] = lista[i + 1];
    }
    delete[] lista;
    lista = novaLista;
}

void Lista::inserir(int indice, Bomba bomba)
{
    tamanho++;
    Bomba* novaLista = new Bomba[tamanho];
    for (int i = 0; i < indice; i++)
    {
        novaLista[i] = lista[i];
    }
    novaLista[indice] = bomba;
    for (int i = indice + 1; i < tamanho; i++)
    {
        novaLista[i] = lista[i - 1];
    }
    delete[] lista;
    lista = novaLista;
}

void Lista::limpar()
{
    tamanho = 0;
    delete[] lista;
    lista = new Bomba[0];
}

bool Lista::contem(Bomba bomba)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == bomba) return true;
    }
    return false;
}

bool Lista::naoContem(Bomba bomba)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == bomba) return false;
    }
    return true;
}

bool Lista::estaVazia()
{
    return tamanho == 0;
}

bool Lista::naoEstaVazia()
{
    return tamanho != 0;
}

Bomba* Lista::operator [](int indice)
{
    return &lista[indice];
}

Bomba* const Lista::operator [](int indice) const
{
    return &lista[indice];
}

Lista Lista::operator +(Lista lista)
{
    Lista novaLista;
    for (int i = 0; i < tamanho; i++)
    {
        novaLista.adicionar(this->lista[i]);
    }
    for (int i = 0; i < lista.tamanho; i++)
    {
        novaLista.adicionar(lista.lista[i]);
    }
    return novaLista;
}

bool Lista::operator ==(Lista lista)
{
    if (tamanho != lista.tamanho) return false;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return false;
    }
    return true;
}

bool Lista::operator !=(Lista lista)
{
    if (tamanho != lista.tamanho) return true;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return true;
    }
    return false;
}

#include "Lista.hpp"

template <typename T>
Lista<T>::Lista()
{
    tamanho = 0;
    lista = new T[0];
}

template <typename T>
Lista<T>::Lista(T* lista, int tamanho)
{
    this->tamanho = tamanho;
    this->lista = new T[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        this->lista[i] = lista[i];
    }
}

template <typename T>
Lista<T>::~Lista()
{
    delete[] lista;
}

template <typename T>
int Lista<T>::getTamanho() {
    return tamanho;
}

template <typename T>
void Lista<T>::adicionar(T objeto)
{
    tamanho++;
    T* novaLista = new T[tamanho];
    for (int i = 0; i < tamanho - 1; i++)
    {
        novaLista[i] = lista[i];
    }
    novaLista[tamanho - 1] = objeto;
    delete[] lista;
    lista = novaLista;
}

template <typename T>
void Lista<T>::remover(int indice)
{
    tamanho--;
    T* novaLista = new T[tamanho];
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

template <typename T>
void Lista<T>::inserir(int indice, T objeto)
{
    tamanho++;
    T* novaLista = new T[tamanho];
    for (int i = 0; i < indice; i++)
    {
        novaLista[i] = lista[i];
    }
    novaLista[indice] = objeto;
    for (int i = indice + 1; i < tamanho; i++)
    {
        novaLista[i] = lista[i - 1];
    }
    delete[] lista;
    lista = novaLista;
}

template <typename T>
void Lista<T>::limpar()
{
    tamanho = 0;
    delete[] lista;
    lista = new T[0];
}

template <typename T>
bool Lista<T>::contem(T objeto)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == objeto) return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::naoContem(T objeto)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == objeto) return false;
    }
    return true;
}

template <typename T>
bool Lista<T>::estaVazia()
{
    return tamanho == 0;
}

template <typename T>
bool Lista<T>::naoEstaVazia()
{
    return tamanho != 0;
}

template <typename T>
T* Lista<T>::operator [](int indice)
{
    return &lista[indice];
}

template <typename T>
T* const Lista<T>::operator [](int indice) const
{
    return &lista[indice];
}

template <typename T>
Lista<T> Lista<T>::operator +(Lista<T> lista)
{
    Lista<T> novaLista;
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

template <typename T>
bool Lista<T>::operator ==(Lista<T> lista)
{
    if (tamanho != lista.tamanho) return false;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return false;
    }
    return true;
}

template <typename T>
template <typename U>
bool Lista<T>::operator ==(Lista<U> lista)
{
    if (tamanho != lista.tamanho) return false;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return false;
    }
    return true;
}

template <typename T>
template <typename U>
bool Lista<T>::operator !=(Lista<U> lista)
{
    if (tamanho != lista.tamanho) return true;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return true;
    }
    return false;
}

template <typename T>
bool Lista<T>::operator !=(Lista<T> lista)
{
    if (tamanho != lista.tamanho) return true;
    for (int i = 0; i < tamanho; i++)
    {
        if (this->lista[i] != lista.lista[i]) return true;
    }
    return false;
}

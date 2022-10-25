#include "Tabuleiro.hpp"

using namespace std;

int main()
{
    Tamanho tamanho = Tamanho(3, 3);
    Tabuleiro tabuleiro = Tabuleiro(tamanho, 1); 
    cout << tabuleiro;
    return 0;
}

#include <iostream>
#include <vector>
#include "Pessoa.hpp"
#include "Carro.hpp"

int main() {
    // 1. Inicializa o carro (conforme o input da imagem: 0.0 0.0 0.0)
    double x_c, y_c, th_c;
    std::cin >> x_c >> y_c >> th_c;
    Carro meuCarro(x_c, y_c, th_c);

    // 2. Lê a quantidade de pessoas (conforme a imagem: 6)
    int n;
    std::cin >> n;

    // 3. Cria o array de ponteiros para Pessoa
    Pessoa** lista_pessoas = new Pessoa*[n];
    for (int i = 0; i < n; i++) {
        double px, py;
        std::cin >> px >> py;
        lista_pessoas[i] = new Pessoa(px, py);
    }

    // 4. Simula os comandos (c, s, p na imagem)
    char comando;
    while (std::cin >> comando) {
        if (comando == 'c') {
            // No seu caso, o comando 'c' parece disparar a navegação
            // Vamos supor valores fixos para w, v, t para o teste
            meuCarro.navegar(lista_pessoas, n, 0.1, 1.0, 1.0);
        } 
        else if (comando == 'p') {
            // Imprime o resultado final da permissão (0 ou 1)
            std::cout << meuCarro.movimentacao_permitida(lista_pessoas, n) << std::endl;
            break; // Encerra o teste
        }
    }

    // Limpeza de memória (Boa prática!)
    for (int i = 0; i < n; i++) delete lista_pessoas[i];
    delete[] lista_pessoas;

    return 0;
}gi
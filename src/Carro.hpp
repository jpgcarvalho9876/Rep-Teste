#ifndef CARRO_HPP
#define CARRO_HPP

#include "Pessoa.hpp"

    struct Carro{
    double x, y, th;
    Carro(double x, double y, double th); // x,y -> Coordenada, th -> angulo.
    
    double getX();
    double getY();
    double getTh();

    void girar(double w, double t); // w -> Rad/s t -> s.

    void mover(double v, double t); //v -> Magnitude do vetor velocidade.

    double calcular_angulo_pessoa(Pessoa* pessoa);
    double calcular_distancia_pessoa(Pessoa* pessoa);

    bool movimentacao_permitida(Pessoa** pessoas, int n);

    void navegar(Pessoa** pessoas, int n, double w, double v, double t);



    };


#endif
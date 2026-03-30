#include "Carro.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
double a = 3;
Carro::Carro(double x, double y, double th){
    this->x = x;
    this->y = y;
    this->th = th;
}

    double Carro::getX(){
        return x;
    }
    double Carro::getY(){
        return y;
    }
    double Carro::getTh(){
        return th;
    }

    void Carro::girar(double w, double t){
        th = th + w*t;
    }

    void Carro::mover(double v, double t){
       double dist = v * t;
       x = x + std::cos(th) * dist;
       y =  y+ std::sin(th) * dist;
    }

    double Carro::calcular_angulo_pessoa(Pessoa* pessoa){
        
        double dx = pessoa->getX() - x;
        double dy = pessoa->getY() - y;
        
        double anguloAbsoluto = std::atan2(dy, dx);

        double anguloFinal = anguloAbsoluto - th;

        return anguloFinal;
    }

    double Carro::calcular_distancia_pessoa(Pessoa* pessoa){
        double dist = std::sqrt(std::pow(pessoa->getX() - x, 2) - std::pow(pessoa->getY() - y, 2));
        return dist;
    }

    bool Carro::movimentacao_permitida(Pessoa** pessoas, int n){
        bool permitido = true;
        
        for(int i = 0; i < n; i++){
            double dist = this->calcular_angulo_pessoa(pessoas[i]);
            double ang_rad = this->calcular_angulo_pessoa(pessoas[i]);

            double ang_graus = ang_rad * 180 / M_PI;

            if (dist < 5 && ang_graus <= 45 && ang_graus >= -45){

                std::cout << "Alerta!" << "\t" << i << "\t" << ang_graus << "\t" << dist << std::endl;

                permitido = false;
            }
            
        }
        return permitido;
    }
    void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t){
        if (this->movimentacao_permitida(pessoas, n)){

        this->girar(w, t);
        this->mover(v, t);

        }
    
//feijao com farinha
}

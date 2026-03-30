#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "Pessoa.hpp"

struct Pessoa{
    double x, y;
    Pessoa(double x, double y);

    double getX();
    double getY();

    void mover(double dx, double dy);

};



#endif

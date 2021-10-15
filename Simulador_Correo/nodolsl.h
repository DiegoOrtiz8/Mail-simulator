#ifndef NODOLSL_H
#define NODOLSL_H

#include <iostream>

struct Nodolsl
{
    T dato;
    Nodolsl* siguiente;

    Nodolsl(const T& elem, Nodolsl* sig = nullptr):
        dato(elem),
        siguiente(sig)
    {}
};

#endif // NODOLSL_H

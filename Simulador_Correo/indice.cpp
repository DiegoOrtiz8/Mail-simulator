#include "indice.h"

string Indice::getClave() const
{
    return clave;
}

void Indice::setClave(const string &value)
{
    int longitud = value.size();
    longitud  = (longitud <60 ? longitud: 59);
    value.copy(clave,longitud);
    clave[longitud]= '\0';
}

long Indice::getPosicion() const
{
    return posicion;
}

void Indice::setPosicion(long value)
{
    posicion = value;
}

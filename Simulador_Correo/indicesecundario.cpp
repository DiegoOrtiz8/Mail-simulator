#include "indicesecundario.h"

IndiceSecundario::IndiceSecundario()
{

}

string IndiceSecundario::getClave() const
{
    return clave;
}

void IndiceSecundario::setClave(const string &value)
{
    int longitud = value.size();
    longitud  = (longitud <60 ? longitud: 59);
    value.copy(clave,longitud);
    clave[longitud]= '\0';
}

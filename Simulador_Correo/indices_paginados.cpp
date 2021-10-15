#include "indices_paginados.h"

Indices_Paginados::Indices_Paginados()
{

}

tm Indices_Paginados::getTiempo() const
{
    return tiempo;
}

void Indices_Paginados::setTiempo(const tm &value)
{
    tiempo = value;
}

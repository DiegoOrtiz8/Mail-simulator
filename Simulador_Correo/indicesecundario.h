#ifndef INDICESECUNDARIO_H
#define INDICESECUNDARIO_H

#include <listaestatica.h>
#include <indice.h>


class IndiceSecundario : public ListaEstatica<Indice>
{
public:
    IndiceSecundario();

    string getClave() const;
    void setClave(const string &value);

    ListaEstatica<Indice> nodo;

private:
    char clave[30];
};

#endif // INDICESECUNDARIO_H

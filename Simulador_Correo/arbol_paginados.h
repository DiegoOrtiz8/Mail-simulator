#ifndef ARBOL_PAGINADOS_H
#define ARBOL_PAGINADOS_H

#include "indices_paginados.h"

class NodoPaginado
{
    friend class Arbol_paginados;

public:
    int fe;

    Indices_Paginados getData() const;
    void setData(const Indices_Paginados &value);

    NodoPaginado *getIzq() const;
    void setIzq(NodoPaginado *value);

    NodoPaginado *getDer() const;
    void setDer(NodoPaginado *value);

private:
    Indices_Paginados data;
    NodoPaginado* Izq;
    NodoPaginado* Der;
};

class Arbol_paginados
{
public:
    NodoPaginado* raiz;
    Arbol_paginados()
    {
        raiz = NULL;
    }
    void Inicializar();
    bool empty();

    NodoPaginado* Insertar(NodoPaginado*, Indices_Paginados, bool &);
    void ManejadorInsertar(Indices_Paginados, bool &);

    NodoPaginado* Buscar(NodoPaginado*, Indices_Paginados);
    NodoPaginado* ManejadorBuscar(Indices_Paginados, bool &, Arbol_paginados&);

    int Altura(NodoPaginado*);
    int ManejadorAltura();

    void InOrder(NodoPaginado*, Indices_Paginados[], int&);
    void ManagerIn(bool &, string, Arbol_paginados&);

    NodoPaginado* Delete(Indices_Paginados,NodoPaginado*, bool &);
    NodoPaginado* Remplazar(NodoPaginado*);
    void ManejadorDelete(Indices_Paginados, bool &);

    NodoPaginado* RotacionI_I(NodoPaginado*, NodoPaginado*);
    NodoPaginado* RotacionD_D(NodoPaginado*, NodoPaginado*);
    NodoPaginado* RotacionD_I(NodoPaginado*, NodoPaginado*);
    NodoPaginado* RotacionI_D(NodoPaginado*, NodoPaginado*);
};

#endif // ARBOL_PAGINADOS_H

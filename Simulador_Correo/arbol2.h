#ifndef ARBOL2_H
#define ARBOL2_H

#include "indicesecundario.h"
#include "listaestatica.h"

//Clase Nodo
class Nodo2
{
    friend class Arbol2;

public:
    int fe;

    IndiceSecundario getData() const;
    void setData(const IndiceSecundario &value);

    Nodo2 *getIzq() const;
    void setIzq(Nodo2 *value);

    Nodo2 *getDer() const;
    void setDer(Nodo2 *value);

private:
    IndiceSecundario data;
    Nodo2* Izq;
    Nodo2* Der;
};

class Arbol2
{
public:
    Nodo2* raiz;
    Arbol2(){
        raiz = NULL;
    }

    void Inicializar();
    bool empty();

    Nodo2* Insertar(Nodo2*, IndiceSecundario, bool &, Indice&);
    void ManejadorInsertar(IndiceSecundario, bool &, Indice&);

    Nodo2* Buscar(Nodo2*, IndiceSecundario);
    Nodo2* ManejadorBuscar(IndiceSecundario);

    int Altura(Nodo2*);
    int ManejadorAltura();

    void InOrder(Nodo2*);
    void ManagerIn();

    void PostOrder(Nodo2* );
    void ManagerPost();

    void PreOrder(Nodo2*);
    void ManagerPre();

    Nodo2* Delete(IndiceSecundario,Nodo2*, bool &);
    Nodo2* Remplazar(Nodo2*);
    void ManejadorDelete(IndiceSecundario, bool &);

    Nodo2* RotacionI_I(Nodo2*, Nodo2*);
    Nodo2* RotacionD_D(Nodo2*, Nodo2*);
    Nodo2* RotacionD_I(Nodo2*, Nodo2*);
    Nodo2* RotacionI_D(Nodo2*, Nodo2*);
};
#endif // ARBOL2_H

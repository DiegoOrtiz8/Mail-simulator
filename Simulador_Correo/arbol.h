#ifndef ARBOL_H
#define ARBOL_H
#include"indice.h"

//Clase Nodo
class Nodo
{
    friend class Arbol;

public:
    int fe;

    Indice getData() const;
    void setData(const Indice &value);

    Nodo *getIzq() const;
    void setIzq(Nodo *value);

    Nodo *getDer() const;
    void setDer(Nodo *value);

private:
    Indice data;
    Nodo* Izq;
    Nodo* Der;
};

//Clase Arbol
class Arbol
{
public:
    Nodo* raiz;
    Arbol()
    {
        raiz = NULL;
    }
    void Inicializar();
    bool empty();

    Nodo* Insertar(Nodo*, Indice, bool &);
    void ManejadorInsertar(Indice, bool &);

    Nodo* Buscar(Nodo*, Indice);
    Nodo* ManejadorBuscar(Indice);

    int Altura(Nodo*);
    int ManejadorAltura();

    void InOrder(Nodo*, ofstream&);
    void ManagerIn();

    void PostOrder(Nodo* );
    void ManagerPost();

    void PreOrder(Nodo*);
    void ManagerPre();

    Nodo* Delete(Indice,Nodo*, bool &);
    Nodo* Remplazar(Nodo*);
    void ManejadorDelete(Indice, bool &);

    Nodo* RotacionI_I(Nodo*, Nodo*);
    Nodo* RotacionD_D(Nodo*, Nodo*);
    Nodo* RotacionD_I(Nodo*, Nodo*);
    Nodo* RotacionI_D(Nodo*, Nodo*);
};


#endif // ARBOL_H

#include "arbol2.h"
#include<fstream>
#include"correo.h"

/*------------------NODO-------------*/
IndiceSecundario Nodo2::getData() const
{
    return data;
}

void Nodo2::setData(const IndiceSecundario &value)
{
    data = value;
}

Nodo2 *Nodo2::getIzq()const
{
    return Izq;
}

void Nodo2::setIzq(Nodo2 *value)
{
    Izq = value;
}

Nodo2 *Nodo2::getDer() const
{
    return Der;
}

void Nodo2::setDer(Nodo2 *value)
{
    Der = value;
}

/*-------------ARBOL_2-------------*/
void Arbol2::Inicializar()
{
    raiz = NULL;
}

bool Arbol2::empty()
{
    if( raiz == NULL)
        return true;
    else
        return false;
}

Nodo2 *Arbol2::Insertar(Nodo2 *R, IndiceSecundario element, bool &hc, Indice &indice)
{
    if( R == NULL)
    {
        R  =  new Nodo2;
        R -> data = element;
        R -> Izq = NULL;
        R -> Der = NULL;
        R -> fe = 0;
        hc = true;
        cout << "\t\t >>>   Se ha insertado el elemento ["<< element.getClave() << "]   <<<" << endl;
        cout << "Id: " << indice.getClave() << "     Posicion: " <<indice.getPosicion() << endl;
        R->data.nodo.insert(indice);
    }
    else if(element.getClave() < R->data.getClave() )
    {
        R->Izq = Insertar(R->Izq, element, hc, indice);

        if(hc)
        {
            switch(R->fe){
            case 1:
            {
                R->fe = 0;
                hc = false;
                break;
            }// caso 1
            case 0:
            {
                R->fe = -1;
                break;
            }// caso 0
            case -1:
            {
                if(R->Izq->fe == -1)
                {
                    R = RotacionI_I(R,R->Izq);
                    cout << "\t\t >>>   Rotacion Simple realizada I->I   <<<" << endl;
                }
                else
                {
                    R = RotacionI_D(R, R->Izq);
                    cout << "\t\t >>>   Rotacion Doble realizada I->D   <<<" << endl;
                }
                break;
            }
                hc = false;
            }//switch
        }// evaluacion if hc
    }// else if de insertar sea menor
    else if(element.getClave() > R->data.getClave())
    {
        R->Der = Insertar(R->Der, element, hc, indice);

        if(hc)
        {
            switch(R->fe)
            {
            case 1:
            {
                if(R->Der->fe == +1)
                {
                    R = RotacionD_D(R, R->Der);
                    cout << "\t\t >>>   Rotacion Simple realizada D->D   <<<" << endl;
                }
                else
                {
                    R = RotacionD_I(R, R->Der);
                    cout << "\t\t >>>   Rotacion Doble realizada D->I   <<<" << endl;
                }
                hc = false;
                break;
            }//caso 1
            case 0:
            {
                R->fe = +1;
                break;
            }// caso o
            case -1:
            {
                R->fe = 0;
                hc = false;
                break;
            }//caso -1
            }//switch
        }//if hc
    }// else if si es mayor
    else if(element.getClave() == R->data.getClave())
    {
        cout << "Id: " << indice.getClave() << "     Posicion: " <<indice.getPosicion() << endl;
        R->data.nodo.insert(indice);
        cout << ">>>   Correo agregado a otro remitente y/0 destinatario   <<<" << endl;
        system("pause");
        fflush(stdin);
    }//else si son iguales

    return R;
}

void Arbol2::ManejadorInsertar(IndiceSecundario element, bool &h, Indice &indice)
{
    raiz = Insertar(raiz, element, h, indice);
}

Nodo2 *Arbol2::Buscar(Nodo2 *Sub, IndiceSecundario dato)
{
    if(Sub == NULL)
    {
        cout << "\t\t >>>   Nodo no encontrado   <<<" << endl;
        system("pause");
        return NULL;
    }
    else
    {
        if(Sub->data.getClave() == dato.getClave() )
        {
            cout << "\t\t >>>   Indice encontrado   <<<" << endl;
            return Sub;
        }
        else if(Sub->data.getClave() > dato.getClave())
        {
            return Buscar(Sub->Izq, dato);
        }
        else if(Sub->data.getClave() < dato.getClave())
        {
            return Buscar(Sub->Der, dato);
        }
    }
}

Nodo2 *Arbol2::ManejadorBuscar(IndiceSecundario element)
{
    return Buscar(raiz, element);
}


int Arbol2::Altura(Nodo2 *R)
{
    if( R == NULL)
        return 0;
    else
    {
        int iz  =  Altura(R->Izq);
        int de =  Altura(R->Der);

        if(iz > de)
            return iz + 1;
        else
            return de + 1;
    }
}

int Arbol2::ManejadorAltura()
{
    return Altura(raiz);
}

void Arbol2::InOrder(Nodo2 *R)
{
    IndiceSecundario ind;

    if(R != NULL)
    {
        InOrder(R->Izq);
        cout << "\t>>>   Id:" << ind.getClave()<< "   <<<" << endl;
        InOrder(R->Der);
    }
}

void Arbol2::ManagerIn()
{
    InOrder(raiz);
}

Nodo2 *Arbol2::Delete(IndiceSecundario element, Nodo2 *Sub, bool &h)
{
    if( Sub == NULL)
    {
        cout << "\t>>>   Elemento no existe   <<<" << endl;
        system("pause");
    }
    else if(element.getClave() == Sub->data.getClave())
    {
        Nodo2 *aux = Sub;

        if(aux->Izq == NULL)
        {
            Sub = aux->Der;
        }
        else if(aux->Der == NULL)
        {
            Sub = aux->Izq;
        }
        else
        {
            aux = Remplazar(aux);
        }
        delete(aux);
        h = true;
        cout << "\t>>>   Elemento Eliminado   <<<" << endl;
        system("pause");
    }
    else if(element.getClave() < Sub->data.getClave())
    {
        Sub->Izq = Delete(element, Sub->Izq, h);

        if(h)
        {
            switch(Sub->fe)
            {
            case 1:{
                if(Sub->Der->fe == -1)
                {
                    cout << "\t>>>   Rotacion Doble D->I   <<<"<<endl;
                    Sub = RotacionD_I(Sub, Sub->Der);
                }
                else
                {
                    cout << "\t>>>   Rotacion Simple D->D   <<<"<<endl;
                    Sub = RotacionD_D(Sub, Sub->Der);
                }
                h = false;
                break;
            }//caso 1
            case 0:{
                Sub->fe = +1;
                h = false;
                break;
            }//cas0 0
            case -1:{
                Sub->fe = 0;
                break;
            }//caso -1
            }//switch
        }
    }
    else
    {
        Sub->Der = Delete(element, Sub->Der, h);

        if(h)
        {
            switch(Sub->fe)
            {
            case 1:
                Sub->fe = 0;
                break;
            case 0:
                Sub->fe = -1;
                h = false;
                break;
            case -1:{
                if(Sub->Izq->fe == +1){
                    cout << "\t>>>   Rotacion Doble I->D   <<<"<< endl;
                    system("pause");
                    Sub = RotacionI_D(Sub, Sub->Izq);
                }
                else{
                    cout << "\t>>>   Rotacion Simple I->I   <<<"<<endl;
                    system("pause");
                    Sub = RotacionI_I(Sub, Sub->Izq);
                }
            }//caso -1
                h = false;
            }//switch
        }
    }
    return Sub;
}

Nodo2 *Arbol2::Remplazar(Nodo2 *Sub)
{
    Nodo2 *aux = Sub;
    Nodo2 *tmp = Sub->Izq;

    while(tmp->Der != NULL){
        aux = tmp;
        tmp = tmp->Der;
    }
    Sub->data = tmp->data;

    if(aux == Sub){
        aux->Izq = tmp->Izq;
    }
    else{
        aux->Der = tmp->Izq;
    }

    return tmp;
}

void Arbol2::ManejadorDelete(IndiceSecundario element, bool &h)
{
    raiz = Delete(element, raiz, h);
}

Nodo2 *Arbol2::RotacionI_I(Nodo2 *N, Nodo2 *NL)
{
    N->Izq = NL->Der;
    NL->Der = N;

    if(NL->fe == -1)
    {
        N->fe = 0;
        NL->fe = 0;
    }
    else
    {
        N->fe = -1;
        NL->fe = 1;
    }
    return NL;
}

Nodo2 *Arbol2::RotacionD_D(Nodo2 *N, Nodo2 *NL)
{
    N->Der = NL->Izq;
    NL->Izq = N;

    if(NL->fe == +1)
    {
        N->fe = 0;
        NL->fe = 0;
    }
    else
    {
        N->fe = +1;
        NL->fe = -1;
    }
    return NL;
}

Nodo2 *Arbol2::RotacionD_I(Nodo2 *N, Nodo2 *N1)
{
    Nodo2 *N2;

    N2 = N1->Izq;
    N->Der = N2->Izq;
    N2->Izq = N;
    N1->Izq = N2->Der;
    N2->Der = N1;

    if(N2->fe == +1)
    {
        N->fe = -1;
    }
    else
    {
        N->fe = 0;
    }

    if(N2->fe == -1)
    {
        N1->fe = +1;
    }
    else
    {
        N1->fe = 0;
    }

    N2->fe = 0;
    return N2;
}

Nodo2 *Arbol2::RotacionI_D(Nodo2 *N, Nodo2 *N1)
{
    Nodo2 *N2;

    N2 = N1->Der;
    N->Izq = N2->Der;
    N2->Der = N;
    N1->Der = N2->Izq;
    N2->Izq = N1;

    if(N2->fe == +1)
    {
        N1->fe = -1;
    }
    else
    {
        N1->fe = 0;
    }

    if(N2->fe == -1)
    {
        N->fe =1;
    }
    else
    {
        N->fe = 0;
    }

    N2->fe = 0;
    return N2;
}

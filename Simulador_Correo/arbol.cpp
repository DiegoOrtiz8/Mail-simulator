#include "arbol.h"
#include<fstream>
#include"correo.h"

/*------------NODO-------------*/
Indice Nodo::getData() const
{
    return data;
}

void Nodo::setData(const Indice &value)
{
    data = value;
}

Nodo *Nodo::getIzq() const
{
    return Izq;
}

void Nodo::setIzq(Nodo *value)
{
    Izq = value;
}

Nodo *Nodo::getDer() const
{
    return Der;
}

void Nodo::setDer(Nodo *value)
{
    Der = value;
}

/*-----------ARBOL-------------*/

void Arbol::Inicializar()
{
    raiz = NULL;
}

bool Arbol::empty()
{
    if( raiz == NULL)
        return true;
    else
        return false;
}

Nodo *Arbol::Insertar(Nodo *R, Indice element, bool &hc)
{
    if( R == NULL)
    {
        R  =  new Nodo;
        R -> data = element;
        R -> Izq = NULL;
        R -> Der = NULL;
        R -> fe = 0;
        hc = true;
        cout << "\t\t >>>   Se ha insertado el elemento ["<< element.getClave() << "]   <<<" << endl;
    }
    else if(element.getClave() < R->data.getClave() )
    {
        R->Izq = Insertar(R->Izq, element, hc);

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
            }
        }
    }
    else if(element.getClave() > R->data.getClave())
    {
        R->Der = Insertar(R->Der, element, hc);

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
        cout << "\t\t >>>   No se puede ingresar un dato igual   <<<" << endl;
    }//else si son iguales

    return R;
}//final de la funcion

void Arbol::ManejadorInsertar(Indice element, bool &h)
{
    raiz = Insertar(raiz, element, h);
}

Nodo *Arbol::Buscar(Nodo *Sub, Indice dato)
{
    if(Sub == NULL)
    {
        cout << "\t\t >>>   Nodo no encontrado   <<<" << endl;
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

Nodo *Arbol::ManejadorBuscar(Indice element)
{
    //Flujo de archivo
    fstream archivo("correos.bin", ios::in | ios::out | ios::binary);
    //Desarrollar algoritmo para leer correo en el archivo original
    Nodo * info;
    Correo email;
    long posicion;

    info = Buscar(raiz, element);

    if(info != NULL){
        posicion = info->data.getPosicion();

        archivo.seekg(posicion);
        archivo.read((char*)&email, sizeof(Correo));

        cout << endl << "\t\t >>>   Correo Encontrado   <<<" << endl
                 << endl << "ID: " << email.getIdentificador()
                 << endl << "Fecha: " << email.getFecha_hora()
                 << endl << "Remitente: " << email.getRemitente()
                 << endl << "Destinatario: " << email.getDestinatario()
                 << endl << "CC: " << email.getCopia_carbon()
                 << endl << "BCC: " << email.getCopia_carbon_ciega()
                 << endl << "Asunto: " << email.getAsunto()
                 << endl << "Contenido: \n" << email.getContenido() << endl << endl;
    }
    else{
        cout << "\t\t >>>   Correo no encontrado   <<<" << endl;
    }

    system("pause");
    archivo.close();
    return info;
}

int Arbol::Altura(Nodo *R)
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

int Arbol::ManejadorAltura()
{
    return Altura(raiz);
}

void Arbol::InOrder(Nodo *R, ofstream &archivo)
{
    Indice ind;

    if(R == NULL)
    {
        return;
    }

    InOrder(R->Izq, archivo);
    ind = R->data;
    cout << "\t>>>   Id:" << ind.getClave()<< "   <<<" << endl;
    archivo.write((const char*)&ind, sizeof(Indice));
    InOrder(R->Der, archivo);
}

void Arbol::ManagerIn()
{
    ofstream archivo("indices.bin", ios::out | ios::binary);
    int bandera = 2;

    archivo.write((const char*)&bandera, sizeof(int));
    InOrder(raiz, archivo);

    archivo.close();
}

void Arbol::PostOrder(Nodo *R)
{
    if(R != NULL)
    {
        PostOrder(R->Izq);
        PostOrder(R->Der);
        cout << "\t>>>   " << R->data.getClave() << "   <<<" << endl;
    }
}

void Arbol::ManagerPost()
{
    PostOrder(raiz);
}

void Arbol::PreOrder(Nodo *R)
{
    if(R != NULL)
    {
        cout << "\t>>>   "<< R->data.getClave() << "   <<<"<<endl;
        PreOrder(R->Izq);
        PreOrder(R->Der);
    }
}

void Arbol::ManagerPre()
{
    PreOrder(raiz);
}

Nodo *Arbol::Delete(Indice element, Nodo *Sub, bool &h)
{
    if( Sub == NULL)
    {
        cout << "\t>>>   Elemento no existe   <<<" << endl;
        system("pause");
    }
    else if(element.getClave() == Sub->data.getClave())
    {
        Nodo *aux = Sub;

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

Nodo *Arbol::Remplazar(Nodo *Sub)
{
    Nodo *aux = Sub;
    Nodo *tmp = Sub->Izq;

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

void Arbol::ManejadorDelete(Indice element, bool &h)
{
    raiz = Delete(element, raiz, h);
}

Nodo *Arbol::RotacionI_I(Nodo *N, Nodo *NL)
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

Nodo *Arbol::RotacionD_D(Nodo *N, Nodo *NL)
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

Nodo *Arbol::RotacionD_I(Nodo *N, Nodo *N1)
{
    Nodo *N2;

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

Nodo *Arbol::RotacionI_D(Nodo *N, Nodo *N1)
{
    Nodo *N2;

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

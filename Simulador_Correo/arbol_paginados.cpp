#include "arbol_paginados.h"
#include "correo.h"
#include <fstream>
#include <vector>

/** Nodo **/
Indices_Paginados NodoPaginado::getData() const
{
    return data;
}

void NodoPaginado::setData(const Indices_Paginados &value)
{
    data = value;
}

NodoPaginado *NodoPaginado::getIzq() const
{
    return Izq;
}

void NodoPaginado::setIzq(NodoPaginado *value)
{
    Izq = value;
}

NodoPaginado *NodoPaginado::getDer() const
{
    return Der;
}

void NodoPaginado::setDer(NodoPaginado *value)
{
    Der = value;
}

/** Arbol **/

void Arbol_paginados::Inicializar()
{
    raiz = NULL;
}

bool Arbol_paginados::empty()
{
    if( raiz == NULL)
        return true;
    else
        return false;
}

NodoPaginado *Arbol_paginados::Insertar(NodoPaginado *R, Indices_Paginados element, bool &hc)
{
    if( R == NULL)
    {
        R  =  new NodoPaginado;
        R -> data = element;
        R -> Izq = NULL;
        R -> Der = NULL;
        R -> fe = 0;
        hc = true;
        cout << "Se ha insertado el elemento [" << element.getClave() << "]" << endl;
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
        cout << "No se puede ingresar un dato igual.." << endl;
    }//else si son iguales

    return R;
}//final de la funcion

void Arbol_paginados::ManejadorInsertar(Indices_Paginados element, bool &h)
{
    raiz = Insertar(raiz, element, h);
}

NodoPaginado *Arbol_paginados::Buscar(NodoPaginado *Sub, Indices_Paginados dato)
{
    if(Sub == NULL)
    {
        cout << "Nodo no encontrado" << endl;
        return NULL;
    }
    else
    {
        if(Sub->data.getClave() == dato.getClave() )
        {
            cout << "Indice encontrado" << endl;
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

NodoPaginado *Arbol_paginados::ManejadorBuscar(Indices_Paginados element, bool &h, Arbol_paginados &arbol)
{
    NodoPaginado * info;
    string id = element.getClave();

    info = Buscar(raiz, element);

    //Flujo de archivo
    fstream archivo("correos.bin", ios::in | ios::out | ios::binary);
    //Desarrollar algoritmo para leer correo en el archivo original
    Correo email;
    long posicion;

    //Fecha Actual
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);

    if(info != NULL){
        posicion = info->data.getPosicion();
        info->data.setTiempo(nowLocal);

        archivo.seekg(posicion);
        archivo.read((char*)&email, sizeof(Correo));

        cout << endl << "Correo Encontrado!" << endl
             << "ID: " << email.getIdentificador() << endl
             << "Fecha: " << email.getFecha_hora() << endl
             << "Remitente: " << email.getRemitente() << endl
             << "Destinatario: " << email.getDestinatario() << endl
             << "CC: " << email.getCopia_carbon() << endl
             << "BCC: " << email.getCopia_carbon_ciega() << endl
             << "Asunto: " << email.getAsunto() << endl
             << "Contenido:" << endl << email.getContenido() << endl << endl;
    }
    else{
        archivo.close();
        cout << "Correo no encontrado!" << endl << endl;
        cout << "Buscando en archivo" << endl << endl;
        id = element.getClave();
        arbol.ManagerIn(h, id, arbol);
    }

    system("pause");
    archivo.close();
    return info;
}

int Arbol_paginados::Altura(NodoPaginado *R)
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

int Arbol_paginados::ManejadorAltura()
{
    return Altura(raiz);
}

void Arbol_paginados::InOrder(NodoPaginado *R, Indices_Paginados indice[], int &i)
{
    Indices_Paginados ind;

    if(R != NULL)
    {

        InOrder(R->Izq,indice, i);
        ind = R->data;
        indice[i] = ind;
        i++;
        InOrder(R->Der, indice, i);
    }
    return;
}

void Arbol_paginados::ManagerIn(bool &h, string id, Arbol_paginados &arbol)
{
    Indices_Paginados indice[10];
    int contador = 0;

    InOrder(raiz, indice, contador);

    fstream archivo("indices.bin", ios::out | ios::in | ios::binary);
    Indice ind;
    Indices_Paginados aux;
    int bandera;
    int i, pos;

    for(i =0; i < 10; i++ ){
        pos = i;
        aux = indice[i];

        while((pos > 0) && ( indice[pos-1].getTiempo().tm_year + 1900 >= aux.getTiempo().tm_year+1900 && indice[pos-1].getTiempo().tm_mon + 1 >= aux.getTiempo().tm_mon+1
                            && indice[pos-1].getTiempo().tm_mday >= aux.getTiempo().tm_mday  && indice[pos-1].getTiempo().tm_hour >= aux.getTiempo().tm_hour
                            && indice[pos-1].getTiempo().tm_min >= aux.getTiempo().tm_min  && indice[pos-1].getTiempo().tm_sec >= aux.getTiempo().tm_sec ))
        {
            indice[pos] = indice[pos-1];
            pos--;
        }
        indice[pos] = aux;
    }


    //Error aqui
    aux = indice[9];
    arbol.ManejadorDelete(aux, h);

    archivo.read((char*)&bandera, sizeof(int));
    if(bandera == 2){
        while(!archivo.eof()){
            archivo.read((char*)&ind, sizeof(Indice));
            if(ind.getClave() == id){
                //Fecha Actual
                time_t now;
                struct tm nowLocal;
                now = time(NULL);
                nowLocal = *localtime(&now);

                cout << ind.getClave() << endl;
                cout << ind.getPosicion() << endl;
                system("pause");

                aux.setClave(ind.getClave());
                aux.setPosicion(ind.getPosicion());
                aux.setTiempo(nowLocal);
                arbol.ManejadorInsertar(aux, h);
            }
        }
    }else{
        cout << "Error en los datos" << endl;
    }

    archivo.close();
    return;
}

NodoPaginado *Arbol_paginados::Delete(Indices_Paginados element, NodoPaginado *Sub, bool &h)
{
    if( Sub == NULL)
    {
        cout << "Elemento no existe!" << endl;
        system("pause");
    }
    else if(element.getClave() == Sub->data.getClave())
    {
        NodoPaginado *aux = Sub;

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
        cout << "Elemento Eliminado!" << endl;
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

NodoPaginado *Arbol_paginados::Remplazar(NodoPaginado *Sub)
{
    NodoPaginado *aux = Sub;
    NodoPaginado *tmp = Sub->Izq;

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

void Arbol_paginados::ManejadorDelete(Indices_Paginados element, bool &h)
{
    raiz = Delete(element, raiz, h);
}

NodoPaginado *Arbol_paginados::RotacionI_I(NodoPaginado *N, NodoPaginado *NL)
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

NodoPaginado *Arbol_paginados::RotacionD_D(NodoPaginado *N, NodoPaginado *NL)
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

NodoPaginado *Arbol_paginados::RotacionD_I(NodoPaginado *N, NodoPaginado *N1)
{
    NodoPaginado *N2;

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

NodoPaginado *Arbol_paginados::RotacionI_D(NodoPaginado *N, NodoPaginado *N1)
{
    NodoPaginado *N2;

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

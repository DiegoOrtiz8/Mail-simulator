#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H
#include <iostream>
#include <stdexcept> //Lanzar excepciones

using namespace std;

template<typename T> //Definicion de una plantilla
class ListaEstatica
{
public:
    //Constructor. Inicializamos index en 0
    ListaEstatica<T>() : index(0){}

    bool empty();
    bool full();
    size_t size();
    void insert(const T& elem);
    void print();
    T& operator[](size_t idx);
    size_t find(const T& elem);
    void remove(size_t idx);

private:
    static const size_t CAPACITY = 1000;
    T elements[CAPACITY];
    size_t index; //size_t es un entero sin signo
};

template<typename T>
bool ListaEstatica<T>::empty()
{
    return index == 0;
}

template<typename T>
bool ListaEstatica<T>::full()
{
    return index == CAPACITY;
}

template<typename T>
size_t ListaEstatica<T>::size()
{
    return index;
}

template<typename T>
void ListaEstatica<T>::insert(const T& elem)
{
    if(full())
        throw invalid_argument("Full list");
    elements[index++]=elem;//Operador de post incremento, primero asigna luego ingrementa

}

template<typename T>
void ListaEstatica<T>::print()
{
    if(empty())
        cout << "Lista Vacia... " << endl;
    for(size_t i=0; i<index; ++i){
        cout << elements[i]<<endl;
    }
}

template<typename T>
T& ListaEstatica<T>::operator[](size_t idx)
{
    if(empty())
        throw invalid_argument("[] on empty list");
    if(idx >= index)
        throw invalid_argument("[] on non existing position ");
    return elements[idx];
}

template<typename T>
size_t ListaEstatica<T>::find(const T &elem)
{
    for(size_t i=0; i<index; ++i){
        if(elements[i]==elem){
            return i;
        }
    }
}

template<typename T>
void ListaEstatica<T>::remove(size_t idx)
{
    if(empty())
        throw invalid_argument("[] on empty list");
    if(idx >= index)
        throw invalid_argument("[] on non existing position ");
    for(size_t i=idx; i<index; ++i){
        elements[idx]=elements[idx+1];
        idx=idx+1;
    }
    --index;
}


#endif // LISTA_ESTATICA_H

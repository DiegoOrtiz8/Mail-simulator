#ifndef LISTASIMPLELIGADA_H
#define LISTASIMPLELIGADA_H
#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

template<typename T>
class ListaSimpleLigada{
public:
    ListaSimpleLigada(){
        listsize = 0;
        listfront = nullptr;
        listback = nullptr;
    }

    ListaSimpleLigada(const ListaSimpleLigada& other)
    {
        listfront = nullptr;
        listback = nullptr;
        listsize = 0;
        //Corregir ahorita
        for(size_t i =0; i < other.size();  ++i)
            push_back(other[i]);
    }

    ListaSimpleLigada& operator =(const ListaSimpleLigada& other){
        listfront = nullptr;
        listback = nullptr;
        listsize = 0;
        for(size_t i = 0; i < other.size(); ++i )
            push_back(other[i]);
        return this;
    }

    ~ListaSimpleLigada(){
        clear();
    }

    bool empty() const;
    size_t size() const;
    void push_front(const T& elem);
    void push_back(const T& elem);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& elem);
    void erase(size_t position);
    void clear();
    void remove(const T& value);
    T& operator [](size_t idx) const;

private:
#include"nodolsl.h"
    size_t listsize;
    Nodolsl* listfront;
    Nodolsl* listback;
};
#endif // LISTASIMPLELIGADA_H

template<typename T>
bool ListaSimpleLigada<T>::empty() const
{
    return listsize == 0;
}

template<typename T>
size_t ListaSimpleLigada<T>::size() const
{
    return listsize;
}

template<typename T>
void ListaSimpleLigada<T>::push_front(const T &elem)
{
    if (empty())
    {
        listfront = new Nodolsl(elem);
        listback = listfront;
    }
    else
    {
        Nodolsl* temp = new Nodolsl(elem, listfront);
        listfront = temp;
    }
    ++listsize;
}

template<typename T>
void ListaSimpleLigada<T>::push_back(const T &elem)
{
    if(empty())
    {
        listfront = new Nodolsl(elem);
        listback = listfront;
    }
    else
    {
        Nodolsl* temp = new Nodolsl(elem);
        listback->siguiente= temp;
        listback = temp;
    }
    ++listsize;
}

template<typename T>
const T &ListaSimpleLigada<T>::front() const
{
    if(empty())
      throw invalid_argument("front() on empty list");

    return listfront->dato;
}

template<typename T>
const T &ListaSimpleLigada<T>::back() const
{
    if(empty())
      throw invalid_argument("back() on empty list");

    return listback->dato;
}

template<typename T>
void ListaSimpleLigada<T>::pop_front()
{
    if(empty())
      throw invalid_argument("pop_front() on empty list");

    Nodolsl* eliminar = listfront;
    listfront = listfront->siguiente;
    delete eliminar;
    eliminar = nullptr;
    --listsize;
}

template<typename T>
void ListaSimpleLigada<T>::pop_back()
{
    if(empty())
      throw invalid_argument("pop_back() on empty list");

    Nodolsl* temp = listfront;
    while(temp->siguiente != nullptr && temp->siguiente != listback)
        temp = temp->siguiente;
    Nodolsl* eliminar = listback;
    listback = temp;
    listback->siguiente = nullptr;
    delete eliminar;
    eliminar = nullptr;
    --listsize;
}

template<typename T>
void ListaSimpleLigada<T>::insert(size_t position, const T &elem)
{
    if(empty())
      throw invalid_argument("insert() on empty list");
    else if(position > listsize)
        throw invalid_argument("insert() on non valid position");
    else if(position == 0)
        push_front(elem);
    else if(position == listsize)
        push_back(elem);
    else
    {
        Nodolsl* temp = listfront;
        for (size_t i=0; i<position - 1; ++i)
            temp = temp->siguiente;
        Nodolsl* nuevo = new Nodolsl(elem, temp->siguiente);
        temp->siguiente = nuevo;
        ++listsize;
    }

}

template<typename T>
void ListaSimpleLigada<T>::erase(size_t position)
{
    if(empty())
      throw invalid_argument("erase() on empty list");
    else if (position >= listsize)
        throw invalid_argument("erase() on non valid argument");
    else if(position == 0)
        pop_front();
    else if(position == listsize - 1)
        pop_back();
    else
    {
        Nodolsl* temp = listfront;
        for(size_t i = 0; i < position - 1; ++i)
            temp = temp->siguiente;
        Nodolsl* eliminar = temp->siguiente;
        temp->siguiente = eliminar->siguiente;//temp->siguiente->siguiente tambien es valido
        delete eliminar;
        eliminar = nullptr;
        --listsize;
    }
}

template<typename T>
void ListaSimpleLigada<T>::clear()
{
    if(!empty())
    {
        for(size_t i = 0;i < listsize; ++i)
            pop_front();
    }
    listfront = nullptr;
    listback = nullptr;
    listsize = 0;
}

template<typename T>
void ListaSimpleLigada<T>::remove(const T &value)
{
    if(empty())
       throw invalid_argument("remove() on empty list");
    Nodolsl* temp = listfront;
    T dato;
    size_t i = 0;
    while(temp != nullptr)
    {
        dato = temp->dato;
        temp = temp->siguiente;
        if(dato == value)
        {
            erase(i);
            --i;
        }
        ++i;
    }
}

template<typename T>
T &ListaSimpleLigada<T>::operator [](size_t idx) const
{
    if(empty())
       throw invalid_argument("[] on empty list");
    else if(idx >= listsize)
        throw invalid_argument("index out of range");
    Nodolsl* temp = listfront;
    for (size_t i = 0; i < idx; ++i)
        temp = temp->siguiente;
    return temp->dato;
}

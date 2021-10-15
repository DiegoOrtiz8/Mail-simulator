#include "correo.h"
#include <iostream>
#include <string>

using namespace std;

Correo::Correo()
{

}

int Correo::getIdentificador() const
{
    return identificador;
}

void Correo::setIdentificador(int value)
{
    identificador = value;
}

string Correo::getRemitente() const
{
    return remitente;
}

void Correo::setRemitente(const string & value)
{
    int longitud = value.size();
    longitud  = (longitud <60 ? longitud: 59);
    value.copy(remitente,longitud);
    remitente[longitud]= '\0';
}

string Correo::getDestinatario() const
{
    return destinatario;
}

void Correo::setDestinatario(const string &value)
{
    int longitud = value.size();
    longitud  = (longitud <100 ? longitud: 99);
    value.copy(destinatario,longitud);
    destinatario[longitud]= '\0';
}

string Correo::getCopia_carbon() const
{
    return copia_carbon;
}

void Correo::setCopia_carbon(const string  &value)
{
    int longitud = value.size();
    longitud = (longitud < 100 ? longitud:99);
    value.copy(copia_carbon,longitud);
    copia_carbon[longitud]= '\0';
}

string Correo::getCopia_carbon_ciega() const
{
    return copia_carbon_ciega;
}

void Correo::setCopia_carbon_ciega(const string &value)
{
    int longitud = value.size();
    longitud = (longitud < 100 ? longitud: 99);
    value.copy(copia_carbon_ciega,longitud);
    copia_carbon_ciega[longitud]='\0';
}

string Correo::getAsunto() const
{
    return asunto;
}

void Correo::setAsunto(const string &value)
{
    int longitud = value.size();
    longitud = (longitud < 100 ? longitud: 99);
    value.copy(asunto,longitud);
    asunto[longitud]='\0';
}

string Correo::getContenido() const
{
    return contenido;
}

void Correo::setContenido(const string &value)
{
    int longitud = value.size();
    longitud = (longitud < 3000 ? longitud: 2999);
    value.copy(contenido,longitud);
    contenido[longitud -1 ]='\0';
}

string Correo::getFecha_hora() const
{
    return fecha_hora;
}

void Correo::setFecha_hora(const string &value)
{
    int longitud = value.size();
    longitud = (longitud < 100 ? longitud: 99);
    value.copy(fecha_hora,longitud);
    fecha_hora[longitud -1 ]='\0';
}

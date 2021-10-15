#ifndef CORREO_H
#define CORREO_H

#include <iostream>
#include <string>
using namespace std;

class Correo
{
public:
    Correo();

    int getIdentificador() const;
    void setIdentificador(int value);

    string getRemitente() const;
    void setRemitente(const string &value);

    string getDestinatario() const;
    void setDestinatario(const string  &value);

    string getCopia_carbon() const;
    void setCopia_carbon(const string  &value);

    string getCopia_carbon_ciega() const;
    void setCopia_carbon_ciega(const string  &value);

    string getAsunto() const;
    void setAsunto(const string  &value);

    string getContenido() const;
    void setContenido(const string  &value);

    string getFecha_hora() const;
    void setFecha_hora(const string  &value);


private:
    int identificador;              // Identificador 10 digitos
    char remitente[60];             // From:
    char destinatario[100];         // To:
    char copia_carbon[100];         // CC:
    char copia_carbon_ciega[100];   // BCC:
    char asunto[100];               // Subject:
    char contenido[3000];           // Contenido
    char fecha_hora[100];           // Fecha correo D/M/A - H/M/S

};

#endif // CORREO_H

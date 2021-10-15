#ifndef INDICE_H
#define INDICE_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "correo.h"
using namespace std;

class Indice
{

public:

    string getClave() const;
    void setClave(const string &value);

    long getPosicion() const;
    void setPosicion(long value);

    friend ostream& operator <<(ostream &out, Indice &i)
    {
        out << "Id: " << i.getClave() << endl << "Posicion: " << i.getPosicion() << endl;

        fstream archivo("Correos.bin", ios::in | ios::binary);
        int id;
        Correo email;

        id = atoi(i.getClave().c_str());
        archivo.seekg((id-1)*sizeof(Correo));
        archivo.read((char*)&email, sizeof(Correo));

        // Informacion
        cout << "\t\tCORREO" << endl
             << "Fecha: " << email.getFecha_hora() << endl
             << "Id: " << email.getIdentificador() << endl
             << "From: " << email.getRemitente() << endl
             << "To: " << email.getDestinatario() << endl
             << "CC: " << email.getCopia_carbon() << endl
             << "BCC: " << email.getCopia_carbon_ciega() << endl
             << "Subject: " << email.getAsunto() << endl
             << "Content: " << email.getContenido() << endl
             << endl;

        archivo.close();

        return out;
    }


private:
    char clave[11];
    long posicion;
};
#endif // INDICE_H

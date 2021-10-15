#include "dispersion.h"

Dispersion::Dispersion()
{

}

int Dispersion::Funcion(char *clave)
{
    char *p;
    unsigned int h = 0, g;
    for (p = clave; *p != '\0'; ++p) {
        h = (h << 4) + (*p);
        g = h&0xF0000000;
        if(g > 1)
        {
            h = h ^ (g << 24);
            h = h ^ g;
        }
    }
    return (h&PRIMO);
}

void Dispersion::add()
{
    // Flujos
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    // Variable objeto
    Correo email;

    char llave[35];
    int posicion;

    if(!archivo.is_open())
        cout << "Error al cargar los correos" << endl;

    else {
        while(!archivo.eof()) {
            archivo.read((char*)&email, sizeof(Correo));

            if(archivo.eof())
                break;

            if(email.getIdentificador() != 0) {
                strcpy(llave, email.getRemitente().c_str());
                posicion = Funcion(llave);
                hashi[posicion].push_back(email);
            }
        }
        archivo.close();
    }
}

void Dispersion::search()
{
    char buscar[35];
    int posicion;
    int cont;

    cout << "\t\tBUSCAR CORREOS UTILIZANDO DISPERSION" << endl << endl;

    cout << "Remitente a buscar: ";
    cin >> buscar;
    system("cls");
    fflush(stdin);
    posicion = Funcion(buscar);

    if(!hashi[posicion].empty()) {
        cont = hashi[posicion].size();
        for (int i = 0; i < cont; i++) {
            if(hashi[posicion][i].getRemitente() == buscar) {
                cout << "Correo encontrado!" << endl << endl;
                cout << "ID: " << hashi[posicion][i].getIdentificador() << endl
                     << "FROM: " << hashi[posicion][i].getRemitente() << endl
                     << "TO: " << hashi[posicion][i].getDestinatario() << endl
                     << "CC: " << hashi[posicion][i].getCopia_carbon() << endl
                     << "BCC: " << hashi[posicion][i].getCopia_carbon_ciega() << endl
                     << "SUBJECT: " << hashi[posicion][i].getAsunto() << endl
                     << "CONTENT: " << hashi[posicion][i].getContenido() << endl
                     << endl;
            }
        }
    }

    else {
        cout << "Correo no encontrado .." << endl << endl;
    }
}

void Dispersion::exportar()
{
    // Flujo al archivo
    ofstream archTabla;

    Correo aux;
    int cont, tam;

    archTabla.open("Serializacion.bin", ios::binary | ios::out);

    //cout << "Archivo Exportado!" << endl << endl;

    if(!archTabla.is_open())
        cout << "Error al abrir el archivo" << endl;

    else {
        cont = 0;
        while(cont < PRIMO) {

            if(hashi[cont].empty())
                cont++;
            else {
                tam = hashi[cont].size();
                for (int i = 0; i < tam; ++i) {
                    aux.setIdentificador(hashi[cont][i].getIdentificador());
                    aux.setRemitente(hashi[cont][i].getRemitente());
                    aux.setDestinatario(hashi[cont][i].getDestinatario());
                    aux.setCopia_carbon(hashi[cont][i].getCopia_carbon());
                    aux.setCopia_carbon_ciega(hashi[cont][i].getCopia_carbon_ciega());
                    aux.setAsunto(hashi[cont][i].getAsunto());
                    aux.setContenido(hashi[cont][i].getContenido());

                    archTabla.write((char*)&aux, sizeof(Correo));
                }
                cont ++;
            }
        }
        archTabla.close();
        cout << endl << "Tabla exportada" << endl;
    }
}

void Dispersion::importar()
{
    // Flujo al archivo
    fstream archTabla;
    Correo email;
    char llave[35];
    int posicion;

    archTabla.open("Serializacion.bin", ios::in | ios::binary);

    while(!archTabla.eof()) {
        archTabla.read((char*)&email, sizeof(Correo));
        if(archTabla.eof())
            break;
        if(strcpy(llave, email.getRemitente().c_str()));
        posicion = Funcion(llave);
        hashi[posicion].push_back(email);
    }

    archTabla.close();

    cout << endl <<"Importar exitoso!" << endl << endl;
}



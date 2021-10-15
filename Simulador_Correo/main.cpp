#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <bits/stdc++.h>
#include <list>
#include <vector>
#include <windows.h>
#include "correo.h"
#include "indice.h"
#include "arbol.h"
#include "arbol2.h"
#include "indicesecundario.h"
#include "indices_paginados.h"
#include "arbol_paginados.h"
#include "dispersion.h"

using namespace std;

// Prototipo de funciones
long CrearCorreo(int);
void LeerCorreo_ID();
void EditarCorreo_ID();
void EliminarCorreo_ID(int);
void LeerCorreo_RE();
void EditarCorreo_RE();
void EliminarCorreo_RE();
void CrearCopia();
void ImportarCopia();
void EditarCorreo_Copia();
void EliminarCorreo_Copia();
void ExportarCorreo_LongitudVariable();
void EditarCorreo_longitudVariable();
void EliminarCorreo_longitudVariable();
void BusquedaCorreo_RAM();
bool ActualizarIndices();
void IndicesPrimarios_AVL();
void IndicesSecundarios();
void IndicesPaginados();
void B_Dispersion();
void ControlCifrado();
bool Cifrado();
bool Descifrado();
void ControlCompresion();
bool Compresion();

string scan(string);

enum Opciones{
    OPC_CREAR=1,                            // Opcion para crear el correo
    OPC_BUSCAR_ID,                          // Opcion para leer el correo por ID
    OPC_EDITAR_ID,                          // Opcion para editar el correo  por ID
    OPC_BUSCAR_REMITENTE,                   // Opcion para leer correo por Remitente
    OPC_EDITAR_REMITENTE,                   // Opcion para editar el correo por Remitente
    OPC_ELIMINAR_ID,                        // Opcion para eliminar correo por ID
    OPC_ELIMINAR_REMITENTE,                 // Opcion para eliminar correo por Remitente
    OPC_CREARCOPIA_CSV,                     // Opcion para crear copia CSV
    OPC_IMPORTARCOPIA_CSV,                  // Opcion para importar informacion de la copia csv
    OPC_EDITAR_CORREO_CSV,                  // Opcion para editar algun correo en la copia csv
    OPC_ELIMINAR_CORREO_CSV,                // Opcion para eliminar correo en la copia csv
    OPC_EXPORTAR_CORREO_LGV,                // Opcion para exportar informacion a Longitud Variable
    OPC_EDITAR_CORREO_LGV,                  // Opcion para leer correo con Longitud Variable
    OPC_ELIMINAR_CORREO_LGV,                // Opcion para eliminar correo en LGV
    OPC_BUSQUEDA_RAM,                       // Opcion para buscar en RAM
    OPC_INDICEPRIMARIO,                     // Opcion para buscar por indice primario
    OPC_INDICESECUNDARIO,                   // Opcion para buscar por indices secundarios
    OPC_INDICESPAGINADOS,                   // Opcion para utilizar indices paginados
    OPC_DISPERSION,                         // Opcion para utilizar dispersion / serializacion
    OPC_CONTROLCIFRAR,                      // Opcion para controlar el cifrado
    OPC_CONTROLCOMPRESION,
    OPC_SALIR=0                             // Opcion para salir del programa
};

int main()
{
    int op; // Var controla el menu
    int id;

    do{
        cout << "\tGESTOR DE CORREO\t\n" << endl;
        cout << " " << OPC_CREAR << ") Crear Correo" << endl
             << " " << OPC_BUSCAR_ID << ") Leer Correo por ID" << endl
             << " " << OPC_EDITAR_ID << ") Editar Correo por ID" << endl
             << " " << OPC_BUSCAR_REMITENTE << ") Leer Correo por Remitente" << endl
             << " " << OPC_EDITAR_REMITENTE << ") Editar Correo por Remitente" << endl
             << " " << OPC_ELIMINAR_ID << ") Eliminar Correo por ID" << endl
             << " " << OPC_ELIMINAR_REMITENTE << ") Eliminar Correo por Remitente" << endl
             << " " << OPC_CREARCOPIA_CSV << ") Crear Copia CSV" << endl
             << " " << OPC_IMPORTARCOPIA_CSV << ") Importar Copia CSV" << endl
             << OPC_EDITAR_CORREO_CSV << ") Editar Correo CSV" << endl
             << OPC_ELIMINAR_CORREO_CSV << ") Eliminar Copia CSV" << endl
             << OPC_EXPORTAR_CORREO_LGV << ") Exportar Correo LGV" << endl
             << OPC_EDITAR_CORREO_LGV << ") Editar Correo LGV" << endl
             << OPC_ELIMINAR_CORREO_LGV << ") Eliminar Correo LGV" << endl
             << OPC_BUSQUEDA_RAM << ") Buscar Correo en RAM" << endl
             << OPC_INDICEPRIMARIO << ") Buscar Utilizando Indices" << endl
             << OPC_INDICESECUNDARIO << ") Buscar Utilizando Indices Secundarios" << endl
             << OPC_INDICESPAGINADOS << ") Indices Paginados" << endl
             << OPC_DISPERSION << ") Dispersion" << endl
             << OPC_CONTROLCIFRAR << ") Cifrado" << endl
             << OPC_CONTROLCOMPRESION << ") Compresion" << endl
             << " " << OPC_SALIR << ") Salir del programa" << endl << endl
             << "Seleccione una opcion: ";
        cin >> op;
        system("cls");
        cout << endl;

        switch (op) {
        case OPC_CREAR:
        {
            cout << "\tCrear nuevo correo\t" << endl << endl
                 << "Ingrese el ID del nuevo correo: ";
            cin >> id;
            cin.ignore();
            CrearCorreo(id);
            system("pause");
            system("cls");
        }break;
        case OPC_BUSCAR_ID:
            LeerCorreo_ID();
            system("pause");
            system("cls");
            break;
        case OPC_EDITAR_ID:
            EditarCorreo_ID();
            system("pause");
            system("cls");
            break;
        case OPC_ELIMINAR_ID:
            cout << "\tELIMINAR CORREO" << endl << endl;
            cout << "Ingresa el ID: ";
            cin >> id;
            cin.ignore();
            EliminarCorreo_ID(id);
            system("pause");
            system("cls");
            break;
        case OPC_BUSCAR_REMITENTE:
            LeerCorreo_RE();
            system("pause");
            system("cls");
            break;
        case OPC_EDITAR_REMITENTE:
            EditarCorreo_RE();
            system("pause");
            system("cls");
            break;
        case OPC_ELIMINAR_REMITENTE:
            EliminarCorreo_RE();
            system("pause");
            system("cls");
            break;
        case OPC_CREARCOPIA_CSV:
            CrearCopia();
            system("pause");
            system("cls");
            break;
        case OPC_IMPORTARCOPIA_CSV:
            ImportarCopia();
            system("pause");
            system("cls");
            break;
        case OPC_EDITAR_CORREO_CSV:
            EditarCorreo_Copia();
            system("pause");
            system("cls");
            break;
        case OPC_ELIMINAR_CORREO_CSV:
            EliminarCorreo_Copia();
            system("pause");
            system("cls");
            break;
        case OPC_EXPORTAR_CORREO_LGV:
            ExportarCorreo_LongitudVariable();
            system("pause");
            system("cls");
            break;
        case OPC_EDITAR_CORREO_LGV:
            EditarCorreo_longitudVariable();
            system("pause");
            system("cls");
            break;
        case OPC_ELIMINAR_CORREO_LGV:
            EliminarCorreo_longitudVariable();
            system("pause");
            system("cls");
            break;
        case OPC_BUSQUEDA_RAM:
            BusquedaCorreo_RAM();
            system("pause");
            system("cls");
            break;
        case OPC_INDICEPRIMARIO:
            IndicesPrimarios_AVL();
            system("pause");
            system("cls");
            break;
        case OPC_INDICESECUNDARIO:
            IndicesSecundarios();
            system("pause");
            system("cls");
            break;
        case OPC_INDICESPAGINADOS:
            IndicesPaginados();
            system("pause");
            system("cls");
            break;
        case OPC_DISPERSION:
            B_Dispersion();
            system("pause");
            system("cls");
            break;
        case OPC_CONTROLCIFRAR:
            ControlCifrado();
            system("pause");
            system("cls");
            break;
        case OPC_CONTROLCOMPRESION:
            ControlCompresion();
            system("pause");
            system("cls");
        case OPC_SALIR:
            break;
        default:
            cout << "Opcion invalida" << endl << endl;
            system("pause");
            system("cls");
        }
    } while(op != OPC_SALIR);

    return 0;

}

//Funcion para convertir un string a cadena de caracteres
string scan(string cadena){

    //Variables
    string value(cadena);
    string::size_type pos = 0;

    string from = ("\"");
    string to = "\"\"";

    while((pos = value.find(from,pos)) < string::npos){
        value.replace(pos, from.length(), to);
        pos += to.size();
    }

    return value;
}

long CrearCorreo(int identificador)
{
    // Obtener fecha y hora actual
    time_t now = time(0);
    string date;
    date = ctime(&now);

    // Creacion archivo
    fstream archivo("Correos.bin", ios::binary | ios::in | ios::out);
    if(!archivo.is_open()) {
        //cout << "El archivo no se puede abrir" << endl;
        archivo.open("Correos.bin", ios::out);
    }

    // Crear nuevo flujo para actualizar bandera
    fstream salida("indices.bin", ios::binary | ios::out | ios::in);
    if(!salida) {
        cout << "Error en el archivo" << endl;
        return 0;
    }

    fflush(stdin);

    // Objeto de la clase Correo
    Correo email;

    int id;
    long posicion;
    string remitente;
    string destinatario;
    string Asunto = " ";
    string Contenido = " ";
    string Copia_Carbon = " ";
    string Copia_Carbon_Ciega = " ";
    string renglon = " ";

    id = identificador;
    archivo.seekg( (id - 1) * sizeof(Correo) );
    archivo.read((char *)&email, sizeof(Correo) );

    if(email.getIdentificador() != id && id != 0) {
        email.setIdentificador(id);
        fflush(stdin);

        cout << "From: ";
        getline(cin, remitente);
        email.setRemitente(remitente);
        fflush(stdin);

        cout << "To: ";
        getline(cin, destinatario);
        email.setDestinatario(destinatario);
        fflush(stdin);

        cout << "CC: ";
        getline(cin, Copia_Carbon);
        email.setCopia_carbon(Copia_Carbon);
        fflush(stdin);

        cout << "BCC: ";
        getline(cin, Copia_Carbon_Ciega);
        email.setCopia_carbon_ciega(Copia_Carbon_Ciega);
        fflush(stdin);

        cout << "Subject: ";
        getline(cin, Asunto);
        email.setAsunto(Asunto);
        fflush(stdin);

        email.setFecha_hora(date);
        fflush(stdin);

        cout << endl;
        cout << "Pulse Ctrl + Z + Enter para finalizar de escribir" << endl;
        cout << "Contenido: " << endl;
        while(getline(cin, renglon)) {
            Contenido += renglon + "\n";
        }
        email.setContenido(Contenido);
        cin.clear();

        system("cls");

        // Escribir Archivo
        archivo.seekp( (id - 1) * sizeof(Correo) );
        posicion = archivo.tellg();
        archivo.write( (const char *)&email, sizeof(Correo) );

        // Actualizar bandera de cambio
        int bandera = 1;
        salida.write((const char*)&bandera, sizeof(int));

        cout << endl;
        cout << "Correo creado" << endl << endl
             << "Fecha: " << email.getFecha_hora() << endl
             << "ID: " << email.getIdentificador() << endl
             << "From: " << email.getRemitente() << endl
             << "To: " << email.getDestinatario() << endl
             << "CC: " << email.getCopia_carbon() << endl
             << "BBC: " << email.getCopia_carbon_ciega() << endl
             << "Subject: " << email.getAsunto() << endl
             << "Content: " << email.getContenido() << endl;
        cout << endl;
    }
    else {
        cout << endl << "No es posible crear, ID existente" << endl << endl;
    }
    salida.close();
    archivo.close();

    return posicion;
}

void LeerCorreo_ID()
{
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    Correo email;
    int id;

    system("cls");
    cout << "\tLEER CORREO\t" << endl << endl;
    cout << "Ingrese el ID del correo a leer: ";
    cin >> id;
    cout << endl;

    // Comprobar si existe el id
    archivo.clear();
    archivo.seekg( (id - 1) * sizeof(Correo) );
    archivo.read((char*)&email, sizeof(Correo));

    if(email.getIdentificador() == id && id != 0) {
        cout << "Correo encontrado" << endl << endl
             << "Fecha: " << email.getFecha_hora() << endl
             << "ID: " << email.getIdentificador() << endl
             << "From: " << email.getRemitente() << endl
             << "To: " << email.getDestinatario() << endl
             << "CC: " << email.getCopia_carbon() << endl
             << "BBC: " << email.getCopia_carbon_ciega() << endl
             << "Subject: " << email.getAsunto() << endl
             << "Content: " << email.getContenido() << endl;
    }
    else {
        cout << "No se encontro el correo" << endl;
    }
    cout << endl;
    archivo.close();
}

void EditarCorreo_ID()
{
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    fstream salida;
    salida.open("indices.bin", ios::in | ios::out | ios::binary);

    Correo email;
    string opc;
    int bandera = 0;

    int id;
    string remitente;
    string destinatario;
    string Asunto =" ";
    string Contenido = " ";
    string Copia_Carbon = " ";
    string Copia_Carbon_Ciega = " ";
    string renglon;

    cout << "\tEDITAR CORREO\t" << endl << endl
         << "Ingrese el ID del correo a buscar: ";
    cin >> id;
    cout << endl;
    cin.ignore();

    //Lector de archivo para comparar si ya existe dicho ID
    archivo.seekg( (id - 1) * sizeof(Correo) );
    archivo.read( (char *)&email ,  sizeof(Correo) );

    if(email.getIdentificador() == id && id != 0) {
        bandera = 1;
        cout << "Correo encontrado!" << endl
             << "1) Modificar FROM" << endl
             << "2) Modificar TO" << endl
             << "3) Modificar CC" << endl
             << "4) Modificar BBC" << endl
             << "5) Modificar Subject" << endl
             << "6) Modificar Content" << endl
             << "7) Salir" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        getline(cin, opc);

        if(opc == "1") {
            cout << "FROM: ";
            getline(cin, remitente);
            email.setRemitente(remitente);
        }
        else if(opc == "2") {
            cout << "To: ";
            getline(cin, destinatario);
            email.setDestinatario(destinatario);
        }
        else if(opc == "3") {
            cout << "CC: ";
            getline(cin, Copia_Carbon);
            email.setCopia_carbon(Copia_Carbon);
        }
        else if(opc == "4") {
            cout << "BCC: ";
            getline(cin, Copia_Carbon_Ciega);
            email.setCopia_carbon_ciega(Copia_Carbon_Ciega);
        }
        else if(opc == "5") {
            cout << "Subject: ";
            getline(cin, Asunto);
            email.setAsunto(Asunto);
        }
        else if(opc == "6") {
            cout << "Pulse Ctrl + Z + Enter para finalizar de escribir" << endl;
            cout << "Contenido: " << endl;
            while(getline(cin, renglon)) {
                Contenido += renglon + "\n";
            }
            email.setContenido(Contenido);
            cin.clear();
        }
        else {
            cout << endl;
        }

        if(bandera == 1) {
            archivo.seekp( (id - 1) * sizeof(Correo) );
            archivo.write( (const char *)&email, sizeof(Correo) );
            cout << endl << "Correo editado!" << endl;
        }

        int bandera_indice = 1;
        salida.write((const char *)&bandera_indice, sizeof(int));
    }
    else {
        cout << "No se encontro el correo a editar..." << endl;
    }
    salida.close();
    archivo.close();
}

void EliminarCorreo_ID(int id)
{
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    fstream salida;
    salida.open("indices.bin", ios::in | ios::out | ios::binary);

    //int opc = 0;
    int bandera = 0;

    // Objeto de la clase Correo
    Correo email;

    // Variables
    int id_aux = 0;
    string remitente =" ";
    string destinatario =" ";
    string Asunto =" ";
    string Contenido = " ";
    string Copia_Carbon = " ";
    string Copia_Carbon_Ciega = " ";
    string Fecha_Hora = " ";

    // Lectura para comprobar que exista el ID
    archivo.clear();
    archivo.seekg( (id - 1) * sizeof(Correo) );
    archivo.read( (char *)&email ,  sizeof(Correo) );
    cout << endl;

    if(email.getIdentificador() == id && id != 0) {
        cout << "Correo encontrado" << endl << endl
             << "Fecha: " << email.getFecha_hora() << endl
             << "ID: " << email.getIdentificador() << endl
             << "From: " << email.getRemitente() << endl
             << "To: " << email.getDestinatario() << endl
             << "CC: " << email.getCopia_carbon() << endl
             << "BBC: " << email.getCopia_carbon_ciega() << endl
             << "Subject: " << email.getAsunto() << endl
             << "Content: " << email.getContenido() << endl << endl;

        cout << endl;

        email.setIdentificador(id_aux);
        email.setAsunto(Asunto);
        email.setContenido(Contenido);
        email.setCopia_carbon(Copia_Carbon);
        email.setCopia_carbon_ciega(Copia_Carbon_Ciega);
        email.setDestinatario(destinatario);
        email.setFecha_hora(Fecha_Hora);
        email.setRemitente(remitente);
        bandera = 1;

        if(bandera == 1) {
            archivo.clear();
            archivo.seekp((id -1) * sizeof(Correo));
            archivo.write((const char *)&email, sizeof(Correo));

            cout << "Correo eliminado!" << endl << endl;

            int bandera_indice = 1;
            salida.write((const char *)&bandera_indice, sizeof(int));
        }
    }
    else {
        cout << "No se encontro el correo, intente otro ID" << endl;
    }
    salida.close();
    archivo.close();
}

void LeerCorreo_RE()
{
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    Correo email;
    int opc, pos = 0, bandera = 0;

    // Variable para buscar
    string remitente = " ";
    string remitente_aux = " ";

    cout << "\tLEER POR REMITENTE\t" << endl << endl;

    cout << "Ingrese el remitente a buscar: ";
    getline(cin, remitente);
    cout << endl;

    while(bandera != 1) {
        // Lectura del correo
        archivo.clear();
        archivo.seekg( pos * sizeof(Correo) );
        archivo.read( (char *)&email ,  sizeof(Correo) );

        if(email.getRemitente() == remitente && remitente_aux != email.getRemitente() && email.getIdentificador() != 0) {
            cout << "Correo encontrado" << endl << endl
                  << "Fecha: " << email.getFecha_hora() << endl
                  << "ID: " << email.getIdentificador() << endl
                  << "From: " << email.getRemitente() << endl
                  << "To: " << email.getDestinatario() << endl
                  << "CC: " << email.getCopia_carbon() << endl
                  << "BBC: " << email.getCopia_carbon_ciega() << endl
                  << "Subject: " << email.getAsunto() << endl
                  << "Content: " << email.getContenido() << endl << endl;

            cout << "Puede que existan mas correos con el mismo remitente" << endl
                 << "Desea continuar? 1-SI || 2-NO ";
            cin >> opc;
            system("cls");
            cout << endl;
            if(opc == 1) {
                pos += 1;
                remitente_aux = email.getRemitente();
                if(archivo.eof()) {
                    bandera = 1;
                    cout << "No se encontraron mas correos" << endl;
                }
            }
            else if(opc == 2) {
                bandera = 1;
            }
            else {
                cout << "Opcion no valida" << endl;
            }
            archivo.clear();
        }
        else {
            pos += 1;
            remitente_aux = email.getRemitente();
            if(archivo.eof()) {
                bandera = 1;
                cout << "No se encontro el correo" << endl;
            }
        }
    }
    archivo.close();
}

void EditarCorreo_RE()
{
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    fstream salida;
    salida.open("indices.bin", ios::in | ios::out | ios::binary);

    int bandera = 0;
    int bandera_ed = 0;
    int pos = 0;
    string opc;
    string remitente = " ";

    Correo email;

    //Variables
    string destinatario;
    string Asunto =" ";
    string Contenido = " ";
    string Copia_Carbon = " ";
    string Copia_Carbon_Ciega = " ";
    string renglon;

    cout << "\tEDITAR CORREO POR REMITENTE\t" << endl << endl;

    cout << "Ingrese el remitente a buscar: ";
    getline(cin, remitente);
    cout << endl;

    while(bandera != 1) {
        // Lectura del correo
        archivo.clear();
        archivo.seekg( pos * sizeof(Correo) );
        archivo.read( (char *)&email ,  sizeof(Correo) );

        if(email.getRemitente() == remitente && email.getIdentificador() != 0) {
            bandera = 1;
            bandera_ed = 1;
            cout << "Correo encontrado" << endl << endl
                 << "Fecha: " << email.getFecha_hora() << endl
                 << "ID: " << email.getIdentificador() << endl
                 << "From: " << email.getRemitente() << endl
                 << "To: " << email.getDestinatario() << endl
                 << "CC: " << email.getCopia_carbon() << endl
                 << "BBC: " << email.getCopia_carbon_ciega() << endl
                 << "Subject: " << email.getAsunto() << endl
                 << "Content: " << email.getContenido() << endl << endl;
            archivo.clear();

            cout << "1) Modificar FROM" << endl
                 << "2) Modificar TO" << endl
                 << "3) Modificar CC" << endl
                 << "4) Modificar BBC" << endl
                 << "5) Modificar Subject" << endl
                 << "6) Modificar Content" << endl
                 << "7) Salir" << endl;
            cout << endl;
            cout << "Seleccione una opcion: ";
            getline(cin, opc);
            cout << endl;

            if(opc == "1") {
                cout << "FROM: ";
                getline(cin, remitente);
                email.setRemitente(remitente);
            }
            else if(opc == "2") {
                cout << "To: ";
                getline(cin, destinatario);
                email.setDestinatario(destinatario);
            }
            else if(opc == "3") {
                cout << "CC: ";
                getline(cin, Copia_Carbon);
                email.setCopia_carbon(Copia_Carbon);
            }
            else if(opc == "4") {
                cout << "BCC: ";
                getline(cin, Copia_Carbon_Ciega);
                email.setCopia_carbon_ciega(Copia_Carbon_Ciega);
            }
            else if(opc == "5") {
                cout << "Subject: ";
                getline(cin, Asunto);
                email.setAsunto(Asunto);
            }
            else if(opc == "6") {
                cout << "Pulse Ctrl + Z + Enter para finalizar de escribir" << endl;
                cout << "Contenido: " << endl;
                while(getline(cin, renglon)) {
                    Contenido += renglon + "\n";
                }
                email.setContenido(Contenido);
                cin.clear();
            }
            else {
                bandera = 1;
            }
        }
        else {
            pos += 1;
            if(archivo.eof()) {
                bandera = 1;
                cout << "No se encontro el correo" << endl;
                archivo.clear();
            }
        }
    }
    // Escribiendo los datos
    if(bandera_ed ==1){
        //Escritura de archivos
        archivo.clear();
        archivo.seekp( pos * sizeof(Correo) );
        archivo.write( (const char *)&email, sizeof(Correo) );
       cout << endl <<"Correo Editado" << endl << endl;

       int bandera_indices = 1;
       salida.write((const char *)&bandera_indices, sizeof(int));

    }
    salida.close();
    archivo.close();
}

void EliminarCorreo_RE()
{
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    fstream salida;
    salida.open("indices.bin", ios::in | ios::out | ios::binary);

    int opc=0;
    int bandera=0;
    int bandera_el=0;
    int pos=0;
    string remitente_aux = " ";

    //Objeto
    Correo email;

    //Variables
    int id_aux = 0;
    string remitente =" ";
    string destinatario =" ";
    string Asunto =" ";
    string Contenido = " ";
    string Copia_Carbon = " ";
    string Copia_Carbon_Ciega = " ";
    string Fecha_Hora = " ";

    cout << "\tELIMINAR CORREO POR REMITENTE\t" << endl << endl;

    cout << "Ingrese el remitente a buscar: ";
    getline(cin, remitente_aux);
    cout << endl;

    while(bandera != 1) {

        // Lectura del correo
        archivo.clear();
        archivo.seekg( pos * sizeof(Correo) );
        archivo.read( (char *)&email ,  sizeof(Correo) );

        if(email.getRemitente() == remitente_aux && email.getIdentificador() != 0) {
            bandera = 1;
            bandera_el = 1;
            cout << "Correo encontrado" << endl << endl
                 << "Fecha: " << email.getFecha_hora() << endl
                 << "ID: " << email.getIdentificador() << endl
                 << "From: " << email.getRemitente() << endl
                 << "To: " << email.getDestinatario() << endl
                 << "CC: " << email.getCopia_carbon() << endl
                 << "BBC: " << email.getCopia_carbon_ciega() << endl
                 << "Subject: " << email.getAsunto() << endl
                 << "Content: " << email.getContenido() << endl << endl;

            cout << "Desea eliminar este correo?" << endl;
            cout << "1-SI || 2-NO: ";
            cin >> opc;
            cout << endl;

            if(opc == 1) {
                email.setIdentificador(id_aux);
                email.setAsunto(Asunto);
                email.setContenido(Contenido);
                email.setCopia_carbon(Copia_Carbon);
                email.setCopia_carbon_ciega(Copia_Carbon_Ciega);
                email.setDestinatario(destinatario);
                email.setFecha_hora(Fecha_Hora);
                email.setRemitente(remitente);
                bandera = 1;
            }
            else {
                cout << "No se ha eliminado el correo" << endl << endl;
            }
        }
        else {
            pos += 1;
            if (archivo.eof()) {
                bandera = 1;
                cout << "No se encontro el correo" << endl;
                archivo.clear();
            }
        }
    }

    // Escribiendo los datos
    if(bandera_el == 1){
        //Escritura de archivos
        archivo.clear();
        archivo.seekp( pos * sizeof(Correo) );
        archivo.write( (const char *)&email, sizeof(Correo) );
       cout <<"Correo eliminado" << endl;

       // Actualizar bandera indices
       int bandera_indices = 1;
       salida.write((const char *)&bandera_indices, sizeof(int));
    }
    salida.close();
    archivo.close();
}

void CrearCopia()
{
    // Creacion de Flujo
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    // Objeto de la clase Correo
    Correo email;

    // Variables
    int posicion = 0;
    int bandera = 0;
    int id_aux = 0;
    int opc;

    // Flujo del archivo CSV
    ofstream copia;
    copia.open("Copia.csv");
    copia << " ID " << ","  << " FECHA " << ","<< " FROM " << "," << " TO " << ","
          << " CC " << "," << " BCC " << "," << " SUBJECT " << "," << " CONTENT " << endl;

    while(bandera != 1) {
        // Lectura del correo
        archivo.clear();
        archivo.seekg( posicion * sizeof(Correo) );
        archivo.read( (char *)&email, sizeof(Correo));

        if(email.getIdentificador() != 0 && id_aux != email.getIdentificador()) {
            // Pasar la informacion al csv
            copia << email.getIdentificador() << ',';
            copia << '"' << email.getFecha_hora() << '"' << ',';
            copia << email.getRemitente() << ',';
            copia << email.getDestinatario() << ',';
            copia << email.getCopia_carbon() << ',';
            copia << email.getCopia_carbon_ciega() << ',';
            copia << email.getAsunto() << ',';
            copia << '"' << scan(email.getContenido()) << '"' << endl;

            opc = 1;
            if(opc == 1) {
                posicion += 1;
                id_aux = email.getIdentificador();
                if(archivo.eof()) {
                    bandera = 1;
                    cout << endl;
                    cout << "Copia CSV fallida" << endl;

                }
            }
            archivo.clear();
        }
        else {
            posicion += 1;
            id_aux = email.getIdentificador();
            if(archivo.eof()) {
                bandera = 1;
                cout << endl;
                cout << "Copia CSV creada!!" << endl << endl;
            }
        }
    }
    copia.close();
    archivo.close();
}

void ImportarCopia()
{
    // Creacion del flujo de csv copia
    fstream LeerCopia("Copia.csv", ios::in);

    // Creacion del flujo del archivo aux
    fstream EscribirCopia("temporal.bin", ios::out | ios::binary);

    // Creacion del flujo de indices
    fstream salida;
    salida.open("indices.bin", ios::in | ios::out | ios::binary);

    Correo email;         // Objeto para guardar y escribir
    Correo email_blanco;  // Objeto para guardar info previa

    int id;
    int contador = 0;
    char caracter;
    string cadena;
    string cadena_aux;

    // Verificar que se abra el archivo
    if(!LeerCopia || !EscribirCopia) {
        cout << endl;
        cout << "Importacion del archivo CSV fallida" << endl;
        return;
    }
    else {
        // Leer encabezado
        getline(LeerCopia, cadena, '\n');

        // Leer el archivo Copia.csv
        while(!LeerCopia.eof()) {
            contador ++;
            int posicion = 0;

            // Leer ID
            getline(LeerCopia, cadena, ',');
            id = atoi(cadena.c_str());

            if(contador != id) {
                int numero;
                numero = id - contador;
                for (int i = 0; i < numero; ++i) {
                    email_blanco.setIdentificador(0);
                    EscribirCopia.write((char*)&email_blanco, sizeof(Correo));
                }
                contador = id;
            }

            // Guardar ID
            email.setIdentificador(id);

            // Leer y guardar fecha y hora
            getline(LeerCopia, cadena, ',');
            email.setFecha_hora(cadena);

            // Leer el resto de los campos
            do {
                LeerCopia.get(caracter);
                if(caracter == '"') {
                    cadena_aux = "";
                    do {
                        getline(LeerCopia, cadena, '"');
                        cadena_aux +=  cadena;

                        LeerCopia.get(caracter);
                        if(caracter == '"') {
                            cadena_aux += '"';
                        }
                    } while(caracter == '"');
                }
                else {
                    // Concatenacion de toda la casilla
                    getline(LeerCopia, cadena, ',');
                    cadena_aux = caracter + cadena;
                }

                // Guardar Remitente
                if(posicion == 0)
                    email.setRemitente(cadena_aux);

                // Guardar Destinatario
                else if(posicion == 1)
                    email.setDestinatario(cadena_aux);

                // Guardar CC
                else if(posicion == 2)
                    email.setCopia_carbon(cadena_aux);

                // Guardar BCC
                else if(posicion == 3)
                    email.setCopia_carbon_ciega(cadena_aux);

                // Guardar Asunto
                else if(posicion == 4)
                    email.setAsunto(cadena_aux);

                // Guardar Contenido
                else if(posicion == 5) {
                    email.setContenido(cadena_aux);
                }

                posicion ++;
            } while(posicion < 6);

            EscribirCopia.write((char *)&email, sizeof(Correo));
            if(LeerCopia.eof()) {
                break;
            }
        }
    }

    // Flag indices
    int bandera_indices = 1;
    salida.write((const char *)&bandera_indices, sizeof(int));
    salida.close();

    // Cierre flujo CSV Copia (Lectura)
    LeerCopia.close();

    // Cierre flujo CSV .bin (Escritura)
    EscribirCopia.close();

    // Limpieza
    remove("Correos.bin");
    rename("temporal.bin", "Correos.bin");
    remove("temporal.bin");

    cout << "Importacion CSV exitosa!" << endl << endl;
}

void EditarCorreo_Copia()
{
    // Creacion del flujo de csv copia
    fstream LeerCopia("Copia.csv", ios::in);

    // Creacion del flujo de csv aux
    fstream EscribirCopia("temporal.csv", ios::out);

    Correo email;

    int id;
    int id_aux;
    int contador = 0;
    int bandera = 0;

    char caracter;

    string cadena;
    string cadena_aux;

    if(!LeerCopia || !EscribirCopia) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    else {
        cout << "Editar Correo CSV" << endl << endl;

        cout << "Ingrese el ID: ";
        cin >> id;
        cout << endl;

        EscribirCopia << " ID " << ","  << " FECHA " << ","<< " FROM " << "," << " TO " << ","
                      << " CC " << "," << " BCC " << "," << " SUBJECT " << "," << " CONTENT " << endl;

        // Lee el encabezado de copia, pero no lo almacena
        getline(LeerCopia, cadena, '\n');


        // Lectura del archivo
        while(!LeerCopia.eof()) {
            contador ++;
            int posicion = 0;

            // Guardar Id
            getline(LeerCopia, cadena, ',');
            id_aux = atoi(cadena.c_str());
            email.setIdentificador(id_aux);

            // Guardar Fecha y hora
            getline(LeerCopia, cadena, ',');
            email.setFecha_hora(cadena);

            // Guardar los demas campos
            do {
                // Leer por caracteres
                LeerCopia.get(caracter);
                if(caracter == '"') {
                    cadena_aux = "";
                    do {
                        getline(LeerCopia, cadena, '"');
                        cadena_aux += cadena;
                        LeerCopia.get(caracter);
                        if(caracter == '"') {
                            cadena += '"';
                        }
                    } while(caracter == '"');
                }
                else {
                    // Concatenacion de todo el campo
                    getline(LeerCopia, cadena, ',');
                    cadena_aux = caracter + cadena;
                }

                // Guardar remitente
                if(posicion == 0)
                    email.setRemitente(cadena_aux);

                // Guardar destinatario
                if(posicion == 1)
                    email.setDestinatario(cadena_aux);

                // Guardar CC
                if(posicion == 2)
                    email.setCopia_carbon(cadena_aux);

                // Guardar BCC
                if(posicion == 3)
                    email.setCopia_carbon_ciega(cadena_aux);

                // Guardad Asunto
                if(posicion == 4)
                    email.setAsunto(cadena_aux);

                if(posicion == 5)
                    email.setContenido(cadena_aux);

                posicion ++;
            } while(posicion < 6);

            // Editor de Correo
            if(email.getIdentificador() == id && id != 0) {
                string opc;
                string renglon = "";
                string destinatario;
                string Copia_Carbon;
                string Copia_Carbon_Ciega;
                string Asunto;
                string Contenido;


                // Informacion del correo encontrado
                bandera = 1;
                cout << "Correo encontrado" << endl << endl
                     << "Fecha: " << email.getFecha_hora() << endl
                     << "ID: " << email.getIdentificador() << endl
                     << "From: " << email.getRemitente() << endl
                     << "To: " << email.getDestinatario() << endl
                     << "CC: " << email.getCopia_carbon() << endl
                     << "BBC: " << email.getCopia_carbon_ciega() << endl
                     << "Subject: " << email.getAsunto() << endl
                     << "Content: " << email.getContenido() << endl << endl;

                // Elegir el dato a modificar
                cout << "1) Modificar TO" << endl
                     << "2) Modificar CC" << endl
                     << "3) Modificar BBC" << endl
                     << "4) Modificar Subject" << endl
                     << "5) Modificar Content" << endl
                     << "6) Salir" << endl;
                cout << endl;
                fflush(stdin);
                cout << "Seleccione una opcion: ";
                getline(cin, opc);
                cout << endl;
                fflush(stdin);

                if(opc == "1") {
                    cout << "To: ";
                    getline(cin, destinatario);
                    email.setDestinatario(destinatario);
                }
                else if(opc == "2") {
                    cout << "CC: ";
                    getline(cin, Copia_Carbon);
                    email.setCopia_carbon(Copia_Carbon);
                }
                else if(opc == "3") {
                    cout << "BCC: ";
                    getline(cin, Copia_Carbon_Ciega);
                    email.setCopia_carbon_ciega(Copia_Carbon_Ciega);
                }
                else if(opc == "4") {
                    cout << "Subject: ";
                    getline(cin, Asunto);
                    email.setAsunto(Asunto);
                }
                else if(opc == "5") {
                    fflush(stdin);
                    cout << "Pulse Ctrl + Z + Enter para finalizar de escribir" << endl;
                    cout << "Contenido: " << endl;
                    while(getline(cin, renglon)) {
                        Contenido += renglon + "\n";
                    }
                    email.setContenido(Contenido);
                    cin.clear();
                }

                EscribirCopia << email.getIdentificador() << ',';
                EscribirCopia << '"' << scan(email.getFecha_hora()) << '"' << ',';
                EscribirCopia << email.getRemitente() << ',';
                EscribirCopia << email.getDestinatario() <<',';
                EscribirCopia << email.getCopia_carbon() <<',';
                EscribirCopia << email.getCopia_carbon_ciega() << ',';
                EscribirCopia << email.getAsunto() << ',';
                EscribirCopia << '"' << scan(email.getContenido()) << '"' << endl;
            }
            else if(email.getIdentificador() != 0) {
                EscribirCopia << email.getIdentificador() << ',';
                EscribirCopia << '"' << scan(email.getFecha_hora()) << '"' << ',';
                EscribirCopia << email.getRemitente() << ',';
                EscribirCopia << email.getDestinatario() <<',';
                EscribirCopia << email.getCopia_carbon() <<',';
                EscribirCopia << email.getCopia_carbon_ciega() << ',';
                EscribirCopia << email.getAsunto() << ',';
                EscribirCopia << '"' << scan(email.getContenido()) << '"'<< endl;
            }

            if(LeerCopia.eof())
                break;
        }

        if(bandera == 0) {
            cout << endl << "Correo no encontrado!" << endl;
        }

    }

    LeerCopia.close();

    EscribirCopia.close();

    // Limpieza
    remove("Copia.csv");
    rename("temporal.csv", "Copia.csv");
    remove("temporal.csv");
}

void EliminarCorreo_Copia()
{
    // Creacion del flujo de csv copia
    fstream LeerCopia("Copia.csv", ios::in);

    // Creacion del flujo de csv aux
    fstream EscribirCopia("temp.csv", ios::out);

    Correo email;
    int id;
    int id_aux;
    int contador = 0;
    int bandera = 0;
    char caracter;
    string cadena;
    string cadena_aux;


    if(!LeerCopia || !EscribirCopia) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    else {
        cout << endl << "Eliminar Correo CSV" << endl << endl;

        cout << "Ingrese el ID: ";
        cin >> id;

        // Escribir encabezado en la copia original
        EscribirCopia << " ID " << ","  << " FECHA " << ","<< " FROM " << "," << " TO " << ","
                      << " CC " << "," << " BCC " << "," << " SUBJECT " << "," << " CONTENT " << endl;

        // Lee el encabezado, pero no lo alamcena
        getline(LeerCopia, cadena, '\n');

        // Leer todo el archivo
        while(!LeerCopia.eof()) {
            contador ++;
            int posicion = 0;

            // Leer y guardar Id
            getline(LeerCopia, cadena, ',');
            id_aux = atoi(cadena.c_str());
            email.setIdentificador(id_aux);

            // Leer y guardar fecha y hora
            getline(LeerCopia, cadena, ',');
            email.setFecha_hora(cadena);

            // Leer demas campos
            do {
                // Lectura por caracteres
                LeerCopia.get(caracter);
                if(caracter == '"') {
                    cadena_aux = "";
                    do {
                        getline(LeerCopia, cadena, '"');
                        cadena_aux += cadena;
                        LeerCopia.get(caracter);
                        if(caracter == '"') {
                            cadena += '"';

                        }
                    } while(caracter == '"');
                }
                else {
                    // Concatenacion de todo el campo
                    getline(LeerCopia, cadena, ',');
                    cadena_aux = caracter + cadena;
                }

                if(posicion == 0)
                    email.setRemitente(cadena_aux);
                if(posicion == 1)
                    email.setDestinatario(cadena_aux);
                if(posicion == 2)
                    email.setCopia_carbon(cadena_aux);
                if(posicion == 3)
                    email.setCopia_carbon_ciega(cadena_aux);
                if(posicion == 4)
                    email.setAsunto(cadena_aux);
                if(posicion == 5)
                    email.setContenido(cadena_aux);
                posicion ++;
            } while(posicion < 6);


            // Editor de correo
            if(email.getIdentificador() == id && id != 0) {
                string opc;
                fflush(stdin);

                // Inf. correo leido
                cout << "Correo encontrado" << endl << endl
                     << "Fecha: " << email.getFecha_hora() << endl
                     << "ID: " << email.getIdentificador() << endl
                     << "From: " << email.getRemitente() << endl
                     << "To: " << email.getDestinatario() << endl
                     << "CC: " << email.getCopia_carbon() << endl
                     << "BBC: " << email.getCopia_carbon_ciega() << endl
                     << "Subject: " << email.getAsunto() << endl
                     << "Content: " << email.getContenido() << endl << endl;

                cout << "Desea eliminar este correo? [1 - Si] [2 - No] ";
                getline(cin, opc);
                cout << endl;

                fflush(stdin);

                if(opc == "1") {
                    cout << endl << "Este correo se eliminara.." << endl << endl;
                    bandera = 1;
                }

                else if(opc == "2") {
                    EscribirCopia << email.getIdentificador() << ',';
                    EscribirCopia << '"' << scan(email.getFecha_hora()) << '"' << ',';
                    EscribirCopia << email.getRemitente() << ',';
                    EscribirCopia << email.getDestinatario() <<',';
                    EscribirCopia << email.getCopia_carbon() <<',';
                    EscribirCopia << email.getCopia_carbon_ciega() << ',';
                    EscribirCopia << email.getAsunto() << ',';
                    EscribirCopia << '"' << scan(email.getContenido()) << '"'<< endl;
                }
                else {
                    cout << "Opcion no valida" << endl;
                }
            }

            else if(email.getIdentificador() != 0 && email.getIdentificador() != id) {
                EscribirCopia << email.getIdentificador() << ',';
                EscribirCopia << '"' << scan(email.getFecha_hora()) << '"' << ',';
                EscribirCopia << email.getRemitente() << ',';
                EscribirCopia << email.getDestinatario() <<',';
                EscribirCopia << email.getCopia_carbon() <<',';
                EscribirCopia << email.getCopia_carbon_ciega() << ',';
                EscribirCopia << email.getAsunto() << ',';
                EscribirCopia << '"' << scan(email.getContenido()) << '"'<< endl;
            }

            if(LeerCopia.eof())
                break;
        }    
    }

    if (id == 0 || bandera != 1) {
        cout << endl << "Eliminacion fallida" << endl;
        return;
    }

    LeerCopia.close();

    EscribirCopia.close();

    remove("Copia.csv");
    rename("temp.csv", "Copia.csv");
    remove("temp.csv");

}

void ExportarCorreo_LongitudVariable()
{

    // Correos.bin
    fstream archivo;
    archivo.open("Correos.bin", ios::in | ios::out | ios::binary);

    // Correos_lgv.bin
    ofstream archivo_salida;
    archivo_salida.open("Correos_lgv.bin", ios::out | ios::binary);

    Correo email;

    int pos = 1;
    int id_aux2;

    // Variables con los tamaños
    int tam_rem;
    int tam_dest;
    int tam_cc;
    int tam_bcc;
    int tam_asu;
    int tam_cont;
    int tam_fecha;

    // Leer correos
    while (!archivo.eof()) {
        archivo.clear();
        archivo.seekg((pos - 1) * sizeof(Correo));
        archivo.read((char *)&email, sizeof(Correo));

        // Variables para almacenar los datos
        int id_aux = email.getIdentificador();
        string remitente_aux = email.getRemitente();
        string destinatario_aux = email.getDestinatario();
        string cc_aux = email.getCopia_carbon();
        string bcc_aux = email.getCopia_carbon_ciega();
        string asunto_aux = email.getAsunto();
        string contenido_aux = email.getContenido();
        string fechaHora_aux = email.getFecha_hora();

        if(email.getIdentificador() != 0 && email.getIdentificador() != id_aux2) {

            //Lectura
            cout << "\tCORREO" << endl
                 << "FECHA: " << fechaHora_aux << endl
                 << "ID: " << id_aux << endl
                 << "FROM: " << remitente_aux << endl
                 << "TO: " << destinatario_aux << endl
                 << "CC: " << cc_aux << endl
                 << "BCC: " << bcc_aux << endl
                 << "SUBJECT: " << asunto_aux << endl
                 << "CONTENT: " << contenido_aux << endl;
            system("pause");
            system("cls");
            cout << endl;
            fflush(stdin);

            // Asignar tamaños
            tam_rem = remitente_aux.length();
            tam_dest = destinatario_aux.length();
            tam_cc = cc_aux.length();
            tam_bcc = bcc_aux.length();
            tam_asu = asunto_aux.length();
            tam_cont = contenido_aux.length();
            tam_fecha = fechaHora_aux.length();

            //Informacion en caracteres
            int id;
            char fecha[tam_fecha + 1];
            char remitente[tam_rem + 1];
            char destinatario[tam_dest + 1];
            char cc[tam_cc + 1];
            char bcc[tam_bcc + 1];
            char asunto[tam_asu + 1];
            char contenido[tam_cont + 1];

            // Asignacion de valores
            id = id_aux;
            strcpy(fecha, fechaHora_aux.c_str());
            strcpy(remitente, remitente_aux.c_str());
            strcpy(destinatario, destinatario_aux.c_str());
            strcpy(cc, cc_aux.c_str());
            strcpy(bcc, bcc_aux.c_str());
            strcpy(asunto, asunto_aux.c_str());
            strcpy(contenido, contenido_aux.c_str());

            // Escritura
            archivo_salida.write((const char*)&id, sizeof(int));        // ID

            archivo_salida.write((const char*)&tam_fecha, sizeof(int)); // FECHA
            archivo_salida.write((const char*)&fecha, tam_fecha);

            archivo_salida.write((const char*)&tam_rem, sizeof(int));   // FROM
            archivo_salida.write((const char*)&remitente, tam_rem);

            archivo_salida.write((const char*)&tam_dest, sizeof(int));  // TO
            archivo_salida.write((const char*)&destinatario, tam_dest);

            archivo_salida.write((const char*)&tam_cc, sizeof(int));    // CC
            archivo_salida.write((const char*)&cc, tam_cc);

            archivo_salida.write((const char*)&tam_bcc, sizeof(int));   // BCC
            archivo_salida.write((const char*)&bcc, tam_bcc);

            archivo_salida.write((const char*)&tam_asu, sizeof(int));   // SUBJECT
            archivo_salida.write((const char*)&asunto, tam_asu);

            archivo_salida.write((const char*)&tam_cont, sizeof(int));  // CONTENT
            archivo_salida.write((const char*)&contenido, tam_cont);

            pos++;
            id_aux2 = email.getIdentificador();
        }
        else {
            if(archivo.eof()) {
                break;
            }
        }
    }

    cout << endl << "Exportacion LGV exitosa! .." << endl << endl;

    archivo.close();
    archivo_salida.close();
}

void EditarCorreo_longitudVariable()
{
    // flujo de archivo lectura
    fstream ArchivoEntrada;
    ArchivoEntrada.open("Correos_lgv.bin", ios::in | ios::out);

    // flujo de archivo de salida temporal
    ofstream ArchivoSalida;
    ArchivoSalida.open("temporal.bin", ios::out | ios::binary);

    int id_g;
    int id_2 = 0;
    string opc;
    string renglon = "";
    string Contenido;

    // var con los tamaños
    int tam_rem;
    int tam_dest;
    int tam_cc;
    int tam_bcc;
    int tam_asu;
    int tam_cont;
    int tam_fecha;

    // Variables de almacenamiento
    int id_aux;
    string remitente_aux;
    string destinatario_aux;
    string cc_aux;
    string bcc_aux;
    string asunto_aux;
    string contenido_aux;
    string fechaHora_aux;


    cout << endl << "EDITAR CORREO" << endl << endl;
    cout << "Ingresa el ID: ";
    cin >> id_g;

    while(!ArchivoEntrada.eof()) {

        int id;
        ArchivoEntrada.read((char*)&id, sizeof(int));

        // Fecha
        ArchivoEntrada.read((char*)&tam_fecha, sizeof(int));
        char fecha[tam_fecha];
        fecha[tam_fecha] = '\0';
        ArchivoEntrada.read((char*)&fecha, tam_fecha);

        // Remitente
        ArchivoEntrada.read((char*)&tam_rem, sizeof(int));
        char remitente[tam_rem];
        remitente[tam_rem] = '\0';
        ArchivoEntrada.read((char*)&remitente, tam_rem);

        // Destinatario
        ArchivoEntrada.read((char*)&tam_dest, sizeof(int));
        char destinatario[tam_dest];
        destinatario[tam_dest] = '\0';
        ArchivoEntrada.read((char*)&destinatario, tam_dest);

        // CC
        ArchivoEntrada.read((char*)&tam_cc, sizeof(int));
        char cc[tam_cc];
        cc[tam_cc] = '\0';
        ArchivoEntrada.read((char*)&cc, tam_cc);

        // BCC
        ArchivoEntrada.read((char*)&tam_bcc, sizeof(int));
        char bcc[tam_bcc];
        bcc[tam_bcc] = '\0';
        ArchivoEntrada.read((char*)&bcc, tam_bcc);

        // Asunto
        ArchivoEntrada.read((char*)&tam_asu, sizeof(int));
        char asunto[tam_asu];
        asunto[tam_asu] = '\0';
        ArchivoEntrada.read((char*)&asunto, tam_asu);

        // Contenido
        ArchivoEntrada.read((char*)&tam_cont, sizeof(int));
        char contenido[tam_cont];
        contenido[tam_cont] = '\0';
        ArchivoEntrada.read((char*)&contenido, tam_cont);

        id_aux = id;
        fechaHora_aux = fecha;
        remitente_aux = remitente;
        destinatario_aux = destinatario;
        cc_aux = cc;
        bcc_aux = bcc;
        asunto_aux = asunto;
        contenido_aux = contenido;

        if(id_g == id_aux && id_g != id_2) {
            cout << "Correo encontrado!" << endl << endl;
            cout << "ID: " << id << endl
                 << "FECHA: " << fecha << endl
                 << "FROM: " << remitente << endl
                 << "TO: " << destinatario << endl
                 << "CC: " << cc << endl
                 << "BCC: " << bcc << endl
                 << "SUBJECT: " << asunto << endl
                 << "CONTENT: " << contenido << endl;
            cout << endl;

            cout << "1) Modificar TO" << endl
                 << "2) Modificar CC" << endl
                 << "3) Modificar BBC" << endl
                 << "4) Modificar Subject" << endl
                 << "5) Modificar Content" << endl
                 << "6) Salir" << endl;
            cout << endl;
            fflush(stdin);
            cout << "Seleccione una opcion: ";
            getline(cin, opc);
            cout << endl;
            fflush(stdin);

            if (opc == "1") {
                cout << "TO: ";
                getline(cin, destinatario_aux);
                strcpy(destinatario, destinatario_aux.c_str());
            }
            else if (opc == "2") {
                cout << "CC: ";
                getline(cin, cc_aux);
                strcpy(cc, cc_aux.c_str());
            }
            else if (opc == "3") {
                cout << "BCC: ";
                getline(cin, bcc_aux);
                strcpy(bcc, bcc_aux.c_str());
            }
            else if (opc == "4") {
                cout << "SUBJECT: ";
                getline(cin, asunto_aux);
                strcpy(asunto, asunto_aux.c_str());
            }
            else if (opc == "5") {
                cout << "[Presione CTRL + Z + Enter para terminar de escribir]" << endl;
                cout << "CONTENT: ";
                while(getline(cin, renglon)) {
                    Contenido += renglon + '\n';
                }
                cin.clear();
                strcpy(contenido, Contenido.c_str());
            }

            tam_fecha = fechaHora_aux.length();
            tam_rem = remitente_aux.length();
            tam_dest = destinatario_aux.length();
            tam_cc = cc_aux.length();
            tam_bcc = bcc_aux.length();
            tam_asu = asunto_aux.length();
            tam_cont = contenido_aux.length();

            ArchivoSalida.write((const char*)&id, sizeof(int));

            ArchivoSalida.write((const char*)&tam_fecha, sizeof(int));
            ArchivoSalida.write((const char*)&fecha, tam_fecha);

            ArchivoSalida.write((const char*)&tam_rem, sizeof(int));
            ArchivoSalida.write((const char*)&remitente, tam_rem);

            ArchivoSalida.write((const char*)&tam_dest, sizeof(int));
            ArchivoSalida.write((const char*)&destinatario, tam_dest);

            ArchivoSalida.write((const char*)&tam_cc, sizeof(int));
            ArchivoSalida.write((const char*)&cc, tam_cc);

            ArchivoSalida.write((const char*)&tam_bcc, sizeof(int));
            ArchivoSalida.write((const char*)&bcc, tam_bcc);

            ArchivoSalida.write((const char*)&tam_asu, sizeof(int));
            ArchivoSalida.write((const char*)&asunto, tam_asu);

            ArchivoSalida.write((const char*)&tam_cont, sizeof(int));
            ArchivoSalida.write((const char*)&contenido, tam_cont);

            id_2 = id_g;

        } // Final if

        else {
            if (ArchivoEntrada.eof())
                break;

            if (id_aux != 0) {
                tam_fecha = fechaHora_aux.length();
                tam_rem = remitente_aux.length();
                tam_dest = destinatario_aux.length();
                tam_cc = cc_aux.length();
                tam_bcc = bcc_aux.length();
                tam_asu = asunto_aux.length();
                tam_cont = contenido_aux.length();

                ArchivoSalida.write((const char*)&id, sizeof(int));

                ArchivoSalida.write((const char*)&tam_fecha, sizeof(int));
                ArchivoSalida.write((const char*)&fecha, tam_fecha);

                ArchivoSalida.write((const char*)&tam_rem, sizeof(int));
                ArchivoSalida.write((const char*)&remitente, tam_rem);

                ArchivoSalida.write((const char*)&tam_dest, sizeof(int));
                ArchivoSalida.write((const char*)&destinatario, tam_dest);

                ArchivoSalida.write((const char*)&tam_cc, sizeof(int));
                ArchivoSalida.write((const char*)&cc, tam_cc);

                ArchivoSalida.write((const char*)&tam_bcc, sizeof(int));
                ArchivoSalida.write((const char*)&bcc, tam_bcc);

                ArchivoSalida.write((const char*)&tam_asu, sizeof(int));
                ArchivoSalida.write((const char*)&asunto, tam_asu);

                ArchivoSalida.write((const char*)&tam_cont, sizeof(int));
                ArchivoSalida.write((const char*)&contenido, tam_cont);
            }
        }
    }

    ArchivoEntrada.close();
    ArchivoSalida.close();

    remove("Correos_lgv.bin");
    rename("temporal.bin", "Correos_lgv.bin");
}

void EliminarCorreo_longitudVariable()
{

    fstream ArchivoEntrada;
    ArchivoEntrada.open("Correos_lgv.bin", ios::in | ios::out | ios::binary);

    ofstream ArchivoSalida;
    ArchivoSalida.open("temporal.bin", ios::out | ios::binary);

    int id_g;
    int id_2 = 0;

    int tam_rem;
    int tam_dest;
    int tam_cc;
    int tam_bcc;
    int tam_asu;
    int tam_cont;
    int tam_fecha;

    int id_aux;
    string remitente_aux;
    string destinatario_aux;
    string cc_aux;
    string bcc_aux;
    string asunto_aux;
    string contenido_aux;
    string fechaHora_aux;

    cout << "EDITAR CORREO" << endl << endl;

    cout << "Ingrese el id: ";
    cin >> id_g;
    cout << endl;

    while(!ArchivoEntrada.eof()) {
        int id;
        ArchivoEntrada.read((char*)&id, sizeof(int));

        // Fecha
        ArchivoEntrada.read((char*)&tam_fecha, sizeof(int));
        char fecha[tam_fecha];
        fecha[tam_fecha] = '\0';
        ArchivoEntrada.read((char*)&fecha, tam_fecha);

        // Remitente
        ArchivoEntrada.read((char*)&tam_rem, sizeof(int));
        char remitente[tam_rem];
        remitente[tam_rem] = '\0';
        ArchivoEntrada.read((char*)&remitente, tam_rem);

        // Destinatario
        ArchivoEntrada.read((char*)&tam_dest, sizeof(int));
        char destinatario[tam_dest];
        destinatario[tam_dest] = '\0';
        ArchivoEntrada.read((char*)&destinatario, tam_dest);

        // CC
        ArchivoEntrada.read((char*)&tam_cc, sizeof(int));
        char cc[tam_cc];
        cc[tam_cc] = '\0';
        ArchivoEntrada.read((char*)&cc, tam_cc);

        // BCC
        ArchivoEntrada.read((char*)&tam_bcc, sizeof(int));
        char bcc[tam_bcc];
        bcc[tam_bcc] = '\0';
        ArchivoEntrada.read((char*)&bcc, tam_bcc);

        // Asunto
        ArchivoEntrada.read((char*)&tam_asu, sizeof(int));
        char asunto[tam_asu];
        asunto[tam_asu] = '\0';
        ArchivoEntrada.read((char*)&asunto, tam_asu);

        // Contenido
        ArchivoEntrada.read((char*)&tam_cont, sizeof(int));
        char contenido[tam_cont];
        contenido[tam_cont] = '\0';
        ArchivoEntrada.read((char*)&contenido, tam_cont);

        id_aux = id;
        fechaHora_aux = fecha;
        remitente_aux = remitente;
        destinatario_aux = destinatario;
        cc_aux = cc;
        bcc_aux = bcc;
        asunto_aux = asunto;
        contenido_aux = contenido;

        if (id_g == id_aux && id_g != id_2) {
            cout << "Se ha eliminado el correo!" << endl << endl;
        }

        else {
            if(ArchivoEntrada.eof())
                break;

            if(id_aux != 0) {
                tam_fecha = fechaHora_aux.length();
                tam_rem = remitente_aux.length();
                tam_dest = destinatario_aux.length();
                tam_cc = cc_aux.length();
                tam_bcc = bcc_aux.length();
                tam_asu = asunto_aux.length();
                tam_cont = contenido_aux.length();

                ArchivoSalida.write((const char*)&id, sizeof(int));

                ArchivoSalida.write((const char*)&tam_fecha, sizeof(int));
                ArchivoSalida.write((const char*)&fecha, tam_fecha);

                ArchivoSalida.write((const char*)&tam_rem, sizeof(int));
                ArchivoSalida.write((const char*)&remitente, tam_rem);

                ArchivoSalida.write((const char*)&tam_dest, sizeof(int));
                ArchivoSalida.write((const char*)&destinatario, tam_dest);

                ArchivoSalida.write((const char*)&tam_cc, sizeof(int));
                ArchivoSalida.write((const char*)&cc, tam_cc);

                ArchivoSalida.write((const char*)&tam_bcc, sizeof(int));
                ArchivoSalida.write((const char*)&bcc, tam_bcc);

                ArchivoSalida.write((const char*)&tam_asu, sizeof(int));
                ArchivoSalida.write((const char*)&asunto, tam_asu);

                ArchivoSalida.write((const char*)&tam_cont, sizeof(int));
                ArchivoSalida.write((const char*)&contenido, tam_cont);
            }
        }
    }

    ArchivoEntrada.close();
    ArchivoSalida.close();

    remove("Correos_lgv.bin");
    rename("temporal.bin", "Correos_lgv.bin");
}

void BusquedaCorreo_RAM()
{

    fstream ArchivoEntrada;
    ArchivoEntrada.open("Correos.bin", ios::in | ios::out | ios::binary);

    Correo email;
    Correo lista[100];
    Correo email_aux;

    string remitente;
    int pst;
    int size = 0;
    int posicion = 0;
    string opc;
    int bandera = 0;

    if(!ArchivoEntrada.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    else {
        while(!ArchivoEntrada.eof()) {

            ArchivoEntrada.read((char*)&email, sizeof(Correo));

            if(ArchivoEntrada.eof()) {
                break;
            }

            // Cargar correo a la ram
            if(email.getIdentificador() != 0) {
                cout << "Correo Cargado" << endl;
                cout << "ID: " << email.getIdentificador() << endl
                     << "FECHA: " << email.getFecha_hora() << endl
                     << "FROM: " << email.getRemitente() << endl
                     << "TO: " << email.getDestinatario() << endl
                     << "CC: " << email.getCopia_carbon() << endl
                     << "BCC: " << email.getCopia_carbon_ciega() << endl
                     << "SUBJECT: " << email.getAsunto() << endl
                     << "CONTENT: " << endl << email.getContenido() << endl;
                cout << endl;

                lista[size] = email;
                bandera = 1;
                size++;
            }
            system("pause");
            system("cls");
        }

        cout << "Correos cargados: " << size << endl << endl;
        system("pause");

        // Ordenar correos Shell sort

        if (bandera == 1) {

            posicion = size / 2; // Mitad arreglo
            while(posicion > 0) {
                for (int i = 0; i < size - posicion; ++i) {
                    pst = i + posicion;
                    email_aux = lista[pst];
                    while(pst >= posicion && strcmp(email_aux.getRemitente().c_str(),
                                                    lista[pst - posicion].getRemitente().c_str()) < 0) {
                        lista[pst] = lista[pst - posicion];
                        pst -= posicion;
                    }
                }

                if(posicion == 2)
                    posicion = 1;
                else
                    posicion /= 2;
            }
        }

        // Si no se cargaron los correos ...
        else {
            cout << "Error, no fue posible cargar los correos exitosamente!" << endl;
            ArchivoEntrada.close();
            return;
        }

        // Busqueda binaria de correos
        do {
            system("cls");
            cout << "BUSQUEDA DE CORREOS EN RAM" << endl << endl;

            cout << "Ingrese el remitente: ";
            getline(cin, remitente);
            system("cls");

            bandera = 0;

            // Pivotes
            int inferior = 0;
            int superior = size;
            int central;

            while(inferior <= superior) {
                central = ((inferior + superior) / 2);

                if(strcmp(lista[central].getRemitente().c_str(), remitente.c_str()) == 0) {
                    cout << endl << "Correo Encontrado!" << endl << endl;
                    cout << "ID: " << lista[central].getIdentificador() << endl
                         << "FECHA: " << lista[central].getFecha_hora()
                         << "FROM: " << lista[central].getRemitente() << endl
                         << "TO: " << lista[central].getDestinatario() << endl
                         << "CC: " << lista[central].getCopia_carbon() << endl
                         << "BCC: " << lista[central].getCopia_carbon_ciega() << endl
                         << "SUBJECT: " << lista[central].getAsunto() << endl
                         << "CONTENT: " << lista[central].getContenido() << endl;
                    bandera = 1;
                    break;
                }
                else if(strcmp(lista[central].getRemitente().c_str(), remitente.c_str()) > 0) {
                    superior = central - 1;
                }
                else if(strcmp(lista[central].getRemitente().c_str(), remitente.c_str()) < 0) {
                    inferior = central + 1;
                }
            }

            if (bandera == 0) {
                cout << endl << "No se encontro el correo" << endl;
            }

            cout << endl << "Desea continuar la busqueda? [1 - Si] [0 - No]:  ";
            getline(cin, opc);

        } while(opc != "0");
    }

    ArchivoEntrada.close();
}

bool ActualizarIndices(){

    //FLUJO
    fstream archivoEntrada("correos.bin", ios::in | ios::out | ios::binary);
    if(!archivoEntrada){
        cout << "Problemas en los archivos \nAbortando..." << endl;
        return 0;
    }
    ofstream archivoSalida("indices.bin", ios::out | ios::binary);

    //Objeto
    Correo email;
    Indice st_indice;

    //Variables
    int clave_aux;
    string clave = " ";
    int aux_clave;
    long posicion;
    int bandera = 2;

    archivoSalida.write((const char*)&bandera, sizeof(int));
    cout << "Actualizando datos" << endl;

    while(!archivoEntrada.eof()){

        posicion = archivoEntrada.tellg();
        archivoEntrada.read((char*)&email, sizeof(Correo));
        clave_aux = email.getIdentificador();

        if(email.getIdentificador() != 0 && email.getIdentificador() != aux_clave){

            clave = to_string(clave_aux);
            st_indice.setClave(clave);
            st_indice.setPosicion(posicion);

            archivoSalida.write((const char*)&st_indice, sizeof(Indice));

            aux_clave = email.getIdentificador();
        }
    }
    system("pause");

    //Cierre de flujos
    archivoEntrada.close();
    archivoSalida.close();

    return 1;
}

void IndicesPrimarios_AVL(){

    int bandera;

    //FLUJO
    fstream archivoEntrada("Correos.bin", ios::in | ios::out | ios::binary);
    if(!archivoEntrada){
        cout << "Problemas en los archivos" << endl;
        return;
    }
    fstream archivoSalida("Indices.bin", ios::in | ios::out | ios::binary);
    if(!archivoSalida){
        cout << "Creando archivo" << endl;
        archivoSalida.open("Indices.bin", ios::out);
        bandera = 1;
        archivoSalida.write((const char*)&bandera, sizeof(int));
        system("pause");
    }

    //Objeto
    Correo email;
    Indice st_indice;
    Arbol arbol;

    //Inicializacion
    arbol.Inicializar();
    bool e = false;
    bool &h = e;

    //Variables
    int opc;
    int valor_opc;
    int id;
    long posicion;
    string id_aux;
    int valor;

    system("cls");
    archivoSalida.read((char*)&bandera, sizeof(int));
    if(bandera == 2){

        if(bandera == 2){
            while(!archivoSalida.eof()){
                archivoSalida.read((char*)&st_indice, sizeof(Indice));
                if(st_indice.getPosicion() >= 0 && st_indice.getPosicion() != valor ){
                    arbol.ManejadorInsertar(st_indice, h);
                    valor = st_indice.getPosicion();
                }
            }
            system("pause");
        }
        system("cls");
        cout << endl;
        //Cargando datos a estructuras
            do{ 
                system("cls");
                //cout << endl << "Indices actualizados!" << endl << endl;
                cout << "1) Buscar" << endl
                     << "2) Insertar" << endl
                     << "3) Eliminar" << endl
                     << "0) Salir" << endl;
                cout << ">> ";
                cin >> valor_opc;
                system("cls");
                switch (valor_opc) {
                case 1:{
                    //cout << "Arboles balanceados" << endl;
                    cout << "Ingresa el ID: ";
                    cin >> id;
                    cout << endl;
                    id_aux = to_string(id);
                    st_indice.setClave(id_aux);
                    st_indice.setPosicion(0);
                    arbol.ManejadorBuscar(st_indice);
                    break;
                }
                case 2:{
                    //cout << "Arboles balanceados" << endl;
                    cout << "Ingresa el ID: ";
                    cin >> id;
                    cout << endl;
                    posicion = CrearCorreo(id);
                    //cout << "Posicion: " << endl;system("pause");
                    id_aux = to_string(id);
                    st_indice.setClave(id_aux);
                    st_indice.setPosicion(posicion);
                    arbol.ManejadorInsertar(st_indice, h);
                    break;
                }
                case 3:{
                    //cout << "Arboles balanceados" << endl;
                    cout << "Ingresa el ID: ";
                    cin >> id;
                    cout << endl;

                    id_aux = to_string(id);
                    st_indice.setClave(id_aux);
                    st_indice.setPosicion(0);
                    h = e;
                    arbol.ManejadorDelete(st_indice, h);
                    EliminarCorreo_ID(id);
                    break;
                }
                case OPC_SALIR:{
                    cout << endl << "In Orden" << endl;
                    arbol.ManagerIn();
                    cout << endl;
                    break;
                }
                default:
                    cout << endl << endl << "La opcion elegida es incorrecta" << endl;
                    break;
                }

            }while(valor_opc != OPC_SALIR);
        }
        else{
            opc = ActualizarIndices();
            if(opc == 1){
                cout << endl << "Indices Actualizados Correctamente!" << endl;
            }
            else{
                cout << "Ocurrio un error, no se logro actualizar correctamente" << endl;
            }//fallo al actulizar indices
        }

    //Cierre de flujos
    archivoEntrada.close();
    archivoSalida.close();
}

void IndicesSecundarios(){

    //Flujos
    fstream ArchivoCorreo("correos.bin", ios::out | ios::in | ios::binary);
    fstream ArchivoIndices("indices.bin", ios::out | ios::in | ios::binary);
    if(!ArchivoCorreo && !ArchivoIndices)
        return;

    //Objetos
    Arbol2 Remitente;
    Arbol2 Destinatario;

    Nodo2 *nodo_aux;

    IndiceSecundario nodo_dato;
    Indice nodo_clave;
    Correo email;

    //Inicializacion
    Remitente.Inicializar();
    Destinatario.Inicializar();
    bool e = false;
    bool &h = e;

    int opc;
    int bandera;
    int resp;
    int id;
    int id_aux;
    long pos;
    string remitente;
    string destinatario;

    ArchivoIndices.read((char*)&bandera, sizeof(int));
    if(bandera == 2){

        //Cargar correo a Arboles
        while (!ArchivoIndices.eof()) {
            ArchivoIndices.read((char*)&nodo_clave, sizeof(Indice));               //Leer Indice
            pos = nodo_clave.getPosicion();

            ArchivoCorreo.seekg(pos);
            ArchivoCorreo.read((char*)&email, sizeof(Correo));                          //Leer Correo

            id = atoi(nodo_clave.getClave().c_str());       //Convertir string a int

            if(email.getIdentificador() == id && id_aux != email.getIdentificador()){
                remitente = email.getRemitente();
                nodo_dato.setClave(remitente);
                Remitente.ManejadorInsertar(nodo_dato,h, nodo_clave);

                destinatario = email.getDestinatario();
                nodo_dato.setClave(destinatario);
                Destinatario.ManejadorInsertar(nodo_dato,h, nodo_clave);

                id_aux = email.getIdentificador();
            }
        }
    }
    else{
        resp = ActualizarIndices();
        if(resp == 1){
            cout << ">>>   Indices Actualizados   <<<" << endl;
            system("pause");
            IndicesSecundarios();
        }
        else{
            cout << ">>>   Error de Actualizacion   <<<" << endl;
            system("pause");
            return;
        }
    }


    system("pause");
    do{
        system("cls");
        cout << "\t\tBUSQUEDA DE CORREOS" << endl << endl;
        cout << "1) Buscar por Remitente" << endl
             << "2) Buscar por Destinatario" << endl
             << "0) Salir" << endl
             << ">> ";
        cin >> opc;
        system("cls");

        switch(opc)
        {
        case 1:{
            fflush(stdin);
            cout << "Ingrese el Remitente a buscar: ";
            getline(cin, remitente);
            system("cls");
            nodo_dato.setClave(remitente);
            nodo_aux = Remitente.ManejadorBuscar(nodo_dato);

            if(nodo_aux != NULL){
                nodo_aux->getData().nodo.print();
                system("pause");
            }
            break;
        }//caso 1
        case 2:{
            fflush(stdin);
            cout << "Ingrese el Destinatario a buscar: ";
            getline(cin, destinatario);
            system("cls");
            nodo_dato.setClave(destinatario);
            nodo_aux = Destinatario.ManejadorBuscar(nodo_dato);

            if(nodo_aux != NULL){
                nodo_aux->getData().nodo.print();
                system("pause");
            }
            break;
        }//caso 2
        case OPC_SALIR:{
            break;
        }//caso Salir
        default:
            cout << "Opcion Invalida!<<<" << endl;
            break;
        }//switch

    }while(opc != OPC_SALIR);

    ArchivoCorreo.close();
    ArchivoIndices.close();
}

void IndicesPaginados()
{
    // Flujos de archivos
    fstream archivoEntrada("correos.bin", ios::in | ios::out | ios::binary);
    fstream archivoSalida("indices.bin", ios::in | ios::out | ios::binary);

    if(!archivoEntrada && !archivoSalida)
        return;

    // Variables objeto
    Indice indice;
    Indices_Paginados indicePag;
    Arbol_paginados arbol;

    // Otras var
    struct tm time_1;
    int bandera;
    int contador = 0;
    string id;
    string id_aux;
    int opc;

    // Se inicializa el arbol
    arbol.Inicializar();
    bool e = false;
    bool &h = e;

    archivoSalida.read((char*)&bandera, sizeof(int));
    if(bandera == 2) {
        cout << endl << "Indices Actualizados!" << endl;

        while(contador < 10) {
            // Fecha actual
            time_t now;
            struct tm nowLocal;
            now = time(NULL);
            nowLocal = *localtime(&now);

            archivoSalida.read((char*)&indice, sizeof(Indice));

            if(indice.getClave() != "0" && indice.getClave() != id_aux) {

                indicePag.setClave(indice.getClave());
                indicePag.setPosicion(indice.getPosicion());
                indicePag.setTiempo(nowLocal);
                arbol.ManejadorInsertar(indicePag, h);

                id_aux = indice.getClave();
                contador ++;
                Sleep(1000);
            }
        }
        system("pause");

        do {
            system("cls");
            cout << "1) Buscar Correo" << endl
                 << "0) Salir" << endl
                 << ">> ";
            cin >> opc;
            system("cls");
            fflush(stdin);
            switch (opc) {
            case 1: {
                cout << "Ingresa el ID del correo a buscar: ";
                getline(cin, id);
                system("cls");
                indicePag.setClave(id);
                arbol.ManejadorBuscar(indicePag, h, arbol);
                break;
            }
            case OPC_SALIR: {
                break;
            }
            default:
                cout << endl << "Opcion invalida!" << endl;
                break;
            }
        } while(opc != OPC_SALIR);
    }

    else {
        cout << endl << "Indices Desactualizados" << endl;
        ActualizarIndices();
    }

    archivoEntrada.close();
    archivoSalida.close();
}

void B_Dispersion()
{
    // Flujo a los archivos
    fstream archivo("Serializacion.bin", ios::binary | ios::in);

    int opc;

    Dispersion tabla;

    // Leer archivo
    if(archivo.is_open()) {
        cout << endl << "Importando tabla" << endl;
        archivo.close();
        tabla.importar();
    }

    else {
        cout << endl << "Creado tabla" << endl;
        archivo.close();
        tabla.add();
    }

    // Menu para buscar
    system("cls");
    do {
        system("cls");
        cout << "1) Buscar Correo" << endl
             << "0) Salir" << endl
             << ">> ";
        cin >> opc;
        fflush(stdin);
        system("cls");

        switch(opc) {
        case 1:
            tabla.search();
            system("pause");
            break;
        case 0:
            tabla.exportar();
            return;
            break;
        default:
            cout << "Opcion invalida!" << endl;
            break;
        }
    } while(opc != OPC_SALIR);
}

bool Cifrado()
{
    fstream entrada;
    ofstream salida;

    entrada.open("Copia.csv", ios::in);
    salida.open("Cifrado.csv", ios::out);

    if(!entrada.is_open()) {
        entrada.close();
        salida.close();
        cout << endl << "Error en el archivo" << endl << endl;
        return 1;
    }

    char contrasenia[20];
    char aux[20];
    char caracter;
    int tamanio;
    string tam;

    // Ingresar la contrasenia
    cout << "Contrasenia: ";
    cin >> contrasenia;
    fflush(stdin);
    system("cls");

    // Cifrar la contrasenia
    tamanio = strlen(contrasenia);

    for (int i = 0; i <= tamanio; ++i) {
        contrasenia[i] = contrasenia[i] + 3;
    }

    strcpy(aux, contrasenia);
    tam = to_string(tamanio);

    for (int i = 0; i < sizeof(tam); ++i) {
        tam[i] = tam[i] + 3;
    }

    // Escribir en el archivo
    salida << tam << ',' << contrasenia << "\n";

    while(!entrada.eof()) {
        entrada.get(caracter);
        caracter = caracter + 3;
        salida << caracter;
    }

    cout << endl << "Cifrado terminado" << endl << endl;

    entrada.close();
    salida.close();

    return 0;
}

bool Descifrado()
{
    fstream entrada;
    ofstream salida;

    entrada.open("Cifrado.csv", ios::in);
    salida.open("Descifrado.csv", ios::out);

    if(!entrada.is_open()) {
        cout << endl << "Error en el archivo" << endl << endl;
        entrada.close();
        salida.close();
        return 1;
    }

    char contrase[20];
    string contra;
    char aux_contrasenia[20];

    char caracter;
    int tamanio;
    string tam;
    char tamn[50];
    int opc;
    int bandera = 1;

    // Obtener tam de la contrasenia
    getline(entrada, tam, ',');
    strcpy(tamn, tam.c_str());

    for (int i = 0; i < sizeof(tam); ++i) {
        tamn[i] = tam[i] - 3;
    }

    tamanio = stoi(tamn);

    // Obtener contrasenia
    getline(entrada, contra, '\n');
    strcpy(contrase, contra.c_str());

    char contrasenia[tamanio];
    strcpy(contrasenia, contrase);

    for (int i = 0; i <= tamanio; ++i) {
        contrasenia[i] = contrasenia[i] - 3;
    }

    do {
        cout << "Contrasenia: ";
        cin >> aux_contrasenia;
        fflush(stdin);

        for (int i = 0; i <= tamanio; ++i) {
            if(contrasenia[i] != aux_contrasenia[i])
                bandera = 0;
        }

        if(bandera == 1) {
            cout << endl << "Contrasenia correcta!, Descifrando archivo" << endl << endl;
                 //<< "Contrasenia original: " << contrasenia << endl
                 //<< "Contrasenia ingresada: " << aux_contrasenia << endl << endl;

            // Comenzar a descifrar
            while(!entrada.eof()) {
                entrada.get(caracter);
                caracter = caracter - 3;
                salida << caracter;
            }

            cout << "Descencriptacion exitosa!" << endl;
            opc = OPC_SALIR;
        }

        else {
            cout << "Contrasenia incorrecta!" << endl
                 << endl << "Volver a intentar? [1-Si] [0-No] " << endl
                 << ">> ";
            cin >> opc;
            system("cls");
            fflush(stdin);

            if(opc == 0) {
                entrada.close();
                salida.close();
                return 1;
            }
        }
    } while(opc != OPC_SALIR);

    entrada.close();
    salida.close();

    // Renombrar archivo
    remove("Cifrado.csv");

    return 0;
}

void ControlCifrado()
{
    int opc;
    int resp;

    do {
        cout << "1) Cifrar Archivo" << endl
             << "2) Descifrar Archivo" << endl
             << "0) Salir" << endl
             << ">> ";
        cin >> opc;
        system("cls");
        fflush(stdin);

        switch (opc) {
        case 1:
            resp = Cifrado();

            if(resp == 0) {
                 cout << "El archivo ha sido cifrado correctamente!" << endl;
                system("cls");
            }
            else {
                cout << "Ha ocurrido un error a la hora de realizar el cifrado" << endl;
                system("cls");
            }
            break;
        case 2:
            resp = Descifrado();

            if(resp == 0) {
                cout << "El archivo ha sido descifrado correctamente!" << endl;
               system("cls");
           }
           else {
               cout << "Ha ocurrido un error a la hora de realizar el descifrado" << endl;
               system("cls");
           }
            break;
        case OPC_SALIR:
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while(opc != OPC_SALIR);

    return;
}

bool Compresion()
{
    ofstream Salida("Compresion.csv", ios::out);
    fstream Entrada("Copia.csv", ios::in);

    if(!Entrada)
        return 1;

    char caracter;
    char aux_caracter;
    int contador = 0;

    while(!Entrada.eof()) {
        Entrada.get(caracter);

        if(Entrada.eof())
            break;

        else {
            if(caracter == aux_caracter) {
                contador++;
            }
            else {
                if(contador == 0) {
                    Salida << caracter;
                }
                else {
                    Salida << contador << caracter;
                    contador = 0;
                }
            }
        }
        aux_caracter = caracter;
    }

    return 0;
}

void ControlCompresion()
{
    int opc, resp;

    do {
        cout << "1) Compresion de archivo" << endl
             << "0) Salir" << endl
             << ">> ";
        cin >> opc;
        system("cls");
        fflush(stdin);

        switch (opc) {
        case 1:
            resp = Compresion();

            if(resp == 0) {
                cout << endl << "Compresion exitosa!" << endl;
                system("pause");
                system("cls");
            }
            else {
                cout << endl << "Compresion fallida!" << endl;
                system("pause");
                system("cls");
            }
            break;
        case OPC_SALIR:
            break;
        default:
            cout << endl << "Opcion invalida" << endl;
            break;
        }
    } while(opc != OPC_SALIR);

    return;
}

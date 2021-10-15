#ifndef DISPERSION_H
#define DISPERSION_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "correo.h"
#include "listasimpleligada.h"
using namespace std;
#define PRIMO 211

class Dispersion
{
private:
    ListaSimpleLigada<Correo> hashi[PRIMO];

public:
    Dispersion();

    int Funcion(char *);
    void add();
    void search();

    // Tabla csv
    void exportar();
    void importar();
};

#endif // DISPERSION_H

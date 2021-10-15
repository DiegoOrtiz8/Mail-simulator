#ifndef INDICES_PAGINADOS_H
#define INDICES_PAGINADOS_H

#include "indice.h"
#include <ctime>

class Indices_Paginados : public Indice
{
public:
    Indices_Paginados();

    tm getTiempo() const;
    void setTiempo(const tm &value);

    friend ostream& operator <<(ostream &out, Indices_Paginados &i){
        out << "Fecha: " << i.getTiempo().tm_mday <<  "-" << i.getTiempo().tm_mon+1 << "-" << i.getTiempo().tm_year+1900 << endl;
        out << "Hora: " << i.getTiempo().tm_hour << ":" << i.getTiempo().tm_min << ": " << i.getTiempo().tm_sec << endl;
    }

private:
    struct tm tiempo;
};

#endif // INDICES_PAGINADOS_H

#ifndef DT_LISTAR_VIAJE_H
#define DT_LISTAR_VIAJE_H

#include "DTFecha.h"
#include <string>

using namespace std;

class DTListarViaje {
private:
    int codigo;
    DTFecha fecha;
    string origen;
    string destino;
    string conductor;

public:
    DTListarViaje(int codigo, DTFecha fecha, string origen, string destino, string conductor);

    int getCodigo();
    DTFecha getFecha();
    string getOrigen();
    string getDestino();
    string getConductor();
    bool operator<(const DTListarViaje& otro) const;

};

#endif

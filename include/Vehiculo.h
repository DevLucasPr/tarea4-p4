#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTListarViaje.h"
#include <string>
#include <set>
using namespace std;

class Vehiculo {
private:
    string matricula;
    int capacidad;
    string marca;
    string modelo;
    TipoVehiculo tipo;

public:
    Vehiculo(string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo);

    string getMatricula();
    int getCapacidad();
    string getMarca();
    TipoVehiculo getTipo();

    set<DTListarViaje> listarViajesVehiculo();
    DTVehiculosConductor getDTVehiculoConductor();
    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
    void asociarViaje();

    ~Vehiculo();
};

#endif

#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTListarViaje.h"
#include "Conductor.h"
#include <string>
#include <set>
#include <map>
using namespace std;
class Viaje;

class Vehiculo {
private:
    string matricula;
    int capacidad;
    string marca;
    string modelo;
    TipoVehiculo tipo;
    Conductor *conductor;
    map<int, Viaje *> viajes;

public:
    Vehiculo(string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo);

    string getMatricula();
    int getCapacidad();
    string getMarca();
    string getModelo();
    TipoVehiculo getTipo();
    DTVehiculosConductor getDTVehiculoConductor();
    Conductor *getConductor();

    void setConductor(Conductor *conductor);

    // Retorna el conjunto viajes de los datavalue del tipo DTListarViaje
    set<DTListarViaje> listarViajesVehiculo();

    // Devuelve True en caso de que hayan alugún viaje en la fecha dada asociados al Conductor del Vehiculo 
    bool hayViajesConductor(DTFecha fecha);

    // Devuelve True en caso de que haya un viaje asociado al vehiculo en la fecha dada
    bool hayViajesFecha(DTFecha fecha);

    void asociarViaje(Viaje *v);
    void desasociarViaje(int codigo);

    ~Vehiculo();
};

#endif

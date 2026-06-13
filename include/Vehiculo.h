#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTListarViaje.h"
#include "Conductor.h"
#include <string>
#include <set>
#include <map>

class Viaje;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    Conductor *conductor;    
    std::map<int, Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);

    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    DTVehiculosConductor getDTVehiculoConductor();
    Conductor *getConductor();

    void setConductor(Conductor *conductor);

    // Retorna el conjunto viajes de los datavalue del tipo DTListarViaje
    std::set<DTListarViaje> listarViajesVehiculo();

    // Devuelve True en caso de que hayan alugún viaje en la fecha dada asociados al Conductor del Vehiculo 
    bool hayViajesConductor(DTFecha fecha);

    // Devuelve True en caso de que haya un viaje asociado al vehiculo en la fecha dada
    bool hayViajesFecha(DTFecha fecha);

    void asociarViaje(Viaje *v);
    void desasociarViaje(int codigo);

    ~Vehiculo();
};

#endif

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTFecha.h"
#include <set>

class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::set<Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();

    std::set<DTListarViaje*> listarViajesUsuario();
    bool puedeManejarTipo(TipoVehiculo tipo);
    bool esPasajero();
    void linkVehiculo(Vehiculo* v);
    std::set<DTVehiculosConductor> listarVehiculos();
    bool hayViajesFecha(DTFecha fecha);
};

#endif

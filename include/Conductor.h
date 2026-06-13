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
    set<TipoLibreta> libretas;
    set<Vehiculo*> vehiculos;

public:
    Conductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libs);
    ~Conductor();

    virtual set<DTListarViaje> listarViajesUsuario();
    bool puedeManejarTipo(TipoVehiculo tipo);
    bool esPasajero();
    void linkVehiculo(Vehiculo* v);
    set<DTVehiculosConductor> listarVehiculos();
    bool hayViajesFecha(DTFecha fecha);
};

#endif

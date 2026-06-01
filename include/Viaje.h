#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTUsuarioViaje.h"
#include "DTConsultaViaje.h"
#include "Pasajero.h"
#include <string>
#include <set>
using namespace std;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    string origen;
    string destino;
    int asientosPublicados;
    float precio;

public:
    Viaje(int codigo, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio);
    ~Viaje();
    set<DTUsuarioViaje> listarUsuariosViaje(int codigo);
    DTFecha getFecha();
    bool filtroViaje(DTFecha fecha, string origen, string destino);
    bool asientosDisp(int asientos);
    DTConsultaViaje obtenerViajes();
    bool sePuedeReservar(Pasajero *p, int asientos);
};

#endif

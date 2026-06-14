#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTUsuarioViaje.h"
#include "DTConsultaViaje.h"
#include "DTDetalleViaje.h"
#include "DTDetalleVehiculo.h"
#include "DTDetalleReserva.h"
#include "Vehiculo.h"
#include <string>
#include <set>
using namespace std;
class Reserva;
class Pasajero;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    string origen;
    string destino;
    int asientosPublicados;
    float precio;

    set<Reserva*> reservas;
    Vehiculo* vehiculo;

public:
    Viaje(int codigo, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio);

    int getCodigo();
    DTFecha getFecha();
    string getOrigen();
    string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    Vehiculo* getVehiculo();
    DTDetalleViaje getDTDetalleViaje();

    void setVehiculo(Vehiculo *v);

    set<DTUsuarioViaje> listarUsuariosViaje(string nicknameExcluido);
    bool filtroViaje(DTFecha fecha, string origen, string destino);
    bool asientosDisp(int asientos);
    DTConsultaViaje obtenerViajes(int asientos);

    bool sePuedeReservar(Pasajero *p, int asientos);

    void asociarReserva(Reserva *reserva);
    void eliminar();
    DTListarViaje getDTListarViaje();

    ~Viaje();
};

#endif

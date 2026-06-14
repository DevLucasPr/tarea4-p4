#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>
#include <set>
#include "../include/Viaje.h"

class Reserva;

class Pasajero : public Usuario {
private:
    string ci;
    set<Reserva*> reservas;

public:
    Pasajero(string nickname, string nombre, string contrasena, string email, string ci);
    ~Pasajero();

    set<DTListarViaje> listarViajesUsuario();
    bool esPasajero();
    void linkReserva(int codigoMem, Calificacion* c);
    void asociarReserva(Reserva* r);
    void desasociarReserva(Reserva* r);
};

#endif
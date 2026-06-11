#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>
#include <set>

class Reserva;

class Pasajero : public Usuario {
private:
    std::string ci;
    std::set<Reserva*> reservas;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
    ~Pasajero();

    std::set<DTListarViaje*> listarViajesUsuario();
    bool esPasajero();
    void linkReserva(int codigoMem, Calificacion* c);
    void addReserva(Reserva* r);
};

#endif
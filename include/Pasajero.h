#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>
#include <set>

class Pasajero : public Usuario {
private:
    std::string ci;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
    ~Pasajero();

    std::set<DTListarViaje*> listarViajesUsuario();
    bool esPasajero();
    void linkReserva();
};

#endif
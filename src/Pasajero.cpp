#include "../include/Pasajero.h"
#include "../include/Reserva.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = ci;
}

Pasajero::~Pasajero() {}

bool Pasajero::esPasajero() {
    return true;
}

std::set<DTListarViaje*> Pasajero::listarViajesUsuario() {
    std::set<DTListarViaje*> viajes;
    for (Reserva* r : this->reservas) {
        std::set<DTListarViaje*> dts = r->listarViajesReserva();
        viajes.insert(dts.begin(), dts.end());
    }
    return viajes;
}

void Pasajero::linkReserva(int codigoMem, Calificacion* c) {
    for (Reserva* r : this->reservas) {
        r->linkReservaViaje(codigoMem, c);
    }
}

void Pasajero::addReserva(Reserva* r) {
    this->reservas.insert(r);
}
#include "../include/Pasajero.h"
#include "../include/Reserva.h"

Pasajero::Pasajero(string nickname, string nombre, string contrasena, string email, string ci)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = ci;
}

Pasajero::~Pasajero() {}

bool Pasajero::esPasajero() {
    return true;
}

//Tendria que recorrer todas las reservas del pasajero
set<DTListarViaje> Pasajero::listarViajesUsuario() {
    set<DTListarViaje> viajes;
    for (Reserva* r : this->reservas) {
        viajes.insert(r->listarViajesReserva());
    }
    return viajes;
}

void Pasajero::linkReserva(int codigoMem, Calificacion* c) {
    for (Reserva* r : this->reservas) {
        r->linkReservaViaje(codigoMem, c);
    }
}

void Pasajero::asociarReserva(Reserva* r) {
    this->reservas.insert(r);
}
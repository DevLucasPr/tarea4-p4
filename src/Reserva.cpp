#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = nullptr;
    this->viaje = nullptr;
}

int Reserva::getAsientosReservados(){
    return this->asientosReservados;
}

DTFecha Reserva::getFecha(){
    return this->fecha;
}

Pasajero* Reserva::getPasajero() {
    return this->pasajero;
}

DTListarViaje Reserva::listarViajesReserva(){
    return DTListarViaje(viaje->getCodigo(), viaje->getFecha(), viaje->getOrigen(), viaje->getDestino(), viaje->getVehiculo()->getConductor()->getNickname());
}

bool Reserva::estaAsociadoViajeACalif(int codigoMem){
    return (codigoMem == viaje->getCodigo());
}

void Reserva::linkReservaViaje(int codigoMem, Calificacion *calificacion){
    if (viaje->getCodigo() == codigoMem) {
        calificaciones.insert(calificacion);
        calificacion->linkReserva(this);
    }
}

void Reserva::eliminar() {
    // (post. 2 y 3) calificaciones y sus links a los usuarios
    for (Calificacion* calificacion : calificaciones) {
        calificacion->eliminar();   // cada calif se quita de los sets de SUS usuarios
        delete calificacion;
    }
    calificaciones.clear();
    pasajero->desasociarReserva(this);
}

void Reserva::setPasajero(Pasajero* pasajero) {
    this->pasajero = pasajero;
}

void Reserva::setViaje(Viaje* viaje) {
    this->viaje = viaje;
}

Reserva::~Reserva() {}
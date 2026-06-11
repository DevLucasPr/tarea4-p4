#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}

int Reserva::getAsientosReservados(){
    return this->asientosReservados;
}

DTFecha Reserva::getFecha(){
    return this->fecha;
}

DTListarViaje Reserva::listarViajesReserva(){
    return DTListarViaje(viaje.getCodigo(), viaje.getFecha(), viaje.getOrigen(), viaje.getDestino(), viaje.getVehiculo()->getConductor()->getNickname());
}

bool Reserva::estaAsociadoViajeACalif(int codigoMem){
    return (codigoMem == viaje.getCodigo());
}

void Reserva::linkReservaViaje(int codigoMem, Calificacion calificacion){
    if (viaje.getCodigo() == codigoMem) {
        calificaciones.insert(calificacion);
    }
}

Reserva::~Reserva() {}

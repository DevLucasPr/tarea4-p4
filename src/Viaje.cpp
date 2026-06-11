#include "../include/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}


int getCodigo();
DTFecha Viaje::getFecha(){
    return this->fecha;
}
string Viaje::getOrigen(){
    return this->origen;
}
string Viaje::getDestino(){
    return this->destino;
}
int Viaje::getAsientosPublicados(){
    return this->asientosPublicados;
}
float Viaje::getPrecio(){
    return this->precio;
}

Vehiculo* Viaje::getVehiculo(){
    return this->vehiculo;
}

void Viaje::setVehiculo(Vehiculo *v){
    this->vehiculo = v;
}

set<DTUsuarioViaje> listarUsuariosViaje(int codigo){

}

bool Viaje::filtroViaje(DTFecha fecha, string origen, string destino){
    return (this->fecha == fecha && this->origen == origen && this->destino == destino);
}

bool Viaje::asientosDisp(int asientos){
    int asientosReservados = 0;
    set<Reserva*>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
        asientosReservados += (*it)->getAsientosReservados();
    return ((asientosPublicados - asientosReservados) >= asientos);
}

DTConsultaViaje Viaje::obtenerViajes(int asientos){
    return DTConsultaViaje(codigo, vehiculo->getMarca(), vehiculo->getModelo(), vehiculo->getConductor()->getNickname(), vehiculo->getConductor()->getCalificacionProm(), precio * asientos);
} 

bool Viaje::sePuedeReservar(Pasajero *p, int asientos){

}

Viaje::~Viaje() {}

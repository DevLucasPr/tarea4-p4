#include "../include/Viaje.h"
#include "../include/Reserva.h"


Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

int Viaje::getCodigo(){
    return this->codigo;
}

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

DTDetalleViaje Viaje::getDTDetalleViaje() {
    DTDetalleVehiculo detalleVehiculo = DTDetalleVehiculo(vehiculo->getMatricula(), vehiculo->getCapacidad(), vehiculo->getMarca(), vehiculo->getModelo(), vehiculo->getTipo());
    std::vector<DTDetalleReserva> detalleReserva;
    for (Reserva* reserva : reservas)
        detalleReserva.push_back(DTDetalleReserva(reserva->getAsientosReservados(), reserva->getFecha(), reserva->getPasajero()->getNickname()));
    return DTDetalleViaje(codigo, fecha, origen, destino, asientosPublicados, precio, detalleVehiculo, detalleReserva);
}

void Viaje::setVehiculo(Vehiculo *v){
    this->vehiculo = v;
}

set<DTUsuarioViaje> Viaje::listarUsuariosViaje(string nicknameExcluido) {
    set<DTUsuarioViaje> usuariosViaje;
    int orden = 0;
    string nicknameConductor = vehiculo->getConductor()->getNickname();
    if (nicknameConductor != nicknameExcluido)
        usuariosViaje.insert(DTUsuarioViaje(nicknameConductor, TipoUsuario::Conductor, orden++));

    for (Reserva* r : reservas) {
        string nicknamePasajero = r->getPasajero()->getNickname();
        if (nicknamePasajero != nicknameExcluido)
            usuariosViaje.insert(DTUsuarioViaje(nicknamePasajero, TipoUsuario::Pasajero, orden++));
    }
    return usuariosViaje;
}

bool Viaje::filtroViaje(DTFecha fecha, string origen, string destino){
    return (this->fecha == fecha && this->origen == origen && this->destino == destino);
}

bool Viaje::asientosDisp(int asientos){
    int asientosReservados = 0;
    for (Reserva* r : reservas)
        asientosReservados += r->getAsientosReservados();
    return ((asientosPublicados - asientosReservados) >= asientos);
}

DTConsultaViaje Viaje::obtenerViajes(int asientos){
    return DTConsultaViaje(codigo, vehiculo->getMarca(), vehiculo->getModelo(), vehiculo->getConductor()->getNombre(), vehiculo->getConductor()->getCalificacionProm(), precio * asientos);
} 

bool Viaje::sePuedeReservar(Pasajero* p, int asientos) {
    if (!this->asientosDisp(asientos))
        return false;
    for (Reserva* reserva : this->reservas) {
        if (reserva->getPasajero() == p)
            return false;
    }
    return true;
}

void Viaje::asociarReserva(Reserva *reserva){
    reservas.push_back(reserva);
}

void Viaje::eliminar() {
    vehiculo->desasociarViaje(this->codigo);
    for (Reserva* reserva : reservas) {
        reserva->eliminar();
        delete reserva;
    }
    reservas.clear();
}

DTListarViaje Viaje::getDTListarViaje() {
    return DTListarViaje(codigo, fecha, origen, destino, vehiculo->getConductor()->getNickname());
}

Viaje::~Viaje() {
    for (Reserva* r : reservas)
        delete r;
    reservas.clear();
}
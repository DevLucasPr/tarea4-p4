#include "../include/ControladorViajes.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorUsuarios.h"
#include "../include/DTConsultaViaje.h"
#include "../include/DTFecha.h"
#include "../include/Fabrica.h"
#include <map>

ControladorViajes *ControladorViajes::instancia = nullptr;

ControladorViajes::ControladorViajes() {
    codigoMem = 0;
    ultimoViaje = 0;

    this->handlerVehiculos = HandlerVehiculos::getInstance();
    this->handlerUsuarios = handlerUsuarios::getInstance();
    this->handlerViajes = HandlerViajes::getInstance();
}

ControladorViajes* ControladorViajes::getInstance(){
    if (instancia == NULL)
    {
        instancia = new ControladorViajes();
    }
}

bool ControladorViajes::generarReserva(string nickname, int codigo, int asientos){
    Viaje* viajeReserva = handlerViajes->getViaje(codigo);
    Pasajero* pasajeroReserva = handlerUsuarios->getPasajero(nickname);
    if (!viajeReserva->sePuedeReservar(pasajeroReserva, asientos))
        return false;

    DTFecha fechaActual = Fabrica::getInstance()->getIControladorFechaActual()->getFecha();
    Reserva* reserva = new Reserva(asientos, fechaActual);
    viajeReserva->asociarReserva(reserva);
    pasajeroReserva->asociarReserva(reserva);
    return true;
}

bool ControladorViajes::altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precio) {
    Vehiculo* vehiculo = this->handlerVehiculos->getVehiculo(matricula);
    if (asientos > vehiculo->getCapacidad())
        return false;

    if (vehiculo->hayViajesConductor(fecha))
        return false;

    this->ultimoViaje++;
    this->handlerViajes->crearViaje(this->ultimoViaje, fecha, origen, destino, asientos, precio);
    Viaje* viaje = this->handlerViajes->getViaje(this->ultimoViaje);
    vehiculo->asociarViaje(viaje);
    viaje->setVehiculo(vehiculo);
    return true;
}

set<DTConsultaViaje> ControladorViajes::consultarViajes(DTFecha fecha, string origen, string destino, int asientos) {
    set<DTConsultaViaje> viajesConsultados;
    map<int, Viaje*> viajes = this->handlerViajes->getColeccionViaje();
    for (pair<const int, Viaje*> par : viajes) {
        Viaje* viaje = par.second;
        if (viaje->filtroViaje(fecha, origen, destino) && viaje->asientosDisp(asientos))
            viajesConsultados.insert(viaje->obtenerViajes(asientos));
    }
    return viajesConsultados;
}

set<DTUsuarioViaje> ControladorViajes::listarUsuariosViaje(int codigo) {
    set<DTUsuarioViaje> usuariosViaje;
    Viaje* viaje = this->handlerViajes->getViaje(codigo);
    string nicknameMem = ControladorUsuarios::getInstance()->getNicknameMem();
    usuariosViaje = viaje->listarUsuariosViaje(nicknameMem);
    this->codigoMem = codigo;
    return usuariosViaje;
}

int ControladorViajes::getCodigoMem(){
    this->codigoMem;
}

int ControladorViajes::getUltimoViaje(){
    this->ultimoViaje;
}


set<DTListarViaje> ControladorViajes::listarViajes() {
    set<DTListarViaje> viajesListados;
    const map<int, Viaje*> viajes = this->handlerViajes->getColeccionViaje();
    for (pair<const int, Viaje*> par : viajes)
        viajesListados.insert(par.second->getDTListarViaje());
    return viajesListados;
}

DTDetalleViaje ControladorViajes::detalleViaje(int codigo){
    Viaje* viaje = this->handlerViajes->getViaje(codigo);
    DTDetalleViaje detalleViaje = viaje->getDTDetalleViaje();   
    this->codigoMem = codigo;                    
    return detalleViaje;
}

void ControladorViajes::eliminarViaje() {
    this->handlerViajes->eliminarViaje(this->codigoMem);  
    this->codigoMem = -1;                                 
}

void ControladorViajes::cancelarEliminarViaje() {
    this->codigoMem = -1;                                  
}

ControladorViajes::~ControladorViajes(){
}
#include "../include/Vehiculo.h"
#include "../include/Viaje.h"
#include "../include/Reserva.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

string Vehiculo::getMatricula(){
    return matricula;
};

int Vehiculo::getCapacidad(){
    return capacidad;
};

string Vehiculo::getMarca(){
    return marca;
};

string Vehiculo::getModelo(){
    return modelo;
};

TipoVehiculo Vehiculo::getTipo(){
    return tipo;
};

DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    return DTVehiculosConductor(this->matricula, this->modelo, this->capacidad);
};

Conductor *Vehiculo::getConductor(){
    return this->conductor;
}

void Vehiculo::setConductor(Conductor *conductor){
    this->conductor = conductor;
}

set<DTListarViaje> Vehiculo::listarViajesVehiculo(){
    set<DTListarViaje> viajesVehiculo;
    map<int, Viaje*>::iterator it;
    for (it = viajes.begin(); it != viajes.end(); ++it) {
        Viaje* v = it->second;
        DTListarViaje dt(v->getCodigo(), v->getFecha(), v->getOrigen(), v->getDestino(), conductor->getNickname());
        viajesVehiculo.insert(dt);
    }
    return viajesVehiculo;    
};

bool Vehiculo::hayViajesConductor(DTFecha fecha){
    return conductor->hayViajesFecha(fecha);
};

bool Vehiculo::hayViajesFecha(DTFecha fecha){
    map<int, Viaje*>::iterator it;

    for (it = viajes.begin(); it != viajes.end(); ++it) {
        if (it->second->getFecha() == fecha)
            return true;
    }
    return false;
};

void Vehiculo::asociarViaje(Viaje *v){
    int cod = v->getCodigo();
    viajes.insert({cod, v});
};

void Vehiculo::desasociarViaje(int codigo) {
    viajes.erase(codigo);
}

Vehiculo::~Vehiculo() {};
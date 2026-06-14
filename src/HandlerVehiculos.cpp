#include "../include/HandlerVehiculos.h"
#include "../include/Vehiculo.h"

using namespace std;

HandlerVehiculos* HandlerVehiculos::instancia = nullptr;

HandlerVehiculos::HandlerVehiculos() {}

HandlerVehiculos::~HandlerVehiculos() {
    for (map<string, Vehiculo*>::iterator it = coleccionVehiculos.begin(); it != coleccionVehiculos.end(); ++it) {
        delete it->second;
    }
}

HandlerVehiculos* HandlerVehiculos::getInstance() {
    if (instancia == nullptr) {
        instancia = new HandlerVehiculos();
    }
    return instancia;
}

void HandlerVehiculos::destroy() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}

bool HandlerVehiculos::existeVehiculo(string matricula) {
    return coleccionVehiculos.find(matricula) != coleccionVehiculos.end();
}

void HandlerVehiculos::agregarVehiculo(Vehiculo* vehiculo) {
    coleccionVehiculos.insert({vehiculo->getMatricula(), vehiculo});
}

Vehiculo* HandlerVehiculos::crearVehiculo(string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo) {
    Vehiculo* vehiculo = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
    agregarVehiculo(vehiculo);
    return vehiculo;
}

void HandlerVehiculos::eliminarVehiculo(string matricula) {
    if (existeVehiculo(matricula)) {
        delete coleccionVehiculos[matricula];
        coleccionVehiculos.erase(matricula);
    }
}

map<string, Vehiculo*> HandlerVehiculos::getColeccionVehiculo() {
    return coleccionVehiculos;
}

Vehiculo* HandlerVehiculos::getVehiculo(string matricula) {
    if (existeVehiculo(matricula)) {
        return coleccionVehiculos[matricula];
    }
    return nullptr;
}
#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(string matricula, string marca, int capacidad) {
    this->matricula = matricula;
    this->marca = marca;
    this->capacidad = capacidad;
}

string DTVehiculosConductor::getMatricula() {
    return this->matricula;
}

string DTVehiculosConductor::getMarca() {
    return this->marca;
}

int DTVehiculosConductor::getCapacidad() {
    return this->capacidad;
}

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& otro) const {
    return matricula < otro.matricula;
}
#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(string matricula, string modelo, int capacidad) {
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}

string DTVehiculosConductor::getMatricula() {
    return this->matricula;
}

string DTVehiculosConductor::getModelo() {
    return this->modelo;
}

int DTVehiculosConductor::getCapacidad() {
    return this->capacidad;
}

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& otro) const {
    return matricula < otro.matricula;
}
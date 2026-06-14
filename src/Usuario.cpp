#include "../include/Usuario.h"
#include "../include/Calificacion.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() {
    return this->nickname;
}

std::string Usuario::getNombre() {
    return this->nombre;
}

float Usuario::getCalificacionProm() {
    if (calificacionesRecibidas.empty())
        return 5;
    float suma = 0;
    for (Calificacion* c : calificacionesRecibidas)
        suma += c->getPuntaje();
    return suma / calificacionesRecibidas.size();
}

bool Usuario::existeCalificacion(std::string nicknameCalificado, int codigoMem) {
    for (Calificacion* c : calificacionesRealizadas) {
        if (c->existeCalificacion(nicknameCalificado, codigoMem))
            return true;
    }
    return false;
}

Calificacion* Usuario::calificarUsuario(int puntaje, DTFecha fechaActual) {
    Calificacion* c = new Calificacion(fechaActual, puntaje);
    this->calificacionesRealizadas.insert(c);
    c->linkRealiza(this);    
    return c;
}

void Usuario::linkCalifica(Calificacion* c) {
    this->calificacionesRecibidas.insert(c);
}

void Usuario::desvincularRealizada(Calificacion* c) {
    calificacionesRealizadas.erase(c);
}
void Usuario::desvincularRecibida(Calificacion* c) {
    calificacionesRecibidas.erase(c);
}
#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->calificacionPromedio = 0;
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() {
    return this->nickname;
}

std::string Usuario::getNombre() {
    return this->nombre;
}

bool Usuario::existeCalificacion(std::string nicknameCalificado, int codigoMem) {
    
    return false;
}

void Usuario::calificarUsuario(int puntaje, DTFecha fechaActual) {
    
}

void Usuario::linkCalifica() {
    
}
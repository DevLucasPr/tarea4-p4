#include "../include/DTUsuarioViaje.h"

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo) {
    this->nickname = nickname;
    this->tipo = tipo;
    this->orden = 0;
}

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo, int orden) {
    this->nickname = nickname;
    this->tipo = tipo;
    this->orden = orden;
}

std::string DTUsuarioViaje::getNickname() {
    return nickname;
}
TipoUsuario DTUsuarioViaje::getTipo() {
    return tipo;
}

bool DTUsuarioViaje::operator<(const DTUsuarioViaje& otro) const {
    return orden < otro.orden;
}
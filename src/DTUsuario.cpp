#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->grupo = 0;
}

DTUsuario::DTUsuario(std::string nickname, std::string nombre, int grupo) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->grupo = grupo;
}

std::string DTUsuario::getNickname() { 
    return nickname; 
}
std::string DTUsuario::getNombre() {
    return nombre;
}

bool DTUsuario::operator<(const DTUsuario& otro) const {
    if (grupo != otro.grupo)
        return grupo < otro.grupo;
    return nickname < otro.nickname;
}
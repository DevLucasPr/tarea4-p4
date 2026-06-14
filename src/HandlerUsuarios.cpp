#include "../include/HandlerUsuarios.h"
#include "../include/Usuario.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"

using namespace std;

HandlerUsuarios* HandlerUsuarios::instancia = nullptr;

HandlerUsuarios::HandlerUsuarios() {}

HandlerUsuarios::~HandlerUsuarios() {

}

bool HandlerUsuarios::existeUsuario(string nickname) {
    return usuarios.find(nickname) != usuarios.end(); // forma correcta en un map
}

bool HandlerUsuarios::existePasajero(string nickname) {
    return pasajeros.find(nickname) != pasajeros.end();
}

bool HandlerUsuarios::existeConductor(string nickname) {
    return conductores.find(nickname) != conductores.end();
}

void HandlerUsuarios::agregarUsuario(Usuario* usuario) {
    usuarios.insert({usuario->getNickname(), usuario});
}

void HandlerUsuarios::agregarPasajero(Pasajero* pasajero) {
    pasajeros.insert({pasajero->getNickname(), pasajero});
    agregarUsuario(pasajero);
}

void HandlerUsuarios::agregarConductor(Conductor* conductor) {
    conductores.insert({conductor->getNickname(), conductor});
    agregarUsuario(conductor);
}

map<string, Usuario*> HandlerUsuarios::getUsuarios() {
    return usuarios;
}

map<string, Pasajero*> HandlerUsuarios::getPasajeros() {
    return pasajeros;
}

set<Pasajero*> HandlerUsuarios::listarPasajeros() {
    set<Pasajero*> resultado;
    for (map<string, Pasajero*>::iterator it = pasajeros.begin(); it != pasajeros.end(); ++it)
        resultado.insert(it->second);
    return resultado;
}

map<string, Conductor*> HandlerUsuarios::getConductores() {
    return conductores;
}

Usuario* HandlerUsuarios::getUsuario(string nickname) {
    if (existeUsuario(nickname)) {
        return usuarios[nickname];
    }
    return nullptr;
}

Pasajero* HandlerUsuarios::getPasajero(string nickname) {
    if (existePasajero(nickname)) {
        return pasajeros[nickname];
    }
    return nullptr;
}

Conductor* HandlerUsuarios::getConductor(string nickname) {
    if (existeConductor(nickname)) {
        return conductores[nickname];
    }
    return nullptr;
}

void HandlerUsuarios::eliminarUsuario(string nickname) {
    if (existeUsuario(nickname)) {
        delete usuarios[nickname];
        usuarios.erase(nickname);
    }
}

void HandlerUsuarios::eliminarPasajero(string nickname) {
    if (existePasajero(nickname)) {
        eliminarUsuario(nickname);
        pasajeros.erase(nickname);
    }
}

void HandlerUsuarios::eliminarConductor(string nickname) {
    if (existeConductor(nickname)) {
        eliminarUsuario(nickname);
        conductores.erase(nickname);
    }
}

HandlerUsuarios* HandlerUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new HandlerUsuarios();
    }
    return instancia;
}
#include "../include/HandlersUsuarios.h"
#include "../include/Usuario.h"
#include "../include/Pasajero.h"

using namespace std;

HandlersUsuarios* HandlersUsuarios::instancia = nullptr;

HandlersUsuarios::HandlersUsuarios() {}

HandlersUsuarios::~HandlersUsuarios() {
    
}

bool HandlersUsuarios::existeUsuario(string nickname) {
    return usuarios.find(nickname) != usuarios.end();
}

bool HandlersUsuarios::existePasajero(string nickname) {
    return pasajeros.find(nickname) != pasajeros.end();
}

bool HandlersUsuarios::existeConductor(string nickname) {
    return conductores.find(nickname) != conductores.end();
}

void HandlersUsuarios::agregarUsuario(Usuario* usuario) {
    usuarios[usuario->getNickname()] = usuario;
}

void HandlersUsuarios::agregarPasajero(Pasajero* pasajero) {
    pasajeros[pasajero->getNickname()] = pasajero;
    agregarUsuario(pasajero);
}

void HandlersUsuarios::agregarConductor(Conductor* conductor) {
    conductores[conductor->getNickname()] = conductor;
    agregarUsuario(conductor);
}

set<string> HandlersUsuarios::listarUsuarios() {
    set<string> lista;
    for (const auto& pair : usuarios) {
        lista.insert(pair.first);
    }
    return lista;
}

map<string, Usuario*> HandlersUsuarios::getUsuarios() {
    return usuarios;
}

map<string, Pasajero*> HandlersUsuarios::getPasajeros() {
    return pasajeros;
}

map<string, Conductor*> HandlersUsuarios::getConductores() {
    return conductores;
}

Usuario* HandlersUsuarios::getUsuario(string nickname) {
    if (existeUsuario(nickname)) {
        return usuarios[nickname];
    }
    return nullptr;
}

Pasajero* HandlersUsuarios::getPasajero(string nickname) {
    if (existePasajero(nickname)) {
        return pasajeros[nickname];
    }
    return nullptr;
}

Conductor* HandlersUsuarios::getConductor(string nickname) {
    if (existeConductor(nickname)) {
        return conductores[nickname];
    }
    return nullptr;
}

void HandlersUsuarios::eliminarUsuario(string nickname) {
    if (existeUsuario(nickname)) {
        delete usuarios[nickname];
        usuarios.erase(nickname);
    }
}

void HandlersUsuarios::eliminarPasajero(string nickname) {
    if (existePasajero(nickname)) {
        eliminarUsuario(nickname);
        pasajeros.erase(nickname);
    }
}

void HandlersUsuarios::eliminarConductor(string nickname) {
    if (existeConductor(nickname)) {
        eliminarUsuario(nickname);
        conductores.erase(nickname);
    }
}

HandlersUsuarios* HandlersUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new HandlersUsuarios();
    }
    return instancia;
}
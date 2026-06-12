#include "../include/CtrlUsuarios.h"

#include "../include/Conductor.h"
#include "../include/Pasajero.h"
#include "../include/DTVehiculosConductor.h"
#include "../include/DTListarViaje.h"
#include "../include/DTCalificarUsuario.h"
#include "../include/Fabrica.h"

CtrlUsuarios* CtrlUsuarios::instancia = nullptr;

CtrlUsuarios::CtrlUsuarios() {
    codigoMem = 0;
    nicknameMem = "";
}

CtrlUsuarios::~CtrlUsuarios() {}

CtrlUsuarios* CtrlUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new CtrlUsuarios();
    }
    return instancia;
}

bool CtrlUsuarios::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
º   if (HandlersUsuarios::getInstance()->existeUsuario(nickname)) {
        return false;
    }
    Pasajero* pasajero = new Pasajero(nickname, nombre, contrasena, email, ci);
    HandlersUsuarios::getInstance()->agregarPasajero(pasajero);
    return true;
}

bool CtrlUsuarios::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) {
    if (HandlersUsuarios::getInstance()->existeUsuario(nickname)) {
        return false;
    }
    Conductor* conductor = new Conductor(nickname, nombre, contrasena, email, libretas);
    HandlersUsuarios::getInstance()->agregarConductor(conductor);
    return true;
}

std::set<DTVehiculosConductor> CtrlUsuarios::listarVehiculosConductor(std::string nickname) {
    std::set<DTVehiculosConductor> dtVehiculos;
    Conductor* conductor = HandlersUsuarios::getInstance()->getConductor(nickname);
    if (conductor != nullptr) {
        dtVehiculos = conductor->listarVehiculos();
    }
    return dtVehiculos;
}

int CtrlUsuarios::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    Usuario* usuario = HandlersUsuarios::getInstance()->getUsuario(nickname);
    if (usuario != nullptr) {
        Conductor* conductor = dynamic_cast<Conductor*>(usuario);
        if (conductor != nullptr) {
            return conductor->agregarVehiculo(matricula, capacidad, marca, modelo, tipo);
        }
    }
    return -1;
}

std::set<DTListarViaje> CtrlUsuarios::listarViajes(std::string nickname) {
    std::set<DTListarViaje> dtViajes;
    Usuario* usuario = HandlersUsuarios::getInstance()->getUsuario(nickname);
    if (usuario != nullptr) {
        for (const auto& viaje : usuario->getViajes()) {
            dtViajes.insert(DTListarViaje(viaje->getCodigo(), viaje->getOrigen(), viaje->getDestino(), viaje->getFechaHora()));
        }
    }
    return dtViajes;
}

std::set<std::string> CtrlUsuarios::listarPasajeros() {
    std::set<std::string> pasajeros;
    for (const auto& pasajero : HandlersUsuarios::getInstance()->listarPasajeros()) {
        pasajeros.insert(pasajero->getNickname());
    }
    return pasajeros;
}

bool CtrlUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    Usuario* usuario = HandlersUsuarios::getInstance()->getUsuario(nicknameCalificado);
    if (usuario != nullptr) {
        usuario->agregarCalificacion(calificacion);
        return true;
    }
    return false;
}
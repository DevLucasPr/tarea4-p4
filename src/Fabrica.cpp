#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorViajes.h"
#include "../include/ControladorUsuarios.h"
#include "../include/HandlerUsuarios.h"
#include "../include/HandlerViajes.h"
#include "../include/HandlerVehiculos.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

IControladorViajes* Fabrica::getIControladorViajes(){
    return ControladorViajes::getInstance();
}

IControladorUsuarios* Fabrica::getIControladorUsuarios(){
    return ControladorUsuarios::getInstance();
}

Fabrica::~Fabrica() {}

// Libera toda la memoria del sistema 
void Fabrica::destroy() {
    HandlerUsuarios::destroy();
    HandlerViajes::destroy();
    HandlerVehiculos::destroy();
    ControladorUsuarios::destroy();
    ControladorViajes::destroy();
    ControladorFechaActual::destroy();
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}
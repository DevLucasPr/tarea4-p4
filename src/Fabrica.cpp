#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorViajes.h"
#include "../include/ControladorUsuarios.h"

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

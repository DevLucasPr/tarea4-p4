#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IControladorViajes.h"
#include "IControladorUsuarios.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstance();
    static void destroy();
    ~Fabrica();

    IControladorFechaActual* getIControladorFechaActual();
    IControladorViajes* getIControladorViajes();
    IControladorUsuarios* getIControladorUsuarios();
    
};

#endif

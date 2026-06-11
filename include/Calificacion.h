#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
#include "Usuario.h"
#include "Reserva.h"
#include <string>

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* usuarioCalificado;     //pseudoatributo para generar la asociacion
    Reserva* reservaAsociada;       //  ""

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
    bool Calificacion::existeCalificacion(std::string nicknameCalificado, int codigoMem);
};

#endif


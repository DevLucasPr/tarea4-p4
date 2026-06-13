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
    Reserva* reservaAsociada;       

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    int getPuntaje();

    bool existeCalificacion(string nicknameCalificado, int codigoMem);
    void linkCalifica(Usuario* usuarioCalificado);
    void linkReserva(Reserva* reservaAsociada);
    void linkRealiza(Usuario* u);
    void eliminar();
};

#endif

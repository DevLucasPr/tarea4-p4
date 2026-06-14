#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "Pasajero.h"
#include "Calificacion.h"
#include <set>

using namespace std;
class Viaje;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero;
    Viaje* viaje;
    set<Calificacion*> calificaciones;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    
    int getAsientosReservados();
    DTFecha getFecha();
    Pasajero* getPasajero();

    DTListarViaje listarViajesReserva();

    //Devuelve true si viaje.codigo coincide con el codigoMem dado
    bool estaAsociadoViajeACalif(int codigoMem);

    //Agrega la calificacion a la coleccion de calificaciones si el codigoMem es el mismo que this->viaje.codigo
    void linkReservaViaje(int codigoMem, Calificacion *calificacion);

    void eliminar();

    ~Reserva();
};

#endif

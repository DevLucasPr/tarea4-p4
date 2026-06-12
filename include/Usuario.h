#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include "DTListarViaje.h"
#include "DTFecha.h"

class Calificacion;

class Usuario {
protected:
    string nickname;
    string nombre;
    string contrasena;
    string email;
    set<Calificacion*> calificacionesRealizadas;
    set<Calificacion*> calificacionesRecibidas;

    
public:
    Usuario(string nickname, string nombre, string contrasena, string email);
    virtual ~Usuario();

    string getNickname();
    string getNombre();
    float getCalificacionProm();

    virtual set<DTListarViaje> listarViajesUsuario() = 0;
    virtual bool esPasajero() = 0;

    bool existeCalificacion(string nicknameCalificado, int codigoMem);
    Calificacion* calificarUsuario(int puntaje, DTFecha fechaActual);
    void linkCalifica(Calificacion* c);
};

#endif
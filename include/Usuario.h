#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include "DTListarViaje.h"
#include "DTFecha.h"

class Calificacion;

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::set<Calificacion*> calificacionesRealizadas;
    std::set<Calificacion*> calificacionesRecibidas;

    
public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    std::string getNickname();
    std::string getNombre();
    float getCalificacionProm();

    virtual std::set<DTListarViaje*> listarViajesUsuario() = 0;
    virtual bool esPasajero() = 0;

    bool existeCalificacion(std::string nicknameCalificado, int codigoMem);
    Calificacion* calificarUsuario(int puntaje, DTFecha fechaActual);
    void linkCalifica(Calificacion* c);
};

#endif
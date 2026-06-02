#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include "DTListarViaje.h"
#include "DTFecha.h

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    float calificacionPromedio;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    std::string getNickname();
    std::string getNombre();

    virtual std::set<DTListarViaje*> listarViajesUsuario() = 0;
    virtual bool esPasajero() = 0;

    bool existeCalificacion(std::string nicknameCalificado, int codigoMem);
    void calificarUsuario(int puntaje, DTFecha fechaActual);
    void linkCalifica();
};

#endif
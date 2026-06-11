#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

bool Calificacion::existeCalificacion(std::string nicknameCalificado, int codigoMem){
    
    bool existe = false;
    if(usuarioCalificado != nullptr){
        std:: string nickname = usuarioCalificado->getNickname();

        if((reservaAsociada != nullptr)&&(nickname==nicknameCalificado)){
            existe= reservaAsociada->estaAsociadoViajeACalif(codigoMem);
        }
    }
    return existe;
}

void Calificacion::linkCalifica(Usuario usuarioCalificado){
    this->usuarioCalificado= usuarioCalificado;
}

void Calificacion::linkReserva(Reserva reservaAsociada){
    this->reservaAsociada= reservaAsociada;
}

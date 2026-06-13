#include "../include/Calificacion.h"
 
Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioCalificador = nullptr;
    this->usuarioCalificado = nullptr;
    this->reservaAsociada = nullptr;
}
 
Calificacion::~Calificacion() {}
 
int Calificacion::getPuntaje(){
    return this->puntaje;
}
 
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
 
void Calificacion::linkCalifica(Usuario* usuarioCalificado){
    this->usuarioCalificado= usuarioCalificado;
}
 
void Calificacion::linkReserva(Reserva* reservaAsociada){
    this->reservaAsociada= reservaAsociada;
}
 
void Calificacion::linkRealiza(Usuario* u) {
    this->usuarioCalificador = u;
}
 
void Calificacion::eliminar() {
    if (usuarioCalificador != nullptr)
        usuarioCalificador->desvincularRealizada(this);
    if (usuarioCalificado != nullptr)
        usuarioCalificado->desvincularRecibida(this);
}
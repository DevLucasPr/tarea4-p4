#include "../include/Calificacion.h"
#include "../include/Usuario.h"
#include "../include/Reserva.h"
 
Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioCalificador = NULL;
    this->usuarioCalificado = NULL;
    this->reservaAsociada = NULL;
}
 
Calificacion::~Calificacion() {}
 
int Calificacion::getPuntaje(){
    return this->puntaje;
}
 
bool Calificacion::existeCalificacion(std::string nicknameCalificado, int codigoMem){
    
    bool existe = false;
    if(usuarioCalificado != NULL){
        std:: string nickname = usuarioCalificado->getNickname();
 
        if((reservaAsociada != NULL)&&(nickname==nicknameCalificado)){
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
    if (usuarioCalificador != NULL)
        usuarioCalificador->desvincularRealizada(this);
    if (usuarioCalificado != NULL)
        usuarioCalificado->desvincularRecibida(this);
}
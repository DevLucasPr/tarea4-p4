#include "../include/HandlerViajes.h"

HandlerViajes *HandlerViajes::instancia = nullptr;

HandlerViajes::HandlerViajes() {};

HandlerViajes *HandlerViajes::getInstance(){
    if (instancia == NULL)
        instancia = new HandlerViajes();
    return instancia;
}

void HandlerViajes::agregarViaje(Viaje *viaje){
    coleccionViajes.insert({viaje->getCodigo(), viaje});
}

void HandlerViajes::eliminarViaje(int codigo) {
    Viaje* viaje = coleccionViajes[codigo];
    viaje->eliminar();  
    coleccionViajes.erase(coleccionViajes.find(codigo));  
    delete viaje;   
}

bool HandlerViajes::existeViaje(int codigoViajes){
    return coleccionViajes.find(codigoViajes) != coleccionViajes.end();
}

void HandlerViajes::crearViaje(int codigo, DTFecha fecha, string origen, string destino, int asientos, float precio){
   Viaje* viaje = new Viaje(codigo,fecha, origen, destino, asientos, precio);
   agregarViaje(viaje);
}

map<int, Viaje*> HandlerViajes::getColeccionViaje(){
    return coleccionViajes;
};

Viaje* HandlerViajes::getViaje(int codigo){
    return coleccionViajes[codigo];
};

HandlerViajes::~HandlerViajes(){
    for (map<int, Viaje *>::iterator it = this->coleccionViajes.begin(); it != this->coleccionViajes.end(); it++)
        delete it->second;
    this->coleccionViajes.clear();
}
#ifndef HANDLERVIAJES_H
#define HANDLERVIAJES_H

#include "Viaje.h"

#include <map>
#include <string>

using namespace std;

class Viaje;

class HandlerViajes {
private:
	map<int, Viaje*> coleccionViajes;
	static HandlerViajes* instancia;
	HandlerViajes();

public:
	static HandlerViajes* getInstance();

	void agregarViaje(Viaje* viaje);
	void eliminarViaje(int codigo);
	bool existeViaje(int codigo);
	void crearViaje(int codigo, DTFecha fecha, string origen, string destino, int asientos, float precio);

	map<int, Viaje*> getColeccionViaje();

	//PRE: Existe un viaje en la coleccion tal que codigo == viaje.codigo
	Viaje* getViaje(int codigo);
	
	static void destroy();
	~HandlerViajes();
};

#endif
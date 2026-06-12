#ifndef HANDLERVehiculos_H
#define HANDLERVehiculos_H

#include "Vehiculo.h"

#include <map>
#include <string>

using namespace std;

class Vehiculo;

class HandlerVehiculos {
private:
	map<int, Vehiculo*> coleccionVehiculos;
	static HandlerVehiculos* instancia;
	HandlerVehiculos();

public:
	static HandlerVehiculos* getInstance();

	void agregarVehiculo(Vehiculo* Vehiculo);
	void eliminarVehiculo(string matricula);
	bool existeVehiculo(string matricula);

	map<string, Vehiculo*> getColeccionVehiculo();

	//PRE: Existe un Vehiculo en la coleccion tal que matricula == Vehiculo.matricula
	Vehiculo* getVehiculo(string matricula);
	
	static void destroy();
	~HandlerVehiculos();
};

#endif
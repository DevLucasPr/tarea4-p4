#ifndef HANDLERSVIAJES_H
#define HANDLERSVIAJES_H

#include <set>
#include <string>

class Viaje;

class HandlerViajes {
private:
	std::set<Viaje*> viajes;
	static HandlerViajes* instancia;

	HandlerViajes();

public:
	static HandlerViajes* getInstance();
	Viaje* getViaje();
};

#endif
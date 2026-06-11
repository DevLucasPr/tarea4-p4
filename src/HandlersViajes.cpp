#include "../include/HandlersViajes.h"
#include "../include/Viaje.h"

using namespace std;

HandlerViajes* HandlerViajes::instancia = nullptr;

HandlerViajes::HandlerViajes() {}

HandlerViajes* HandlerViajes::getInstance() {
	if (instancia == nullptr) {
		instancia = new HandlerViajes();
	}
	return instancia;
}

Viaje* HandlerViajes::getViaje() {
	if (viajes.empty()) {
		return nullptr;
	}
	return *viajes.begin();
}
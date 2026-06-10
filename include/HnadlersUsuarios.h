#ifndef HNADLERSUSUARIOS_H
#define HNADLERSUSUARIOS_H

#include <set>
#include <string>

class Usuario;
class Pasajero;
class Conductor;

class HandlerUsuarios {
private:
	std::set<Usuario*> usuarios;
	std::set<Pasajero*> pasajeros;
	std::set<Conductor*> conductores;

	static HandlerUsuarios* instancia;

	HandlerUsuarios() = default;

public:
	HandlerUsuarios(const HandlerUsuarios&) = delete;
	HandlerUsuarios& operator=(const HandlerUsuarios&) = delete;

	static HandlerUsuarios* getInstance();
	Pasajero* getPasajero(const std::string& nickname);
};

#endif

#ifndef HANDLERSUSUARIOS_H
#define HANDLERSUSUARIOS_H

#include <set>
#include <string>

class Usuario;
class Pasajero;
class Conductor;

class HandlersUsuarios {
private:
	std::set<Usuario*> usuarios;
	std::set<Pasajero*> pasajeros;
	std::set<Conductor*> conductores;

	static HandlersUsuarios* instancia;

	HandlersUsuarios();

public:
	static HandlersUsuarios* getInstance();
};

#endif

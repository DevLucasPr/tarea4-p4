#ifndef HANDLERUSUARIOS_H
#define HANDLERUSUARIOS_H

#include <set>
#include <map>
#include <string>

class Usuario;
class Pasajero;
class Conductor;

class HandlerUsuarios {
private:
	std::map<std::string, Usuario*> usuarios;
	std::map<std::string, Pasajero*> pasajeros;
	std::map<std::string, Conductor*> conductores;

	static HandlerUsuarios* instancia;

	HandlerUsuarios();

public:
	~HandlerUsuarios();
	
	bool existeUsuario(std::string nickname);
	bool existePasajero(std::string nickname);
	bool existeConductor(std::string nickname);
	void agregarUsuario(Usuario* usuario);
	void agregarPasajero(Pasajero* pasajero);
	void agregarConductor(Conductor* conductor);
	std::map<std::string, Usuario*> getUsuarios();
	std::map<std::string, Pasajero*> getPasajeros();
	std::set<Pasajero*> listarPasajeros();
	std::map<std::string, Conductor*> getConductores();
	Usuario* getUsuario(std::string nickname);
	Pasajero* getPasajero(std::string nickname);
	Conductor* getConductor(std::string nickname);
	void eliminarUsuario(std::string nickname);
	void eliminarPasajero(std::string nickname);
	void eliminarConductor(std::string nickname);

	static HandlerUsuarios* getInstance();
	static void destroy();
};

#endif
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
	~HandlersUsuarios();

	bool existeUsuario(std::string nickname);
	void agregarPasajero(Pasajero* pasajero);
	void agregarConductor(Conductor* conductor);
	std::set<Usuario*> listarUsuarios();
	Usuario* getUsuario(std::string nickname);
	Pasajero* getPasajero(std::string nickname);
	Conductor* getConductor(std::string nickname);
	std::set<DTVehiculosConductor> listarVehiculos(std::string nickname);
	bool existeCalibreta(std::string nickname,std::string nicknameCalificado,int codigoMem);
	void crearCalificacion(std::string nicknameCalificado,int calificacion);

	static HandlersUsuarios* getInstance();
};

#endif

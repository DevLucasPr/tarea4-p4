#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include <set>
#include <string>

#include "TipoLibreta.h"
#include "TipoVehiculo.h"

class DTVehiculosConductor;
class DTListarViaje;

class ControladorUsuarios {
private:
	int codigoMem;
	std::string nicknameMem;
	static ControladorUsuarios* instancia;

	handlerUsuarios* handlerUsuarios;

	ControladorUsuarios();

public:
	~ControladorUsuarios();

	bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
	bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas);
	std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
	int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
	std::set<DTListarViaje> listarViajes(std::string nickname);
	std::set<std::string> listarPasajeros();
	bool calificarUsuario(std::string nicknameCalificado, int calificacion);

	static ControladorUsuarios* getInstance();
};

#endif

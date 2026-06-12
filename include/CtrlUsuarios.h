#ifndef CTRLUSUARIOS_H
#define CTRLUSUARIOS_H

#include <set>
#include <string>

#include "TipoLibreta.h"
#include "TipoVehiculo.h"

class DTVehiculosConductor;
class DTListarViaje;

class CtrlUsuarios {
private:
	int codigoMem;
	std::string nicknameMem;
	static CtrlUsuarios* instancia;

	handlerUsuarios* handlerUsuarios;

	CtrlUsuarios();

public:
	~CtrlUsuarios();

	bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci);
	bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas);
	std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nickname);
	int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
	std::set<DTListarViaje> listarViajes(std::string nickname);
	std::set<std::string> listarPasajeros();
	bool calificarUsuario(std::string nicknameCalificado, int calificacion);

	static CtrlUsuarios* getInstance();
};

#endif

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
	string nicknameMem;
	static CtrlUsuarios* instancia;

	handlerUsuarios* handlerUsuarios;

	CtrlUsuarios();

public:
	~CtrlUsuarios();

	bool altaPasajero(string nickname, string nombre, string contrasena, string email, string ci);
	bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libretas);
	set<DTVehiculosConductor> listarVehiculosConductor(string nickname);
	int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo);
	set<DTListarViaje> listarViajes(string nickname);
	set<string> listarPasajeros();
	bool calificarUsuario(string nicknameCalificado, int calificacion);

	static CtrlUsuarios* getInstance();
};

#endif

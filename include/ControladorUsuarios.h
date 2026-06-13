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
	string nicknameMem;
	static ControladorUsuarios* instancia;

	HandlerVehiculos *handlerVehiculos;
    HandlersUsuarios *handlerUsuarios;
	HandlerViajes *handlerViajes;

	ControladorUsuarios();

public:
	~ControladorUsuarios();

	bool altaPasajero(string nickname, string nombre, string contrasena, string email, string ci);
	bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libretas);
	set<DTVehiculosConductor> listarVehiculosConductor(string nickname);
	int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo);
	set<DTUsuario> listarUsuarios();
	set<DTListarViaje> listarViajes(string nickname);
	set<string> listarPasajeros();
	bool calificarUsuario(string nicknameCalificado, int calificacion);

	static ControladorUsuarios* getInstance();
};

#endif

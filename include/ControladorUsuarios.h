#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include "IControladorUsuarios.h"
#include <set>
#include <string>
using namespace std;

#include "TipoLibreta.h"
#include "TipoVehiculo.h"

class DTVehiculosConductor;
class DTListarViaje;
class DTUsuario;
class HandlerVehiculos;
class HandlerUsuarios;
class HandlerViajes;

class ControladorUsuarios : public IControladorUsuarios {
private:
	int codigoMem;
	string nicknameMem;
	static ControladorUsuarios* instancia;

	HandlerVehiculos *handlerVehiculos;
    HandlerUsuarios *handlerUsuarios;
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

	int getCodigoMem();
	string getNicknameMem();

	static ControladorUsuarios* getInstance();
	static void destroy();
};

#endif
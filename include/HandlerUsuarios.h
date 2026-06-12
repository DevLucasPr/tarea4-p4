#ifndef HANDLERSUSUARIOS_H
#define HANDLERSUSUARIOS_H

#include <set>
#include <map>
#include <string>

using namespace std;

class Usuario;
class Pasajero;
class Conductor;

class HandlersUsuarios {
private:
	set<Usuario*> usuarios;
	set<Pasajero*> pasajeros;
	set<Conductor*> conductores;

	static HandlersUsuarios* instancia;

	HandlersUsuarios();

public:
	~HandlersUsuarios();

	bool existeUsuario(string nickname);
	void agregarPasajero(Pasajero* pasajero);
	void agregarConductor(Conductor* conductor);
	set<Usuario*> listarUsuarios();
	Usuario* getUsuario(string nickname);
	Pasajero* getPasajero(string nickname);
	Conductor* getConductor(string nickname);
	set<DTVehiculosConductor> listarVehiculos(string nickname);
	bool existeCalibreta(string nickname,string nicknameCalificado,int codigoMem);
	void crearCalificacion(string nicknameCalificado,int calificacion);

	static HandlersUsuarios* getInstance();
};

#endif

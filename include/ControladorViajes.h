#ifndef CONTROLADORVIAJES_H
#define CONTROLADORVIAJES_H

#include "IControladorViajes.h"
#include "HandlerViajes.h"
#include "HandlerVehiculos.h"
#include "HandlerUsuarios.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "DTDetalleViaje.h"

#include <set>
#include <string>

using namespace std;

class DTFecha;
class DTConsultaViaje;

class ControladorViajes : public IControladorViajes{
private:
	ControladorViajes();
	int codigoMem;
	int ultimoViaje;
	static ControladorViajes *instancia;

	HandlerVehiculos *handlerVehiculos;
    HandlerUsuarios *handlerUsuarios;
	HandlerViajes *handlerViajes;

public:
	static ControladorViajes *getInstance();
	static void destroy();
	
	//Crear un nuevo viaje en el sistema con los datos proporcionados relacionandolo
	//con el vehículo y notificar si se pudo crear con éxito.
	//PRE: Existe una instancia de Vehículo v con v.matricula = matricula
	bool altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precio);

	//PRE: Existe una instancia de Viaje vi con vi.codigo = codigo
	//PRE: Existe una instancia de Pasajero p con p.nickname = nickname
	// Crea una reserva para el pasajero y el viaje pasado por parámetro
	bool generarReserva(string nickname, int codigo, int asientos);

	set<DTConsultaViaje> consultarViajes(DTFecha fecha, string origen, string destino, int asientos);
	set<DTUsuarioViaje> listarUsuariosViaje(int codigo);
	set<DTListarViaje> listarViajes();

	int getCodigoMem();
	int getUltimoViaje();

	DTDetalleViaje detalleViaje(int codigo);

	void eliminarViaje();
	void cancelarEliminarViaje();


	~ControladorViajes();
};
#endif
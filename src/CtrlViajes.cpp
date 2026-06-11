#include "../include/CtrlViajes.h"

#include "../include/ControladorFechaActual.h"
#include "../include/DTConsultaViaje.h"
#include "../include/DTFecha.h"
#include "../include/Fabrica.h"

CtrlViajes *CtrlViajes::instancia = nullptr;

CtrlViajes::CtrlViajes() {
	
}

set<DTConsultaViaje> CtrlViajes::consultarViajes(DTFecha fecha, string origen, string destino, int asientos) {
	set<DTConsultaViaje> resultado;

	if (asientos <= 0) {
		return resultado;
	}

	for (const auto &viaje : viajesRegistrados()) {
		DTFecha fechaViaje = viaje.fecha;
		if (!(fechaViaje == fecha)) {
			continue;
		}
		if (viaje.origen != origen || viaje.destino != destino) {
			continue;
		}
		if (asientosDisponibles(viaje) < asientos) {
			continue;
		}

		resultado.insert(DTConsultaViaje(
			viaje.codigo,
			viaje.marca,
			viaje.modelo,
			viaje.conductor,
			viaje.calificacionProm,
			viaje.precio * asientos));
	}

	return resultado;
}

bool CtrlViajes::generarReserva(string nickname, int codigo, int asientos) {
	if (nickname.empty() || asientos <= 0) {
		return false;
}

	ViajeRegistro *viaje = buscarViaje(codigo);
	if (viaje == nullptr) {
		return false;
	}

	if (asientosDisponibles(*viaje) < asientos) {
		return false;
	}

	IControladorFechaActual *controladorFecha = Fabrica::getInstance()->getIControladorFechaActual();
	viaje->reservas.push_back(ReservaRegistro{nickname, asientos, controladorFecha->getFecha()});
	codigoMem += 1;
	return true;
}

CtrlViajes *CtrlViajes::getInstance() {
	if (instancia == nullptr) {
		instancia = new CtrlViajes();
	}
	return instancia;
}

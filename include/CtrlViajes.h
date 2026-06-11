#ifndef CTRLVIAJES_H
#define CTRLVIAJES_H

#include <set>
#include <string>

class DTFecha;
class DTConsultaViaje;

class CtrlViajes {
private:
	int codigoMem;
	int ultimoViaje;
	static CtrlViajes *instancia;

	CtrlViajes();

public:
    ~CtrlViajes();

	std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
	bool generarReserva(std::string nickname, int codigo, int asientos);

	static CtrlViajes *getInstance();
};

#endif

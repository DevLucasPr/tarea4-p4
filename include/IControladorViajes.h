#ifndef ICONTROLADORViajes_H
#define ICONTROLADORViajes_H

#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "DTConsultaViaje.h"
#include "DTFecha.h"
#include "DTUsuarioViaje.h"
#include "DTDetalleViaje.h"
#include "DTListarViaje.h"

#include <string>
#include <set>

using namespace std;

class IControladorViajes
{
    public:
        virtual bool altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precio) = 0;
        virtual bool generarReserva(string nickname, int codigo, int asientos) = 0;

        virtual set<DTConsultaViaje> consultarViajes(DTFecha fecha, string origen, string destino, int asientos) = 0;
        virtual set<DTUsuarioViaje> listarUsuariosViaje(int codigo) = 0;
        virtual set<DTListarViaje> listarViajes() = 0;
        
        virtual DTDetalleViaje detalleViaje(int codigo) = 0;

        virtual void eliminarViaje() = 0;
        virtual void cancelarEliminarViaje() = 0;

        virtual ~IControladorViajes() = default;
};
#endif
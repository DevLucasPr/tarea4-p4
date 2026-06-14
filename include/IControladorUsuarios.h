#ifndef ICONTROLADORUsuarios_H
#define ICONTROLADORUsuarios_H

#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTUsuario.h"

#include <string>
#include <set>

using namespace std;

class IControladorUsuarios
{
    public:
        virtual bool altaPasajero(string nickname, string nombre, string contrasena, string email, string ci) = 0;
        virtual bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libretas) = 0;

        virtual int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipoVehiculo) = 0;

        virtual set<DTVehiculosConductor> listarVehiculosConductor(string nickname) = 0;
        virtual set<DTListarViaje> listarViajes(string nickname) = 0;
        virtual set<DTUsuario> listarUsuarios() = 0;
        virtual set<string> listarPasajeros() = 0;

        virtual bool calificarUsuario(string nicknameCalificado, int calificacion) = 0;

        virtual ~IControladorUsuarios() = default;
};
#endif
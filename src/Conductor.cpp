#include "../include/Conductor.h"
#include "../include/Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

std::set<DTListarViaje*> Conductor::listarViajesUsuario() {
    std::set<DTListarViaje*> resultado;
    for (Vehiculo* v : vehiculos) {
        std::set<DTListarViaje> viajesV = v->listarViajesVehiculo();
        for (DTListarViaje dt : viajesV) {
            resultado.insert(new DTListarViaje(dt.getCodigo(), dt.getFecha(), dt.getOrigen(), dt.getDestino(), dt.getConductor()));
        }
    }
    return resultado;
}

bool Conductor::puedeManejarTipo(TipoVehiculo tipo) {
    for (TipoLibreta lib : libretas) {
        if (tipo == Auto && (lib == AutoProfesional || lib == AutoAmateur))
            return true;
        if (tipo == Moto && (lib == MotoProfesional || lib == MotoAmateur))
            return true;
    }
    return false;
}

bool Conductor::esPasajero() {
    return false;
}

void Conductor::linkVehiculo(Vehiculo* v) {
    vehiculos.insert(v);
}

std::set<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::set<DTVehiculosConductor> resultado;
    for (Vehiculo* v : vehiculos) {
        resultado.insert(v->getDTVehiculoConductor());
    }
    return resultado;
}

bool Conductor::hayViajesFecha(DTFecha fecha) {
    for (Vehiculo* v : vehiculos) {
        if (v->hayViajesFecha(fecha))
            return true;
    }
    return false;
}

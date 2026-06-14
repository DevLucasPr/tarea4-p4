#include "../include/ControladorUsuarios.h"

#include "../include/Conductor.h"
#include "../include/Pasajero.h"
#include "../include/Calificacion.h"
#include "../include/DTVehiculosConductor.h"
#include "../include/DTListarViaje.h"
#include "../include/ControladorViajes.h"
#include "../include/Fabrica.h"

ControladorUsuarios* ControladorUsuarios::instancia = nullptr;

ControladorUsuarios::ControladorUsuarios() {
    codigoMem = 0;
    nicknameMem = "";
}

ControladorUsuarios::~ControladorUsuarios() {}

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorUsuarios();
    }
    return instancia;
}

// Crear un nuevo pasajero con los datos proporcionados. Notifica en caso de éxito
// o de error al crear el pasajero.
bool ControladorUsuarios::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    if (HandlerUsuarios::getInstance()->existeUsuario(nickname)) {
        return false;
    }
    Pasajero* pasajero = new Pasajero(nickname, nombre, contrasena, email, ci);
    HandlerUsuarios::getInstance()->agregarPasajero(pasajero);
    return true;
}

// Crear un nuevo conductor con los datos proporcionados. Notifica en caso de
// éxito o de error al crear el conductor.
bool ControladorUsuarios::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) {
    if (HandlerUsuarios::getInstance()->existeUsuario(nickname)) {
        return false;
    }
    Conductor* conductor = new Conductor(nickname, nombre, contrasena, email, libretas);
    HandlerUsuarios::getInstance()->agregarConductor(conductor);
    return true;
}

// Devuelve un conjunto de DTVehiculosConductor con los datos de los vehículos del conductor identificado por nickname.
std::set<DTVehiculosConductor> ControladorUsuarios::listarVehiculosConductor(std::string nickname) {
    std::set<DTVehiculosConductor> dtVehiculos;
    Conductor* conductor = HandlerUsuarios::getInstance()->getConductor(nickname);
    if (conductor != nullptr) {
        dtVehiculos = conductor->listarVehiculos();
    }
    return dtVehiculos;
}

// int indicando si la operación fue exitosa o que error ocurrió (0 correcta, -1
// matrícula repetida, -2 no tiene tipo de licencia para el vehículo) 
// PRE: Existe conductor
int ControladorUsuarios::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    // matricula repetida -> la coleccion de vehiculos la maneja HandlerVehiculos
    if (HandlerVehiculos::getInstance()->existeVehiculo(matricula)) {
        return -1;
    }
    Conductor* conductor = HandlerUsuarios::getInstance()->getConductor(nickname);
    // el conductor es el Expert sobre sus libretas
    if (!conductor->puedeManejarTipo(tipo)) {
        return -2;
    }
    // HandlerVehiculos crea el vehiculo y lo agrega a la coleccion
    Vehiculo* vehiculo = HandlerVehiculos::getInstance()->crearVehiculo(matricula, capacidad, marca, modelo, tipo);
    // link Conductor <-> Vehiculo en ambos sentidos
    vehiculo->setConductor(conductor);
    conductor->linkVehiculo(vehiculo);
    return 0;
}

// Devuelve la información de nickname y nombre de todos los usuarios
std::set<DTUsuario> ControladorUsuarios::listarUsuarios() {
    std::set<DTUsuario> usuarios;
    std::map<std::string, Usuario*> listaUsuarios = HandlerUsuarios::getInstance()->getUsuarios();
    for (std::map<std::string, Usuario*>::iterator it = listaUsuarios.begin(); it != listaUsuarios.end(); ++it) {
        usuarios.insert(DTUsuario(it->first, it->second->getNombre()));
    }
    return usuarios;
}

// Devuelve la información de viajes relacionados al usuario pasado
std::set<DTListarViaje> ControladorUsuarios::listarViajes(std::string nickname) {
    std::set<DTListarViaje> dtViajes;
    Usuario* usuario = HandlerUsuarios::getInstance()->getUsuario(nickname);
    if (usuario != nullptr) {
        dtViajes = usuario->listarViajesUsuario();
    }
    this->nicknameMem = nickname;   // se guarda en memoria el nickname (caso de uso Calificar)
    return dtViajes;
}

// Devuelve los nicknames de todos los pasajeros.
std::set<std::string> ControladorUsuarios::listarPasajeros() {
    std::set<std::string> pasajeros;
    std::set<Pasajero*> listaPasajeros = HandlerUsuarios::getInstance()->listarPasajeros();
    for (std::set<Pasajero*>::iterator it = listaPasajeros.begin(); it != listaPasajeros.end(); ++it) {
        pasajeros.insert((*it)->getNickname());
    }
    return pasajeros;
}

// Genera una nueva calificación para el usuario pasado por parámetro desde el
// usuario guardado en memoria para el viaje guardado en memoria
//PRE: Existe en memoria el nickname del usuario calificador y el código del viaje, el valor de calificación es válido (entre 1 y 5)
//PRE: Existe el usuario a calificar, existe una instancia de viaje con el código dado, el usuario calificado es distinto al usuario calificador, el usuario calificado participó en el viaje dado.
bool ControladorUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    // el codigo del viaje lo guardo CtrlViajes en su memoria (listarUsuariosViaje)
    int codigoViaje = ControladorViajes::getInstance()->getCodigoMem();

    Usuario* calificador = HandlerUsuarios::getInstance()->getUsuario(this->nicknameMem);
    Usuario* calificado  = HandlerUsuarios::getInstance()->getUsuario(nicknameCalificado);

    // si ya existe una calificacion de este calificador hacia ese usuario por ese viaje -> false
    if (calificador->existeCalificacion(nicknameCalificado, codigoViaje)) {
        return false;
    }

    DTFecha fechaActual = Fabrica::getInstance()->getIControladorFechaActual()->getFecha();

    // el calificador crea la Calificacion (link realiza) y el calificado la recibe (link califica)
    Calificacion* c = calificador->calificarUsuario(calificacion, fechaActual);
    c->linkCalifica(calificado);  
    calificado->linkCalifica(c);

    // se conecta la calificacion con la Reserva del viaje correspondiente:
    // - si el calificador es Pasajero, la reserva es la de el (recorre SUS reservas)
    // - si el calificador es Conductor, la reserva es la del Pasajero calificado
    if (calificador->esPasajero()) {
        ((Pasajero*) calificador)->linkReserva(codigoViaje, c);
    } else {
        ((Pasajero*) calificado)->linkReserva(codigoViaje, c);
    }

    // se libera la memoria del caso de uso
    this->nicknameMem = "";
    this->codigoMem = 0;
    return true;
}

std::string ControladorUsuarios::getNicknameMem() {
    return this->nicknameMem;
}

int ControladorUsuarios::getCodigoMem() {
    return this->codigoMem;
}
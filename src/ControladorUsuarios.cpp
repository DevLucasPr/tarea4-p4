#include "../include/ControladorUsuarios.h"

#include "../include/Conductor.h"
#include "../include/Pasajero.h"
#include "../include/DTVehiculosConductor.h"
#include "../include/DTListarViaje.h"
#include "../include/DTCalificarUsuario.h"
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
    if (HandlersUsuarios::getInstance()->existeUsuario(nickname)) {
        return false;
    }
    Pasajero* pasajero = new Pasajero(nickname, nombre, contrasena, email, ci);
    HandlersUsuarios::getInstance()->agregarPasajero(pasajero);
    return true;
}

// Crear un nuevo conductor con los datos proporcionados. Notifica en caso de
// éxito o de error al crear el conductor.
bool ControladorUsuarios::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) {
    if (HandlersUsuarios::getInstance()->existeUsuario(nickname)) {
        return false;
    }
    Conductor* conductor = new Conductor(nickname, nombre, contrasena, email, libretas);
    HandlersUsuarios::getInstance()->agregarConductor(conductor);
    return true;
}

// Devuelve un conjunto de DTVehiculosConductor con los datos de los vehículos del conductor identificado por nickname.
std::set<DTVehiculosConductor> ControladorUsuarios::listarVehiculosConductor(std::string nickname) {
    std::set<DTVehiculosConductor> dtVehiculos;
    Conductor* conductor = HandlersUsuarios::getInstance()->getConductor(nickname);
    if (conductor != nullptr) {
        dtVehiculos = conductor->listarVehiculos();
    }
    return dtVehiculos;
}

// int indicando si la operación fue exitosa o que error ocurrió (0 correcta, -1
// matrícula repetida, -2 no tiene tipo de licencia para el vehículo) 
// PRE: Existe conductor
int ControladorUsuarios::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    Conductor* conductor = HandlersUsuarios::getInstance()->getConductor(nickname);
    if (conductor->existeMatricula(matricula)) {
        return -1; // Matrícula repetida
    }
    if (!conductor->puedeManejarTipo(tipo)) {
        return -2; // No tiene tipo de licencia para el vehículo
    }
    conductor->agregarVehiculo(matricula, capacidad, marca, modelo, tipo);
    return 0; // Operación exitosa
}

// Devuelve la información de nickname y nombre de todos los usuarios
std::set<DTUsuario> ControladorUsuarios::listarUsuarios() {
    std::set<DTUsuario> usuarios;
    std::map<std::string, Usuario*> listaUsuarios = HandlersUsuarios::getInstance()->getUsuarios();
    for (std::map<std::string, Usuario*>::iterator it = listaUsuarios.begin(); it != listaUsuarios.end(); ++it) {
        usuarios.insert(DTUsuario(it->first, it->second->getNombre()));
    }
    return usuarios;
}

// Devuelve la información de viajes relacionados al usuario pasado
std::set<DTListarViaje> ControladorUsuarios::listarViajes(std::string nickname) {
    std::set<DTListarViaje> dtViajes;
    Usuario* usuario = HandlersUsuarios::getInstance()->getUsuario(nickname);
    if (usuario != nullptr) {
        dtViajes = usuario->listarViajesUsuario(); // TENEMOS QUE PONER LA FUNCION EN USUARIO
    }
    return dtViajes;
}

// Devuelve los nicknames de todos los pasajeros.
std::set<std::string> ControladorUsuarios::listarPasajeros() {
    std::set<std::string> pasajeros;
    std::set<Pasajero*> listaPasajeros = HandlersUsuarios::getInstance()->listarPasajeros();
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

}
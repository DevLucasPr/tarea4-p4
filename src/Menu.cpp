#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/IControladorFechaActual.h"
#include "../include/CargaDatos.h"
#include "../include/DTConsultaViaje.h"
#include "../include/DTDetalleReserva.h"
#include "../include/DTDetalleVehiculo.h"
#include "../include/DTDetalleViaje.h"
#include "../include/DTFecha.h"
#include "../include/DTListarViaje.h"
#include "../include/DTUsuario.h"
#include "../include/DTUsuarioViaje.h"
#include "../include/DTVehiculosConductor.h"
#include <iostream>
#include <limits>
#include <string>
#include <set>


void Menu::altaUsuario() {
    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorUsuarios* controlador = fabrica->getIControladorUsuarios();

    bool usuarioOk = false;

    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci);
        if (usuarioOk) std::cout << "Pasajero creado exitosamente.\n";
        else std::cout << "Ya existe un usuario con ese nickname.\n";

    } else if (tipoUsuario == 2) {
        bool tieneMotoProfesional = false, tieneMotoAmateur = false;
        bool tieneAutoProfesional = false, tieneAutoAmateur = false;
        int cantLibretas = 0, agregarLibreta = 1;

        while (agregarLibreta == 1 && cantLibretas < 4) {
            int tipoLibreta;
            std::cout << "\n=== Registrar Libreta ===\n";
            std::cout << "0. Moto (Profesional)\n1. Moto (Amateur)\n2. Auto (Profesional)\n3. Auto (Amateur)\n";
            std::cout << "Seleccione el tipo de libreta: ";
            std::cin >> tipoLibreta;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool yaExiste = false;
            if (tipoLibreta == 0) { if (tieneMotoProfesional) yaExiste = true; else { tieneMotoProfesional = true; cantLibretas++; } }
            else if (tipoLibreta == 1) { if (tieneMotoAmateur) yaExiste = true; else { tieneMotoAmateur = true; cantLibretas++; } }
            else if (tipoLibreta == 2) { if (tieneAutoProfesional) yaExiste = true; else { tieneAutoProfesional = true; cantLibretas++; } }
            else if (tipoLibreta == 3) { if (tieneAutoAmateur) yaExiste = true; else { tieneAutoAmateur = true; cantLibretas++; } }
            else { std::cout << "Opcion invalida.\n"; continue; }

            if (yaExiste) std::cout << "Esa libreta ya fue ingresada.\n";
            else std::cout << "Libreta agregada.\n";

            if (cantLibretas < 4) {
                std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
                std::cin >> agregarLibreta;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cout << "Se ha alcanzado el limite maximo de libretas.\n";
            }
        }

        if (cantLibretas == 0) {
            std::cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
            return;
        }

        std::set<TipoLibreta> libretas;
        if (tieneMotoProfesional) libretas.insert(TipoLibreta::MotoProfesional);
        if (tieneMotoAmateur) libretas.insert(TipoLibreta::MotoAmateur);
        if (tieneAutoProfesional) libretas.insert(TipoLibreta::AutoProfesional);
        if (tieneAutoAmateur) libretas.insert(TipoLibreta::AutoAmateur);
        

        usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas);
        if (!usuarioOk) {
            std::cout << "Ya existe un usuario con ese nickname.\n";
        } else {
            std::cout << "Conductor creado exitosamente.\n";
        }

        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            TipoVehiculo tipoV = (tipo == 0) ? TipoVehiculo::Auto : TipoVehiculo::Moto;
            int resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipoV);

            if (resultadoRegistrarVehiculo == -1) std::cout << "Ya existe un vehiculo con esa matricula.\n";
            else if (resultadoRegistrarVehiculo == -2) std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            else if (resultadoRegistrarVehiculo == 0) std::cout << "Vehiculo registrado exitosamente.\n";

            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::altaViaje() {
    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorUsuarios* controlador = fabrica->getIControladorUsuarios();

    std::set<DTVehiculosConductor> vehiculos = controlador->listarVehiculosConductor(nickname);

    for (DTVehiculosConductor v : vehiculos) {
        std::cout << "> Matricula: " << v.getMatricula()
                  << ", Marca: " << v.getMarca()
                  << ", Capacidad: " << v.getCapacidad() << "\n";
    }

    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);
    bool matriculaValida = false;
    for (DTVehiculosConductor v : vehiculos) {
        if (v.getMatricula() == matricula) { matriculaValida = true; break; }
    }
    if (!matriculaValida) {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);
    if (viajeOk) std::cout << "Viaje registrado exitosamente.\n";
    else std::cout << "Error al registrar el viaje.\n";
}


void Menu::generarReserva() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorUsuarios* ctrlUsuarios = fabrica->getIControladorUsuarios();
    IControladorViajes* ctrlViajes = fabrica->getIControladorViajes();

    std::set<std::string> pasajeros = ctrlUsuarios->listarPasajeros();
    for (std::string p : pasajeros) {
        std::cout << "> " << p << "\n";
    }

    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    bool nicknameValido = false;
    for (std::string p : pasajeros) {
        if (p == nickname) { nicknameValido = true; break; }
    }
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::set<DTConsultaViaje> viajes = ctrlViajes->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);

    if (viajes.empty()) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    for (DTConsultaViaje v : viajes) {
        std::cout << "> Codigo: " << v.getCodigo()
                  << ", Marca: " << v.getMarca()
                  << ", Modelo: " << v.getModelo()
                  << ", Conductor: " << v.getConductor()
                  << ", CalificacionPromedio: " << v.getCalificacionProm()
                  << ", PrecioTotal: " << v.getPrecioTotal() << "\n";
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool codigoValido = false;
    for (DTConsultaViaje v : viajes) {
        if (v.getCodigo() == codigo) { codigoValido = true; break; }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = ctrlViajes->generarReserva(nickname, codigo, asientos);
    if (reservaOk) std::cout << "Reserva realizada exitosamente.\n";
    else std::cout << "Error al realizar la reserva.\n";
}


void Menu::calificarUsuario() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorUsuarios* ctrlUsuarios = fabrica->getIControladorUsuarios();
    IControladorViajes* ctrlViajes = fabrica->getIControladorViajes();

    std::set<DTUsuario> usuarios = ctrlUsuarios->listarUsuarios();
    for (DTUsuario usuario : usuarios) {
        std::cout << "> Nickname: " << usuario.getNickname()
                  << ", Nombre: " << usuario.getNombre() << std::endl;
    }

    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    bool nicknameValido = false;
    for (DTUsuario usuario : usuarios) {
        if (usuario.getNickname() == nickname) { nicknameValido = true; break; }
    }
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    std::set<DTListarViaje> viajes = ctrlUsuarios->listarViajes(nickname);
    for (DTListarViaje viaje : viajes) {
        DTFecha fechaViaje = viaje.getFecha();
        std::cout << "> Codigo: " << viaje.getCodigo()
                  << ", Fecha: " << fechaViaje.getDia() << "/" << fechaViaje.getMes() << "/" << fechaViaje.getAnio()
                  << ", Origen: " << viaje.getOrigen()
                  << ", Destino: " << viaje.getDestino()
                  << ", Conductor: " << viaje.getConductor()
                  << std::endl;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    for (DTListarViaje viaje : viajes) {
        if (viaje.getCodigo() == codigo) { codigoValido = true; break; }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    std::set<DTUsuarioViaje> usuariosViaje = ctrlViajes->listarUsuariosViaje(codigo);
    for (DTUsuarioViaje usuarioV : usuariosViaje) {
        std::cout << "> Nickname: " << usuarioV.getNickname()
                  << ", Tipo: " << (usuarioV.getTipo() == TipoUsuario::Pasajero ? "Pasajero" : "Conductor")
                  << std::endl;
    }

    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool nicknameCalificadoValido = false;
    for (DTUsuarioViaje usuarioV : usuariosViaje) {
        if (nicknameCalificado == usuarioV.getNickname()) { nicknameCalificadoValido = true; break; }
    }
    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = ctrlUsuarios->calificarUsuario(nicknameCalificado, calificacion);
    if (calificacionOk) std::cout << "Calificacion exitosa.\n";
    else std::cout << "Error al calificar.\n";
}

void Menu::eliminarViaje() {
    Fabrica* fabrica = Fabrica::getInstance();
    IControladorViajes* controladorViajes = fabrica->getIControladorViajes();

    //TODO: Coleccion de DTListarViaje = controlador->listarViajes()
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"

    std::set<DTListarViaje> listaViajes = controladorViajes->listarViajes();
    for (DTListarViaje it : listaViajes) {
        DTFecha itFecha = it.getFecha();
        std::cout << "> Codigo: " << it.getCodigo()
                  << ", Fecha: " << itFecha.getDia() << "/" << itFecha.getMes() << "/" << itFecha.getAnio()
                  << ", Origen: " << it.getOrigen()
                  << ", Destino: " << it.getDestino()
                  << ", Conductor: " << it.getConductor()
                  << "\n";
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;

    //TODO: Validar codigo en listado
    for (DTListarViaje dt : listaViajes) {
        if (dt.getCodigo() == codigo) {
            codigoValido = true;
            break;
        }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }
    
    //TODO: DTDetalleViaje = controlador->detalleViaje(codigo)
    //TODO: Mostrar detalle del viaje siguiendo el formato
    //>> Viaje <<
    //--- Matrícula: aa, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Capacidad: bbb, Precio por asiento: qqq
    //>> Vehiculo <<
    //--- Matricula: mm, Capacidad: aa, Marca: bbb, Modelo: ccc, Tipo: ddd
    //>> Reservas <<
    //--- AsientosReservados: xx, Fecha: dd/mm/aaaa, Pasajero: aaa

    DTDetalleViaje detalleViaje = controladorViajes->detalleViaje(codigo);
    DTDetalleVehiculo detalleVehiculo = detalleViaje.getVehiculo();
    std::cout << ">> Viaje <<\n"
              << "--- Matrícula: " << detalleVehiculo.getMatricula()
              << ", Fecha: " << detalleViaje.getFecha().getDia() << "/" << detalleViaje.getFecha().getMes() << "/" << detalleViaje.getFecha().getAnio()
              << ", Origen: " << detalleViaje.getOrigen()
              << ", Destino: " << detalleViaje.getDestino()
              << ", Capacidad: " << detalleViaje.getAsientosPublicados()
              << ", Precio por asiento: " << detalleViaje.getPrecio() << "\n"
              << ">> Vehiculo <<\n"
              << "--- Matricula: " << detalleVehiculo.getMatricula()
              << ", Capacidad: " << detalleVehiculo.getCapacidad()
              << ", Marca: " << detalleVehiculo.getMarca()
              << ", Modelo: " << detalleVehiculo.getModelo()
              << ", Tipo: " << (detalleVehiculo.getTipo() == TipoVehiculo::Auto ? "Auto" : "Moto") << "\n"
              << ">> Reservas <<\n";
    for (DTDetalleReserva dtr : detalleViaje.getReservas()) {
        DTFecha fechaReserva = dtr.getFecha();
        std::cout << "--- AsientosReservados: " << dtr.getAsientosReservados()
                  << ", Fecha: " << fechaReserva.getDia() << "/" << fechaReserva.getMes() << "/" << fechaReserva.getAnio()
                  << ", Pasajero: " << dtr.getPasajero() << "\n";
    }
    
    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        //TODO: controlador->eliminarViaje()
        controladorViajes->eliminarViaje();
        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
        //TODO: controlador->cancelarEliminarViaje()
        controladorViajes->cancelarEliminarViaje();
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}

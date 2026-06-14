#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/IControladorUsuarios.h"
#include "../include/IControladorViajes.h"
#include "../include/IControladorFechaActual.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoVehiculo.h"
#include "../include/DTFecha.h"
#include <iostream>
#include <set>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }

    std::cout << "Cargando datos harcodeados del sistema...\n";

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorUsuarios* cu = fabrica->getIControladorUsuarios();
    IControladorViajes* cv = fabrica->getIControladorViajes();
    IControladorFechaActual* cf = fabrica->getIControladorFechaActual();

    // ===== Usuarios: Conductores =====
    // (libretas segun columnas: autoamateur, autoprofesional, motoamateur, motoprofesional)
    {
        std::set<TipoLibreta> l; l.insert(AutoAmateur);
        cu->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", l);
    }
    {
        std::set<TipoLibreta> l; l.insert(AutoProfesional);
        cu->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", l);
    }
    {
        std::set<TipoLibreta> l; l.insert(MotoAmateur);
        cu->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", l);
    }
    {
        std::set<TipoLibreta> l; l.insert(MotoProfesional);
        cu->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", l);
    }
    {
        std::set<TipoLibreta> l; l.insert(AutoProfesional); l.insert(MotoAmateur);
        cu->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", l);
    }

    // ===== Usuarios: Pasajeros =====
    cu->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    cu->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    cu->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    cu->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    cu->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    // ===== Vehiculos =====
    cu->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", Auto);
    cu->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", Auto);
    cu->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", Auto);
    cu->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", Auto);
    cu->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", Moto);
    cu->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", Moto);
    cu->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", Auto);
    cu->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", Moto);

    // ===== Viajes (el codigo queda asignado por orden de insercion) =====
    cv->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);     // 1
    cv->altaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250);        // 2
    cv->altaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200);        // 3
    cv->altaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200);     // 4
    cv->altaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300);     // 5
    cv->altaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350);     // 6
    cv->altaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260);     // 7
    cv->altaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150);  // 8
    cv->altaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140);       // 9
    cv->altaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180);       // 10
    cv->altaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100);       // 11
    cv->altaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600);       // 12
    cv->altaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250);        // 13

    // ===== Reservas (se usa setFecha para fijar la fecha de cada reserva) =====
    cf->setFecha(DTFecha(14, 3, 2026)); cv->generarReserva("santi_90", 9, 2);
    cf->setFecha(DTFecha(14, 3, 2026)); cv->generarReserva("mari_b", 9, 1);
    cf->setFecha(DTFecha(14, 3, 2026)); cv->generarReserva("nacho_f", 10, 5);
    cf->setFecha(DTFecha(14, 3, 2026)); cv->generarReserva("valen_uy", 10, 3);
    cf->setFecha(DTFecha(14, 3, 2026)); cv->generarReserva("joaco_r", 10, 1);
    cf->setFecha(DTFecha(13, 3, 2026)); cv->generarReserva("mari_b", 12, 1);
    cf->setFecha(DTFecha(13, 3, 2026)); cv->generarReserva("nacho_f", 12, 1);
    cf->setFecha(DTFecha(1, 6, 2026));  cv->generarReserva("mari_b", 1, 2);
    cf->setFecha(DTFecha(13, 3, 2026)); cv->generarReserva("nacho_f", 9, 1);

    // ===== Calificaciones (via el caso de uso completo: listarViajes -> listarUsuariosViaje -> calificarUsuario) =====
    cargarCalificacion(cu, cv, "santi_90", 9, "matil92", 4);
    cargarCalificacion(cu, cv, "mari_b", 9, "matil92", 4);
    cargarCalificacion(cu, cv, "matil92", 9, "mari_b", 3);
    cargarCalificacion(cu, cv, "ana_silva", 10, "valen_uy", 5);
    cargarCalificacion(cu, cv, "ana_silva", 10, "joaco_r", 5);
    cargarCalificacion(cu, cv, "mari_b", 12, "carlos_r", 5);
    cargarCalificacion(cu, cv, "carlos_r", 12, "nacho_f", 5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}

// Reproduce la secuencia del caso de uso Calificar Usuario para fijar la memoria
// (nickname del calificador y codigo del viaje) antes de calificar.
void CargaDatos::cargarCalificacion(IControladorUsuarios* cu, IControladorViajes* cv,
                                    std::string nickname, int codigo,
                                    std::string nicknameCalificado, int calificacion) {
    cu->listarViajes(nickname);        // guarda el nickname del calificador en memoria
    cv->listarUsuariosViaje(codigo);   // guarda el codigo del viaje en memoria
    cu->calificarUsuario(nicknameCalificado, calificacion);
}

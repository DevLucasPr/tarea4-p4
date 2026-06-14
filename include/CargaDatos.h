#ifndef CARGA_DATOS_H
#define CARGA_DATOS_H

#include <string>

class IControladorUsuarios;
class IControladorViajes;

class CargaDatos {
private:
    static CargaDatos* instancia;
    bool datosCargados;

    CargaDatos();

    void cargarCalificacion(IControladorUsuarios* cu, IControladorViajes* cv,
                            std::string nickname, int codigo,
                            std::string nicknameCalificado, int calificacion);

public:
    static CargaDatos* getInstance();
    void cargarDatos();
};

#endif
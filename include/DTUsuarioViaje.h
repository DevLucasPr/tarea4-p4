#ifndef DT_USUARIO_VIAJE_H
#define DT_USUARIO_VIAJE_H

#include "TipoUsuario.h"
#include <string>

class DTUsuarioViaje {
private:
    string nickname;
    TipoUsuario tipo;

public:
    DTUsuarioViaje(string nickname, TipoUsuario tipo);

    string getNickname();
    TipoUsuario getTipo();
};

#endif

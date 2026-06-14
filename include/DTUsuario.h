#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <string>
using namespace std;

class DTUsuario {
private:
    string nickname;
    string nombre;
    int grupo;   // 0 = conductor, 1 = pasajero (para listar conductores antes que pasajeros)

public:
    DTUsuario(string nickname, string nombre);
    DTUsuario(string nickname, string nombre, int grupo);

    string getNickname();
    string getNombre();

    bool operator<(const DTUsuario& otro) const;
};

#endif
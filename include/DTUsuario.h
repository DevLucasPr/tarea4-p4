#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <string>
using namespace std;

class DTUsuario {
private:
    string nickname;
    string nombre;

public:
    DTUsuario(string nickname, string nombre);

    string getNickname();
    string getNombre();

    bool operator<(const DTUsuario& otro) const;
};

#endif
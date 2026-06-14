#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>
using namespace std;

class DTVehiculosConductor {
private:
  string matricula;
  string marca;
  int capacidad;

public:
  DTVehiculosConductor(string matricula, string marca, int capacidad);

  string getMatricula();
  string getMarca();
  int getCapacidad();
  bool operator<(const DTVehiculosConductor& otro) const;
};

#endif

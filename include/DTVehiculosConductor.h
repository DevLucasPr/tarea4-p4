#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>
using namespace std;

class DTVehiculosConductor {
private:
  string matricula;
  string modelo;
  int capacidad;

public:
  DTVehiculosConductor(string matricula, string modelo, int capacidad);

  string getMatricula();
  string getModelo();
  int getCapacidad();
  bool operator<(const DTVehiculosConductor& otro) const;
};

#endif

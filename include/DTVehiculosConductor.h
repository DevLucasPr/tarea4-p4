#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>

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
};

#endif

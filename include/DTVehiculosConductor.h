#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>

class DTVehiculosConductor {
private:
  std::string matricula;
  std::string modelo;
  int capacidad;

public:
  DTVehiculosConductor(std::string matricula, std::string marca, int capacidad);

  std::string getMatricula();
  std::string getModelo();
  int getCapacidad();
};

#endif

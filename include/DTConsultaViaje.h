#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <string>
using namespace std;

class DTConsultaViaje {
private:
  int codigo;
  string marca;
  string modelo;
  string conductor;
  float calificacionProm;
  float precioTotal;

public:
  DTConsultaViaje(int codigo, string marca, string modelo, string conductor, float calificacionProm, float precioTotal);

  int getCodigo();
  string getMarca();
  string getModelo();
  string getConductor();
  float getCalificacionProm();
  float getPrecioTotal();

  bool operator<(const DTConsultaViaje& otro) const;
};

#endif
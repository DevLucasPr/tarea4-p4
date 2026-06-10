#ifndef CTRLUSUARIO_H
#define CTRLUSUARIO_H

#include <set>
#include <string>

class CtrlUsuarios {
private:
	int codigoMem;
	std::string nicknameMem;
	static CtrlUsuarios* instancia;

	CtrlUsuarios();

public:
	std::set<std::string> listarPasajeros();
    
	static CtrlUsuarios* getInstance();
};

#endif


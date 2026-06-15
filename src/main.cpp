#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/CargaDatos.h"

int main() {
    Menu menu;
    menu.mostrarMenu();
    Fabrica::destroy();      // libera controladores, handlers y objetos de dominio
    CargaDatos::destroy();   // libera el singleton de carga de datos
    return 0;
}
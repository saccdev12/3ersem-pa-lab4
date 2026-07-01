#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string>
#include "DTUsuario.h"

using namespace std;

class DTInmobiliaria : public DTUsuario {
private:
    string direccion;
    string telefono;

public:

    DTInmobiliaria(string nick, string nom, string email, string dir, string tel)
        : DTUsuario(nick, nom, email), direccion(dir), telefono(tel) {}

    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    virtual ~DTInmobiliaria() {}
};

#endif // DTINMOBILIARIA_H
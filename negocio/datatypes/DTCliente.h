#ifndef LAB_2_DTCLIENTE_H
#define LAB_2_DTCLIENTE_H

#include <string>
#include "DTUsuario.h"

using namespace std;

class DTCliente : public DTUsuario {
private:
    string nombre;
    string apellido;
    int idCliente;

public:
    DTCliente(string nom, string apellido, int id)
        : DTUsuario(nom, nom, ""), nombre(nom), apellido(apellido), idCliente(id) {}

    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    int getIdCliente() { return idCliente; }

    virtual ~DTCliente() {}
};

#endif // LAB_2_DTCLIENTE_H
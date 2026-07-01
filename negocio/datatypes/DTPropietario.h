#ifndef LAB_2_DTPROPIETARIO_H
#define LAB_2_DTPROPIETARIO_H

#include <string>
#include "DTUsuario.h"

using namespace std;

class DTPropietario : public DTUsuario {
private:
    int cuentaBancaria;
    string telefono;

public:
    DTPropietario(string _nick, string _nom, string _em, int _cuenta, string _tel): DTUsuario(_nick, _nom, _em), cuentaBancaria(_cuenta), telefono(_tel) {}

    int getCuentaBancaria() { return cuentaBancaria; }
    string getTelefono() { return telefono; }

    virtual ~DTPropietario() {}
};

#endif //LAB_2_DTPROPIETARIO_H
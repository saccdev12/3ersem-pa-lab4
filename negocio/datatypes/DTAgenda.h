#ifndef DTAGENDA_H
#define DTAGENDA_H

#include <string>
#include "datatypes/Date.h"

using namespace std;

class DTAgenda {
private:
    Date fecha;
    string formaContacto;
    string nombre;
    string apellido;

public:
    DTAgenda(Date _fecha, string _formaContacto, string _nombre, string _apellido)
        : fecha(_fecha), formaContacto(_formaContacto), nombre(_nombre), apellido(_apellido) {}

    Date getFecha() const { return fecha; }
    string getFormaContacto() const { return formaContacto; }
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }

    ~DTAgenda() {}
};

#endif // DTAGENDA_H
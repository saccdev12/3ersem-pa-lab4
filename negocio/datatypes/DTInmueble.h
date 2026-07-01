#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H
#include <string>
#include "Date.h"
using namespace std;

class DTInmueble {
private:
    int codNumerico;
    string direccion;
    string nombrePropietario;
    Date fechaAdministracion;
public:
    DTInmueble(int _cod, string _dir, string _nomProp, Date _fechaAdministracion)
        : codNumerico(_cod), direccion(_dir), nombrePropietario(_nomProp), fechaAdministracion(_fechaAdministracion) {}

    int getCodNumerico() const { return codNumerico; }
    string getDireccion() const { return direccion; }
    string getNombrePropietario() const { return nombrePropietario; }
    Date getFechaAdministracion() const { return this->fechaAdministracion; }
    ~DTInmueble() {}
};
#endif


#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#include "Date.h"

class DTInmueble;
class Inmueble;

class Administracion {
private:
    Date fechaRegistro;
    Inmueble* inmuebleVinculado;

public:
    Administracion(Date fecha, Inmueble* inm);

    DTInmueble* obtenerInmueble();

    Inmueble* getInmueble() {
        return this->inmuebleVinculado;
    }
};

#endif
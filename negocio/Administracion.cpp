//
// Created by Facundo Caraballo Beledo on 28/6/26.
//

#include "Administracion.h"
#include "Inmueble.h"

Administracion::Administracion(Date fecha, Inmueble* inm) {
    this->fechaRegistro = fecha;
    this->inmuebleVinculado = inm;
}

DTInmueble* Administracion::obtenerInmueble() {
    return this->inmuebleVinculado->getDTInmueble();
}
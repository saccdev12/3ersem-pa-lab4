#include "Inmueble.h"
#include "datatypes/DTInmueble.h"
#include "datatypes/DTPublicacion.h"
#include "Propietario.h"


DTInmueble* Inmueble::getDTInmueble() {
    return new DTInmueble(this->id, this->direccion, "", this->fechaAdministracion);
}

Publicacion* Inmueble::crearPublicacion(DTPublicacion* publicacion) {

    int nuevoNroId = this->publicaciones.size() + 1;
    Publicacion* p = new Publicacion(nuevoNroId, publicacion);
    
    p->setAdministracion(this->miAdministracion);

    this->publicaciones[nuevoNroId] = p;
    return p;
}



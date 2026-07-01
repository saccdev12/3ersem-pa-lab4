#include "Publicacion.h"
#include "Cliente.h"
#include "Agenda.h"
#include "Inmobiliaria.h"
#include "Administracion.h"
#include "datatypes/DTInmueble.h"
#include <iostream>
#include "Inmueble.h"

DTInmueble* Publicacion::seleccionPublicacion() {
    if (this->miAdministracion == nullptr) {
        return nullptr;
    }

    return this->miAdministracion->getInmueble()->getDTInmueble();
}

void Publicacion::agendarVisita(Cliente* c, Date fechaComunicacion, string formaContacto) {
    Agenda* x = new Agenda(c, fechaComunicacion, formaContacto, this);

    this->colAgendas.insert(x);

    c->agendarVisita(x);
}

bool Publicacion::cumpleFiltro(string tipo, DTRango* rango, DTInteres interes) {
    if (this->tipoPublicacion != tipo) {
        return false;
    }

    if (this->precio < rango->getMinimo() || this->precio > rango->getMaximo()) {
        return false;
    }

    return true;
}

DTListaPublicacion* Publicacion::getDTListaPublicacion() {

    string nombreInmo = "Inmobiliaria Desconocida";

    return new DTListaPublicacion(
        this->nroId,
        this->fechaPublicacion,
        this->texto,
        this->precio,
        nombreInmo
    );
}
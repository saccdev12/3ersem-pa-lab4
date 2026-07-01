#include "Propietario.h"
#include "datatypes/DTInmobiliariaDetalles.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"
#include "datatypes/DTUsuario.h"
#include "datatypes/DTPropietario.h"



void Propietario::agregarInmobiliaria(Inmobiliaria* inmo) {
    if (inmo != nullptr) {
        this->inmobiliarias[inmo->getNickname()] = inmo;
    }
}

void Propietario::agregarInmueble(Inmueble* inm) {
    this->misInmuebles[inm->getId()] = inm;
}

map<int, Inmueble*> Propietario::getInmuebles() {
    return this->misInmuebles;
}

bool Propietario::tieneInmobiliaria(string nickInmo) {
    return this->inmobiliarias.find(nickInmo) != this->inmobiliarias.end();
}

DTUsuario* Propietario::CrearDTUsuario() {
    return new DTPropietario(this->getNickname(), this->getNombre(), this->getEmail(), this->cuentaBancaria, this->telefono);
}
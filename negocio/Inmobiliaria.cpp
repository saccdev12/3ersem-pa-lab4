#include "Inmobiliaria.h"
#include "Propietario.h"
#include "datatypes/DTRepresentado.h"
#include "DTInmueble.h"
#include "Inmueble.h"
#include <string>
#include <iostream>

Inmobiliaria::Inmobiliaria(string _nick, string _pass, string _nom, string _em, string _dir, string _tel, string _url)
    : Usuario(_nick, _pass, _nom, _em) {
    this->direccion = _dir;
    this->telefono = _tel;
    this->url = _url;
}

bool Inmobiliaria::tienePropietario(string nickPropietario) {
    return this->propietariosRepresentados.find(nickPropietario) != this->propietariosRepresentados.end();
}

void Inmobiliaria::agregarPropietario(Propietario* prop) {
    if (prop != nullptr) {
        this->propietariosRepresentados[prop->getNickname()] = prop;
    }
}

void Inmobiliaria::registrarRepresentacion(Propietario* p) {
    p->agregarInmobiliaria(this);
    this->propietariosRepresentados[p->getNickname()] = p;
}

DTUsuario* Inmobiliaria::CrearDTUsuario() {
    return new DTInmobiliaria(this->getNickname(), this->getNombre(), this->getEmail(), this->direccion, this->telefono);;
}

DTInmobiliariaDetalles Inmobiliaria::getDtInmobiliariaDetalles() {
    return DTInmobiliariaDetalles(this->getNickname(), this->getNombre(), this->getEmail());
}

Inmobiliaria::~Inmobiliaria() {
}

set<DTRepresentado*> Inmobiliaria::ObtenerRepresentados() {
    set<DTRepresentado*> res;

    // La inmobiliaria recorre sus propios representados (Flecha 2.1)
    for (auto const& propPair : this->propietariosRepresentados) {
        Propietario* p = propPair.second;

        // Creamos el DataType (Flecha 2.2)
        res.insert(new DTRepresentado(p->getNickname(), p->getNombre()));
    }

    return res;
}

void Inmobiliaria::agregarAdministracion(Administracion* admin) {
    this->administraciones.push_back(admin);
}

set<DTInmueble*> Inmobiliaria::ObtenerInmueblesAAdministrar() {
    set<DTInmueble*> res;

    for (auto const& propPair : this->propietariosRepresentados) {
        Propietario* p = propPair.second;
        map<int, Inmueble*> inmueblesDelProp = p->getInmuebles();

        for (auto const& inmPair : inmueblesDelProp) {
            Inmueble* inm = inmPair.second;
            if (!inm->estaAdministrado()) {
                res.insert(new DTInmueble(inm->getId(), inm->getDireccion(), p->getNombre(), inm->getFechaAdministracion()));
            }
        }
    }
    return res;
}


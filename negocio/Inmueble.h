#ifndef LAB_2_INMUEBLE_H
#define LAB_2_INMUEBLE_H

#include <string>
#include <map>
#include "Publicacion.h"

#include "datatypes/DTInmueble.h"

class Inmobiliaria;
using namespace std;

class Inmueble {
protected:
    int id;
    string direccion;
    int nroPuerta;
    int superficie;
    int anioConstruccion;
    Date fechaAdministracion;
    map<int, Publicacion*> publicaciones;
    Inmobiliaria* administradoPor = nullptr;
    bool administrado = false;
    Administracion* miAdministracion;
public:
    Inmueble(int _id, string _dir, int _nro, int _sup, int _anio): id(_id), direccion(_dir), nroPuerta(_nro), superficie(_sup), anioConstruccion(_anio) {}

    virtual ~Inmueble() {}

    int getId() { return id; }
    string getDireccion() { return direccion; }
    int getNroPuerta() { return nroPuerta; }
    int getSuperficie() { return superficie; }
    int getAnioConstruccion() { return anioConstruccion; }

    DTInmueble* getDTInmueble();
    Publicacion* crearPublicacion(DTPublicacion* publicacion);
    map<int, Publicacion*> getPublicaciones() { return publicaciones; }
    bool estaAdministrado() { return this->administradoPor != nullptr; }

    void setAdministrado(bool estado) { this->administrado = estado; }

    Inmobiliaria* getAdministrador() { return this->administradoPor; }
    Date getFechaAdministracion() {

        return Date();
    }
    void setAdministrador(Inmobiliaria* inmo) {
        this->administradoPor = inmo;
    }

    void setAdministracion(Administracion* admin) { this->miAdministracion = admin; }
    Administracion* getAdministracion() { return this->miAdministracion; }
};


#endif
#ifndef LAB_2_INMOBILIARIA_H
#define LAB_2_INMOBILIARIA_H

#include <string>
#include <map>
#include "Usuario.h"
#include "datatypes/DTUsuario.h"
#include "datatypes/DTInmobiliaria.h"
#include "datatypes/DTRepresentado.h"
#include "datatypes/DTInmobiliariaDetalles.h"
#include "Administracion.h"

using namespace std;

class Propietario;

class Inmobiliaria : public Usuario {
private:
    string direccion;
    string telefono;
    string url;

    map<string, Propietario*> propietariosRepresentados;
    vector<Administracion*> administraciones;

public:
    Inmobiliaria(string _nick, string _pass, string _nom, string _em, string _dir, string _tel, string _url);

    bool tienePropietario(string nickPropietario);
    void agregarPropietario(Propietario* prop);
    void registrarRepresentacion(Propietario* p);

    DTInmobiliariaDetalles getDtInmobiliariaDetalles();
    ~Inmobiliaria();

    TipoUsuario getTipo() {
        return INMOBILIARIA;
    }
    DTUsuario* CrearDTUsuario();

    set<DTRepresentado*> ObtenerRepresentados();

    void agregarAdministracion(Administracion* admin);
    set<DTInmueble*> ObtenerInmueblesAAdministrar();
};

#endif // LAB_2_INMOBILIARIA_H
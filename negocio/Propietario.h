#ifndef LAB_2_PROPIETARIO_H
#define LAB_2_PROPIETARIO_H

#include <string>
#include <map>
#include "Usuario.h"
#include "datatypes/DTUsuario.h"

using namespace std;

class Inmobiliaria;
class Inmueble;

class Propietario : public Usuario {
private:
    int cuentaBancaria;
    string telefono;

    map<int, Inmueble*> inmuebles;
    map<string, Inmobiliaria*> inmobiliarias;
    map<int, Inmueble*> misInmuebles;

public:
    Propietario(string _nick, string _pass, string _nom, string _email, int _cuenta, string _tel)
        : Usuario(_nick, _pass, _nom, _email) {
        this->cuentaBancaria = _cuenta;
        this->telefono = _tel;
    }

    int getCuentaBancaria() { return cuentaBancaria; }
    string getTelefono() { return telefono; }

    void agregarInmueble(Inmueble* inm);
    void agregarInmobiliaria(Inmobiliaria* inmo);
    bool tieneInmobiliaria(string nickInmo);
    map<int, Inmueble*> getInmuebles();

    ~Propietario() {}

    TipoUsuario getTipo()  {
        return PROPIETARIO;
    }

    DTUsuario* CrearDTUsuario() ;

    bool tieneInmueble(int idInmueble) {
        return inmuebles.find(idInmueble) != inmuebles.end();
    }

    void removerInmueble(int idInmueble) {
        inmuebles.erase(idInmueble);
    }

};

#endif // LAB_2_PROPIETARIO_H
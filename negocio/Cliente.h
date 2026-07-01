#ifndef LAB_2_CLIENTE_H
#define LAB_2_CLIENTE_H

#include <string>
#include <set>
#include "Usuario.h"
#include "datatypes/DTUsuario.h"
#include "datatypes/DTCliente.h"

class Agenda;

using namespace std;

class Cliente: public Usuario {
private:
    int idCliente;
    string apellido;
    string nombre;
    set<Agenda*> colAgendas;

public:
    Cliente(string _nick, string _pass, string _nom, string _em, string _apellido, int _idCliente)
        : Usuario(_nick, _pass, _nom, _em), idCliente(_idCliente), apellido(_apellido), nombre(_nom) {}

    DTCliente* getDTCliente() {
        return new DTCliente(this->nombre, this->apellido, this->idCliente);
    }

    void agendarVisita(Agenda* x) { this->colAgendas.insert(x); }

    TipoUsuario getTipo() {
        return CLIENTE;
    }
    string getNombre() { return this->nombre; }
    string getApellido() { return this->apellido; }

    DTUsuario* CrearDTUsuario() {
        return new DTCliente(this->nombre, this->apellido, this->idCliente);
    }
};
#endif
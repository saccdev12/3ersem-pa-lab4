#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "Date.h"
#include "Cliente.h"

class Publicacion;

using namespace std;

class Agenda {
private:
    Date fechaVisita;
    string formaContacto;

    Publicacion* publicacion;
    Cliente* cliente;

public:
    Agenda(Cliente* c, Date fecha, string forma, Publicacion* p) {
        this->cliente = c;
        this->fechaVisita = fecha;
        this->formaContacto = forma;
        this->publicacion = p;
    }

    Date getFecha() { return this->fechaVisita; }
    string getFormaContacto() { return this->formaContacto; }
    Cliente* getCliente() { return this->cliente; }
};

#endif // AGENDA_H
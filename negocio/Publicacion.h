#ifndef LAB_2_PUBLICACION_H
#define LAB_2_PUBLICACION_H

#include <string>
#include "datatypes/DTPublicacion.h"
#include <map>
#include "Date.h"
#include <set>
#include "datatypes/DTRango.h"
#include "datatypes/DTInteres.h"
#include "datatypes/DTListaPublicacion.h"
#include "datatypes/DTAgenda.h"

using namespace std;

class Cliente;
class Agenda;
class Administracion;
class DTInmueble;
class DTAgenda;

class Publicacion {
private:
    int nroId;
    Date fechaPublicacion;
    string tipoPublicacion;
    string texto;
    float precio;
    bool activa;
    Administracion* miAdministracion; // Soluciona el error de la línea 6
    set<Agenda*> colAgendas;
public:

    Publicacion(int _nroId, DTPublicacion* dt) {
        this->nroId = _nroId;
        this->fechaPublicacion = dt->getFecha();
        this->tipoPublicacion = dt->getTipo();
        this->texto = dt->getTexto();
        this->precio = dt->getPrecio();
        this->activa = dt->getActiva();
        this->miAdministracion = nullptr;
    }
    ~Publicacion() {}

    DTInmueble* seleccionPublicacion();
    void agendarVisita(Cliente* c, Date fechaComunicacion, string formaContacto);
    bool cumpleFiltro(string tipo, DTRango* rango, DTInteres interes);
    DTListaPublicacion* getDTListaPublicacion();

    int getId() { return this->nroId; } // Usá el nombre de tu variable
    string getContenido() { return this->texto; }
    Date getFecha() { return this->fechaPublicacion; }
    set<Agenda*> getAgendas() { return this->colAgendas;}
    void setAdministracion(Administracion* admin) {
        this->miAdministracion = admin;
    }
};


#endif //LAB_2_PUBLICACION_H

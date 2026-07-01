#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include <string>
#include "datatypes/Date.h"
using namespace std;

class DTPublicacion {
private:
    int id;
    Date fechaPublicacion;
    string tipoPublicacion;  // "Venta" o "Alquiler" (O un enum DTTipo)
    string texto;
    float precio;
    bool activa;
public:
    DTPublicacion(int _id, Date _fecha, string _tipo, string _texto, float _precio, bool _activa) :id(_id), fechaPublicacion(_fecha), tipoPublicacion(_tipo), texto(_texto), precio(_precio), activa(_activa) {}
    int getId() const { return this->id; }
    Date getFecha() const { return fechaPublicacion; }
    string getTipo() const { return tipoPublicacion; }
    string getTexto() const { return texto; }
    float getPrecio() const { return precio; }
    bool getActiva() const { return activa; }

    ~DTPublicacion() {}
};
#endif

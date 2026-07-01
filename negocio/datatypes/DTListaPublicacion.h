#ifndef DTLISTAPUBLICACION_H
#define DTLISTAPUBLICACION_H
#include <string>
#include "Date.h"
using namespace std;

class DTListaPublicacion {
private:
    int codigo;
    Date fecha;
    string texto;
    float precio;
    string nombreInmobiliaria;

public:
    DTListaPublicacion(int cod, Date f, string txt, float pre, string inmo) : codigo(cod), fecha(f), texto(txt), precio(pre), nombreInmobiliaria(inmo) {}
    int getCodigo() { return codigo; }
    Date getFecha() { return fecha; }
    string getTexto() { return texto; }
    float getPrecio() { return precio; }
    string getNombreInmobiliaria() { return nombreInmobiliaria; }
    
    virtual ~DTListaPublicacion() {}
};
#endif


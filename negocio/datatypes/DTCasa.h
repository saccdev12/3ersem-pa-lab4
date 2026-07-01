#ifndef LAB_2_DTCASA_H
#define LAB_2_DTCASA_H

#include "DTInmuebleDetalles.h"
#include "DTTecho.h"

class DTCasa :public DTInmuebleDetalles {
private: bool propiedadHorizontal;
    DTTecho tipoTecho;
    public:
    DTCasa(string _dir, int _nro, int _sup, int _anio, bool _ph, DTTecho _techo): DTInmuebleDetalles(_dir, _nro, _sup, _anio), propiedadHorizontal(_ph), tipoTecho(_techo){}

    bool getPropiedadHorizontal() {return propiedadHorizontal;}
    DTTecho getTipoTecho() {return tipoTecho;}
};


#endif //LAB_2_DTCASA_H

//
// Created by Facundo Caraballo Beledo on 16/5/26.
//

#ifndef LAB_2_CASA_H
#define LAB_2_CASA_H

#include "Inmueble.h"
#include "datatypes/DTTecho.h"

class Casa : public Inmueble {
private:
    bool propiedadHorizontal;
    DTTecho tipoTecho;

public:
    Casa(int _id, string _dir, int _nro, int _sup, int _anio, bool _ph, DTTecho _techo): Inmueble(_id, _dir, _nro, _sup, _anio), propiedadHorizontal(_ph), tipoTecho(_techo) {}

    bool getPropiedadHorizontal() { return propiedadHorizontal; }
    DTTecho getTipoTecho() { return tipoTecho; }
};


#endif //LAB_2_CASA_H

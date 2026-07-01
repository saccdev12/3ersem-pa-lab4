//
// Created by Facundo Caraballo Beledo on 16/5/26.
//

#ifndef LAB_2_APARTAMENTO_H
#define LAB_2_APARTAMENTO_H

#include "Inmueble.h"

class Apartamento : public Inmueble {
private:
    int nroPiso;
    bool poseeAscensor;
    float gastosComunes;

public:
    Apartamento(int _id, string _dir, int _nro, int _sup, int _anio, int _piso, bool _asc, float _gastos)
        : Inmueble(_id, _dir, _nro, _sup, _anio), nroPiso(_piso), poseeAscensor(_asc), gastosComunes(_gastos) {}

    int getNroPiso() { return nroPiso; }
    bool getPoseeAscensor() { return poseeAscensor; }
    float getGastosComunes() { return gastosComunes; }
};

#endif //LAB_2_APARTAMENTO_H


#ifndef LAB_2_DTAPARTAMENTO_H
#define LAB_2_DTAPARTAMENTO_H
#include "DTInmuebleDetalles.h"


class DTApartamento : public DTInmuebleDetalles {
private:
    int nroPiso;
    bool poseeAscensor;
    float gastosComunes;
    public:
    DTApartamento(string _dir, int _nro, int _sup, int _anio, int _piso, bool _asc, float _gastos) : DTInmuebleDetalles(_dir, _nro, _sup, _anio), nroPiso(_piso), poseeAscensor(_asc), gastosComunes(_gastos) {};

    int getNroPiso() {return nroPiso;}
    bool getPoseeAscensor() {return poseeAscensor;}
    float getGastosComunes() {return gastosComunes;}
};


#endif //LAB_2_DTAPARTAMENTO_H

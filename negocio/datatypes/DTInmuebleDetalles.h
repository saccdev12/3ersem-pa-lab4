#ifndef LAB_2_DTINMUEBLEDETALLES_H
#define LAB_2_DTINMUEBLEDETALLES_H
#include <string>

using namespace std;
class DTInmuebleDetalles {
private:
    string direccion;
    int nroPuerta;
    int superficie;
    int anioConstruccion;
public:
    DTInmuebleDetalles(string _dir, int _nro, int _sup, int _anio): direccion(_dir), nroPuerta(_nro), superficie(_sup), anioConstruccion(_anio) {};

    string getDireccion(){return direccion;}
    int getNroPuerta() {return nroPuerta;}
    int  getSuperficie() {return superficie;}
    int  getAnioConstruccion() {return anioConstruccion;}

    virtual ~DTInmuebleDetalles() {}
};


#endif //LAB_2_DTINMUEBLEDETALLES_H

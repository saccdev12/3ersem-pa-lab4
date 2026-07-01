
#ifndef LAB_2_DTINMOBILIARIADETALLES_H
#define LAB_2_DTINMOBILIARIADETALLES_H

#include <string>
#include <map>
#include "DTPropietario.h"

using namespace std;

class DTInmobiliariaDetalles {
private:
    string nickname;
    string nombre;
    string email;

    map<string, DTPropietario*> propietariosRepresentados;

public:
    DTInmobiliariaDetalles(string _nick, string _nom, string _email): nickname(_nick), nombre(_nom), email(_email) {}

    string getNickname() { return nickname; }
    string getNombre() { return nombre; }
    string getEmail() { return email; }

    bool tienePropietario(string nickPropietario);

    void agregarPropietario(DTPropietario* prop);

    void registrarRepresentacion(DTPropietario* p);

    virtual ~DTInmobiliariaDetalles(){}
};


#endif //LAB_2_DTINMOBILIARIADETALLES_H

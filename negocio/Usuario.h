#ifndef INC_1_LAB3_USUARIO_H
#define INC_1_LAB3_USUARIO_H
#include <string>
#include <set>
#include "datatypes/DTUsuario.h"

using namespace std;

enum TipoUsuario { CLIENTE, PROPIETARIO, INMOBILIARIA };

class Usuario {
private:
    string Nickname;
    string Contraseña;
    string Nombre;
    string Email;
public:
    Usuario(string nick, string pass, string nom, string em);
    string getNickname() const { return Nickname; }
    string getNombre() const { return Nombre; }
    string getEmail() const { return Email; }

    virtual TipoUsuario getTipo() = 0;
    virtual DTUsuario* CrearDTUsuario() = 0;

    virtual ~Usuario(){};
};
#endif
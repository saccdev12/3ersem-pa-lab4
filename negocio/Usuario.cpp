#include "Usuario.h"
using namespace std;
Usuario::Usuario(string nick, string pass, string nom, string em) {
    this->Nickname = nick;
    this->Contraseña = pass;
    this->Nombre = nom;
    this->Email = em;
}

#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <string>
using namespace std;

class DTUsuario {
private:
    string nickname;
    string nombre;
    string email;

public:
    DTUsuario(string _nickname, string _nombre, string _email)
        : nickname(_nickname), nombre(_nombre), email(_email) {}

    string getNickname() { return nickname; }
    string getNombre() { return nombre; }
    string getEmail() { return email; }

    virtual ~DTUsuario() {}
};

#endif
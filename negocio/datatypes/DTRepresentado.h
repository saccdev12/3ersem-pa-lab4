//
// Created by Facundo Caraballo Beledo on 28/6/26.
//

#ifndef LAB_2_DTREPRESENTADO_H
#define LAB_2_DTREPRESENTADO_H
#include <iostream>
#include <string>

class DTRepresentado {
private:
    string Nickname;
    string Nombre;
public:
    DTRepresentado(string nick, string nom) {
        this->Nickname = nick;
        this->Nombre = nom;
    }
    string getNickname() { return this->Nickname; }
    string getNombre() { return this->Nombre; }
    ~DTRepresentado() {}
};
#endif //LAB_2_DTREPRESENTADO_H


#include <iostream>
#include <string>
#include <set>
#include "ISistema.h"
#include "PantallaAltaUsuario.h"
#include "DTCliente.h"
#include "DTPropietario.h"
#include "DTInmobiliaria.h"
#include "Usuario.h"


using namespace std;

void PantallaAltaUsuario(ISistema* sys) {
    string nick, pass, nombre, email;
    int tipo;

    cout << "\n=== ALTA DE USUARIO ===" << endl;

    cout << "Ingrese nickname: ";
    cin >> nick;

    cout << "Ingrese password: ";
    cin >> pass;

    cin.ignore();

    cout << "Ingrese nombre completo: ";
    getline(cin, nombre);

    cout << "Ingrese email: ";
    cin >> email;

    cout << "\n¿Que tipo de usuario desea crear?" << endl;
    cout << "1. Propietario" << endl;
    cout << "2. Inmobiliaria" << endl;
    cout << "Opcion: ";
    cin >> tipo;

    if (tipo == 1) {
        // PROPIETARIO
        int cuenta;
        string tel;

        cout << "\nIngrese cuenta bancaria (solo numeros): ";
        cin >> cuenta;

        cout << "Ingrese telefono: ";
        cin >> tel;

        try {
            sys->AltaDelUsuario(nick, pass, nombre, email, 2, tel, cuenta, "");
            cout << "\n Propietario registrado correctamente." << endl;
        } catch (const exception& e) {
            cout << "\nerror " << e.what() << endl;
        }

    } else if (tipo == 2) {
        // INMOBILIARIA
        string dir, tel;

        cin.ignore();
        cout << "\nIngrese direccion: ";
        getline(cin, dir);

        cout << "Ingrese telefono: ";
        cin >> tel;

        try {
            sys->AltaDelUsuario(nick, pass, nombre, email, 3, dir, 0, tel);
            cout << "\n Inmobiliaria registrada correctamente." << endl;
        } catch (const exception& e) {
            cout << "\n error " << e.what() << endl;
        }

    } else {
        cout << "\n Opcion invalida. Abortando operacion." << endl;
    }
}

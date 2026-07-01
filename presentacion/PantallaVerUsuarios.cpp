#include <iostream>
#include <set>
#include <string>
#include "ISistema.h"
#include "datatypes/DTUsuario.h"
#include "datatypes/DTCliente.h"
#include "datatypes/DTPropietario.h"
#include "datatypes/DTInmobiliaria.h"

using namespace std;

void PantallaVerUsuarios(ISistema *sys) {
    cout << "\n========================================" << endl;
    cout << "            VER USUARIOS                " << endl;
    cout << "========================================" << endl;

    cout << "Seleccione el tipo de usuario a listar:" << endl;
    cout << "1. Cliente" << endl;
    cout << "2. Propietario" << endl;
    cout << "3. Inmobiliaria" << endl;
    cout << "Opción: ";

    int opcion;
    cin >> opcion;

    TipoUsuario tipo;
    if (opcion == 1) tipo = CLIENTE;
    else if (opcion == 2) tipo = PROPIETARIO;
    else if (opcion == 3) tipo = INMOBILIARIA;
    else {
        cout << "Opción inválida." << endl;
        return;
    }

    set<DTUsuario*> usuarios = sys->ObtenerUsuarios(tipo);
    if (usuarios.empty()) {
        cout << "\nNo hay usuarios registrados de este tipo." << endl;
        return;
    }

    cout << "\n--- LISTA DE USUARIOS ---" << endl;
    for (DTUsuario* u : usuarios) {
        cout << "- Nickname: " << u->getNickname() << " | Nombre: " << u->getNombre() << endl;
        delete u;
    }

    cout << "\nIngrese el Nickname del usuario que desea consultar: ";
    string nickname;
    cin >> nickname;

    try {
        // Obtiene el objeto polimórfico
        DTUsuario* detalle = sys->SolicitudInformacionUsuario(nickname);

        char res;
        cout << "¿Desea ver los detalles completos del usuario? (s/n): ";
        cin >> res;

        if (res == 's' || res == 'S') {
            cout << "\n----------------------------------------" << endl;
            cout << "       DETALLES DEL USUARIO             " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Nickname: " << detalle->getNickname() << endl;
            cout << "Nombre: " << detalle->getNombre() << endl;
            cout << "Email: " << detalle->getEmail() << endl;

            DTCliente* dtC = dynamic_cast<DTCliente*>(detalle);
            if (dtC != nullptr) {
                cout << "Tipo de Usuario: Cliente" << endl;
                cout << "ID Cliente: " << dtC->getIdCliente() << endl;
            }

            DTPropietario* dtP = dynamic_cast<DTPropietario*>(detalle);
            if (dtP != nullptr) {
                cout << "Tipo de Usuario: Propietario" << endl;
                cout << "Cuenta Bancaria: " << dtP->getCuentaBancaria() << endl;
                cout << "Teléfono: " << dtP->getTelefono() << endl;
            }

            DTInmobiliaria* dtI = dynamic_cast<DTInmobiliaria*>(detalle);
            if (dtI != nullptr) {
                cout << "Tipo de Usuario: Inmobiliaria" << endl;
                cout << "Dirección: " << dtI->getDireccion() << endl;
                cout << "Teléfono: " << dtI->getTelefono() << endl;
            }
            cout << "----------------------------------------\n" << endl;
        }else {
            cout << "\nVolviendo al menú principal..." << endl;
        }

        delete detalle;

    } catch (const exception& e) {
        cout << "\n" << e.what() << endl;
    }
}
#include <iostream>
#include <string>
#include <set>
#include "ISistema.h"
#include "DTInmobiliariaDetalles.h"
#include "DTPropietario.h"

using namespace std;

void PantallaRepresentarPropietario(ISistema* sys) {
    cout << "=== REPRESENTAR PROPIETARIO (Lab 3) ===" << endl;

    set<DTInmobiliariaDetalles*> inmobiliarias = sys->obtenerInmobiliarias();
    if (inmobiliarias.empty()) {
        cout << "No hay inmobiliarias registradas en el sistema." << endl;
        return;
    }

    cout << "\n-- Inmobiliarias Disponibles --" << endl;
    for (auto inmo : inmobiliarias) {
        cout << "Nickname: " << inmo->getNickname() << " | Nombre: " << inmo->getNombre() << endl;
        delete inmo; // Liberación de memoria del DataType
    }

    string nickInmo;
    cout << "\nIngrese el nickname de la inmobiliaria elegida: ";
    cin >> nickInmo;

    set<DTPropietario*> propietariosDisponibles;
    try {
        propietariosDisponibles = sys->seleccionInmobiliariaParaRepresentar(nickInmo);
    } catch (const invalid_argument& e) {
        cout << "[ERROR] " << e.what() << endl;
        return;
    }

    int deseaContinuar = 1;
    while (deseaContinuar == 1) {
        if (propietariosDisponibles.empty()) {
            cout << "\nNo quedan mas propietarios disponibles para asociar a esta inmobiliaria." << endl;
            break;
        }

        cout << "\n-- Propietarios NO asociados a la inmobiliaria '" << nickInmo << "' --" << endl;
        for (auto prop : propietariosDisponibles) {
            cout << "Nickname: " << prop->getNickname()
                 << " | Nombre: " << prop->getNombre()
                 << " | Email: " << prop->getEmail() << endl;
            delete prop;
        }
        propietariosDisponibles.clear();

        string nickProp;
        cout << "\nIngrese el nickname del propietario que desea representar: ";
        cin >> nickProp;

        try {
            propietariosDisponibles = sys->seleccionARepresentar(nickProp);
            cout << "\n[OK] ¡Relacion de representacion generada con exito!" << endl;
        } catch (const invalid_argument& e) {
            cout << "\n[ERROR] " << e.what() << endl;
            break;
        }

        cout << "\n¿Desea agregar otro propietario a esta misma inmobiliaria? (1: Si / 0: No): ";
        cin >> deseaContinuar;
    }

    for (auto prop : propietariosDisponibles) {
        delete prop;
    }

    cout << "\nFin del caso de uso Representar Propietario." << endl;
}
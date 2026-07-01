//
// Created by Facundo Caraballo Beledo on 28/6/26.
//
#include <iostream>
#include <string>
#include <set>
#include "PantallaVerRepresentados.h"

using namespace std;

void PantallaVerRepresentados(ISistema* sys) {
    cout << "\n=== VER REPRESENTADOS ===" << endl;

    try {
        set<DTInmobiliariaDetalles*> inmos = sys->obtenerInmobiliarias();
        if (inmos.empty()) {
            cout << "No hay inmobiliarias registradas en el sistema." << endl;
            return;
        }

        cout << "\n-- Inmobiliarias Disponibles --" << endl;
        for (auto inmo : inmos) {
            cout << "Nickname: " << inmo->getNickname() << " | Nombre: " << inmo->getNombre() << endl;
            delete inmo; // Liberar memoria
        }

        string nickInmo;
        cout << "\nIngrese el nickname de la inmobiliaria: ";
        cin >> nickInmo;

        set<DTRepresentado*> representados = sys->SeleccionInmobiliaria(nickInmo);

        if (representados.empty()) {
            cout << "\nLa inmobiliaria '" << nickInmo << "' no representa a ningun propietario." << endl;
        } else {
            cout << "\n-- Propietarios Representados por '" << nickInmo << "' --" << endl;
            for (auto rep : representados) {
                cout << "Nickname: " << rep->getNickname()
                     << " | Nombre: " << rep->getNombre() << endl;
                delete rep; // Liberar memoria
            }
        }
    } catch (const exception& e) {
        cout << "\n[ERROR] " << e.what() << endl;
    }

    cout << "\nFin del caso de uso Ver Representados." << endl;
}

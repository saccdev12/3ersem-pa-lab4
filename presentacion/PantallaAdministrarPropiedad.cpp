//
// Created by Facundo Caraballo Beledo on 28/6/26.
//
#include <iostream>
#include <string>
#include <set>
#include "PantallaAdministrarPropiedad.h"
#include "datatypes/DTInmueble.h"
#include "ISistema.h"
#include "DTInmobiliariaDetalles.h"
#include "DTInmueble.h"

using namespace std;

void PantallaAdministrarPropiedad(ISistema* sys) {
    cout << "\n=== ADMINISTRAR PROPIEDAD ===" << endl;

    try {
        set<DTInmobiliariaDetalles*> inmos = sys->obtenerInmobiliarias();
        if (inmos.empty()) {
            cout << "No hay inmobiliarias registradas en el sistema para comenzar administraciones." << endl;
            return;
        }

        cout << "\n-- Inmobiliarias Disponibles --" << endl;
        for (auto inmo : inmos) {
            cout << "Nickname: " << inmo->getNickname()
                 << " | Nombre: " << inmo->getNombre()
                 << " | Email: " << inmo->getEmail() << endl;
            delete inmo; // Liberación higiénica del DataType
        }

        string nickInmo;
        cout << "\nIngrese el nickname de la inmobiliaria elegida: ";
        cin >> nickInmo;

        set<DTInmueble*> inmueblesDisp = sys->SeleccionInmoParaAdministrar(nickInmo);

        if (inmueblesDisp.empty()) {
            cout << "\nLa inmobiliaria '" << nickInmo << "' no posee inmuebles de representados disponibles para administrar." << endl;
            return;
        }

        cout << "\n-- Inmuebles representados NO administrados --" << endl;
        for (auto inm : inmueblesDisp) {
            cout << "Codigo: " << inm->getCodNumerico()
                 << " | Direccion: " << inm->getDireccion();

            if (!inm->getNombrePropietario().empty()) {
                 cout << " | Propietario: " << inm->getNombrePropietario();
            }
            cout << endl;
            delete inm;
        }

        int codInmueble;
        cout << "\nIngrese el codigo del inmueble que desea comenzar a administrar: ";
        cin >> codInmueble;

        sys->SeleccionInmueble(codInmueble);

        cout << "\n[OK] ¡La propiedad comenzo a ser administrada exitosamente en la fecha de hoy!" << endl;

    } catch (const exception& e) {
        cout << "\n[ERROR] " << e.what() << endl;
    }

    cout << "\nFin del caso de uso Administrar Propiedad." << endl;
}
//
// Created by Facundo Caraballo Beledo on 28/6/26.
//

#include "PantallaEliminarInmueble.h"
#include "ISistema.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

void PantallaEliminarInmueble(ISistema* sys) {
    cout << "\n========================================" << endl;
    cout << "           ELIMINAR INMUEBLE            " << endl;
    cout << "========================================" << endl;

    try {
        map<int, string> resumenInmuebles = sys->ObtenerResumenInmuebles();

        if (resumenInmuebles.empty()) {
            cout << "\n[ERROR] No hay inmuebles registrados en el sistema." << endl;
            return;
        }

        cout << "\n--- LISTA DE INMUEBLES ---" << endl;
        for (auto const& item : resumenInmuebles) {
            cout << "- Codigo: " << item.first << " | " << item.second << endl;
        }

        int codigo;
        cout << "\nIngrese el codigo del inmueble a eliminar: ";
        cin >> codigo;

        cout << "\n--- DETALLE DEL INMUEBLE ---" << endl;
        cout << sys->ObtenerDetalleInmuebleString(codigo) << endl;

        char confirmacion;
        cout << "\n¿Esta seguro que desea eliminar este inmueble y todas sus publicaciones asociadas? (s/n): ";
        cin >> confirmacion;

        if (confirmacion == 's' || confirmacion == 'S') {
            sys->EliminarInmueble(codigo);
            cout << "\n[EXITO] Inmueble y publicaciones eliminados correctamente." << endl;
        } else {
            cout << "\nOperacion cancelada. El sistema permanece incambiado." << endl;
        }

    } catch (const exception& e) {
        cout << "\n[ERROR] " << e.what() << endl;
    }
}
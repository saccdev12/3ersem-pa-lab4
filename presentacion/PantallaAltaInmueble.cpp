#include <iostream>
#include <string>
#include <set>
#include "ISistema.h"
#include "DTPropietario.h"
#include "DTCasa.h"
#include "DTApartamento.h"

using namespace std;

void PantallaAltaInmueble(ISistema* sys) {
    cout << "=== ALTA DE INMUEBLE (Lab 3) ===" << endl;

    set<DTPropietario*> propietarios = sys->ObtenerPropietarios();
    if (propietarios.empty()) {
        cout << "No hay propietarios registrados en el sistema para asignar inmuebles." << endl;
        return;
    }

    cout << "\n-- Lista de Propietarios Disponibles --" << endl;
    for (auto it = propietarios.begin(); it != propietarios.end(); ++it) {
        cout << "Nickname: " << (*it)->getNickname()
             << " | Nombre: " << (*it)->getNombre()
             << " | Email: " << (*it)->getEmail() << endl;
        delete *it;
    }

    string nickname;
    cout << "\nIngrese el nickname del propietario elegido: ";
    cin >> nickname;

    int deseaContinuar = 1;
    while (deseaContinuar == 1) {
        string direccion;
        int nroPuerta, superficie, anio;
        int opcionTipo;

        cout << "\n--- Datos del nuevo Inmueble ---" << endl;
        cout << "Direccion: ";
        cin.ignore();
        getline(cin, direccion);
        cout << "Nro de Puerta: ";
        cin >> nroPuerta;
        cout << "Superficie (m2): ";
        cin >> superficie;
        cout << "Anio de construccion: ";
        cin >> anio;

        cout << "Tipo de Inmueble (1. Casa | 2. Apartamento): ";
        cin >> opcionTipo;

        DTInmuebleDetalles* datosInmueble = nullptr;
        if (opcionTipo == 1) {
            int propHoriz, tipoTechoInt;
            cout << "Es Propiedad Horizontal? (1: Si, 0: No): ";
            cin >> propHoriz;
            cout << "Tipo de techo (0: Liviano, 1: Dos Aguas, 2: Plano): ";
            cin >> tipoTechoInt;

            bool ph = (propHoriz == 1);
            DTTecho techo = static_cast<DTTecho>(tipoTechoInt);

            datosInmueble = new DTCasa(direccion, nroPuerta, superficie, anio, ph, techo);
        } else if (opcionTipo == 2) {
            int nroPiso, ascensor;
            float gastos;
            cout << "Nro de Piso: ";
            cin >> nroPiso;
            cout << "Posee ascensor? (1: Si, 0: No): ";
            cin >> ascensor;
            cout << "Gastos comunes: ";
            cin >> gastos;

            bool poseeAsc = (ascensor == 1);
            datosInmueble = new DTApartamento(direccion, nroPuerta, superficie, anio, nroPiso, poseeAsc, gastos);
        }
        if (datosInmueble != nullptr) {
            try {
                sys->IngresarDatosInmueble(nickname, datosInmueble);
                cout << "\n[OK] ¡Inmueble dado de alta con éxito y asociado al propietario!" << endl;
            } catch (const invalid_argument& e) {
                cout << "\n[ERROR] " << e.what() << endl;
                delete datosInmueble;
                break; // Si el nick estaba mal, rompemos el bucle
            }
            delete datosInmueble;
        }

        cout << "\n¿Desea ingresar otro inmueble para el propietario '" << nickname << "'? (1: Si / 0: No): ";
        cin >> deseaContinuar;
    }
    cout << "\nFin del caso de uso Alta Inmueble." << endl;
}
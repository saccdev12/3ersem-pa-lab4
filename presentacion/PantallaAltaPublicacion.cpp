#include "PantallaAltaPublicacion.h"
#include <iostream>
#include <string>
#include <set>
#include "Date.h"

void PantallaAltaPublicacion(ISistema* sys) {
    cout << "=== ALTA DE PUBLICACION ===" << endl;

    // 1. Mostrar Inmuebles
    set<DTInmueble*> inmuebles = sys->obtenerInmuebles();
    cout << "\nInmuebles disponibles en el sistema:" << endl;
    for (DTInmueble* dt : inmuebles) {
        cout << "- Codigo: " << dt->getCodNumerico()
             << " | Direccion: " << dt->getDireccion() << endl;
        delete dt;
    }

    // 2. Pedir código al usuario
    int codInmueble;
    cout << "\nIngrese el Codigo del Inmueble a publicar: ";
    cin >> codInmueble;
    cin.ignore();

    // 3. Pedir datos de la publicación
    string tipoStr, texto;
    int dia, mes, anio;
    float precio;

    cout << "Ingrese Fecha (DD/MM/AAAA): ";
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;
    cin.ignore();

    Date fechaPub = {dia, mes, anio};

    cout << "Ingrese Tipo (Venta / Alquiler): ";
    getline(cin, tipoStr);

    cout << "Ingrese Texto de la publicacion: ";
    getline(cin, texto);

    cout << "Ingrese Precio: ";
    cin >> precio;

    DTPublicacion* dtPub = new DTPublicacion(0,fechaPub, tipoStr, texto, precio, true);

    sys->ingresarDatosPublicacion(codInmueble, dtPub);

    cout << "\n¡Publicacion creada y vinculada al inmueble con exito!" << endl;

    delete dtPub; // Limpiamos el DT
}
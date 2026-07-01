#include <iostream>
#include <string>
#include <set>
#include "Sistema.h"
#include "DTInmobiliaria.h"
#include "DTInmueble.h"
#include "DTPublicacion.h"
#include "DTAgenda.h"
#include "PantallaVerEstadisticasAdministracion.h"
using namespace std;

void PantallaVerEstadisticasAdministracion(ISistema* sistema) {
    cout << "\n=== VER ESTADISTICAS DE ADMINISTRACION ===\n" << endl;


    set<DTInmobiliariaDetalles*> inmos = sistema->obtenerInmobiliarias();
    if (inmos.empty()) {
        cout << "No hay inmobiliarias registradas." << endl;
        return;
    }

    cout << "-- Inmobiliarias del Sistema --" << endl;
    for (DTInmobiliariaDetalles* dt : inmos) {
        cout << "Nickname: " << dt->getNickname()
             << " | Nombre: " << dt->getNombre()
             << " | Mail: " << dt->getEmail() << endl;
        delete dt;
    }

    string nickInmo;
    cout << "\nIngrese el nickname de la inmobiliaria elegida (o '0' para cancelar): ";
    cin >> nickInmo;
    if (nickInmo == "0") return;

    try {

        set<DTInmueble*> inmuebles = sistema->SeleccionInmobiliariaEstadisticas(nickInmo);
        if (inmuebles.empty()) {
            cout << "La inmobiliaria no administra propiedades." << endl;
            return;
        }

        cout << "\n-- Inmuebles Administrados por " << nickInmo << " --" << endl;
        for (DTInmueble* dti : inmuebles) {
            // Ajustá dti->getCodigo() si tu Dt usa getId()
            cout << "Codigo: " << dti->getCodNumerico()
                 << " | Direccion: " << dti->getDireccion()<< endl;
            cout << " | Inicio Admin: "
      << dti->getFechaAdministracion().dia << "/"
      << dti->getFechaAdministracion().mes << "/"
      << dti->getFechaAdministracion().anio << endl;
            delete dti;
        }


        string codInmuebleStr;
        cout << "\nIngrese el Codigo del Inmueble para ver sus publicaciones (o '0' para cancelar): ";
        cin >> codInmuebleStr;
        if (codInmuebleStr == "0") return;

        int codInmueble = stoi(codInmuebleStr);
        set<DTPublicacion*> publicaciones = sistema->SeleccionInmuebleEstadisticas(codInmueble);

        if (publicaciones.empty()) {
            cout << "El inmueble seleccionado no tiene publicaciones." << endl;
            return;
        }

        cout << "\n-- Publicaciones del Inmueble " << codInmueble << " --" << endl;
        for (DTPublicacion* dtp : publicaciones) {
            cout << "ID: " << dtp->getId()
             << " | Fecha: " << dtp->getFecha().dia << "/"
               << dtp->getFecha().mes << "/"
             << dtp->getFecha().anio
             << " | Contenido: " << dtp->getTexto() << endl;
            delete dtp;
        }


        string idPubStr;
        cout << "\nIngrese el ID de la Publicacion para ver sus agendas (o '0' para cancelar): ";
        cin >> idPubStr;
        if (idPubStr == "0") return;

        int idPub = stoi(idPubStr);
        set<DTAgenda*> agendas = sistema->SeleccionPublicacion(idPub);

        if (agendas.empty()) {
            cout << "La publicacion seleccionada no tiene agendas de visitas." << endl;
            return;
        }


        cout << "\n-- Agendas de la Publicacion " << idPub << " --" << endl;
        for (DTAgenda* dta : agendas) {

            cout << "Fecha: " << dta->getFecha().dia << "/"
              << dta->getFecha().mes << "/"
              << dta->getFecha().anio
              << " | Contacto: " << dta->getFormaContacto()
              << " | Cliente: " << dta->getNombre() << " " << dta->getApellido() << endl;

            delete dta;
        }

    } catch (const exception& e) {
        cout << "\n[ERROR] " << e.what() << endl;
    }

    cout << "\nFin del caso de uso Ver Estadisticas de Administracion." << endl;
}
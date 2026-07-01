#include <iostream>
#include <string>
#include <set>
#include "ISistema.h"
#include "datatypes/DTRango.h"
#include "datatypes/DTInteres.h"
#include "datatypes/DTListaPublicacion.h"
#include "datatypes/DTInmueble.h"
#include "datatypes/DTCliente.h"
#include "datatypes/Date.h"
#include "PantallaConsultarPublicaciones.h"

using namespace std;

void PantallaConsultarPublicaciones(ISistema* sys) {
    cout << "\n=== CONSULTAR PUBLICACIONES ===" << endl;

    string tipo;
    cout << "Ingrese tipo de publicacion (Venta/Alquiler): ";
    cin >> tipo;

    float min, max;
    cout << "Ingrese precio minimo: ";
    cin >> min;
    cout << "Ingrese precio maximo: ";
    cin >> max;
    DTRango* rango = new DTRango(min, max);

    int opcionInteres;
    cout << "Ingrese interes (0: Casas, 1: Apartamento, 2: Ambas): ";
    cin >> opcionInteres;
    DTInteres interes = static_cast<DTInteres>(opcionInteres);

    // 2. Ejecutar la busqueda
    set<DTListaPublicacion*> resultados = sys->obtenerPublicaciones(tipo, rango, interes);

    if (resultados.empty()) {
        cout << "No se encontraron publicaciones con esos filtros." << endl;
        delete rango;
        return;
    }

    // 3. Mostrar los resultados
    cout << "\n--- PUBLICACIONES ENCONTRADAS ---" << endl;
    for (auto const& dtPub : resultados) {
        cout << "Codigo: " << dtPub->getCodigo()
             << " | Precio: $" << dtPub->getPrecio()
             << " | Inmobiliaria: " << dtPub->getNombreInmobiliaria() << endl;
    }

    // 4. Flujo Opcional 1: Seleccionar Publicacion para ver Inmueble
    string verDetalle;
    cout << "\nDesea ver el detalle de un inmueble? (s/n): ";
    cin >> verDetalle;

    int codElegido = -1;

    if (verDetalle == "s" || verDetalle == "S") {
        cout << "Ingrese el Codigo de la Publicacion: ";
        cin >> codElegido;

        DTInmueble* dtInm = sys->seleccionPublicacion(codElegido);
        if (dtInm != nullptr) {
            cout << "\n--- DETALLE DEL INMUEBLE ---" << endl;
            cout << "Detalles cargados exitosamente." << endl;
        } else {
            cout << "Error: No se encontro el inmueble." << endl;
        }

        string agendar;
        cout << "\nDesea agendar una visita para este inmueble? (s/n): ";
        cin >> agendar;

        if (agendar == "s" || agendar == "S") {
            // Mostrar clientes disponibles
            cout << "\n--- CLIENTES DEL SISTEMA ---" << endl;
            set<DTCliente*> clientes = sys->obtenerClientes();
            for (auto const& c : clientes) {
                // CORRECCIÓN 1: Cambiamos getId() por getIdCliente()
                cout << "ID: " << c->getIdCliente() << " | Nombre: " << c->getNombre() << endl;
            }

            // Pedir datos de la agenda
            int idCliente;
            cout << "\nIngrese el ID del Cliente: ";
            cin >> idCliente;

            int d, m, y;
            cout << "Fecha de comunicacion - Dia: "; cin >> d;
            cout << "Fecha de comunicacion - Mes: "; cin >> m;
            cout << "Fecha de comunicacion - Anio: "; cin >> y;

            // CORRECCIÓN 2: Usamos llaves {} para inicializar tu struct Date
            Date fechaCom = {d, m, y};

            string formaContacto;
            cout << "Forma de contacto (Presencial/Llamada/Mensaje): ";
            cin >> formaContacto;

            // Ejecutar la accion final
            sys->agendarVisita(idCliente, fechaCom, formaContacto, codElegido);
            cout << "\n¡Visita agendada con exito!" << endl;
        }

        cout << "\nSaliendo de la consulta de publicaciones..." << endl;
        delete rango; // Liberamos memoria del rango que creamos al principio
    }
}
#include <iostream>
#include "negocio/Sistema.h"

#include "presentacion/PantallaAltaUsuario.h"
#include "presentacion/PantallaVerUsuarios.h"
#include "presentacion/PantallaAltaInmueble.h"
#include "presentacion/PantallaEliminarInmueble.h"
#include "presentacion/PantallaRepresentarPropietario.h"
#include "presentacion/PantallaVerRepresentados.h"
#include "presentacion/PantallaAdministrarPropiedad.h"
#include "presentacion/PantallaVerEstadisticasAdministracion.h"
#include "presentacion/PantallaAltaPublicacion.h"
#include "presentacion/PantallaConsultarPublicaciones.h"

void PantallaAltaInmueble(ISistema* sys);
void PantallaRepresentarPropietario(ISistema* sys);


int main() {
    //obtiene la instancia del sistema.
    ISistema* sys = Sistema::getInstancia();
    int opcion;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "   SISTEMA INMOBILIARIO - PROTOTIPO" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Alta de Usuario" << std::endl;
        std::cout << "2. Ver Usuarios" << std::endl;
        std::cout << "3. Alta de Inmueble" << std::endl;
        std::cout << "4. Eliminar Inmueble " << std::endl;
        std::cout << "5. Representar Propietario " << std::endl;
        std::cout << "6. Ver Representados" << std::endl;
        std::cout << "7. Administrar Propiedad" << std::endl;
        std::cout << "8. Ver Estadisticas de Administracion" << std::endl;
        std::cout << "9. Alta de Publicacion" << std::endl;
        std::cout << "10. Consultar Publicaciones" << std::endl;
        std::cout << "11. Precargar Datos" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                PantallaAltaUsuario(sys);
                break;
            case 2:
                PantallaVerUsuarios(sys);
                break;
            case 3:
                PantallaAltaInmueble(sys);
                break;
            case 4:
                PantallaEliminarInmueble(sys);
                break;
            case 5:
                PantallaRepresentarPropietario(sys);
                break;
            case 6:
                PantallaVerRepresentados(sys);
                break;
            case 7:
                PantallaAdministrarPropiedad(sys);
                break;
            case 8:
                PantallaVerEstadisticasAdministracion(sys);
                break;
            case 9:
                PantallaAltaPublicacion(sys);
                break;
            case 10:
                PantallaConsultarPublicaciones(sys);
                break;
            case 11:
                cout << "Cargando datos de prueba..." << endl;
                dynamic_cast<Sistema*>(sys)->cargarDatosPrueba();
                cout << "¡Datos cargados con exito!" << endl;
                break;
            case 0:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}

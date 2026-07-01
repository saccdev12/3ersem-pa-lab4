#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"
#include <map>
#include <string>
#include <set>

#include "Usuario.h"
#include "Cliente.h"
#include "Inmobiliaria.h"
#include "Propietario.h"
#include "datatypes/DTPropietario.h"
#include "DTAgenda.h"
class Publicacion;
class Sistema : public ISistema {
private:
    static Sistema* instancia;
    Sistema();

    int proximoIdInmueble = 1;

    map<string, Usuario*> colUsuarios;

    map<string, Propietario*> propietarios;
    map<int, Inmueble*> inmuebles;
    map<string, Inmobiliaria*> inmobiliarias;
    map<int, Cliente*> colClientes;
    map<int, Publicacion*> colPublicaciones;

    Inmobiliaria* inmobiliariaRecordada = nullptr;
    Propietario* propietarioRecordado;

    Inmueble* inmuebleRecordado;
    Publicacion* publicacionRecordada;



public:
    static Sistema* getInstancia();
    //Ver usuarios
    set<DTUsuario*> ObtenerUsuarios(TipoUsuario tipo);
    DTUsuario* SolicitudInformacionUsuario(string nickname);

    //Alta Usuario
    void AltaDelUsuario(string nickname, string contrasenia, string nombre, string email, int tipoUsuario, string paramString1, int paramInt, string paramString2);

    // Alta Inmueble
    set<DTPropietario*> ObtenerPropietarios();
    void IngresarDatosInmueble(string nickname, DTInmuebleDetalles* datos);
    void seleccionarPropietario(string nickname);
    void altaInmueble(string direccion, int nroPuerta, int superficie, int anioConstruccion, bool esCasa, bool propHorizontal, DTTecho techo, int piso, float gastosComunes, bool tieneAscensor);

    //Elimina Inmueble
    map<int, string> ObtenerResumenInmuebles();
    string ObtenerDetalleInmuebleString(int idInmueble);
    void EliminarInmueble(int idInmueble);

    // Representar Propietario
    set<DTInmobiliariaDetalles*> obtenerInmobiliarias();
    set<DTPropietario*> seleccionInmobiliariaParaRepresentar(string nickname);
    set<DTPropietario*> seleccionARepresentar(string nickname);
    void Representar(string nicknameIn, string nicknameP);

    //Ver Representados 6
    set<DTRepresentado*> SeleccionInmobiliaria(string nickname);

    //Administrar Propiedad 7
    set<DTInmueble*> SeleccionInmoParaAdministrar(string nickname);
    void SeleccionInmueble(int codigo);

    //VerEstadisticasAdministradas
    set<DTInmueble*> SeleccionInmobiliariaEstadisticas(string nickname);
    set<DTPublicacion*> SeleccionInmuebleEstadisticas(int codigo);
    set<DTAgenda*> SeleccionPublicacion(int idPublicacion);

    // Alta Publicación
    set<DTInmueble*> obtenerInmuebles() ;
    void ingresarDatosPublicacion(int cod, DTPublicacion* publicacion);

    // ConsultarPublicacion
    set<DTListaPublicacion*> obtenerPublicaciones(string tipo, DTRango* rango, DTInteres interes);
    DTInmueble* seleccionPublicacion(int codPublicacion);
    set<DTCliente*> obtenerClientes();
    void agendarVisita(int idCliente, Date fechaComunicacion, string formaContacto, int codPublicacion);
    void cargarDatosPrueba();
};

#endif // SISTEMA_H
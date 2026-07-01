#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <set>
#include "datatypes/DTInmobiliaria.h"
#include "datatypes/DTInmueble.h"
#include "datatypes/DTPublicacion.h"
#include "datatypes/DTListaPublicacion.h"
#include "datatypes/DTCliente.h"
#include "datatypes/DTRango.h"
#include "datatypes/DTInteres.h"
#include "datatypes/DTPropietario.h"
#include "datatypes/DTInmuebleDetalles.h"
#include "datatypes/DTCasa.h"
#include "datatypes/DTApartamento.h"
#include "datatypes/DTInmobiliariaDetalles.h"
#include "Usuario.h"
#include "datatypes/DTUsuario.h"
#include "datatypes/DTRepresentado.h"
#include "DTAgenda.h"

class ISistema {
public:

    //Alta Usuario 1
    virtual void AltaDelUsuario(string nickname, string contrasenia, string nombre, string email, int tipoUsuario, string paramString1, int paramInt, string paramString2)=0;

    //Ver Usuarios 2
    virtual set<DTUsuario*> ObtenerUsuarios(TipoUsuario tipo) = 0;
    virtual DTUsuario* SolicitudInformacionUsuario(string nickname) = 0;

    //Alta Inmueble 3
    virtual set<DTPropietario*> ObtenerPropietarios() = 0;
    virtual void IngresarDatosInmueble(string nickname, DTInmuebleDetalles* datos)= 0;
    virtual void seleccionarPropietario(string nickname)=0;
    virtual void altaInmueble(string direccion, int nroPuerta, int superficie, int anioConstruccion, bool esCasa, bool propHorizontal, DTTecho techo, int piso, float gastosComunes, bool tieneAscensor)=0;

    //Elimina INmueble 4
    virtual map<int, string> ObtenerResumenInmuebles()=0;
    virtual string ObtenerDetalleInmuebleString(int idInmueble)=0;
    virtual void EliminarInmueble(int idInmueble)=0;

    //Representar Propietario 5
    virtual set<DTInmobiliariaDetalles*> obtenerInmobiliarias() = 0;
    virtual set<DTPropietario*> seleccionInmobiliariaParaRepresentar(string nickname) = 0;
    virtual set<DTPropietario*> seleccionARepresentar(string nickname) = 0;
    virtual void Representar(string nicknameIn, string nicknameP)=0;

    //Ver Representados 6
    virtual set<DTRepresentado*> SeleccionInmobiliaria(string nickname)=0;

    //Administrar Propiedad 7
    virtual set<DTInmueble*> SeleccionInmoParaAdministrar(string nickname)=0;
    virtual void SeleccionInmueble(int codigo)=0;

    //VerEstadisticasAdministradas
    virtual set<DTInmueble*> SeleccionInmobiliariaEstadisticas(string nickname) = 0;
    virtual set<DTPublicacion*> SeleccionInmuebleEstadisticas(int codigo) = 0;
    virtual set<DTAgenda*> SeleccionPublicacion(int idPublicacion)=0;

    // Alta Publicación 9
    virtual set<DTInmueble*> obtenerInmuebles()=0;
    virtual void ingresarDatosPublicacion(int cod, DTPublicacion* publicacion) = 0;

    //ConsultarPublicacion 10
    virtual set<DTListaPublicacion*> obtenerPublicaciones(string tipo, DTRango* rango, DTInteres interes)=0;
    virtual DTInmueble* seleccionPublicacion(int codPublicacion)=0;
    virtual set<DTCliente*> obtenerClientes()=0;
    virtual void agendarVisita(int idCliente, Date fechaComunicacion, string formaContacto, int codPublicacion)=0;
    virtual void cargarDatosPrueba()=0;

    virtual ~ISistema() {}
};
#endif
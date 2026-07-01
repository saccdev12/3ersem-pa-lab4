#include "Sistema.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include "Cliente.h"
#include "datatypes/DTPropietario.h"
#include "datatypes/DTPublicacion.h"
#include <iostream>
#include <stdexcept>
#include "Inmueble.h"
#include "Casa.h"
#include "Apartamento.h"
#include "DTCasa.h"
#include "DTApartamento.h"
#include "datatypes/DTInmobiliariaDetalles.h"
#include "Publicacion.h"
#include "datatypes/DTListaPublicacion.h"
#include "datatypes/DTRepresentado.h"
#include <ctime>
#include "DTAgenda.h"
#include "Agenda.h"

using namespace std;

Sistema* Sistema::instancia = nullptr;
Sistema::Sistema() {
    this->proximoIdInmueble = 1;
}
Sistema* Sistema::getInstancia() {
    if (instancia == nullptr) instancia = new Sistema();
    return instancia;
}

//
// VER USUARIOS
//

// 1. Caso: ObtenerUsuarios()
set<DTUsuario*> Sistema::ObtenerUsuarios(TipoUsuario tipo) {
    set<DTUsuario*> res;


    for (auto const& par : this->colUsuarios) {


        if (par.second->getTipo() == tipo) {


            DTUsuario* dtU = new DTUsuario(par.second->getNickname(),
                                           par.second->getNombre(),
                                           par.second->getEmail());
            res.insert(dtU);
        }
    }

    return res;
}

// 2. Caso: SolicitudInformacionUsuario()
DTUsuario* Sistema::SolicitudInformacionUsuario(string nickname) {
    // 1. u = find(nickname)
    auto it = this->colUsuarios.find(nickname);
    if (it == this->colUsuarios.end()) {
        throw invalid_argument("Error: El usuario con nickname " + nickname + " no existe.");
    }

    Usuario* u = it->second;

    // 2. CrearDTUsuario(): DTUsuario (Polimórfico: retornará DTCliente, DTPropietario o DTInmobiliaria)
    return u->CrearDTUsuario();
}

//
// ALTA USUARIO
//

void Sistema::AltaDelUsuario(string nickname, string contrasenia, string nombre, string email, int tipoUsuario, string paramString1, int paramInt, string paramString2) {

    if (this->colUsuarios.find(nickname) != this->colUsuarios.end()) {
        throw invalid_argument("Error: Ya existe un usuario registrado con el nickname: " + nickname);
    }

    Usuario* nuevoUsuario = nullptr;

    if (tipoUsuario == 1) { // CASO: CLIENTE
        Cliente* nuevoCliente = new Cliente(nickname, contrasenia, nombre, email, paramString1, paramInt);
        nuevoUsuario = nuevoCliente;

        this->colClientes[paramInt] = nuevoCliente;

    } else if (tipoUsuario == 2) { // CASO: PROPIETARIO
        Propietario* nuevoPropietario = new Propietario(nickname, contrasenia, nombre, email, paramInt, paramString1);
        nuevoUsuario = nuevoPropietario;

        this->propietarios[nickname] = nuevoPropietario;

    } else if (tipoUsuario == 3) { // CASO: INMOBILIARIA

          Inmobiliaria* nuevaInmo = new Inmobiliaria(nickname, contrasenia, nombre, email, paramString1, paramString2, "");
        nuevoUsuario = nuevaInmo;

        this->inmobiliarias[nickname] = nuevaInmo;
    }

    if (nuevoUsuario != nullptr) {
        this->colUsuarios[nickname] = nuevoUsuario;
    }
}

//
//ALTA INMUEBLE
//


set<DTPropietario*> Sistema::ObtenerPropietarios() {
    set<DTPropietario*> res;

    for (auto const& par : this->colUsuarios) {

        Propietario* p = dynamic_cast<Propietario*>(par.second);

        if (p != nullptr) {

            string nick = p->getNickname();
            string nom = p->getNombre();
            string email = p->getEmail();

            int cuenta = p->getCuentaBancaria();
            string tel = p->getTelefono();

            DTPropietario* dtProp = new DTPropietario(nick, nom, email, cuenta, tel);
            res.insert(dtProp);
        }
    }

    return res;
}

void Sistema::IngresarDatosInmueble(string nickname, DTInmuebleDetalles* datos) {
    if (this->propietarios.count(nickname) == 0) {
        throw std::invalid_argument("El propietario no existe.");
    }
    Propietario* prop = this->propietarios[nickname];

    int id = this->proximoIdInmueble;
    Inmueble* nuevo = nullptr;

    DTCasa* dtC = dynamic_cast<DTCasa*>(datos);
    if (dtC != nullptr) {
        nuevo = new Casa(id, dtC->getDireccion(), dtC->getNroPuerta(), dtC->getSuperficie(), dtC->getAnioConstruccion(), dtC->getPropiedadHorizontal(), dtC->getTipoTecho());
    } else {
        DTApartamento* dtA = dynamic_cast<DTApartamento*>(datos);
        if (dtA != nullptr) {
            nuevo = new Apartamento(id, dtA->getDireccion(), dtA->getNroPuerta(), dtA->getSuperficie(), dtA->getAnioConstruccion(), dtA->getNroPiso(), dtA->getGastosComunes(), dtA->getPoseeAscensor());
        }
    }

    if (nuevo != nullptr) {
        this->inmuebles[id] = nuevo;
        prop->agregarInmueble(nuevo);
        this->proximoIdInmueble++;
    }
}

void Sistema::seleccionarPropietario(string nickname) {
    if (this->propietarios.find(nickname) != this->propietarios.end()) {
        this->propietarioRecordado = this->propietarios[nickname];
    } else {
        throw std::runtime_error("Propietario no encontrado");
    }
}

void Sistema::altaInmueble(string direccion, int nroPuerta, int superficie, int anioConstruccion, bool esCasa, bool propHorizontal, DTTecho techo, int piso, float gastosComunes, bool tieneAscensor) {

    if (this->propietarioRecordado == nullptr) {
        throw std::runtime_error("Error: No hay propietario seleccionado.");
    }

    int codigo = this->proximoIdInmueble;
    this->proximoIdInmueble++;

    Inmueble* nuevoInmueble = nullptr;

    if (esCasa) {
        nuevoInmueble = new Casa(codigo, direccion, nroPuerta, superficie, anioConstruccion, propHorizontal, techo);
    } else {
        nuevoInmueble = new Apartamento(codigo, direccion, nroPuerta, superficie, anioConstruccion, piso, gastosComunes, tieneAscensor);
    }

    this->propietarioRecordado->agregarInmueble(nuevoInmueble);
    this->inmuebles[codigo] = nuevoInmueble;
}

//
//Eliminar Inmueble
//

map<int, string> Sistema::ObtenerResumenInmuebles() {
    map<int, string> resumen;

    for (auto const& inm : this->inmuebles) {
        Inmueble* i = inm.second;
        string nombreDuenio = "Desconocido";

        for (auto const& u : this->colUsuarios) {
            if (u.second->getTipo() == PROPIETARIO) {
                Propietario* p = dynamic_cast<Propietario*>(u.second);
                if (p != nullptr && p->tieneInmueble(i->getId())) {
                    nombreDuenio = p->getNombre();
                    break;
                }
            }
        }
        resumen[i->getId()] = "Direccion: " + i->getDireccion() + " | Propietario: " + nombreDuenio;
    }
    return resumen;
}

string Sistema::ObtenerDetalleInmuebleString(int idInmueble) {
    if (this->inmuebles.find(idInmueble) == this->inmuebles.end()) {
        throw invalid_argument("El inmueble no existe.");
    }
    Inmueble* i = this->inmuebles[idInmueble];
    return "ID: " + to_string(i->getId()) + "\nDireccion: " + i->getDireccion() +
           "\nNro Puerta: " + to_string(i->getNroPuerta()) +
           "\nSuperficie: " + to_string(i->getSuperficie()) + "m2\nAnio: " + to_string(i->getAnioConstruccion());
}

void Sistema::EliminarInmueble(int idInmueble) {
    if (this->inmuebles.find(idInmueble) == this->inmuebles.end()) {
        throw invalid_argument("El inmueble no existe en el sistema.");
    }

    Inmueble* inm = this->inmuebles[idInmueble];

    map<int, Publicacion*> pubs = inm->getPublicaciones();
    for (auto const& p : pubs) {
        this->colPublicaciones.erase(p.first);
        delete p.second; // Destruimos la publicacion
    }

    for (auto const& prop : this->propietarios) {
        if (prop.second->tieneInmueble(idInmueble)) {
            prop.second->removerInmueble(idInmueble);
            break;
        }
    }

    this->inmuebles.erase(idInmueble);

    delete inm;
}

//
//Representar Propietario
//

// 1. Obtener Inmobiliarias
set<DTInmobiliariaDetalles*> Sistema::obtenerInmobiliarias() {
    set<DTInmobiliariaDetalles*> res;

    for (auto const& inmoPair : this->inmobiliarias) {
        Inmobiliaria* inmo = inmoPair.second;

        string nick = inmo->getNickname();
        string nombre = inmo->getNombre();
        string email = inmo->getEmail();

        res.insert(new DTInmobiliariaDetalles(nick, nombre, email));
    }

    return res;
}

set<DTPropietario*> Sistema::seleccionInmobiliariaParaRepresentar(string nickname) {
    if (this->inmobiliarias.count(nickname) == 0) {
        throw std::invalid_argument("La inmobiliaria especificada no existe.");
    }

    this->inmobiliariaRecordada = this->inmobiliarias[nickname];
    set<DTPropietario*> res;

    for (auto it = this->propietarios.begin(); it != this->propietarios.end(); ++it) {
        Propietario* prop = it->second;

        if (!this->inmobiliariaRecordada->tienePropietario(prop->getNickname())) {
            res.insert(new DTPropietario(prop->getNickname(), prop->getNombre(), prop->getEmail(),prop->getCuentaBancaria(), prop->getTelefono()));
        }
    }

    return res;
}


set<DTPropietario*> Sistema::seleccionARepresentar(string nickname) {
    if (this->colUsuarios.count(nickname) == 0) {
        throw std::invalid_argument("El propietario especificado no existe.");
    }

    Propietario* prop = dynamic_cast<Propietario*>(this->colUsuarios[nickname]);

    if (prop == nullptr) {
        throw std::invalid_argument("El usuario especificado no es un propietario.");
    }

    this->inmobiliariaRecordada->agregarPropietario(prop);

    set<DTPropietario*> res;

    for (auto const& par : this->colUsuarios) {
        Propietario* p = dynamic_cast<Propietario*>(par.second);

        if (p != nullptr && !this->inmobiliariaRecordada->tienePropietario(p->getNickname())) {

            string nick = p->getNickname();
            string nom = p->getNombre();
            string email = p->getEmail();
            int cuenta = p->getCuentaBancaria();
            string tel = p->getTelefono();

            res.insert(new DTPropietario(nick, nom, email, cuenta, tel));
        }
    }

    return res;
}

void Sistema::Representar(string nicknameIn, string nicknameP) {

    Inmobiliaria* i = this->inmobiliarias[nicknameIn];
    Propietario* p = this->propietarios[nicknameP];

    if (i != nullptr && p != nullptr) {
        i->registrarRepresentacion(p);
    }
}

//
//Ver Representados
//

set<DTRepresentado*> Sistema::SeleccionInmobiliaria(string nickname) {
    if (this->inmobiliarias.find(nickname) == this->inmobiliarias.end()) {
        throw invalid_argument("Error: No se encontro la inmobiliaria.");
    }

    Inmobiliaria* inmo = this->inmobiliarias[nickname];

    return inmo->ObtenerRepresentados();
}

//
//Administrar Propiedad
//

set<DTInmueble*> Sistema::SeleccionInmoParaAdministrar(string nickname) {
    if (this->inmobiliarias.find(nickname) == this->inmobiliarias.end()) {
        throw invalid_argument("Error: No existe una inmobiliaria con el nickname ingresado.");
    }

    this->inmobiliariaRecordada = this->inmobiliarias[nickname];

    return this->inmobiliariaRecordada->ObtenerInmueblesAAdministrar();
}

void Sistema::SeleccionInmueble(int codigo) {
    if (this->inmobiliariaRecordada == nullptr) {
        throw invalid_argument("Error de flujo: No se recordo ninguna inmobiliaria seleccionada.");
    }

    if (this->inmuebles.find(codigo) == this->inmuebles.end()) {
        throw invalid_argument("Error: El codigo de inmueble ingresado no existe en el sistema.");
    }

    Inmueble* inm = this->inmuebles[codigo];

    if (inm->estaAdministrado()) {
        throw invalid_argument("Error: Este inmueble ya se encuentra bajo administracion.");
    }

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    Date fechaActual;
    fechaActual.dia = now->tm_mday;
    fechaActual.mes = now->tm_mon + 1;
    fechaActual.anio = now->tm_year + 1900;

    Administracion* nuevaAdmin = new Administracion(fechaActual, inm);

    this->inmobiliariaRecordada->agregarAdministracion(nuevaAdmin);

    inm->setAdministrador(this->inmobiliariaRecordada);

    this->inmobiliariaRecordada = nullptr;
}


//
//Ver Estadisticas Administracion
//

set<DTInmueble*> Sistema::SeleccionInmobiliariaEstadisticas(string nickname) {
    if (this->inmobiliarias.find(nickname) == this->inmobiliarias.end()) {
        throw std::invalid_argument("Inmobiliaria no encontrada.");
    }

    Inmobiliaria* inmoElegida = this->inmobiliarias[nickname];
    set<DTInmueble*> res;

    // Recorremos los inmuebles del sistema para buscar los administrados por esta inmobiliaria
    for (auto const& pair : this->inmuebles) {
        Inmueble* inm = pair.second;

        // Asumiendo que Inmueble tiene getAdministrador() y getFechaAdministracion()
        if (inm->estaAdministrado() && inm->getAdministrador() == inmoElegida) {
            res.insert(new DTInmueble(inm->getId(), inm->getDireccion(), "", inm->getFechaAdministracion()));
        }
    }
    return res;
}
set<DTPublicacion*> Sistema::SeleccionInmuebleEstadisticas(int codigo) {
    if (this->inmuebles.find(codigo) == this->inmuebles.end()) {
        throw std::invalid_argument("Inmueble no encontrado.");
    }

    this->inmuebleRecordado = this->inmuebles[codigo];
    set<DTPublicacion*> res;

    for (auto const& pair : this->inmuebleRecordado->getPublicaciones()) {
        Publicacion* pub = pair.second;


        res.insert(new DTPublicacion(pub->getId(), pub->getFecha(), "Venta/Alquiler", pub->getContenido(), 0.0f, true));
    }
    return res;
}


set<DTAgenda*> Sistema::SeleccionPublicacion(int idPublicacion) {
    map<int, Publicacion*> pubs = this->inmuebleRecordado->getPublicaciones();

    if (pubs.find(idPublicacion) == pubs.end()) {
        throw std::invalid_argument("Publicacion no encontrada en este inmueble.");
    }
    this->publicacionRecordada = pubs[idPublicacion];
    set<DTAgenda*> res;

    for (Agenda* age : this->publicacionRecordada->getAgendas()) {
        res.insert(new DTAgenda(
    age->getFecha(),
    age->getFormaContacto(),
    age->getCliente()->getNombre(),
    age->getCliente()->getApellido()
));
    }
    return res;
}


//
//Alta Publicacion
//

set<DTInmueble*> Sistema::obtenerInmuebles() {
    set<DTInmueble*> res;
    for (auto const& par : this->inmuebles){
       // int cod = par.first;
        Inmueble* inmueble = par.second;

        res.insert(inmueble->getDTInmueble());
    }
    return res;
}

void Sistema::ingresarDatosPublicacion(int cod, DTPublicacion* publicacion) {
    Inmueble* i = this->inmuebles[cod];
    if (i != nullptr) {
        Publicacion* nuevaPub = i->crearPublicacion(publicacion);

        //int idRealPublicacion = nuevaPub->getId();
        this->colPublicaciones[nuevaPub->getId()] = nuevaPub;

        if (i->getAdministracion() != nullptr) {
            nuevaPub->setAdministracion(i->getAdministracion());
        }

    } else {
        cout << "Error: El inmueble con codigo " << cod << " no existe." << endl;
    }
}


//
//ConsultarPublicacion
//

set<DTListaPublicacion*> Sistema::obtenerPublicaciones(string tipo, DTRango* rango, DTInteres interes) {
    set<DTListaPublicacion*> res;
    cout << "Publicaciones en sistema: " << this->colPublicaciones.size() << endl;
    for (auto const& par : this->colPublicaciones) {
        Publicacion* p = par.second;

        if (p->cumpleFiltro(tipo, rango, interes)) {
            res.insert(p->getDTListaPublicacion());
        }
    }
    return res;
}

DTInmueble* Sistema::seleccionPublicacion(int codPublicacion) {
    if (this->colPublicaciones.find(codPublicacion) == this->colPublicaciones.end()) {
        return nullptr; // No la encontró
    }
    Publicacion* p = this->colPublicaciones[codPublicacion];

    if (p == nullptr) {
        return nullptr;
    }
    return p->seleccionPublicacion();
}

set<DTCliente*> Sistema::obtenerClientes() {
    set<DTCliente*> res;
    for (auto const& par : this->colClientes) {
        Cliente* c = par.second;
        res.insert(c->getDTCliente());
    }
    return res;
}

void Sistema::agendarVisita(int idCliente, Date fechaComunicacion, string formaContacto, int codPublicacion) {
    Cliente* c = this->colClientes[idCliente];

    Publicacion* p = this->colPublicaciones[codPublicacion];

    p->agendarVisita(c, fechaComunicacion, formaContacto);
}





void Sistema::cargarDatosPrueba() {

    Propietario* p1 = new Propietario("juanperez", "pass123", "Juan Perez", "juan@mail.com", 123456, "099111222");
    this->colUsuarios["juanperez"] = p1;
    this->propietarios["juanperez"] = p1;

    Propietario* p2 = new Propietario("mariagomez", "pass456", "Maria Gomez", "maria@mail.com", 0, "099333444");
    this->colUsuarios["mariagomez"] = p2;
    this->propietarios["mariagomez"] = p2;

    Inmobiliaria* inm1 = new Inmobiliaria("inmo_1", "pass_inmo1", "Propiedades Uruguay", "contacto@propiedades.com.uy", "Av. 18 de Julio 1234", "29001122", "www.propiedades.com.uy");
    this->colUsuarios["inmo_1"] = inm1;


    Inmobiliaria* inm2 = new Inmobiliaria("inmo_2", "pass_inmo2", "Alquileres MVD", "mvd@alquileres.com", "Bulevar Artigas 567", "24003344", "www.alquileresmvd.com");
    this->colUsuarios["inmo_2"] = inm2;
}
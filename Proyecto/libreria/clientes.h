#ifndef CLIENTES_H
#define CLIENTES_H

#include "encabezados.h"

enum estado {Deudor=-1, AlDia=1, Afavor=2};
typedef enum estado eEstado;
enum agregar {ExitoAg=1, ErrorAg=-1};
typedef enum agregar eAgregar;
enum modificar {ExitoMod=1, ErrMod=-1};
typedef enum modificar eModificar;


typedef struct
{
    int dia, mes, anio;
} Fecha;

struct Clientes
{
    str nombre, apellido, mail, telefono;
    Fecha fechaNac;
    int estado;
    u_int idCliente;
}; typedef struct Clientes sClientes;

typedef struct
{
    u_int idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    u_int cantInscriptos, idCliente;
    Inscripcion* CursosInscriptos;
} Asistencia;
const sClientes clienteNulo{"","","","",{0,0,0},0,0};
void resizeClientes(sClientes*& cliente, u_int &tam, u_int nuevoTam); //tamaño de clientes
int buscarCliente(sClientes* cliente, str mail, u_int cant); //buscar clientes por dni
eEstado Cuota(sClientes* cliente, str email, u_int &cant); //verificar el estado del cliente
u_int eliminarCliente(sClientes* cliente, str mail, u_int &cant); //eliminar cliente
eAgregar agregarCliente(sClientes*& cliente, sClientes nuevoCliente, u_int &cant, u_int &cantMaxima, u_int nuevoTam); //agregar cliente
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str mail, u_int cant); //modificar cliente
bool espacio(u_int cantMaxima, u_int &cant); //verificar el espacio disponible
int cantClientes(ifstream &archiClientes); //paso el archivo como parámetro y leo la cantidad de registros
#endif // CLIENTES_H

#ifndef CLIENTES_H
#define CLIENTES_H

#include "libreria.h"
#include "clientes.h"

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
    str nombre, apellido, dni, mail, telefono;
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

sClientes* resizeClientes(sClientes* lista, u_int tam, u_int nuevoTam); //tamaño de clientes
int buscarCliente(sClientes* cliente, str dni,int cant); //buscar clientes por dni
eEstado Cuota(sClientes* cliente, u_int dni, int cant); //verificar el estado del cliente
int eliminarCliente(sClientes* cliente, str dni,int cant); //eliminar cliente
eAgregar agregarCliente(sClientes* cliente,sClientes nuevoCliente, int cant, int cantMaxima); //agregar cliente
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str dni, int cant); //modificar cliente
bool espacio(int cantMaxima, int cant); //verificar el espacio disponible
int cantClientes(FILE* archiClientes, int n); //paso el archivo como parámetro y leo la cantidad de registros
#endif // CLIENTES_H

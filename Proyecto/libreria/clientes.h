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
    unsigned int idCliente;
}; typedef struct Clientes sClientes;

typedef struct
{
    int idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    unsigned int cantInscriptos, idCliente;
    Inscripcion* CursosInscriptos;
} Asistencia;

sClientes* resizeClientes(sClientes* lista, unsigned int tam, unsigned int nuevoTam); //tamaño de clientes
int buscarCliente(sClientes* cliente, str dni); //buscar clientes por dni
eEstado Cuota(sClientes* cliente, unsigned int id); //erificar el estado del cliente
int eliminarCliente(sClientes* cliente, str dni); //eliminar cliente
eAgregar agregarCliente(); //agregar cliente
eModificar modificarCliente();//modificar cliente

#endif // CLIENTES_H

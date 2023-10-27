#ifndef CLIENTES_H
#define CLIENTES_H

#include "libreria.h"
#include "clientes.h"

enum estado{Deudor=-1,AlDia=1, Afavor=2};
typedef enum estado Estado;

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

int buscarCliente(sClientes* clientes, str dni); //buscar clientes por dni
Estado Cuota(sClientes* clientes, unsigned int id); //verificar el estado del cliente
int eliminar(sClientes* cliente, Asistencia* asistencia, str dni); //eliminar cliente
//agregar cliente
//modificar cliente

#endif // CLIENTES_H

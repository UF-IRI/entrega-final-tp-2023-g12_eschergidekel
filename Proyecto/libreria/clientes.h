#ifndef CLIENTES_H
#define CLIENTES_H

#include "encabezados.h"
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

int buscarCliente(sClientes* clientes, unsigned int id);
Estado Cuota(sClientes* clientes, unsigned int id);
//eliminar cliente
//agregar cliente
//modificar cliente

#endif // CLIENTES_H

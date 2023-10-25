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

typedef struct
{
    str nombre, apellido, dni, mail, telefono;
    Fecha fechaNac;
    int estado;
    unsigned int idCliente;
} Clientes;

typedef struct
{
    int idCurso;
    time_t fechaInscripcion;
} Inscripcion;

typedef struct {
    unsigned int cantInscriptos, idCliente;
    Inscripcion* CursosInscriptos;
} Asistencia;

Estado Cuota();
//eliminar cliente
//agregar cliente
//modificar cliente

#endif // CLIENTES_H

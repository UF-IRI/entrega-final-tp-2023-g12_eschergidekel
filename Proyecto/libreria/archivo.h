#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "libreria.h"
#include "clientes.h"
#include "clases.h"

FILE archiClientes, archiClases, archiAsistencia;

typedef enum CodArchivos {ErrorLectura=-3, ErrorApertura=-2, ErrorEscritura=-1, ExitoOperacion=1} eCodArchivos;

eCodArchivos leerArchivoClientes(std::fstream* archiClientes);
eCodArchivos escribirArchivoClientes(std::fstream archiClientes,str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente);
eCodArchivos leerArchivoClases(std::fstream* archiClase);
eCodArchivos escribirArchivoClases(std::fstream archiClases, u_int idClase, str nombre, u_int horario);
eCodArchivos leerArchivoAsistencia(std::fstream* archiAsistencia, Asistencia* asistencia);
eCodArchivos informeAsistencia(std::fstream informe, Asistencia *asistencia, Inscripcion* inscripcion);

#endif // ARCHIVO_H

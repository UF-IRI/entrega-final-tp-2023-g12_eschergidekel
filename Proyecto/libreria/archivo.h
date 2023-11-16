#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "libreria.h"
#include "clientes.h"
#include "clases.h"

std::fstream archiClientes, archiClases, archiAsistencia, informe;

typedef enum CodArchivos {ErrorLectura=-3, ErrorApertura=-2, ErrorEscritura=-1, ExitoOperacion=1} eCodArchivos;

eCodArchivos leerArchivoClientes(fstream archiClientes);
eCodArchivos escribirArchivoClientes(fstream archiClientes, str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente);
eCodArchivos leerArchivoClases(fstream* archiClase);
eCodArchivos escribirArchivoClases(fstream archiClases, u_int idClase, str nombre, u_int horario);
eCodArchivos leerArchivoAsistencia(fstream *archiAsistencia, Asistencia* asistencia);
eCodArchivos informeAsistencia(fstream informe, Asistencia *asistencia, Inscripcion* inscripcion);

#endif // ARCHIVO_H

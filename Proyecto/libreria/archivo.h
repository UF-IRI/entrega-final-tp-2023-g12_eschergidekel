#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include "clientes.h"
#include "clases.h"
FILE archiClientes, archiClases, archiAsistencia;

typedef enum CodArchivos {ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1} eCodArchivos;
eCodArchivos leerArchivoClientes(std::fstream* archiClientes, Clientes* cliente);
eCodArchivos escribirArchivoClientes(std::fstream* archiClientes, Clientes* cliente);
eCodArchivos leerArchivoClases(std::fstream* archiClase, Clases* clase);
eCodArchivos escribirArchivoClases(std::fstream* archiClases, Clases* clase);
eCodArchivos leerArchivoAsistencia(std::fstream* archiAsistencia, Asistencia* asistencia);
eCodArchivos escribirArchivoAsistencia(std::fstream* archiAsistencia, Asistencia* asistencia);

#endif // ARCHIVO_H

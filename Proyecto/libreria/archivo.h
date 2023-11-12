#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "libreria.h"
#include "clientes.h"
#include "clases.h"

std::fstream archiClientes, archiClases, archiAsistencia;

typedef enum CodArchivos {ErrorLectura=-3, ErrorApertura=-2, ErrorEscritura=-1, ExitoOperacion=1} eCodArchivos;

eCodArchivos leerArchivoClientes(std::ifstream* archiClientes);
eCodArchivos escribirArchivoClientes(std::ofstream archiClientes,str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente);
eCodArchivos leerArchivoClases(std::ifstream* archiClase);
eCodArchivos escribirArchivoClases(std::ofstream archiClases, u_int idClase, str nombre, u_int horario);
eCodArchivos leerArchivoAsistencia(ifstream *archiAsistencia, Asistencia* asistencia);
eCodArchivos informeAsistencia(std::ofstream informe, Asistencia *asistencia, Inscripcion* inscripcion);

#endif // ARCHIVO_H

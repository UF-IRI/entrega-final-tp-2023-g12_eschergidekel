#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "clases.h"



typedef enum CodArchivos {ErrorLectura=-3, ErrorApertura=-2, ErrorEscritura=-1, ExitoOperacion=1} eCodArchivos;

void leerArchivoClientes(ifstream& archiClientes, sClientes* cliente, u_int &cant);
eCodArchivos escribirArchivoClientes(ofstream& archiClientes, str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente);
void leerArchivoClases(ifstream& archiClases, Clases* clase);
eCodArchivos escribirArchivoClases(ofstream& archiClases, u_int idClase, str nombre, u_int horario);
void leerArchivoAsistencia(ifstream& archiAsistencia, Asistencia*& asistencia, u_int &cantAsistencia, int &longitud);
eCodArchivos informeAsistencia(ofstream &informe, Asistencia *asistencia);

#endif // ARCHIVO_H

#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include "clientes.h"
#include "clases.h"

typedef enum CodArchivos {ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1} eCodArchivos;
eCodArchivos leerArchivo(std::fstream *archivo, Clientes *cliente);
eCodArchivos escribirArchivo(std::fstream *archivo, Clientes *cliente);
eCodArchivos leerArchivoClientes(std::fstream	*archivo, Clases *clase);

#endif // ARCHIVO_H

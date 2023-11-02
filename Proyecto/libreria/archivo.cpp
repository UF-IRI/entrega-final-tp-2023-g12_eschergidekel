#include "archivo.h"
#include "clientes.h"
#include "clases.h"

eCodArchivos leerArchivoClientes(std::fstream* archiClientes, Clientes *cliente)
{
    if(!archiClientes->is_open()) //si el archivo se pudo abrir
        return eCodArchivos::ErrorApertura;

    archiClientes->read((char*)cliente, sizeof(Clientes)); //leer los clientes
    if(!*archiClientes)
        return eCodArchivos::ErrorApertura;

    return eCodArchivos::ExitoOperacion; //archivo csv
}
eCodArchivos escribirArchivoClientes(std::fstream* archiClientes, Clientes *cliente)
{
    if(!archiClientes->is_open())
        return eCodArchivos::ErrorApertura;
    archiClientes->write((char*)cliente, sizeof(Clientes));

    return eCodArchivos::ExitoOperacion;
}
eCodArchivos leerArchivoClases(std::fstream* archiClases, Clases *clase)
{
    if(!archiClases->is_open()) //si el archivo se pudo abrir
        return eCodArchivos::ErrorApertura;

    archiClases->read((char*)clase, sizeof(Clases)); //leer las clases
    if(!*archiClases){
        return eCodArchivos::ErrorEscritura;
    }
    return eCodArchivos::ExitoOperacion; //archivo csv
}
eCodArchivos escribirArchivoClases(std::fstream* archiClases, Clases* clase)
{
    if(!archiClases->is_open())
        return eCodArchivos::ErrorApertura;
    archiClases->write((char*)clase, sizeof(Clases));

    return eCodArchivos::ExitoOperacion;
}
eCodArchivos leerArchivoAsistencia(std::fstream* archiAsistencia, Asistencia* asistencia)
{
    if(!archiAsistencia->is_open()) //si el archivo se pudo abrir
        return eCodArchivos::ErrorApertura;

    archiAsistencia->read((char*)asistencia, sizeof(Asistencia)); //leer las asistencias
    if(!*archiAsistencia){
        return eCodArchivos::ErrorEscritura;
    }
    return eCodArchivos::ExitoOperacion; //archivo binario
}
eCodArchivos escribirArchivoAsistencia(std::fstream* archiAsistencia, Asistencia* asistencia)
{
    if(!archiAsistencia->is_open())
        return eCodArchivos::ErrorApertura;
    archiAsistencia->write((char*)asistencia, sizeof(Asistencia));

    return eCodArchivos::ExitoOperacion;
}

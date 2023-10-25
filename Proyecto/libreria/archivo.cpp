#include "archivo.h"
#include "clientes.h"
#include "clases.h"

eCodArchivos leerArchivoClientes(std::fstream	*archivo, Clientes *cliente){
    if(!archivo->is_open()) //si el archivo se pudo abrir
        return eCodArchivos::ErrorApertura;

    archivo->read((char*)cliente, sizeof(Clientes)); //leer los contactos
    if(!*archivo){
        return eCodArchivos::ErrorEscritura;
    }
    return eCodArchivos::ExitoOperacion; //archivo binario
}
eCodArchivos escribirArchivoClientes(std::fstream	*archivo, Clientes *cliente)
{
    if(!archivo->is_open())
        return eCodArchivos::ErrorApertura;
    archivo->write((char*)cliente, sizeof(Clientes));

    return eCodArchivos::ExitoOperacion;
}
eCodArchivos leerArchivoClientes(std::fstream	*archivo, Clases *clase)
{
    if(!archivo->is_open()) //si el archivo se pudo abrir
        return eCodArchivos::ErrorApertura;

    archivo->read((char*)clase, sizeof(Clases)); //leer los contactos
    if(!*archivo){
        return eCodArchivos::ErrorEscritura;
    }
    return eCodArchivos::ExitoOperacion; //archivo binario
}

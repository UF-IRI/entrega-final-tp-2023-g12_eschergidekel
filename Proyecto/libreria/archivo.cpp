#include <libreria.h>
#include "archivo.h"
#include "clientes.h"
#include "clases.h"

eCodArchivos leerArchivoClientes(std::ifstream archiClientes) //archivo CSV
{
    //Abrir el archivo CSV para lectura
    if(archiClientes.is_open())
    {
        while(archiClientes.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(archiClientes, linea);

            char delimitador = ',';
            str file;
            istringstream iss(linea);
            while(getline(iss, file, delimitador))
                cout << file << " ";
            cout << endl;
        }
        archiClientes.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClientes(std::ofstream archiClientes, str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente)
{
    if(archiClientes.is_open())
    {
        // Escribir los datos en el archivo CSV
        archiClientes << "idCliente, nombre, apellido, email, telefono, fecha de nacimiento, estado" << endl;
        archiClientes << idCliente << "," << nombre << "," << apellido << "," << email << "," << telefono << "," <<
                fechaNac.dia << "/ " << fechaNac.mes << "/ " << fechaNac.anio << "," << estado << "," << endl;

        // Cerrar el archivo
        archiClientes.close();

        return eCodArchivos::ExitoOperacion;
    } else
        return eCodArchivos::ErrorEscritura;
}
eCodArchivos leerArchivoClases(ifstream &archiClases) //archivo CSV
{
    //Abrir el archivo CSV para lectura
    if(archiClases.is_open())
    {
        while(archiClases.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(archiClases, linea);

            char delimitador = ',';
            str file;
            istringstream iss(linea);
            while(getline(iss, file, delimitador))
                cout << file << " ";
            cout << endl;
        }
        archiClases.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClases(std::ofstream archiClases, u_int idClase, str nombre, u_int horario)
{
    if(archiClases.is_open())
    {
        // Escribir los datos en el archivo CSV
        archiClases << "idClase, nombre, horario" << endl;
        archiClases << idClase << "," << nombre << "," << horario << endl;

        // Cerrar el archivo
        archiClases.close();

        return eCodArchivos::ExitoOperacion;
    } else
        return eCodArchivos::ErrorEscritura;
}
eCodArchivos leerArchivoAsistencia(std::ifstream* archiAsistencia, Asistencia* asistencia) //archivo binario
{
    if(!archiAsistencia->is_open()) //si el archivo no se pudo abrir
        return eCodArchivos::ErrorApertura;

    archiAsistencia->read((char*)asistencia, sizeof(Asistencia)); //leer las asistencias
    if(!*archiAsistencia)
        return eCodArchivos::ErrorEscritura;

    return eCodArchivos::ExitoOperacion; //archivo binario
}
eCodArchivos informeAsistencia(std::ofstream informe, Asistencia *asistencia, Inscripcion* inscripcion)
{
    if(informe.is_open())
    {
        informe << "Asistencias del dia:" << endl;
        for(u_int i=0; i<asistencia->cantInscriptos; i++)
        {
            for(u_int j=0; j<asistencia[i].cantInscriptos; j++)
            {
                informe << "ID cliente: " << asistencia[i].idCliente << endl;
                informe << "Cantidad de inscriptos: " << asistencia[i].cantInscriptos << endl;
                informe << "ID clase: " << inscripcion[j].idCurso << endl;
            }
        }
        informe.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}

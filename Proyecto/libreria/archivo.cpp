#include <libreria.h>
#include "archivo.h"
#include "clientes.h"
#include "clases.h"

eCodArchivos leerArchivoClientes(std::ifstream lecturaClientes) //archivo CSV
{
    //Abrir el archivo CSV para lectura
    if(lecturaClientes.is_open())
    {
        while(lecturaClientes.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(lecturaClientes, linea);

            char delimitador = ',';
            str file;
            istringstream iss(linea);
            while(getline(iss, file, delimitador))
                cout << file << " ";
            cout << endl;
        }
        lecturaClientes.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClientes(std::ofstream escrituraClientes, str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente)
{
    if(escrituraClientes.is_open())
    {
        // Escribir los datos en el archivo CSV
        escrituraClientes << "idCliente, nombre, apellido, email, telefono, fecha de nacimiento, estado" << endl;
        escrituraClientes << idCliente << "," << nombre << "," << apellido << "," << email << "," << telefono << "," <<
                fechaNac.dia << "/ " << fechaNac.mes << "/ " << fechaNac.anio << "," << estado << "," << endl;

        // Cerrar el archivo
        escrituraClientes.close();

        return eCodArchivos::ExitoOperacion;
    } else
        return eCodArchivos::ErrorEscritura;
}
eCodArchivos leerArchivoClases(std::ifstream lecturaClases) //archivo CSV
{
    //Abrir el archivo CSV para lectura
    if(lecturaClases.is_open())
    {
        while(lecturaClases.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(lecturaClases, linea);

            char delimitador = ',';
            str file;
            istringstream iss(linea);
            while(getline(iss, file, delimitador))
                cout << file << " ";
            cout << endl;
        }
        lecturaClases.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClases(std::ofstream escrituraClases, u_int idClase, str nombre, u_int horario)
{
    if(escrituraClases.is_open())
    {
        // Escribir los datos en el archivo CSV
        escrituraClases << "idClase, nombre, horario" << endl;
        escrituraClases << idClase << "," << nombre << "," << horario << endl;

        // Cerrar el archivo
        escrituraClases.close();

        return eCodArchivos::ExitoOperacion;
    } else
        return eCodArchivos::ErrorEscritura;
}
eCodArchivos leerArchivoAsistencia(std::ifstream* lecturaAsistencia, Asistencia* asistencia) //archivo binario
{
    if(!lecturaAsistencia->is_open()) //si el archivo no se pudo abrir
        return eCodArchivos::ErrorApertura;

    lecturaAsistencia->read((char*)asistencia, sizeof(Asistencia)); //leer las asistencias
    if(!*lecturaAsistencia)
        return eCodArchivos::ErrorEscritura;

    return eCodArchivos::ExitoOperacion; //archivo binario
}
eCodArchivos informeAsistencia(std::ofstream escrituraInforme, Asistencia *asistencia, Inscripcion* inscripcion)
{
    if(escrituraInforme.is_open())
    {
        escrituraInforme << "Asistencias del dia:" << endl;
        for(u_int i=0; i<asistencia->cantInscriptos; i++)
        {
            for(u_int j=0; j<asistencia[i].cantInscriptos; j++)
            {
                escrituraInforme << "ID cliente: " << asistencia[i].idCliente << endl;
                escrituraInforme << "Cantidad de inscriptos: " << asistencia[i].cantInscriptos << endl;
                escrituraInforme << "ID clase: " << inscripcion[j].idCurso << endl;
            }
        }
        escrituraInforme.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}

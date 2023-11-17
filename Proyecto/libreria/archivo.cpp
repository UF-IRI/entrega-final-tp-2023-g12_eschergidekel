#include <libreria.h>
#include "archivo.h"
#include "clientes.h"
#include "clases.h"

eCodArchivos leerArchivoClientes(fstream &archiClientes, sClientes* cliente) //archivo CSV
{
    sClientes* aux= new sClientes;
    string auxNombre;
    string auxApellido;
    string auxDNI;
    string auxtelefono;
    string auxMail;
    string auxestado;
    string auxid;
    string auxfecha;
    int i=1;


    //Abrir el archivo CSV para lectura
    if(archiClientes.is_open())
    {
        while(archiClientes.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(archiClientes, linea);

            char delimitador = ',';
            char delimitador2='-';
            istringstream iss(linea);
            getline(iss,auxid,delimitador);
            aux[i].idCliente=stoi(auxid);
            getline(iss,auxNombre,delimitador);
            aux[i].nombre=auxNombre;
            getline(iss,auxApellido,delimitador);
            aux[i].apellido=auxApellido;
            getline(iss,auxMail,delimitador);
            aux[i].mail=auxMail;
            getline(iss,auxtelefono,delimitador);
            aux[i].telefono=auxtelefono;
            getline(iss,auxfecha,delimitador);
            istringstream ff(auxfecha);
            getline(ff,auxfecha,delimitador2);
            aux[i].fechaNac.dia=stoi(auxfecha);
            getline(ff,auxfecha,delimitador2);
            aux[i].fechaNac.mes=stoi(auxfecha);
            getline(ff,auxfecha,delimitador2);
            aux[i].fechaNac.dia=stoi(auxfecha);
            getline(iss,auxestado,delimitador);
            aux[i].estado=stoi(auxestado);
            i++;

        }
        archiClientes.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClientes(fstream archiClientes, str nombre, str apellido, str email, str telefono,
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
eCodArchivos leerArchivoClases(fstream &archiClases, Clases* clase) //archivo CSV
{
    Clases*aux= new Clases;
    string auxidClase;
    string auxNombre;
    string auxHorario;
    int i=1;
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
            getline(iss,auxidClase,delimitador);
            aux[i].idClase=stoi(auxidClase);
            getline(iss,auxNombre,delimitador);
            aux[i].nombreClase=auxNombre;
            getline(iss,auxHorario,delimitador);
            aux[i].horarioClase=stoi(auxHorario);
            i++;
        }
        archiClases.close();
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClases(fstream archiClases, u_int idClase, str nombre, u_int horario)
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
eCodArchivos leerArchivoAsistencia(ifstream &archiAsistencia, Asistencia* asistencia) //archivo binario
{
        if (!archiAsistencia.is_open())
        return eCodArchivos::ErrorApertura;
        // Setear inicio
        archiAsistencia.clear();
        archiAsistencia.seekg(0);

        Asistencia *aux = new Asistencia;

        while (!archiAsistencia.eof()) {
            archiAsistencia.read((char *)&aux->idCliente, sizeof(u_int));
            archiAsistencia.read((char *)&aux->cantInscriptos, sizeof(u_int));

            Inscripcion *registro = new Inscripcion[aux->cantInscriptos];
            Inscripcion *auxInscriptions = registro;
            for (u_int i = 0; i < aux->cantInscriptos; i++) {
                archiAsistencia.read((char *)auxInscriptions, sizeof(Inscripcion));
                auxInscriptions++;
            }
            aux->CursosInscriptos = registro;

            aux++;
        }



    return eCodArchivos::ExitoOperacion; //archivo binario
}
eCodArchivos informeAsistencia(fstream informe, Asistencia *asistencia, Inscripcion* inscripcion)
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

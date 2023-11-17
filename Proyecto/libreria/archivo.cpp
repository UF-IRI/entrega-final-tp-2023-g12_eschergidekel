#include <libreria.h>
#include "archivo.h"
#include "clientes.h"
#include "clases.h"

eCodArchivos leerArchivoClientes(ifstream &archiClientes, sClientes* cliente) //archivo CSV
{
    sClientes* aux = new sClientes; //tamaño
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
    archiClientes.open();
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
        cliente=aux;
        delete aux;
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClientes(ofstream &archiClientes, str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente)
{
    archiClientes.open();
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
eCodArchivos leerArchivoClases(ifstream &archiClases, Clases* clase) //archivo CSV
{
    Clases*aux = new Clases[60];
    string auxidClase;
    string auxNombre;
    string auxHorario;
    int i=1;

    //Abrir el archivo CSV para lectura
    archiClases.open();
    if(archiClases.is_open())
    {
        while(archiClases.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(archiClases, linea);

            char delimitador = ',';
            str file;// sacar
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
        clase=aux;
        delete aux;
        return eCodArchivos::ExitoOperacion;
    }
    else
        return eCodArchivos::ErrorApertura;
}
eCodArchivos escribirArchivoClases(ofstream &archiClases, u_int idClase, str nombre, u_int horario)
{
    archiClases.open(); //abrir el archivo para escribir
    if(archiClases.is_open())
    {
        //Escribir los datos en el archivo CSV
        archiClases << "idClase, nombre, horario" << endl;
        archiClases << idClase << "," << nombre << "," << horario << endl;

        //Cerrar el archivo
        archiClases.close();

        return eCodArchivos::ExitoOperacion;
    } else
        return eCodArchivos::ErrorEscritura;
}
eCodArchivos leerArchivoAsistencia(ifstream &archiAsistencia, Asistencia* asistencia) //archivo binario
{
    archiAsistencia.open();
    if(!archiAsistencia.is_open())
        return eCodArchivos::ErrorApertura;
    // Setear inicio
    archiAsistencia.clear();
    archiAsistencia.seekg(0);

    Asistencia* aux = new Asistencia;
    while (!archiAsistencia.eof())
    {
        archiAsistencia.read((char *)&aux->idCliente, sizeof(u_int));
        archiAsistencia.read((char *)&aux->cantInscriptos, sizeof(u_int));
        Inscripcion *registro = new Inscripcion[aux->cantInscriptos];
        Inscripcion *auxInscriptions = registro;
        for (u_int i = 0; i < aux->cantInscriptos; i++)
        {
            archiAsistencia.read((char *)&auxInscriptions, sizeof(Inscripcion));
            auxInscriptions++;
        }
        aux->CursosInscriptos = registro;

        aux++;
    }
    archiAsistencia.close();
    asistencia=aux;
    delete aux;
    return eCodArchivos::ExitoOperacion; //archivo binario
}
eCodArchivos informeAsistencia(ofstream &informe, Asistencia *asistencia, Inscripcion* inscripcion)
{
    informe.open();
    if(!archiAsistencia.is_open())
        return eCodArchivos::ErrorApertura;
    // Setear inicio
    informe.clear();
    informe.seekp(0);

    while (!informe.eof())
    {
        for (u_int i=0; i<asistencia->cantInscriptos; i++)
        {
            informe.write((char*)&asistencia[i].idCliente, sizeof(u_int));
            informe.write((char*)&asistencia[i].cantInscriptos, sizeof(u_int));
            for(u_int j = 0; j < asistencia[i].cantInscriptos; j++)
            {
                informe.write((char*)&asistencia[i].CursosInscriptos[j], sizeof(Inscripcion));
            }
        }
    }
    informe.close();
    return eCodArchivos::ExitoOperacion;
}

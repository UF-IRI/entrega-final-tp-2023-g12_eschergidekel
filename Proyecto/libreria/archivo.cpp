#include "archivo.h"

void leerArchivoClientes(ifstream &archiClientes, sClientes* cliente, u_int &cant) //archivo CSV
{
    sClientes* aux = new sClientes[cant]; //tamaño
    string auxNombre;
    string auxApellido;
    string auxtelefono;
    string auxMail;
    string auxestado;
    string auxid;
    string auxfecha;
    int i=1;

    //Abrir el archivo CSV para lectura
    archiClientes.open("iriClientesGYM.csv");
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
        for(u_int i=0; i<cant; i++)
            cliente[i]=aux[i];
        delete[] aux;
    }
}
eCodArchivos escribirArchivoClientes(ofstream &archivoClientes, str nombre, str apellido, str email, str telefono,
                                     Fecha fechaNac, int estado, u_int idCliente)
{
    archivoClientes.open("iriClientesGYM.csv");
    if(archivoClientes.is_open())
    {
        // Escribir los datos en el archivo CSV
        archivoClientes << "idCliente, nombre, apellido, email, telefono, fecha de nacimiento, estado" << endl;
        archivoClientes << idCliente << "," << nombre << "," << apellido << "," << email << "," << telefono << "," <<
                fechaNac.dia << "/ " << fechaNac.mes << "/ " << fechaNac.anio << "," << estado << "," << endl;

        // Cerrar el archivo
        archivoClientes.close();

        return eCodArchivos::ExitoOperacion;
    }
    return eCodArchivos::ErrorEscritura;
}
void leerArchivoClases(ifstream &archiClases, Clases* clase) //archivo CSV
{
    //Abrir el archivo CSV para lectura
    archiClases.open("iriClasesGYM.csv");
    if(archiClases.is_open())
    {
        string linea;
        Clases*aux = new Clases[33];
        string auxidClase;
        string auxNombre;
        string auxHorario;
        int i=1;
        while(getline(archiClases, linea)) //Leer los datos desde el archivo CSV
        {
            str linea;


            char delimitador = ',';
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
        for(int j=0; j<33; j++)
            clase[j]=aux[j];
        delete[] aux;
    }
}
eCodArchivos escribirArchivoClases(ofstream &archivoClases, u_int idClase, str nombre, u_int horario)
{
    archivoClases.open("iriClasesGYM.csv"); //abrir el archivo para escribir
    if(archivoClases.is_open())
    {
        //Escribir los datos en el archivo CSV
        archivoClases << "idClase, nombre, horario" << endl;
        archivoClases << idClase << "," << nombre << "," << horario << endl;

        //Cerrar el archivo
        archivoClases.close();

        return eCodArchivos::ExitoOperacion;
    }
    return eCodArchivos::ErrorEscritura;
}
void leerArchivoAsistencia(ifstream &archiAsistencia, Asistencia*& asistencia, u_int &cantAsistencia, int &longitud) //archivo binario
{
    archiAsistencia.open("Asistencia.dat");
    // Setear inicio
    archiAsistencia.clear();
    archiAsistencia.seekg(0);
    int i=0;
    Asistencia* aux = new Asistencia[250];
    while (!archiAsistencia.eof())
    {
        archiAsistencia.read((char *)&aux[i].idCliente, sizeof(u_int));
        archiAsistencia.read((char *)&aux[i].cantInscriptos, sizeof(u_int));
        Inscripcion *registro = new Inscripcion[aux[i].cantInscriptos];
        Inscripcion *auxInscriptions = registro;
        for (u_int i = 0; i < aux[i].cantInscriptos; i++)
        {
            archiAsistencia.read((char *)&auxInscriptions, sizeof(Inscripcion));
            auxInscriptions++;
            cantAsistencia++;
        }
        aux[i].CursosInscriptos = registro;

        aux++;
        longitud++;
    }
    archiAsistencia.close();
    delete[] asistencia;
    asistencia=aux; //archivo binario
}
eCodArchivos informeAsistencia(ofstream &informe, Asistencia *asistencia)
{
    informe.open("informe.dat", ios::binary);
    if(!informe.is_open())
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

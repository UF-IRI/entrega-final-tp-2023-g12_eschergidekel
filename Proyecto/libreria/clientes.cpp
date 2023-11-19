#include "clientes.h"
#include "archivo.h"
#include "clases.h"

bool espacio(int cantMaxima, int cant)
{
    return ((cantMaxima-cant)>0);
}
sClientes* resizeClientes(sClientes* cliente, u_int tam, u_int nuevoTam)
{
    sClientes* aux = new sClientes[nuevoTam];
    u_int longitud = (tam < nuevoTam) ? tam : nuevoTam;

    if(aux!=nullptr)
    {
        for(u_int i=0; i<longitud; i++)
            aux[i] = cliente[i]; //*(cliente+1)

        delete[] cliente;
        return aux;
    }

    return nullptr;
}
int buscarCliente(ifstream &archiClientes, sClientes* cliente, str dni, int cant)
{
    eCodArchivos resul = leerArchivoClientes(archiClientes, cliente, cant);
    if(resul != eCodArchivos::ErrorApertura)
    {
        u_int pos;
        int i;
        for(i=0; i<cant; i++)
        {
            if(cliente[i].dni==dni)
                pos=i;
        }
        if(i==cant)
            return -1;
        else
            return pos;
    }else
        return -1;
}
eEstado Cuota(ifstream &archiClientes, sClientes* cliente, str dni, int cant)
{
    u_int pos = buscarCliente(archiClientes, cliente, dni, cant);

    if(cliente[pos].estado == 0)
        return eEstado::AlDia;
    else
        if(cliente[pos].estado > 0)
            return eEstado::Afavor;
        else
            return eEstado::Deudor;
}
int eliminarCliente(ifstream &archiClientes, sClientes* cliente, str dni, int cant)
{
    ofstream archiTemporal("ClientesEditados.csv");
    archiTemporal.open("ClientesEdiatados.csv");
    int pos=buscarCliente(archiClientes, cliente, dni, cant); //cambiar tamaño
    eCodArchivos resul = leerArchivoClientes(archiClientes, cliente, cant);
    if(resul != eCodArchivos::ErrorApertura && archiTemporal.is_open())
    {
        while(archiTemporal.good()) //Copiar las líneas excepto la línea a borrar al archivo temporal
        {
            for(int i=0; i<cant; i++)
            {
                if(cliente[pos].idCliente != cliente[i].idCliente)
                {
                    str linea;
                    getline(archiClases, linea);

                    char delimitador = ',';
                    istringstream iss(linea);
                    string token;
                    getline(iss, token, delimitador);
                }
            }
        }
        archiClientes.close();
        archiTemporal.close();
        if(rename("ClientesEditados.csv", "iriClientesGYM") == 0)
            return cant-1;
        else
            return -1;
    }else
        return -1;
}
int cantClientes(ifstream &archiClientes)
{
    int cont=0;
    archiClientes.open("iriClientesGYM.csv");
    if(archiClientes.is_open())
    {
        str linea;
        while(getline(archiClientes, linea)) //Leer los datos desde el archivo CSV
            cont++;
        archiClientes.close();
        return cont;
    }else
        return -1;
}
eAgregar agregarCliente(ifstream &archiClientes, ofstream &archivoClientes, sClientes* cliente, sClientes nuevoCliente,
                        int cant, int cantMaxima)
{
    int pos = buscarCliente(archiClientes, cliente, nuevoCliente.dni, cant);
    int nuevoTam = cant+30;
    archivoClientes.open("iriClientesGYM.csv");
    if(archivoClientes.is_open())
    {
        if(!espacio(cantMaxima, cant))
        {
            cliente = resizeClientes(cliente, cant, nuevoTam);
            cantMaxima = nuevoTam;
        }
        if(pos == -1) //me aseguro que el cliente ya no este inscripto
        {
            cliente[cant+1] = nuevoCliente;
            eCodArchivos resul = escribirArchivoClientes(archivoClientes, nuevoCliente.nombre, nuevoCliente.apellido,
                                                         nuevoCliente.mail,nuevoCliente.telefono, nuevoCliente.fechaNac.dia,
                                                         nuevoCliente.fechaNac.mes, nuevoCliente.fechaNac.anio,
                                                         nuevoCliente.estado, nuevoCliente.idCliente);
            archivoClientes.close();
            if(resul != eCodArchivos::ErrorEscritura)
                return eAgregar::ExitoAg;
            else
                return eAgregar::ErrorAg;
        }
        else
            return eAgregar::ErrorAg;
    }else
        return eAgregar::ErrorAg;
}
eModificar modificarCliente(ifstream &archiClientes, sClientes* cliente, sClientes clienteModificado, str dni, int cant)
{
    ofstream archiTemporal("ClientesEditados.csv");
    archiTemporal.open("ClientesEditados.csv");
    int pos=buscarCliente(archiClientes, cliente, dni, cant);
    eCodArchivos resul = leerArchivoClientes(archiClientes, cliente, cant);

    string auxNombre;
    string auxApellido;
    string auxDNI;
    string auxtelefono;
    string auxMail;
    string auxestado;
    string auxid;
    string auxfecha;

    if(resul != eCodArchivos::ErrorApertura && archiTemporal.is_open())
    {
        while(archiTemporal.good()) //Copiar las líneas excepto la línea a borrar al archivo temporal
        {
            if(cliente[pos].idCliente == clienteModificado.idCliente)
            {
                str linea;
                getline(archiClientes, linea);

                char delimitador = ',';
                char delimitador2='-';
                istringstream iss(linea);

                getline(iss,auxid,delimitador);
                cliente[pos].idCliente=clienteModificado.idCliente;

                getline(iss,auxNombre,delimitador);
                cliente[pos].nombre=clienteModificado.nombre;

                getline(iss,auxApellido,delimitador);
                cliente[pos].apellido=clienteModificado.apellido;

                getline(iss,auxMail,delimitador);
                cliente[pos].mail=clienteModificado.mail;

                getline(iss,auxtelefono,delimitador);
                cliente[pos].telefono=clienteModificado.telefono;

                getline(iss,auxfecha,delimitador);
                istringstream ff(auxfecha);
                getline(ff,auxfecha,delimitador2);
                cliente[pos].fechaNac.dia=clienteModificado.fechaNac.dia;
                getline(ff,auxfecha,delimitador2);
                cliente[pos].fechaNac.mes=clienteModificado.fechaNac.mes;
                getline(ff,auxfecha,delimitador2);
                cliente[pos].fechaNac.anio=clienteModificado.fechaNac.anio;

                getline(iss,auxestado,delimitador);
                cliente[pos].estado=clienteModificado.estado;
            }
        }
        archiClientes.close();
        archiTemporal.close();
        if(rename("ClientesEditados.csv", "iriClientesGYM") == 0)
            return eModificar::ExitoMod;
        else
            return eModificar::ErrMod;
    }else
        return eModificar::ErrMod;
}

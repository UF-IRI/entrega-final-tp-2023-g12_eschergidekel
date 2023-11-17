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
int buscarCliente(sClientes* cliente, str dni, int cant)
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
}
eEstado Cuota(sClientes* cliente, str dni, int cant)
{
    u_int pos = buscarCliente(cliente, dni, cant);

    if(cliente[pos].estado == 0)
        return eEstado::AlDia;
    else
        if(cliente[pos].estado > 0)
            return eEstado::Afavor;
        else
            return eEstado::Deudor;
}
int eliminarCliente(ifstream &archiClientes, ofstream &archivoClientes, sClientes* cliente, str dni, int cant)
{
    int pos=buscarCliente(cliente,dni, cant); //cambiar tamaño
    eCodArchivos resul = leerArchivoClientes(archiClientes, cliente);
    str linea;
    if(resul != eCodArchivos::ErrorApertura)
    {
        while(getline(archivoEntrada, linea)) //Copiar las líneas excepto la línea a borrar al archivo temporal
        {
            for(int i=0; i<cant, i++)
                if(cliente[pos] != cliente[i])
                    archivoClientes << linea << endl;
        }
        return cant-1;
    }else
        return -1;
}
int cantClientes(fstream &archiClientes)
{
    int n=0;
    archiClientes.open();
    if(archiClientes.is_open())
    {
        while(archiClientes.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(archiClientes, linea);//subir esto al while
            n++;
        }
        archiClientes.close();
    }
    return n;
}
eAgregar agregarCliente(sClientes* cliente, sClientes nuevoCliente, int cant, int cantMaxima)
{
    int pos=buscarCliente(cliente, nuevoCliente.dni, cant);
    int nuevoTam = cant+30;
    if(!espacio(cantMaxima, cant))
    {
        cliente = resizeClientes(cliente, cant, nuevoTam);
        cantMaxima = nuevoTam;
    }
    if(pos == -1) //me aseguro que el cliente ya no este inscripto
    {
        cliente[cant+1] = nuevoCliente;
        return eAgregar::ExitoAg;
    }
    else
        return eAgregar::ErrorAg;
}
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str dni, int cant)
{
    int pos;
    pos=buscarCliente(cliente, dni, cant);

    if(pos != -1)
    {
        cliente[pos]= clienteModificado;
        return eModificar::ExitoMod;
    }
    else
        return eModificar::ErrMod;
}
int cantClientes(ifstream archiClientes)
{
    int cont = 0;
    str linea;

    //Iterar sobre cada línea del archivo
    while (std::getline(archiClientes, linea))
        cont++;

    return cont;
}

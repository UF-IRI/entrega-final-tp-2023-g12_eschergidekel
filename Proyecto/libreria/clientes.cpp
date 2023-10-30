#include "clientes.h"
#include "archivo.h"
#include <libreria.h>
#define N 250

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
int buscarCliente(sClientes* clientes, str dni)
{
    u_int pos;
    for(u_int i=0; i<N ;i++)
    {
        if(clientes[i].dni==dni)
            pos=i;
    }
    return pos;
}
eEstado Cuota(sClientes* clientes, str dni)
{
    u_int pos = buscarCliente(clientes, dni);

    if(clientes[pos].estado == 0)
        return eEstado::AlDia;
    else
        if(clientes[pos].estado > 0)
            return eEstado::Afavor;
        else
            return eEstado::Deudor;
}
int eliminarCliente(sClientes* cliente, str dni)
{
    u_int pos=buscarCliente(cliente,dni);
    if (pos > (N - 1))
        return N;
    if (pos == (N - 1))
        return N - 1;
    for (u_int i = pos; i < (N - 1); i++)
        cliente[i] = cliente[i + 1];
    return N - 1;
}
eAgregar agregarCliente(sClientes nuevoCliente, std::fstream archiClientes)
{

}
eModificar modificarCliente()
{
    ;
}

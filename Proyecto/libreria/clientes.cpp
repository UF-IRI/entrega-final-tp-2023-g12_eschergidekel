#include "clientes.h"
#include <libreria.h>
#define N 250

sClientes* resizeClientes(sClientes* cliente, unsigned int tam, unsigned int nuevoTam)
{
    sClientes* aux = new sClientes[nuevoTam];
    unsigned int longitud = (tam < nuevoTam) ? tam : nuevoTam;

    if(aux!=nullptr)
    {
        for(unsigned int i=0; i<longitud; i++)
            aux[i] = cliente[i]; //*(cliente+1)

        delete[] cliente;
        return aux;
    }

    return nullptr;
}
int buscarCliente(sClientes* clientes, str dni)
{
    unsigned int pos;
    for(unsigned int i=0; i<N ;i++)
    {
        if(clientes[i].dni==dni)
            pos=i;
    }
    return pos;
}
eEstado Cuota(sClientes *clientes, str dni)
{
    unsigned int pos = buscarCliente(clientes, dni);

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
    unsigned int pos=buscarCliente(cliente,dni);
    if (pos > (N - 1))
        return N;
    if (pos == (N - 1))
        return N - 1;
    for (unsigned int i = pos; i < (N - 1); i++)
        cliente[i] = cliente[i + 1];
    return N - 1;
}
eAgregar agregarCliente()
{
    ;
}
eModificar modificarCliente()
{
    ;
}

#include "clientes.h"
#define N 250

int buscarCliente(sClientes* clientes, unsigned int id)
{
    int pos;
    for(int i=0; i<N ;i++)
    {
        if(clientes[i].idCliente==id)
            pos=i;
    }
    return pos;
}
Estado Cuota(sClientes *clientes, unsigned id)
{
    int pos = buscarCliente(clientes, id);

    if(clientes[pos].estado == 0)
        return Estado::AlDia;
    else
        if(clientes[pos].estado > 0)
            return Estado::Afavor;
        else
            return Estado::Deudor;
}

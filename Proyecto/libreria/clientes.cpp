#include "clientes.h"
#define N 250

int buscarCliente(sClientes* clientes, str dni)
{
    int pos;
    for(int i=0; i<N ;i++)
    {
        if(clientes[i].dni==dni)
            pos=i;
    }
    return pos;
}
Estado Cuota(sClientes *clientes, str dni)
{
    int pos = buscarCliente(clientes, dni);

    if(clientes[pos].estado == 0)
        return Estado::AlDia;
    else
        if(clientes[pos].estado > 0)
            return Estado::Afavor;
        else
            return Estado::Deudor;
}
int eliminar(sClientes* cliente, int N, str dni)
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

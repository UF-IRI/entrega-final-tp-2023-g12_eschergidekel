#include "clientes.h"

bool espacio(u_int cantMaxima, u_int &cant)
{
    return ((cantMaxima-(cant))>0);
}
sClientes* resizeClientes(sClientes* cliente, u_int &tam, u_int nuevoTam)
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
int buscarCliente(sClientes* cliente, str dni, u_int &cant)
{
    u_int i;
    int pos;
    for(i=0; i<cant; i++)
    {
        if(cliente[i].dni==dni){
            pos=i;
        }
    }
    if(i==cant)
         return -1;
    else
         return cliente[pos].idCliente;
}
eEstado Cuota(sClientes* cliente, str dni, u_int &cant)
{
    u_int id = buscarCliente(cliente, dni, cant);

    for(u_int i=0; i<cant; i++)
    {
        if(cliente[i].idCliente == id)
        {
            if(cliente[i].estado == 0)
                return eEstado::AlDia;
            else
                if(cliente[i].estado > 0)
                    return eEstado::Afavor;
                else
                    return eEstado::Deudor;
        }
    }
}
u_int eliminarCliente(sClientes* cliente, str dni, u_int &cant)
{
    u_int id=buscarCliente(cliente, dni, cant); //cambiar tamaño
    u_int i=0;
    while(true){
        if(cliente[i].idCliente==id){
            cliente[i]=clienteNulo;
            return (cant)-1;
        }
        if(i==cant)
        {
           return cant;
            break;
        }
        i++;
    }
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
eAgregar agregarCliente(sClientes* cliente, sClientes nuevoCliente, u_int &cant, u_int &cantMaxima, u_int nuevoTam)
{
    int id = buscarCliente(cliente, nuevoCliente.dni, cant);
    if(!espacio(cantMaxima, cant))
    {
       cliente = resizeClientes(cliente, cant, nuevoTam);
       cantMaxima = nuevoTam;
    }
    if(id == -1) //me aseguro que el cliente ya no este inscripto
    {
       cliente[cant]=nuevoCliente;
       cant++;
       return eAgregar:: ExitoAg;
    }
    else
       return eAgregar::ErrorAg;
}
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str dni, u_int &cant)
{
    u_int id=buscarCliente(cliente,dni,cant);
    for(u_int i=0;i<cant;i++)
    {
        if(cliente[i].idCliente==id)
        {
            cliente[i]=clienteModificado;
            return eModificar::ExitoMod;
        }
    }
    return eModificar::ErrMod;
}

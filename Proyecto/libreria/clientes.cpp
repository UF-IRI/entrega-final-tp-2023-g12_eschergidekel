#include "clientes.h"

bool espacio(int cantMaxima, int *cant)
{
    return ((cantMaxima-(*cant))>0);
}
sClientes* resizeClientes(sClientes* cliente, int *tam, u_int nuevoTam)
{
    sClientes* aux = new sClientes[nuevoTam];
    u_int longitud = (*tam < nuevoTam) ? *tam : nuevoTam;

    if(aux!=nullptr)
    {
        for(u_int i=0; i<longitud; i++)
            aux[i] = cliente[i]; //*(cliente+1)

        delete[] cliente;
        return aux;
    }

    return nullptr;
}
int buscarCliente(sClientes* cliente, str dni, int *cant)
{
    int i;
    for(i=0; i<*cant; i++)
    {
      if(cliente[i].dni==dni)
      return cliente[i].idCliente;
    }
      if(i==*cant)
      return -1;
}
eEstado Cuota(sClientes* cliente, str dni, int *cant)
{
    u_int id = buscarCliente(cliente, dni, cant);

    for(int i=0; i<*cant; i++)
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
int eliminarCliente(sClientes* cliente, str dni, int *cant)
{
    u_int id=buscarCliente(cliente, dni, cant); //cambiar tamaño
    int i=0;
    while(true){

        if(cliente[i].idCliente==id){
           cliente[i]=clienteNulo;
                return (*cant)-1;
        }
        if(i==*cant)
        {
           return *cant;
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
eAgregar agregarCliente(sClientes* cliente, sClientes nuevoCliente,int *cant, int cantMaxima)
{
    int id = buscarCliente(cliente, nuevoCliente.dni, cant);
    int nuevoTam = (*cant)+30;
    if(!espacio(cantMaxima, cant))
    {
       cliente = resizeClientes(cliente, cant, nuevoTam);
       cantMaxima = nuevoTam;
    }
    if(id == -1) //me aseguro que el cliente ya no este inscripto
    {
       (*cant)++;
       cliente[(*cant)-1]=nuevoCliente;
       return eAgregar:: ExitoAg;
    }
    else
       return eAgregar::ErrorAg;
}
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str dni, int *cant)
{
    u_int id=buscarCliente(cliente,dni,cant);
    for(int i=0;i<*cant;i++)
    {
        if(cliente[i].idCliente==id)
        {
            cliente[i]=clienteModificado;
            return eModificar::ExitoMod;
        }
        else
            return eModificar::ErrMod;
    }
}

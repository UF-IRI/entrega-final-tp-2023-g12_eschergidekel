#include "clientes.h"

bool espacio(u_int cantMaxima, u_int &cant)
{
    return ((cantMaxima-(cant))>0);
}
void resizeClientes(sClientes*& cliente, u_int &tam, u_int nuevoTam)
{
    sClientes* aux = new sClientes[nuevoTam];
    u_int longitud = (tam < nuevoTam) ? tam : nuevoTam;

    if(aux!=nullptr)
    {
        for(u_int i=0; i<longitud; i++)
            aux[i] = cliente[i]; //*(cliente+1)

        delete[] cliente;
        cliente=aux;
    }
}
int buscarCliente(sClientes* cliente, str mail, u_int cant)
{
    u_int i;
    for(i=0; i<cant; i++)
    {
        if(cliente[i].mail==mail){
            return cliente[i].idCliente;
        }
    }
         return -1;

}
eEstado Cuota(sClientes* cliente, str email, u_int &cant)
{
    u_int id = buscarCliente(cliente, email, cant);

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
u_int eliminarCliente(sClientes* cliente, str mail, u_int &cant)
{
    u_int id=buscarCliente(cliente, mail, cant); //cambiar tamaño
    u_int i=0;
    for(i=0;i<cant;i++){
        if(cliente[i].idCliente==id){
            cliente[i]=clienteNulo;
            return cant-1;
        }
    }
        return cant;

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
eAgregar agregarCliente(sClientes*& cliente, sClientes nuevoCliente, u_int &cant, u_int &cantMaxima, u_int nuevoTam)
{
    int id = buscarCliente(cliente, nuevoCliente.mail, cant);
    if(!espacio(cantMaxima, cant))
    {
      resizeClientes(cliente, cant, nuevoTam);
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
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str mail, u_int cant)
{

    for(u_int i=0;i<cant;i++)
    {
        if(cliente[i].idCliente==clienteModificado.idCliente)
        {
            cliente[i]=clienteModificado;
            return eModificar::ExitoMod;
        }
    }
    return eModificar::ErrMod;
}

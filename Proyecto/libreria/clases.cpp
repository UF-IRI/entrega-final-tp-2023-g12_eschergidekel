#include "clases.h"
#include "archivo.h"
#include "clientes.h"

Inscripto estaInscriptoClase(Asistencia* asistencia, Clases clase)
{
    for(u_int i=0; i<asistencia->cantInscriptos; i++)
    {
        if(asistencia->CursosInscriptos[i].idCurso == clase.idClase) //verificar si ya está inscripto
            return Inscripto::Esta;
        else
            return Inscripto::noEsta;
    }
}
superposicion superposicionHorarios(Asistencia* asistencia, Clases clase,u_int idCliente, int cantClientes)
{
    for(int i=0; i<cantClientes;i++)
    {
        if(asistencia->idCliente==idCliente && asistencia->CursosInscriptos->idCurso == clase.idClase)
            return superposicion::SH;
        else
            return superposicion::noSH;

    }
}
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases nombreClase, int cantClientes)
{
    int result = estaInscriptoClase(asistencia, nombreClase);
    superposicion result2;
    if(result != 1)
        return reservar::ErrR;
    else
    {
        result2 = superposicionHorarios(asistencia, nombreClase, cliente.idCliente, cantClientes);//discutir
        if(result2 != 1)
            return reservar::ErrR;
        else
        {

            return reservar::ExitoR;
        }
    }
}

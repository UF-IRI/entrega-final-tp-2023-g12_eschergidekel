#include "clases.h"
#include "archivo.h"
#include <libreria.h>

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
superposicion superposicionHorarios(Asistencia* asistencia, Clases clase)
{
    for (u_int i = 0; i < asistencia->cantInscriptos; i++)
    {
        if (asistencia->CursosInscriptos[i].fechaInscripcion == clase.horarioClase)
            return superposicion::SH;
        else
            return superposicion::noSH;
    }
}
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases nombreClase)
{
    int result = estaInscriptoClase(asistencia, nombreClase);
    int result2;
    if(result != 1)
        return reservar::ErrR;
    else
    {
        result2 = superposicionHorarios(asistencia, nombreClase);
        if(result2 != 1)
            return reservar::ErrR;
        else
            return reservar::ExitoR;
    }
}

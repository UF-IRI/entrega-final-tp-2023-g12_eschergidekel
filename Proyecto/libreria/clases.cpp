#include "clases.h"

inscripto estaInscriptoClase(Asistencia* asistencia, Clases clase)
{
    for(u_int i=0; i<asistencia->cantInscriptos; i++)
    {
        if(asistencia->CursosInscriptos[i].idCurso == clase.idClase) //verificar si ya está inscripto
            return estaInscripto::Esta;
        else
            return estaInscripto::noEsta;
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
Reservas clases(sClientes cliente, Asistencia asistencia, Clases clase)
{
    int result = estaInscripto(asistencia, clase, cliente);
    int result2;
    if(result != 1)
        return reservar::ErrR;
    else
    {
        result 2 = superposicionHorarios(asistencia, clase);
        if(result2 != 1)
            return reservar::ErrR;
        else
            return reservar::ExitoR;
    }

}

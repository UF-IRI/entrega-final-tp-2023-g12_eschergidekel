#include "clases.h"

inscripto estaInscriptoClase(Asistencia* asistencia, Clases *clase, unsigned int id, unsigned int horario, str nombreClase)
{
    for(unsigned int i=0; i<asistencia->cantInscriptos; i++)
    {
        if(asistencia[i].idCliente == id && clase->horarioClase == horario && clase->nombreClase == nombreClase)
            return estaInscripto::Esta;
        else
            return estaInscripto::noEsta;
    }
}
Reservas clases()
{
    ;
}

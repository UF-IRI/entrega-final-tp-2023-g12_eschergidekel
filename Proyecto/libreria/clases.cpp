#include "clases.h"
#include "archivo.h"
#include "clientes.h"


Inscripto estaInscriptoClase(ifstream &archiAsistencia, Asistencia* asistencia, Clases clase)
{
    archiAsistencia.open("Asistencia.dat");
    if(archiAsistencia.is_open())
    {
        for(u_int i=0; i<asistencia->cantInscriptos; i++)
        {
            if(asistencia->CursosInscriptos[i].idCurso == clase.idClase) //verificar si ya está inscripto
            {
                archiAsistencia.close();
                return Inscripto::Esta;
            }
            else
            {
                archiAsistencia.close();
                return Inscripto::noEsta;
            }
        }
    }
}
superposicion superposicionHorarios(ifstream &archiAsistencia, Asistencia* asistencia, Clases clase, u_int idCliente,
                                    int cantClientes)
{
    archiAsistencia.open("Asistencia.dat");
    if(archiAsistencia.is_open())
    {
        for(int i=0; i<cantClientes; i++)
        {
            if(asistencia->idCliente == idCliente && asistencia->CursosInscriptos[i].idCurso == clase.idClase)
            {
                archiAsistencia.close();
                return superposicion::SH;
            }
            else
            {
                archiAsistencia.close();
                return superposicion::noSH;
            }
        }
    }
}
Reservas clases(ifstream &archiClases, ifstream &archiClientes, ifstream &archiAsistencia, ofstream &informe,
                sClientes cliente, Asistencia* asistencia, Clases clase, int cantClientes)
{
    Inscripto resul = estaInscriptoClase(archiAsistencia, asistencia, clase);
    superposicion resul2 = superposicionHorarios(archiAsistencia, asistencia, clase, cliente.idCliente, cantClientes);
    if(resul != Inscripto::Esta && resul2 != superposicion::SH)
    {
        informe.open("informe.dat");
        if(informe.is_open() && archiClases.is_open())
        {
            eCodArchivos resul3 = informeAsistencia(informe, asistencia);
            if(resul3 != eCodArchivos::ErrorApertura)
            {
                for(int i=0; i<cantClientes; i++)
                {
                    asistencia[i];
                }
            }
        }
        return reservar::ExitoR;
    }
    else
        return reservar::ErrR;
}
Baja cancelarClase(Asistencia* asistencia, Clases clase, int cantClientes)
{
    Clases nula={0,0,""};
    for(int i=0; i<cantClientes;i++)
    {
        if(asistencia[i].CursosInscriptos->idCurso== clase.idClase)
        {
            asistencia[i].cantInscriptos=asistencia[i].cantInscriptos-1;
            asistencia[i].CursosInscriptos->idCurso=0;

        }

    }

}










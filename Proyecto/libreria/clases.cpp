#include "clases.h"
#include "archivo.h"
#include "clientes.h"


Inscripto estaInscriptoClase(ifstream &archiAsistencia, Asistencia* asistencia, Clases* clase)//modificar
{
    archiAsistencia.open("Asistencia.dat");
    if(archiAsistencia.is_open())
    {
        for(u_int i=0; i<asistencia->cantInscriptos; i++)
        {
            if(asistencia[i].CursosInscriptos[i].idCurso == clase[i].idClase) //verificar si ya está inscripto
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
superposicion superposicionHorarios(ifstream &archiAsistencia, Asistencia* asistencia, Clases* clase, u_int idCliente,
                                    int cantClientes)//modificar
{
    archiAsistencia.open("Asistencia.dat");
    if(archiAsistencia.is_open())
    {
        for(int i=0; i<cantClientes; i++)
        {
            for(int k=0; k<60; k++)
            {
                if(asistencia->idCliente == idCliente && asistencia->CursosInscriptos[i].idCurso == clase[k].idClase)
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
}
Reservas clases(ifstream &archiClases, ifstream &archiClientes, ifstream &archiAsistencia, ofstream &informe,
                sClientes cliente, Asistencia* asistencia, Clases* clase, int cantClientes)//modificar
{
    int cont=0;
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
                for(u_int i=0; i<asistencia->cantInscriptos; i++)
                {
                    for(u_int j=0; j<asistencia->cantInscriptos; j++)
                    {
                        if(asistencia[i].CursosInscriptos[j].idCurso  == clase[i].idClase)
                            cont++;
                    }
                }
                //spinning
                if((clase->idClase == '1' || clase->idClase == '2' || clase->idClase == '3' || clase->idClase == '4' ||
                    clase->idClase == '5') && cont<45)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //yoga
                if((clase->idClase == '6' || clase->idClase == '7' || clase->idClase == '8' || clase->idClase == '9' ||
                    clase->idClase == '10' || clase->idClase == '11') && cont<25)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //pilates
                if((clase->idClase == '12' || clase->idClase == '13' || clase->idClase == '14' || clase->idClase == '15' ||
                    clase->idClase == '16' || clase->idClase == '17') && cont<15)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //stretching
                if((clase->idClase == '18' || clase->idClase == '19' || clase->idClase == '20' || clase->idClase == '21' ||
                    clase->idClase == '22' || clase->idClase == '23') && cont<40)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //zumba
                if((clase->idClase == '24' || clase->idClase == '25' || clase->idClase == '26' || clase->idClase == '27' ||
                    clase->idClase == '28' || clase->idClase == '29') && cont<50)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //boxeo
                if((clase->idClase == '30' || clase->idClase == '31' || clase->idClase == '32' || clase->idClase == '33')
                    && cont<30)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
            }
        }
        return reservar::ExitoR;
    }
    else
        return reservar::ErrR;
}
Baja cancelarClase(Asistencia* asistencia, Clases *clase, int cantClientes)//modificar
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


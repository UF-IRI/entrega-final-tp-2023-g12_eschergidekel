#include "clases.h"


bool espacioAsistencias(u_int cantMaxAsistencia, u_int cantAsistencias)
{
  return ((cantMaxAsistencia-(cantAsistencias))>0);
}
bool espacioInscripciones(Asistencia* asistencia, u_int cantMaxInscripciones)
{
  return ((cantMaxInscripciones-(asistencia->cantInscriptos))>0);
}
Inscripto estaInscriptoClases(Asistencia* asistencia, Clases* clase, string nombreClase, u_int horario)
{
    int pos;
    for(int i=0;i<60;i++)
    {
        if(clase[i].nombreClase==nombreClase && clase[i].horarioClase==horario)
            pos=i;
    }

    for(u_int i=0; i<250; i++)
    {
        if(asistencia[i].CursosInscriptos[i].idCurso == clase[pos].idClase) //verificar si ya está inscripto
            return Inscripto::Esta;
    }

    return Inscripto::noEsta;
}
superposicion superposicionHorarios(Asistencia* asistencia, Clases* clase, u_int idCliente, u_int& cantClientes, string nombreClase,
                                    u_int horario, int &longitud)
{
    int pos;
    for(int i=0;i<60;i++)
    {
        if(clase[i].nombreClase==nombreClase && clase[i].horarioClase==horario)
                pos=i;
    }
    for(u_int i=0; i<250; i++)
    {
      if(asistencia[i].idCliente == idCliente && asistencia[i].CursosInscriptos[i].idCurso == clase[pos].idClase)
          return superposicion::SH;
    }

    return superposicion::noSH;
}
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases *clase, u_int &cantClientes, string nombreClase, u_int horario, int &longitud)
{
    int cont=0;
    Inscripto resul = estaInscriptoClases(asistencia, clase,nombreClase, horario);
    superposicion resul2 = superposicionHorarios(asistencia, clase, cliente.idCliente, cantClientes, nombreClase, horario, longitud);
    if(resul != Inscripto::Esta && resul2 != superposicion::SH)
    {
        for(u_int i=0; i<250; i++)
        {
            for(u_int j=0; j<asistencia[i].cantInscriptos; j++)
            {
               if(asistencia[i].CursosInscriptos[j].idCurso  == clase[i].idClase)
                   cont++;
            }

                //spinning
             if((clase[i].idClase == '1' || clase[i].idClase == '2' || clase[i].idClase == '3' || clase[i].idClase == '4' ||
                 clase[i].idClase == '5') && cont<45)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //yoga
                if((clase[i].idClase == 6 || clase[i].idClase == 7 || clase[i].idClase == 8 || clase[i].idClase == 9 ||
                    clase[i].idClase == 10 || clase[i].idClase == 11) && cont<25)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //pilates
                if((clase[i].idClase == 12 || clase[i].idClase == 13 || clase[i].idClase == 14 || clase[i].idClase == 15 ||
                    clase[i].idClase == 16 || clase[i].idClase == 17) && cont<15)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //stretching
                if((clase[i].idClase == 18 || clase[i].idClase == 19 || clase[i].idClase == 20 || clase[i].idClase == 21 ||
                    clase[i].idClase == 22 || clase[i].idClase == 23) && cont<40)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //zumba
                if((clase[i].idClase == 24 || clase[i].idClase == 25 || clase[i].idClase == 26 || clase[i].idClase == 27 ||
                    clase[i].idClase == 28 || clase[i].idClase == 29) && cont<50)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;
                //boxeo
                if((clase[i].idClase == 30 || clase[i].idClase == 31 || clase[i].idClase == 32 || clase[i].idClase == 33)
                    && cont<30)
                {
                    cont++;
                    return reservar::ExitoR;
                }
                else
                    return reservar::ErrR;

        }
        return reservar::ExitoR;
    }
    return reservar::ErrR;
}
Baja cancelarClase(Asistencia* asistencia, u_int idClase, u_int &cant)//modificar
{
    for(u_int i=0; i<cant; i++)
    {
        if(asistencia[i].CursosInscriptos->idCurso == idClase)
        {
            asistencia[i].cantInscriptos=(asistencia[i].cantInscriptos)-1;
            asistencia[i].CursosInscriptos->idCurso = 0;
            return darBaja::ExitoBaja;
        }
    }

    return darBaja::ErrBaja;
}

Asistencia* resizeAsistencia(Asistencia* asistencia, u_int tam, u_int nuevoTam)
{
    Asistencia* aux = new Asistencia[nuevoTam];
    u_int longitud = (tam < nuevoTam) ? tam : nuevoTam;

    if(aux!=nullptr)
    {
        for(u_int i=0; i<longitud; i++)
            aux[i] = asistencia[i]; //*(cliente+1)

        delete[] asistencia;
        return aux;
    }

    return nullptr;
}
Inscripcion* resizeInscripcion(Inscripcion* inscripcion, u_int tam, u_int nuevoTam)
{
    Inscripcion*aux = new Inscripcion[nuevoTam];
    u_int longitud = (tam<nuevoTam)? tam: nuevoTam;

    if(aux!=nullptr)
    {
        for(u_int i=0; i<longitud;i++)
            aux[i] = inscripcion[i];

        delete[] inscripcion;
        return aux;
    }

    return nullptr;
}


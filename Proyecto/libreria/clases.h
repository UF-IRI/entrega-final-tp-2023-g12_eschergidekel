#ifndef CLASES_H
#define CLASES_H
#include "libreria.h"
#include "clientes.h"

enum estaInscripto {Esta = 1, noEsta = -1};
typedef enum estaInscripto inscripto;
enum reservar {ErrR = -1, ExitoR = 1};
typedef enum reservar Reservas;
enum darBaja {ErrBaja = -1, ExitoBaja = 1};
typedef enum darBaja Baja;

typedef struct {
    unsigned int idClase, horarioClase;
    str nombreClase;
} Clases;

inscripto estaInscriptoClases(Asistencia *asistencia,Clases* clase, unsigned int id, unsigned int horario, str nombreClase); //verificar que no se inscriba dos veces
Reservas clases(); //reservar clase
Reservas musculacion(); //reservar musculacion
Baja cancelarClase(); //dar de baja clase
Baja cancelarMusculacion(); //dar de baja musculacion

#endif // CLASES_H

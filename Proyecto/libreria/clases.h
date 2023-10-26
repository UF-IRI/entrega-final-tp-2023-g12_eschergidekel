#ifndef CLASES_H
#define CLASES_H
#include "encabezados.h"
#include "clientes.h"

enum estaInscripto {Esta = 1, noEsta = -1};
typedef enum estaInscripto inscripto;
enum reservar {ErrR = -1, ExitoR = 1};
typedef enum reservar Reservas;

typedef struct {
    unsigned int idClase, horarioClase;
    str nombreClase;
} Clases;

inscripto estaInscriptoClases(Asistencia *asistencia,Clases* clase, unsigned int id, unsigned int horario, str nombreClase); //verificar que no se inscriba dos veces
Reservas clases(); //reservar clase
//reservar musculacion
//dar de baja clase
//dar de baja musculacion

#endif // CLASES_H

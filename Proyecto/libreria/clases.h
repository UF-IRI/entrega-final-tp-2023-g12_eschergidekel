#ifndef CLASES_H
#define CLASES_H
#include "libreria.h"
#include "clientes.h"

enum estaInscripto {Esta = -1, noEsta = 1};
typedef enum estaInscripto Inscripto;
enum reservar {ErrR = -1, ExitoR = 1};
typedef enum reservar Reservas;
enum darBaja {ErrBaja = -1, ExitoBaja = 1};
typedef enum darBaja Baja;
enum superposicion {SH = -1, noSH = 1};
typedef enum superposicion supH;

typedef struct {
    unsigned int idClase, horarioClase;
    str nombreClase;
} Clases;

Inscripto estaInscriptoClases(Asistencia* asistencia, Clases clase); //verificar que no se inscriba dos veces
superposicion superposicionHorarios(Asistencia* asistencia, Clases clase);
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases nombreClase); //reservar clase
Reservas musculacion(); //reservar musculacion
Baja cancelarClase(); //dar de baja clase
Baja cancelarMusculacion(); //dar de baja musculacion

#endif // CLASES_H

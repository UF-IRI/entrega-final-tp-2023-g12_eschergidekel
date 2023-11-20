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

Inscripto estaInscriptoClases(ifstream &archiAsistencia, Asistencia* asistencia, Clases *clase); //verificar que no se inscriba dos veces
superposicion superposicionHorarios(ifstream &archiAsistencia,Asistencia* asistencia, Clases* clase, u_int idCliente, int cantClientes);//modificada
Reservas clases(ifstream &archiClases, ifstream &archiClientes, ifstream &archiAsistencia, ofstream &informe,
                sClientes cliente, Asistencia* asistencia, Clases *clase, int cantClientes); //reservar clase//modificada
Baja cancelarClase(); //dar de baja clase


#endif // CLASES_H

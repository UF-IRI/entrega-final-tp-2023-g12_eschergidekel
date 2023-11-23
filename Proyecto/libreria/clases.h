#ifndef CLASES_H
#define CLASES_H
#include <libreria.h>
#include <clientes.h>

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

Inscripto estaInscriptoClases(Asistencia* asistencia, Clases* clase, string nombreClase, u_int horario); //verificar que no se inscriba dos veces
superposicion superposicionHorarios(Asistencia* asistencia, Clases* clase, u_int idCliente, int cantClientes, string nombreClase,
                                    u_int horario); //verificar que no se superpongan horarios
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases *clase, u_int *cantClientes, string nombreClase, u_int horario); //reservar clase
Baja cancelarClase(Asistencia* asistencia, u_int idClase, u_int *cant); //dar de baja clase
Asistencia* resizeAsistencia(Asistencia* asistencia, u_int tam, u_int nuevoTam); //tamaño de asistencia
bool espacioAsistencias(u_int cantMaxAsistencia, u_int cantAsistencias);
Inscripcion* resizeInscripcion(Inscripcion* inscripcion, u_int tam, u_int nuevoTam);
bool espacioInscripciones(Asistencia* asistencia, u_int cantMaxInscripciones);
#endif // CLASES_H

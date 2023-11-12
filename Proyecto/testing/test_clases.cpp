#include <catch2/catch.hpp>
#include <clases.h>

/*
Inscripto estaInscriptoClases(Asistencia* asistencia, Clases clase);
superposicion superposicionHorarios(Asistencia* asistencia, Clases clase);
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases nombreClase);
*/

TEST_CASE("Incripcion multiple")
{
    Asistencia* asistencia= new Asistencia;
    Clases* clases= new Clases;

    SECTION("Verificando que un cliente no se haya incripto mas de una vez")
    {

    }
}

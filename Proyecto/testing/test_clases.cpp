#include <catch2/catch.hpp>
#include <clases.h>
#include <clientes.h>
#include <archivo.h>
/*
Inscripto estaInscriptoClases(Asistencia* asistencia, Clases clase);
superposicion superposicionHorarios(Asistencia* asistencia, Clases clase, int idCliente);
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases nombreClase);
*/

TEST_CASE("Incripcion multiple")
{
    Asistencia *aux= new Asistencia; //tamaño
    sClientes cliente;
    int cantClientes=1;
    Clases curso;
    cliente.apellido={"serene"};
    cliente.dni={"23456897"};
    cliente.estado=0;
    cliente.fechaNac.anio=2002;
    cliente.fechaNac.mes=5;
    cliente.fechaNac.dia=12;
    cliente.idCliente=1;
    cliente.mail={"serenemartina@gmial.com"};
    cliente.nombre={"Martina"};
    cliente.telefono={"123-456-786"};
    cliente.idCliente=1;
    aux->cantInscriptos=1;
    aux->CursosInscriptos->idCurso=3;
    aux->CursosInscriptos->fechaInscripcion=16112023;
    aux->idCliente=1;
    curso.horarioClase=5;
    curso.idClase=3;
    curso.nombreClase={"boxeo"};
    clases(archiClases, archiClientes, archiAsistencia, informe, cliente,aux ,curso, cantClientes);


    SECTION("Verificacion de inscripcion"){
        Inscripto result=estaInscriptoClases(archiAsistencia,aux, curso);
        REQUIRE(result==1);
    }
    SECTION("Superposicion horaria"){
        superposicion superp = superposicionHorarios(aux, curso, cliente.idCliente, cantClientes);
        REQUIRE (superp==1);
    }
    SECTION("Reserva de clases"){

    }
    SECTION("Cancelacion de clase"){

    }
}

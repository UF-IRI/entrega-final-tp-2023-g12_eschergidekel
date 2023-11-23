#include <catch2/catch.hpp>
#include "archivo.h"
/*
Inscripto estaInscriptoClases(Asistencia* asistencia, Clases clase);
superposicion superposicionHorarios(Asistencia* asistencia, Clases clase, int idCliente);
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases nombreClase);
*/

const Asistencia DefaultAsistencia[3] = {
    {23,1,{5,168999097}},
    {28,2,{8,168999097}},
    {21,6,{2,168999097}}
};

const Inscripcion DefaultInscripcion[3] = {
    {5,168999097},
    {8,168999097},
    {2,168999097}
};

TEST_CASE("Incripcion multiple")
{
    Asistencia *aux= new Asistencia; //tamaño
    sClientes cliente;
    u_int num=1;
    u_int *cantClientes;
    cantClientes=&num;
    Clases *curso;
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
    curso->horarioClase=5;
    curso->idClase=3;
    curso->nombreClase={"boxeo"};
    clases(cliente, aux, curso, cantClientes, curso->nombreClase, curso->horarioClase);//revisar


    SECTION("Verificacion de inscripcion"){
        Inscripto result = estaInscriptoClases(aux, curso, curso->nombreClase, curso->horarioClase);
        REQUIRE(result == 1);
    }
    SECTION("Superposicion horaria"){
        superposicion superp = superposicionHorarios(aux, curso, cliente.idCliente, *cantClientes,curso->nombreClase, curso->horarioClase);
        REQUIRE(superp == 1);
    }
    SECTION("Reserva de clases"){
        Reservas result2 = clases(cliente, aux, curso, cantClientes, curso->nombreClase, curso->horarioClase);
        REQUIRE(result2 == 1);
    }
    SECTION("Cancelacion de clase"){
        Baja result3 = cancelarClase(aux, curso->idClase, cantClientes);
        REQUIRE(result3 == 1);
    }
}
TEST_CASE("Resize")
{
    SECTION("Resize asistencia"){
        Asistencia* asistencia = new Asistencia[2];
        Inscripcion* inscripcion = new Inscripcion[2];

        REQUIRE(asistencia != nullptr);

        for(u_int i=0; i < 2; i++)
            asistencia[i] = DefaultAsistencia[i];

        for(u_int i=0; i<2; i++)
            inscripcion[i] = DefaultInscripcion[i];

        Asistencia* vieja = asistencia;
        u_int num=3;
        u_int cant;
        cant=num;
        resizeAsistencia(asistencia, cant , 2 + 3);
        asistencia[0] = {"23","1",Inscripcion[0]};
        asistencia[1] = {"28","2",inscripcion[1]};

        CHECK(vieja != asistencia);
    }

    SECTION("Resize inscripcion"){
        Inscripcion* inscripcion = new Inscripcion[2];

        REQUIRE(inscripcion != nullptr);

        for(u_int i = 0; i < 2; i++)
            inscripcion[i] = DefaultInscripcion[i];

        Inscripcion* antigua = inscripcion;
        u_int num=3;
        u_int cant;
        cant=num;
        resizeInscripcion(inscripcion, cant , 2 + 3);
        inscripcion[3] = {5,168999097};
        inscripcion[3] = {8,168999097};

        CHECK(antigua != inscripcion);
    }
}
TEST_CASE("Verificar espacio")
{
    SECTION("Asistencia"){
        int cantmax=40;
        u_int num=6;
        u_int cant;
        cant=num;
        REQUIRE(!espacioAsistencias(cantmax,cant));
    }

    SECTION("Inscricion"){
        Asistencia* asistencia;
        int cantmax=40;
        u_int num=2;
        u_int cant;
        cant=num;
        REQUIRE(!espacioInscripciones(asistencia,cantmax));
    }
}

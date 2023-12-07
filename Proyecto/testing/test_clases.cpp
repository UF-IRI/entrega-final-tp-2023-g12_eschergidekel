#include <catch2/catch.hpp>
#include "archivo.h"
/*
Inscripto estaInscriptoClases(Asistencia* asistencia, Clases clase);
superposicion superposicionHorarios(Asistencia* asistencia, Clases clase, int idCliente);
Reservas clases(sClientes cliente, Asistencia* asistencia, Clases nombreClase);
*/

/* Asistencia DefaultAsistencia[3] = {
    {23,1,{5,168999097}},
    {28,2,{8,168999097}},
    {21,6,{2,168999097}}
};
*/
const Inscripcion DefaultInscripcion[3] = {
    {5,168999097},
    {8,168999097},
    {2,168999097}
};

TEST_CASE("Inscripcion multiple")
{
    Asistencia *aux= new Asistencia[1]; //tamaño
    sClientes cliente;
    u_int num=1;
    int longitud=0;
    u_int cantClientes;
    cantClientes=num;
    Clases *curso=new Clases[1];//tamaño
    cliente.apellido={"serene"};

    cliente.estado=0;
    cliente.fechaNac.anio=2002;
    cliente.fechaNac.mes=5;
    cliente.fechaNac.dia=12;
    cliente.idCliente=1;
    cliente.mail={"serenemartina@gmial.com"};
    cliente.nombre={"Martina"};
    cliente.telefono={"123-456-786"};
    aux[0].cantInscriptos=1;
    aux[0].CursosInscriptos->idCurso=3;
    aux[0].CursosInscriptos->fechaInscripcion=0;
    aux[0].idCliente=1;
    curso[0].horarioClase=5;
    curso[0].idClase=3;
    curso[0].nombreClase={"boxeo"};



    SECTION("Verificacion de inscripcion"){
        Inscripto result = estaInscriptoClases(aux, curso, curso[0].nombreClase, curso[0].horarioClase);
        REQUIRE(result == -1);
    }

    SECTION("Superposicion horaria"){
        superposicion superp = superposicionHorarios(aux, curso, cliente.idCliente, cantClientes,curso[0].nombreClase, curso[0].horarioClase, longitud);
        REQUIRE(superp == -1);
    }
    SECTION("Reserva de clases"){
        Reservas result2 = clases(cliente, aux, curso, cantClientes, curso[0].nombreClase, curso[0].horarioClase, longitud);
        REQUIRE(result2 == -1);
    }
    SECTION("Cancelacion de clase"){
        Baja result3 = cancelarClase(aux, curso[0].idClase, cantClientes);
        REQUIRE(result3 == 1);
    }
    delete[] aux;
    delete[] curso;
}
/*
TEST_CASE("Resize")
{
    SECTION("Resize inscripcion"){
        Inscripcion* inscripcion = new Inscripcion[2];

        REQUIRE(inscripcion != nullptr);

        for(u_int i = 0; i < 2; i++)
            inscripcion[i] = DefaultInscripcion[i];

        Inscripcion* antigua = inscripcion;
        u_int num=2;
        u_int cant;
        cant=num;
        resizeInscripcion(inscripcion, cant , 2 + 2);
        inscripcion[3] = {5,168999097};
        inscripcion[4] = {8,168999097};

        CHECK(antigua != inscripcion);

        delete[] inscripcion;
    }

    SECTION("Resize asistencia"){
        Asistencia* asistencia = new Asistencia[2];
        Inscripcion* inscripcion = new Inscripcion[2];

        REQUIRE(asistencia != nullptr);

        for(u_int i=0; i < 2; i++)
            asistencia[i] = DefaultAsistencia[i];

        Asistencia* vieja = asistencia;
        u_int num=3;
        u_int cant;
        cant=num;
        resizeAsistencia(asistencia, cant , 2 + 3);
        asistencia[2] = {23,1,inscripcion};
        asistencia[2] = {28,2,inscripcion};

        CHECK(vieja != asistencia);
    }
}*/
TEST_CASE("Verificar espacio")
{
    SECTION("Asistencia"){
        u_int cantmax=40;
        u_int cant=6;
        REQUIRE(!espacioAsistencias(cantmax,cant));
    }

    SECTION("Inscripcion"){
        Inscripcion* inscripcion = new Inscripcion[1];
        inscripcion[1]={5,168999097};
        Asistencia asistencia[1]={23, 1, inscripcion};
        u_int cantmax=40;
        asistencia->cantInscriptos=6;
        REQUIRE(!espacioInscripciones(asistencia,cantmax));

        delete[] inscripcion;
    }
}

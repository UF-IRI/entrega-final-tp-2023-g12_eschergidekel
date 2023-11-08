#include <catch2/catch.hpp>
#include <clientes.h>

/*sClientes* resizeClientes(sClientes* lista, u_int tam, u_int nuevoTam); //tamaño de clientes
int buscarCliente(sClientes* cliente, str dni,int cant); //buscar clientes por dni
eEstado Cuota(sClientes* cliente, u_int dni, int cant); //verificar el estado del cliente
int eliminarCliente(sClientes* cliente, str dni,int cant); //eliminar cliente
eAgregar agregarCliente(sClientes* cliente,sClientes nuevoCliente, int cant, int cantMaxima); //agregar cliente
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str dni, int cant); //modificar cliente
bool espacio(int cantMaxima, int cant); //verificar el espacio disponible
int cantClientes(FILE* archiClientes, int n); //paso el archivo como parámetro y leo la cantidad de registros */

TEST_CASE("agregar cliente")
{
    sClientes* cliente= new sClientes;
    int cant=0;
    int cantMaxima=6;

    SECTION("agregando dos contactos"){
        eAgregar resul;
        eAgregar resul2;
    resul= agregarCliente(cliente,{"Valentina","Perez","46534213","valenPrez@gmial", "115-233-5643",{12,3,2006},0,1}, cant, cantMaxima); //agregar cliente
    resul2= agregarCliente(cliente,{"Marcos","Aguilar","45025423","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,2}, cant, cantMaxima);
    if(resul==1 && resul2==1)
        cant=2;
    REQUIRE( resul==1);//ambos se agregaron de manera correcta
    REQUIRE(resul2==1);
    CHECK(cant==2);

    }
}

TEST_CASE("eliminar cliente"){

    sClientes*cliente= new sClientes;
    int cant=2;
    int cantMaxima=6;
    int resul;
    int busqueda;
    agregarCliente(cliente,{"Valentina","Perez","46534213","valenPrez@gmial", "115-233-5643",{12,3,2006},0,1}, cant, cantMaxima); //agregar cliente
    agregarCliente(cliente,{"Marcos","Aguilar","45025423","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,2}, cant, cantMaxima);

    resul= eliminarCliente(cliente,"46534213",cant);
    REQUIRE(resul==1);
    CHECK(cant==1);
    busqueda= buscarCliente( cliente, "46534213" ,cant);
    REQUIRE(busqueda==-1);
}




#include <catch2/catch.hpp>
#include <clientes.h>
#include <libreria.h>
#include <archivo.h>
/*
sClientes* resizeClientes(sClientes* lista, u_int tam, u_int nuevoTam); //tamaño de clientes
int buscarCliente(sClientes* cliente, str dni,int cant); //buscar clientes por dni
eEstado Cuota(sClientes* cliente, str dni, int cant); //verificar el estado del cliente
int eliminarCliente(sClientes* cliente, str dni,int cant); //eliminar cliente
eAgregar agregarCliente(sClientes* cliente,sClientes nuevoCliente, int cant, int cantMaxima); //agregar cliente
eModificar modificarCliente(sClientes* cliente, sClientes clienteModificado, str dni, int cant); //modificar cliente
bool espacio(int cantMaxima, int cant); //verificar el espacio disponible
*/

const sClientes DefaultCliente[3] = {
    {"Maria","Lopez","46203718","lopezmaria@gmail.com", "333-444-5555",{6,7,1996},123,1},
    {"Felipe", "Gonzalez", "44312783", "felipeg@gmail.com", "987-654-3210", {15, 11, 1992}, 0, 2},
    {"Laura", "Fernandez", "32145638", "laurafernandez@gamil.com", "316-424-5885", {3, 9, 1995}, 0, 3}
};
/*
TEST_CASE("Agregar cliente")
{
    sClientes* cliente= new sClientes;
    cliente=nullptr;
    u_int cant=0;
    u_int cantMaxima=6;

    SECTION("Agregando dos clientes")
    {
    eAgregar resul= agregarCliente(cliente,{"Valentina","Perez","46534213","valenPrez@gmial", "115-233-5643",{12,3,2006},0,1}, cant, cantMaxima); //agregar cliente
    eAgregar resul2= agregarCliente(cliente,{"Marcos","Aguilar","45025423","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,2}, cant, cantMaxima);
    if(resul==1 && resul2==1)
        cant=2;
    REQUIRE(resul==1); //ambos se agregaron de manera correcta
    REQUIRE(resul2==1);
    CHECK(cant==2);
    }
}

TEST_CASE("Buscar cliente")
{
    sClientes* cliente= new sClientes;
    cliente=nullptr;
    u_int num=2;
    u_int cant;
    cant=num;
    u_int cantMaxima=6;

    eAgregar resul1= agregarCliente(cliente,{"Valentina","Perez","46534213","valenPrez@gmial", "115-233-5643",{12,3,2006},0,1}, cant, cantMaxima);
    eAgregar resul2= agregarCliente(cliente,{"Marcos","Aguilar","45025423","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,2}, cant, cantMaxima);
    REQUIRE(resul1==1);
    REQUIRE(resul2==1);
    SECTION("Buscando el cliente por DNI")
    {
    int resul = buscarCliente(cliente, "46534213", cant);
    REQUIRE(resul == 1);
    }
}

TEST_CASE("Eliminar cliente")
{
    sClientes* cliente= new sClientes;
    cliente=nullptr;
    u_int num=2;
    u_int cant;
    cant=num;
    u_int cantMaxima=6;
    int resul;
    int busqueda;

    SECTION("Eliminando un cliente")
    {
    eAgregar resul1= agregarCliente(cliente,{"Valentina","Perez","46534213","valenPrez@gmial", "115-233-5643",{12,3,2006},0,1}, cant, cantMaxima);
    eAgregar resul2= agregarCliente(cliente,{"Marcos","Aguilar","45025423","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,2}, cant, cantMaxima);
    CHECK(cant==2);
    REQUIRE(resul1==1);
    REQUIRE(resul2==1);
    resul = eliminarCliente(cliente,"46534213", cant);
    REQUIRE(resul==1);
    CHECK(cant==1);
    busqueda = buscarCliente(cliente, "46534213" ,cant);
    REQUIRE(busqueda==-1);
    }
}

TEST_CASE("Modificar cliente")
{
    sClientes* cliente = new sClientes;
    cliente=nullptr;
    str dni;
    u_int num=2;
    u_int cant;
    cant=num;
    u_int cantMaxima=6;

    int pos=buscarCliente(cliente, dni, cant);

    SECTION("Mofificando un cliente")
    {
    eAgregar resul1= agregarCliente(cliente,{"Valentina","Perez","46534213","valenPrez@gmial", "115-233-5643",{12,3,2006},0,1}, cant, cantMaxima); //agregar cliente
    eAgregar resul2= agregarCliente(cliente,{"Marcos","Aguilar","45025423","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,2}, cant, cantMaxima);
    REQUIRE(resul1==1);
    REQUIRE(resul2==1);
    eModificar resul = modificarCliente(cliente, cliente[pos], dni, cant);
    REQUIRE(resul == eModificar::ExitoMod);
    }
}

TEST_CASE("Resize cliente")
{
    sClientes* clientes = new sClientes[3];

    REQUIRE(clientes != nullptr);

    for(u_int i = 0; i < 3; i++)
        clientes[i] = DefaultCliente[i];

    SECTION("Agregando dos nuevos datos")
    {
    sClientes* ViejaDireccion = clientes;
    u_int num=3;
    u_int cant;
    cant=num;
    resizeClientes(clientes, cant , 3 + 2);
    clientes[3] = {"Valentina","Perez","46534213","valenPrez@gmial", "115-233-5643",{12,3,2006},0,4};
    clientes[4] = {"Marcos","Aguilar","45025423","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,5};

    CHECK(ViejaDireccion != clientes);
    }
}*/

TEST_CASE("Estado de la cuota")
{
    sClientes* cliente = new sClientes[3];
    //eEstado Cuota(sClientes* cliente, str dni, int cant)
    str dni1={"46203718"};
    str dni2={"45025423"};
    u_int num=2;
    u_int cant;
    cant=num;
    SECTION("Comprobando estado de dos clientes")
    {
    eEstado resul=Cuota(cliente, dni1, cant);
    REQUIRE(resul==eEstado::Afavor);
    eEstado resul2=Cuota(cliente, dni2, cant);
    REQUIRE(resul2==eEstado::Afavor);
    }
}
TEST_CASE("verificar espacio")
{
    u_int cantmax=6;
    u_int num=6;
    u_int cant;
    cant=num;
    REQUIRE(!espacio(cantmax,cant));
}



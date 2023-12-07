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
    {"Maria","Lopez","lopezmaria@gmail.com", "333-444-5555",{6,7,1996},123,1},
    {"Felipe", "Gonzalez", "felipeg@gmail.com", "987-654-3210", {15, 11, 1992}, 0, 2},
    {"Laura", "Fernandez","laurafernandez@gamil.com", "316-424-5885", {3, 9, 1995}, 0, 3}
};

TEST_CASE("Agregar cliente")
{
    sClientes* cliente= new sClientes[2];
    u_int cant=0;
    u_int cantMaxima=6;
    u_int nuevoTam=cant+3;
    SECTION("Agregando dos clientes")
    {
    eAgregar resul= agregarCliente(cliente,{"Valentina","Perez","valenPrez@gmial", "115-233-5643",{12,3,2006},0,1}, cant, cantMaxima, nuevoTam); //agregar cliente
    eAgregar resul2= agregarCliente(cliente,{"Marcos","Aguilar","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,2}, cant, cantMaxima, nuevoTam);
    if(resul==1 && resul2==1)
        cant=2;
    REQUIRE(resul==1); //ambos se agregaron de manera correcta
    REQUIRE(resul2==1);
    CHECK(cant==2);
    }
    delete[] cliente;
}

TEST_CASE("Buscar cliente")
{
    sClientes* cliente= new sClientes[3];
    u_int num=3;
    u_int cant;
    cant=num;

    SECTION("Buscando el cliente por DNI")
    {
    for(u_int i = 0; i < 3; i++)
        cliente[i] = DefaultCliente[i];

    int resul = buscarCliente(cliente, "lopezmaria@gmail.com", cant);
    REQUIRE(resul == 1);
    }
    delete[] cliente;
}

TEST_CASE("Eliminar cliente")
{
    sClientes* cliente= new sClientes[3];

    u_int num=3;
    u_int cant;
    cant=num;
    u_int resul;
    int busqueda;
    u_int cantInicial=3;

    SECTION("Eliminando un cliente")
    {
    for(u_int i = 0; i < 3; i++)
        cliente[i] = DefaultCliente[i];


    resul = eliminarCliente(cliente,"felipeg@gmail.com", cant);
    REQUIRE(resul==cantInicial-1);
    busqueda = buscarCliente(cliente, "felipeg@gmail.com" ,cant);
    REQUIRE(busqueda==-1);
    }
    delete[] cliente;
}

TEST_CASE("Modificar cliente")
{
    sClientes* cliente = new sClientes[3];
    sClientes clientemod;

    u_int num=3;
    u_int cant;
    cant=num;

    SECTION("Modificando un cliente")
    {
    for(u_int i = 0; i < 3; i++)
        cliente[i] = DefaultCliente[i];
//"Maria","Lopez","lopezmaria@gmail.com", "333-444-5555",{6,7,1996},123,1},

    clientemod.nombre="Maria";
    clientemod.apellido="Lopez";
    clientemod.mail="lopezmaria@gmail.com";
    clientemod.telefono="333-444-5555";
    clientemod.fechaNac.dia=6;
    clientemod.fechaNac.mes=7;
    clientemod.fechaNac.anio=1996;
    clientemod.estado=200;
    clientemod.idCliente=1;

    eModificar resul = modificarCliente(cliente, clientemod,"lopezmaria@gmail.com" , cant);
    REQUIRE(resul == 1);
    }
    delete[] cliente;
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
    clientes[3] = {"Valentina","Perez","valenPrez@gmial", "115-233-5643",{12,3,2006},0,4};
    clientes[4] = {"Marcos","Aguilar","Aguilar115@gmial", "120-465-3289",{6,7,1996},123,5};


    CHECK(ViejaDireccion != clientes);
    }
    delete[] clientes;
}

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
    delete[] cliente;
}

TEST_CASE("verificar espacio")
{
    u_int cantmax=6;
    u_int num=6;
    u_int cant;
    cant=num;
    REQUIRE(!espacio(cantmax,cant));
}



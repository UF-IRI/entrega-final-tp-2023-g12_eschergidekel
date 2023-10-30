#include <iostream>
#include <fstream>
#include <clientes.h>
#include <clases.h>
#include <archivo.h>

using namespace std;

int main() {
    int spinning[12]={45,0,45,0,45,0,0,0,45,0,45,0};
    int yoga[12]={0,25,25,25,0,0,0,25,25,0,0,25};
    int pilates[12]={15,15,15,0,15,0,0,0,0,0,15,15};
    int stretching[12]={40,0,0,0,0,0,40,40,40,0,40,40};
    int zumba[12]={50,0,50,0,50,0,0,0,50,50,50,0};
    int boxeo[12]={0,0,0,0,0,0,0,0,30,30,30,30};

    ifstream archiClientes, archiClases;
    archiClientes.open ("clientes.csv");
    archiClases.open ("clases.csv");
    int tam = 250;
    int opcion;
    cout << "1.Agregar un cliente" << endl;
    cout << "2.Actualizar un cliente" << endl;
    cout << "3.Eliminar un cliente" << endl;
    cout << "4.Reservar clase" << endl;
    cout << "5.Reservar musculacion" << endl;
    cout << "6.Cancelar clase" << endl;
    cout << "7.Cancelar musculacion" << endl;
    cout << "8.Salir";
    cin >> opcion;

    if(opcion == 1)
    {

    }

    if(opcion == 2)
    {

    }

    do
    {
        switch (opcion)
        {
        case 1: //agregar cliente
        {
            break;
        }
        case 2: //actualizar cliente
        {
            break;
        }
        case 3: //eliminar cliente
        {
            break;
        }
        case 4: //reservar clase
        {
            break;
        }
        case 5: //reservar musculacion
        {
            break;
        }
        case 6: //cancelar clase
        {
            break;
        }
        case 7: //cancelar musculacion
        {
            break;
        }
        }
    }while (opcion != 8);

    archiClientes.close();
    archiClases.close();
    return 0;
}

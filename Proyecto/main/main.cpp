#include <libreria.h>
#include <clientes.h>
#include <clases.h>
#include <archivo.h>
#include <libreria.h>
using namespace std;

int main()
{
    //archiclientes csv
    //archiclases csv

    ifstream archiClases("iriClasesGYM.csv");

    if(archiClases.is_open())
    {
       eCodArchivos result= leerArchivoClases(archiClases);
        if(result!=1)
           cout<<"hubo un error"<<endl;
    }
    int n=0;
    sClientes aux;
    sClientes* cliente;



        int spinning[12]={45,0,45,0,45,0,0,0,45,0,45,0};
        int yoga[12]={0,25,25,25,0,0,0,25,25,0,0,25};
        int pilates[12]={15,15,15,0,15,0,0,0,0,0,15,15};
        int stretching[12]={40,0,0,0,0,0,40,40,40,0,40,40};
        int zumba[12]={50,0,50,0,50,0,0,0,50,50,50,0};
        int boxeo[12]={0,0,0,0,0,0,0,0,30,30,30,30};
        int cantMaxima = 250; //inicialmente
        int cant = cantClientes(lecturaClientes);
        int nuevoTam = cant+30; //para agregar mas espacio hacemos un rezise
        cliente = resizeClientes(cliente, cant, nuevoTam);
        cantMaxima = nuevoTam;
        sClientes ultimo = cliente[cant-1];

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

        if(opcion == 1 || opcion==2)
        {
            cout << "Ingresar su nombre: " << endl;
            cin >> aux.nombre;
            cout << "Ingrese su apellido: " << endl;
            cin >> aux.apellido;
            cout << "Ingrese su telefono: " << endl;
            cin >> aux.telefono;
            cout << "Ingrese su DNI: " << endl;
            cin >> aux.dni;
            cout << "Ingrese su mail: " << endl;
            cin >> aux.mail;
            cout << "Ingrese su dia de nacimiento: " << endl;
            cin >> aux.fechaNac.dia;
            cout << "Ingrese su mes de nacimiento: " << endl;
            cin >> aux.fechaNac.mes;
            cout << "Ingrese su anio de nacimiento: " << endl;
            cin >> aux.fechaNac.anio;
            if(opcion==1)
            {
                aux.estado==0;
                aux.idCliente = (ultimo.idCliente) +1;
            } else
            {
                int pos= buscarCliente(cliente, aux.dni, cant);
                cout << "Ingrese su estado actual"<<endl;
                cin >> aux.estado;
                aux.idCliente= cliente[pos].idCliente; //el id sigue siendo el mismo
            }
        }

        if(opcion == 4 || opcion == 5)
        {
            str nombreClase, horario, dni;
            cout << "Ingrese su DNI: " << endl;
            cin >> dni;
            cout << "Ingrese la clase que desea reservar: " << endl;
            cin >> nombreClase;
            cout << "Ingrese el horario: " << endl;
            cin >> horario;
        }

        if(opcion == 6 || opcion == 7)
        {
            str nombreClase, horario, dni;
            cout << "Ingrese su DNI: " << endl;
            cin >> dni;
            cout << "Ingrese la clase que desea dar de baja: " << endl;
            cin >> nombreClase;
            cout << "Ingrese el horario: " << endl;
            cin >> horario;
        }

        do
        {
            switch (opcion)
            {
            case 1: //agregar cliente
            {
                eAgregar result1 = agregarCliente(cliente, aux, cant, cantMaxima);
                if(result1 == -1)
                    cout << "Hubo un error, porfavor vuelva a intentar." << endl;
                else
                    cout << "Se agrego con exito." << endl;
                break;
            }
            case 2: //actualizar cliente
            {
                eModificar result2 = modificarCliente(cliente, aux, aux.dni, cant);
                if(result2 == -1)
                    cout << "Hubo un error, porfavor vuelva a intentar." << endl;
                else
                    cout << "Se modifico con exito." << endl;
                break;
            }
            case 3: //eliminar cliente
            {
                str dni;
                cout << "Ingrese el dni del cliente a eliminar: " << endl;
                cin >> dni;
                int eliminar = eliminarCliente(cliente, dni, cant);
                break;
            }
            case 4: //reservar clase
            {
                str nombreClase, horario, dni;
                cout << "Ingrese su DNI: " << endl;
                cin >> dni;
                cout << "Ingrese la clase que desea reservar: " << endl;
                cin >> nombreClase;
                cout << "Ingrese el horario: " << endl;
                cin >> horario;
                int pos=buscarCliente(cliente, dni, cant);
                reservar result =clases(cliente[pos], Asistencia, nombreClase);
                if(nombreClase == 'Stretching' && horario == '8' && stretching[0]>0)
                {
                    stretching[0]-=stretching[0];
                    cout << "Clase reservada.";
                } else
                    cout << "No hay más cupos disponibles.";


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


    return 0;
}

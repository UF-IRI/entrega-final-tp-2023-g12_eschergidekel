#include <libreria.h>
#include <clientes.h>
#include <clases.h>
#include <archivo.h>
using namespace std;

int main()
{
    ofstream informe("informe.dat");
    ofstream archivoClientes("iriClientesGYM.csv");
    ofstream archivoClases("iriClasesGYM.csv");

    ifstream archiClases("iriClasesGYM.csv");
    ifstream archiClientes("iriClientesGYM.csv");
    ifstream archiAsistencia("AsistenciaGYM.dat");

    informe.open("informe.dat");
    archivoClientes.open("iriClientesGYM.csv");
    archivoClases.open("iriClasesGYM.csv");

    archiClases.open("iriClasesGYM.csv");
    archiClientes.open("iriClientesGYM.csv");
    archiAsistencia.open("AsistenciaGYM.dat");

    sClientes aux;
    sClientes* cliente;
    Asistencia* asistencia;
    Inscripcion* inscripcion;
    Clases* clase;

    if(archiClases.is_open() && archiClientes.is_open() && archiAsistencia.is_open())
    {
        int cant=cantClientes(archiClientes); //cantidad de clientes

        eCodArchivos result = leerArchivoClases(archiClases, clase);
        if(result != eCodArchivos::ExitoOperacion)
            cout << "Hubo un error." << endl;

        eCodArchivos result2 = leerArchivoClientes(archiClientes, cliente, cant);
        if(result2 != eCodArchivos::ExitoOperacion)
            cout << "Hubo un error." << endl;

        u_int nuevoTam = cant+30; //para agregar mas espacio hacemos un rezise
        cliente = resizeClientes(cliente, cant, nuevoTam);
        int cantMaxima = nuevoTam;
        sClientes ultimo = cliente[cant-1];

        int opcion;
        cout << "1.Agregar un cliente" << endl;
        cout << "2.Actualizar un cliente" << endl;
        cout << "3.Eliminar un cliente" << endl;
        cout << "4.Reservar clase" << endl;
        cout << "5.Cancelar clase" << endl;
        cout << "6.Generar informe de asistencia" << endl;
        cout << "7.Salir";
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
            aux.estado=0;
            aux.idCliente = (ultimo.idCliente) +1;
        } else
        {
            int pos = buscarCliente(archiClientes, cliente, aux.dni, cant);
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
                eAgregar result1 = agregarCliente(archiClientes, cliente, aux, cant, cantMaxima);
                if(result1 == -1)
                    cout << "Hubo un error, porfavor vuelva a intentar." << endl;
                else
                    cout << "Se agrego con exito." << endl;
                break;
            }
            case 2: //actualizar cliente
            {
                eModificar result2 = modificarCliente(archiClientes, cliente, aux, aux.dni, cant);
                if(result2 == -1)
                    cout << "Hubo un error, intente nuevamente." << endl;
                else
                    cout << "Se modifico con exito." << endl;
                break;
            }
            case 3: //eliminar cliente
            {
                str dni;
                cout << "Ingrese el dni del cliente a eliminar: " << endl;
                cin >> dni;
                int eliminar = eliminarCliente(archiClientes, cliente, dni, cant);
                if(eliminar == cant-1)
                    cout << "Cliente eliminado." << endl;
                else
                    cout << "Hubo un error, intente nuevamente." << endl;
                break;
            }
            case 4: //reservar clase
            {
                break;
            }
            case 5: //cancelar clase
            {
                break;
            }
            case 6: //generar informe
            {
                informe.open("informe.dat");
                if(informe.is_open())
                {
                    eCodArchivos resultados = informeAsistencia(informe, asistencia);
                    if(resultados == eCodArchivos::ExitoOperacion)
                        cout << "Informe realizado." << endl;
                    informe.close();
                }else
                    cout << "Hubo un errr al generar el informe." << endl;

                break;
            }
            }
        }while (opcion != 7);
        archiClientes.close();
        archiClases.close();
    } else
       cout << "Hubo algun error." << endl;

    return 0;
}

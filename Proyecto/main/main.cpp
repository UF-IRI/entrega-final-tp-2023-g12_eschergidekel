#include <libreria.h>
#include <clientes.h>
#include <clases.h>
#include <archivo.h>
using namespace std;

int main()
{
    //archiClientes csv
    //archiClases csv
    ofstream informe("informe.dat");//indicar que vamos a hacer con ek , binario
    ifstream archiClases("iriClasesGYM.csv");
    ifstream archiClientes("iriClientesGYM.csv");
    ifstream archiAsistencia("AsistenciaGYM.dat");
    informe.open();
    archiClases.open();
    archiClientes.open();
    archiAsistencia.open();

    sClientes aux;
    sClientes* cliente;
    Asistencia* asistencia;
    Inscripcion* inscripcion;
    Clases* clase;

    if(archiClases.is_open() && archiClientes.is_open())
    {
       eCodArchivos result = leerArchivoClases(archiClases, clase);
       if(result != eCodArchivos::ExitoOperacion)
        cout << "Hubo un error." << endl;

       eCodArchivos result2 = leerArchivoClientes(archiClientes, cliente);
       if(result2 != eCodArchivos::ExitoOperacion)
        cout << "Hubo un error." << endl;

       u_int cant=0; //funcion cantidad de clientes
       if(archiClientes.is_open())
       {
        while(archiClientes.good()) //Leer los datos desde el archivo CSV
        {
            str linea;
            getline(archiClientes, linea);
            cant++;
        }
        archiClientes.close();
       }

       u_int nuevoTam = cant+30; //para agregar mas espacio hacemos un rezise
       cliente = resizeClientes(cliente, cant, nuevoTam);
       cantMaxima = nuevoTam;
       sClientes ultimo = cliente[cant-1];

       int opcion;
       cout << "1.Agregar un cliente" << endl;
       cout << "2.Actualizar un cliente" << endl;
       cout << "3.Eliminar un cliente" << endl;
       cout << "4.Reservar clase" << endl;
       cout << "5.Cancelar clase" << endl;
       cout << "6.Salir";
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
            cout << "Cliente eliminado." << endl;
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
        }
       }while (opcion != 6);
       eCodArchivos resultados= informeAsistencia(informe, asistencia, inscripcion);
       archiClientes.close();
       archiClases.close();
    } else
       cout << "Hubo algun error." << endl;

    return 0;
}

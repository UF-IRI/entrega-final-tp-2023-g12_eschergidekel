#include <libreria.h>
#include <clientes.h>
#include <clases.h>
#include <archivo.h>
using namespace std;

int main()
{
    //archiClientes csv
    //archiClases csv

    fstream archiClases("iriClasesGYM.csv");
    fstream archiClientes("iriClientesGYM.csv");

    if(archiClases.is_open() && archiClientes.is_open())
    {
       eCodArchivos result = leerArchivoClases(archiClases);
       if(result != eCodArchivos::ExitoOperacion)
        cout << "Hubo un error." << endl;

       eCodArchivos result2 = leerArchivoClientes(archiClientes);
       if(result2 != eCodArchivos::ExitoOperacion)
        cout << "Hubo un error." << endl;
    }
    sClientes aux;
    sClientes* cliente;
    Asistencia* asistencia;
    Clases* clase;

    int Spinning[12]={45,0,45,0,45,0,0,0,45,0,45,0};
    int Yoga[12]={0,25,25,25,0,0,0,25,25,0,0,25};
    int Pilates[12]={15,15,15,0,15,0,0,0,0,0,15,15};
    int Stretching[12]={40,0,0,0,0,0,40,40,40,0,40,40};
    int Zumba[12]={50,0,50,0,50,0,0,0,50,50,50,0};
    int Boxeo[12]={0,0,0,0,0,0,0,0,30,30,30,30};
    int cantMaxima = 250; //inicialmente

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
            str dni;
            Clases auxclase;
            int cont=0;
            int pos2;
            cout << "Ingrese su DNI: " << endl;
            cin >> dni;
            cout << "Ingrese la clase que desea reservar: " << endl;
            cin >> auxclase.nombreClase;
            cout << "Ingrese el horario: " << endl;
            cin >> auxclase.horarioClase;
            int pos=buscarCliente(cliente, dni, cant);
            Reservas result = clases(cliente[pos], asistencia,auxclase , cant);
            if(result != reservar::ErrR)
            {
                for(int i=0; i<cant; i++)
                {
                    if(clase[i].nombreClase==auxclase.nombreClase && clase[i].horarioClase==auxclase.horarioClase)
                    {
                        cont++;
                        pos2=i;
                    }
                }
                if(cont>0 && clase[pos2].nombreClase=="Spinning" && cont<45)
                {
                    if(clase[pos2].horarioClase == '8')
                        Spinning[0]=Spinning[0]-1;
                    if(clase[pos2].horarioClase == '10')
                        Spinning[2]=Spinning[2]-1;
                    if(clase[pos2].horarioClase == '12')
                        Spinning[4]=Spinning[4]-1;
                    if(clase[pos2].horarioClase == '16')
                        Spinning[8]=Spinning[8]-1;
                    if(clase[pos2].horarioClase == '18')
                        Spinning[10]=Spinning[10]-1;
                }else
                    cout << "No hay cupos disponibles." << endl;
                if(cont>0 && clase[pos2].nombreClase=="Yoga" && cont<25)
                {
                    if(clase[pos2].horarioClase == '9')
                       Yoga[1]=Yoga[1]-1;
                    if(clase[pos2].horarioClase == '10')
                        Yoga[2]=Yoga[2]-1;
                    if(clase[pos2].horarioClase == '11')
                        Yoga[3]=Yoga[3]-1;
                    if(clase[pos2].horarioClase == '15')
                        Yoga[7]=Yoga[7]-1;
                    if(clase[pos2].horarioClase == '16')
                        Yoga[8]=Yoga[8]-1;
                    if(clase[pos2].horarioClase == '19')
                        Yoga[11]=Yoga[11]-1;
                }else
                    cout << "No hay cupos disponibles." << endl;
                if(cont>0 && clase[pos2].nombreClase=="Pilates" && cont<25)
                {
                    if(clase[pos2].horarioClase == '8')
                        Pilates[0]=Pilates[0]-1;
                    if(clase[pos2].horarioClase == '9')
                        Pilates[1]=Pilates[1]-1;
                    if(clase[pos2].horarioClase == '10')
                        Pilates[2]=Pilates[2]-1;
                    if(clase[pos2].horarioClase == '12')
                        Pilates[4]=Pilates[4]-1;
                    if(clase[pos2].horarioClase == '18')
                        Pilates[10]=Pilates[10]-1;
                    if(clase[pos2].horarioClase == '19')
                        Pilates[11]=Pilates[11]-1;
                }else
                    cout << "No hay cupos disponibles." << endl;
                if(cont>0 && clase[pos2].nombreClase=="Stretching" && cont<40)
                {
                    if(clase[pos2].horarioClase == '8')
                        Stretching[0]=Stretching[0]-1;
                    if(clase[pos2].horarioClase == '14')
                        Stretching[6]=Stretching[6]-1;
                    if(clase[pos2].horarioClase == '15')
                        Stretching[7]=Stretching[7]-1;
                    if(clase[pos2].horarioClase == '16')
                        Stretching[8]=Stretching[8]-1;
                    if(clase[pos2].horarioClase == '18')
                        Stretching[10]=Stretching[10]-1;
                    if(clase[pos2].horarioClase == '19')
                        Stretching[11]=Stretching[11]-1;
                }else
                    cout << "No hay cupos disponibles." << endl;
            }
            if(cont>0 && clase[pos2].nombreClase=="Zumba" && cont<50)
            {
                if(clase[pos2].horarioClase == '8')
                    Zumba[0]=Zumba[0]-1;
                if(clase[pos2].horarioClase == '10')
                    Zumba[2]=Zumba[2]-1;
                if(clase[pos2].horarioClase == '12')
                    Zumba[4]=Zumba[4]-1;
                if(clase[pos2].horarioClase == '16')
                    Zumba[8]=Zumba[8]-1;
                if(clase[pos2].horarioClase == '17')
                    Zumba[9]=Zumba[9]-1;
                if(clase[pos2].horarioClase == '18')
                    Zumba[10]=Zumba[10]-1;
            }else
                cout << "No hay cupos disponibles." << endl;
            if(cont>0 && clase[pos2].nombreClase=="Boxeo" && cont<30)
            {
                if(clase[pos2].horarioClase == '16')
                    Boxeo[8]=Boxeo[8]-1;
                if(clase[pos2].horarioClase == '17')
                    Boxeo[9]=Boxeo[9]-1;
                if(clase[pos2].horarioClase == '18')
                    Boxeo[10]=Boxeo[10]-1;
                if(clase[pos2].horarioClase == '19')
                    Boxeo[11]=Boxeo[11]-1;
            }else
                cout << "No hay cupos disponibles." << endl;
            break;
        }
        case 5: //cancelar clase
        {
            break;
        }
        }
    }while (opcion != 6);


    return 0;
}

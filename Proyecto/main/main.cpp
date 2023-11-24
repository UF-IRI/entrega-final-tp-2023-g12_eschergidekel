#include "archivo.h"
using namespace std;

int main()
{
    ofstream informe;

    ifstream archiClases;
    ifstream archiClientes;
    ifstream archiAsistencia;

    informe.open("informe.dat",ios::binary);
    archiClases.open("iriClasesGYM.csv",ios::in);
    archiClientes.open("iriClientesGYM.csv");
    archiAsistencia.open("asistencias_1697673600000.dat",ios::binary);

    sClientes aux;
    sClientes* cliente;
    Asistencia* asistencia;
    Inscripcion* inscripcion;
    Clases* clase;
    u_int cantidad=cantClientes(archiClientes); //cantidad de clientes, lo paso como variable global para que los cambios se reflejen en todo el programa
    u_int *cant;
    cant=&cantidad;
    u_int cantAsistencia=0;
    if(archiClases.is_open() && archiClientes.is_open() && archiAsistencia.is_open())
    {
        eCodArchivos result = leerArchivoClases(archiClases, clase);
        if(result != eCodArchivos::ExitoOperacion)
           cout << "Hubo un error." << endl;

        eCodArchivos result2 = leerArchivoClientes(archiClientes, cliente, cant);
        if(result2 != eCodArchivos::ExitoOperacion)
           cout << "Hubo un error." << endl;

        eCodArchivos result3 = leerArchivoAsistencia(archiAsistencia, asistencia, cantAsistencia);
        if(result3 != eCodArchivos::ExitoOperacion)
           cout << "Huno un error." << endl;

        u_int nuevoTam = *cant+30; //para agregar mas espacio hacemos un rezise
        cliente = resizeClientes(cliente, *cant, nuevoTam);
        int cantMaxima = nuevoTam;
        sClientes ultimo = cliente[(*cant)-1];
        u_int cantMaxAsistencia = cantAsistencia+30;
        u_int cantMaxInscripciones = (asistencia->cantInscriptos)+30;
        int opcion;
        cout << "1.Agregar un cliente" << endl;
        cout << "2.Actualizar un cliente" << endl;
        cout << "3.Eliminar un cliente" << endl;
        cout << "4.Reservar clase" << endl;
        cout << "5.Cancelar clase" << endl;
        cout << "6.Generar informe de asistencia" << endl;//?
        cout << "7.Salir";
        cin >> opcion;

        if(opcion == 1)
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
            aux.estado=0;
            aux.idCliente = (ultimo.idCliente) +1;
        }

        if(opcion==2)//modificar
        {
           int pos = buscarCliente(cliente, aux.dni, *cant);
           cout << "Ingrese su estado actual"<<endl;
           cin >> aux.estado;
           aux.idCliente= cliente[pos].idCliente; //el id sigue siendo el mismo
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

        if(opcion == 5)
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

                    eAgregar result1 = agregarCliente(cliente, aux, *cant, cantMaxima);
                    if(result1 == -1)
                        cout << "Hubo un error, porfavor vuelva a intentar." << endl;
                    else
                        cout << "Se agrego con exito." << endl;
                    break;
                }
                case 2: //actualizar cliente
                {
                    eModificar result2 = modificarCliente(cliente, aux, aux.dni, *cant);
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
                    u_int eliminar = eliminarCliente(cliente, dni, *cant);
                    if(eliminar == (*cant)-1)
                        cout << "Cliente eliminado." << endl;
                    else
                        cout << "Hubo un error, intente nuevamente." << endl;
                    break;
                }
                case 4: //reservar clase
                {
                    /*Reservas clases(ifstream &archiClases, ifstream &archiClientes, ifstream &archiAsistencia, ofstream &informe,
                    sClientes cliente, Asistencia* asistencia, Clases clase, int cantClientes); */
                    str nombreClase, dni;
                    u_int horario;
                    cout << "Ingrese su DNI: " << endl;
                    cin >> dni;
                    cout << "Ingrese la clase que desea reservar: " << endl;
                    cin >> nombreClase;
                    cout << "Ingrese el horario: " << endl;
                    cin >> horario;

                    int pos=0;
                    int posCliente=0;
                    u_int id = buscarCliente(cliente, dni, *cant);
                    for(u_int i=0;i<*cant;i++)
                    {
                        if(cliente[i].idCliente == id)
                            posCliente=i;
                    }
                    for(int i=0;i<33;i++){
                        if(clase[i].nombreClase==nombreClase && clase[i].horarioClase==horario)
                            pos=i;
                    }
                    Reservas lugares= clases(cliente[pos], asistencia,clase,*cant, nombreClase, horario);
                    if(lugares !=1)
                        cout<<"No hay lugar para dicha clase para ese horario"<<endl;

                    if(!espacioAsistencias(cantMaxAsistencia,cantAsistencia))
                       asistencia= resizeAsistencia(asistencia,cantAsistencia, cantMaxAsistencia);
                    if(!espacioInscripciones(asistencia,cantMaxInscripciones))
                       inscripcion=resizeInscripcion(inscripcion,asistencia->cantInscriptos,cantMaxInscripciones);

                    Inscripto resul = estaInscriptoClases(asistencia, clase, nombreClase, horario);
                    if(resul==1){
                        for(u_int i=0; i<*cant; i++)
                        {
                            if(asistencia[i].idCliente==id)
                            {
                                asistencia[i].cantInscriptos=(asistencia[i].cantInscriptos)+1;
                                asistencia[i].CursosInscriptos[0].idCurso=clase[pos].idClase;
                            }
                        }
                    }else//si ya tiene cursos inscriptos me fijo que no esten superpuestos
                    {
                        superposicion resul2 = superposicionHorarios(asistencia, clase, id, cantidad, nombreClase, horario);
                        if(resul2==1)
                        {
                            for(u_int i=0;i<*cant;i++)
                            {
                                if(asistencia[i].idCliente==id)
                                {
                                    asistencia[i].cantInscriptos=(asistencia[i].cantInscriptos)+1;
                                    asistencia[i].CursosInscriptos[(asistencia->cantInscriptos)-1].idCurso=clase[i].idClase; //fijarme que posicion esoty ocupando en cursosinscriptos

                                }
                            }
                        }else//si esta inscripto y superpuesto
                        {
                            string respuesta;
                            cout << "Usted ya tiene una reserva programada para dicho horario." << endl;
                            cout << "¿Desea cancelarla?" << endl;
                            cout << "Ingrese 'Si' en caso de querer cancelarla, o 'No' en caso de no desearlo: " << endl;
                            cin >> respuesta;
                            if(respuesta == "Si"){
                                Baja cancelar= cancelarClase(asistencia, clase[pos].idClase, *cant);
                                if(cancelar==1)
                                {
                                    cout << "Su reserva se cancelo con exito." << endl;
                                    for(u_int i=0; i<*cant; i++)
                                    {
                                        if(asistencia[i].idCliente==id)
                                        {
                                            asistencia[i].cantInscriptos=(asistencia[i].cantInscriptos)+1;
                                            asistencia[i].CursosInscriptos[i].idCurso=clase[i].idClase; //fijarme que posicion estoy ocupando en cursosinscriptos
                                        }
                                    }
                                    cout << "Su clase nueva ya fue reservada." << endl;
                                }
                                else
                                    cout << "Hubo problemas para cancelar su clase." << endl;
                            }
                            else if(respuesta == "No")
                                cout << "Su reserva no ha sido modificada." << endl;
                        }
                    }
                }
                case 5: //cancelar clase
                {
                    string nombre;
                    u_int horario;
                    int pos;
                    cout<<"Ingrese el nombre de la clase que desea cancelar"<<endl;
                    cin>>nombre;
                    cout<<"Ingrese el horario de la clase que desea cancelar"<<endl;
                    cin>>horario;

                    for(u_int i=0; i<*cant; i++)
                    {
                        if(clase[i].nombreClase==nombre && clase[i].horarioClase==horario)
                            pos=i;
                    }
                    Baja cancelar=cancelarClase(asistencia, clase[pos].idClase, *cant);
                    if(cancelar==1)
                        cout<<"Su clase fue cancelada con exito"<<endl;
                    else
                        cout<<"Hubco un error al cancelar su clase"<<endl;
                    break;
                }
                case 6: //generar informe
                {
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
        } while (opcion != 7);

        informe.close();
        archiAsistencia.close();
        archiClientes.close();
        archiClases.close();
    }else
        cout << "Hubo algun error.1" << endl;

    return 0;
}

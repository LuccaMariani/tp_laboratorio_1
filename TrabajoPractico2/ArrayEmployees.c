#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bibliotecas.h"
#include "ArrayEmployees.h"

#define TAM 1000

int initEmployees(sEmployee listado[], int len)
{
    //      Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
    //      (isEmpty) en TRUE en todas las posiciones del array.
    int error = 1;

    if(listado != NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            listado[i].isEmpty = 1;
        }
        error=0;
    }

    return error; //Retorna 1 si hubo algun error en la ejecucion de la funcion
}

int addEmployee(sEmployee listado[], int len, int id)
{
    //      Agrega en un array de empleados existente los valores recibidos
    //      como parámetro en la primer posición libre.

    int error=1;
    int lugarLibre;
    int confirma;

    sEmployee newEmployee;


    if(listado != NULL && len > 0)
    {
        //hay lugar en la lista?
        lugarLibre = findEmptyEmployee(listado, len, id);

        if( lugarLibre > -1)
        {
            //  si hay pedis datos
            printf("\n- Ingrese los datos para el nuevo Empleado.\n\n> Legajo: %d", id);
            newEmployee.id=id;

            printf("\n> Nombre: ");
            fflush(stdin);
            gets(newEmployee.name);

            while(validacionCadenaCaracteres(newEmployee.name))
            {
                printf("- Solo se permiten letras en el Nombre.\n");
                printf("> Nombre: ");
                fflush(stdin);
                gets(newEmployee.name);

            }

            printf("> Apellido: ");
            fflush(stdin);
            gets(newEmployee.lastName);
            while(validacionCadenaCaracteres(newEmployee.lastName))
            {
                printf("- Solo se permiten letras en el Apellido.\n");
                printf("> Apellido: ");
                fflush(stdin);
                gets(newEmployee.lastName);
            }

            printf("> Salario: ");
            fflush(stdin);
            scanf("%f", &newEmployee.salary);

            printf("> Sector: ");
            fflush(stdin);
            scanf("%d", &newEmployee.sector);

            while(newEmployee.sector<0)
            {
                printf("- Solo se permiten numeros positivos en el sector.\n");
                printf("> Sector: ");
                fflush(stdin);
                scanf("%d", &newEmployee.sector);
            }

            printf("\n> Confirma el ingreso de datos en este nuevo empelado? (Si = 1) (No = 0)\n> ");
            fflush(stdin);
            scanf("%d",&confirma);
            while(confirma>1 || confirma<0 || isalpha(confirma)!=0)
            {
                printf("\n> Confirma el ingreso de datos en este nuevo empelado? (Si = 1) (No = 0)\n> ");
                fflush(stdin);
                scanf("%d",&confirma);
            }

            newEmployee.isEmpty=0;

            if(confirma==1)
            {
                //  insertarlos en el lugar libre
                listado[lugarLibre]= newEmployee;
                printf("\n- Se dio de alta correctamente al empleado");
                error=1;
            }
            else
            {
                printf("- Se cancelo correctamente el alta del empleado");
                error=-1;
            }
        }
        else
        {
            //  no hay lugar
            printf("\n- No hay lugar para cargar un Empleado.\n");
            error=-2;
        }
    }

    return error;
}

int findEmptyEmployee(sEmployee listado[], int len,int id)
{
    int lugarLibre=0;

    for(int i=0; i<len; i++)
    {
        if(listado[i].isEmpty == 1)
        {
            lugarLibre=i;
            break;
        }
        else
        {
            lugarLibre=-1;
        }
    }

    return lugarLibre; // Retorna un numero positivo del lugar libre, y si no hay ningun lugar libre, devuelve -1
}

int EmptyEmployeeList(sEmployee listado[], int len)
{
    int listadoVacio=1;

    for(int i=0; i<len; i++)
    {
        if(listado[i].isEmpty == 0)
        {
            listadoVacio=0;
            break;
        }
    }

    return listadoVacio; // retorna un si=1 la lista esta vacia, sino un 0 (osea que si hay gente).
}


int findEmployeeById(sEmployee listado[], int len,int id)
{
    //  Busca un empleado recibiendo como parámetro de búsqueda su Id.
    int lugarEmployee=0;

    for(int i=0; i<len; i++)
    {

        if( listado[i].id==id && listado[i].isEmpty == 0)
        {
            lugarEmployee=i;
            //printf("\nPersona Encontrada!\n");
            break;
        }
        else
        {
            //printf("\nPersona no encontrado!\n");
            lugarEmployee=-1;
        }
    }

    return lugarEmployee;
}


int removeEmployee(sEmployee listado[], int len, int id)
{
    //      Elimina de manera lógica (isEmpty Flag en 1)
    //      un empleado recibiendo como parámetro su Id.

    int lugarEmployee;
    int respuesta;
    int error = 1;

    if(listado != NULL && len > 0 && id > 0)
    {
        printEmployees(listado,len);
        printf("\n> Ingrese id del empleado a dar de baja: ");
        fflush(stdin);
        scanf("%d",&id);

        lugarEmployee = findEmployeeById(listado,len,id);

        if(lugarEmployee == -1)
        {
            printf("\n- No hay ninguna persona con ese id.\n\n");
        }
        else
        {
            printf("\n- Empleado a dar de baja: ");
            mostrarEmployee(listado[lugarEmployee]);

            printf("\n- Confirma baja de este empleado ? (Si = 1) (No = 0)\n > ");
            fflush(stdin);
            scanf("%d",&respuesta);

            if(respuesta)
            {
                listado[lugarEmployee].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = -2;
            }
        }
    }

    return error;
}


int sortEmployees(sEmployee listado[], int len, int order)
{
    //      Ordena el array de empleados por apellido
    //      y sector de manera ascendente o descendente
    sEmployee auxEmployee;

    if(order)// order == 1
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                //criterio+condicion de ordenamiento dentro del if > o <
                if(strcmp(listado[i].lastName,listado[j].lastName) > 0)
                {
                    auxEmployee=listado[i];
                    listado[i]=listado[j];
                    listado[j]=auxEmployee;
                }
                //criterio+condicion de ordenamiento dentro del if > o <
                if(listado[i].sector>listado[j].sector)
                {
                    auxEmployee=listado[i];
                    listado[i]=listado[j];
                    listado[j]=auxEmployee;
                }
            }
        }
    }
    else// order != 1
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i + 1; j < len; j++)
            {
                //criterio+condicion de ordenamiento dentro del if > o <
                if(strcmp(listado[i].lastName,listado[j].lastName) < 0)
                {
                    auxEmployee=listado[i];
                    listado[i]=listado[j];
                    listado[j]=auxEmployee;
                }
                //criterio+condicion de ordenamiento dentro del if > o <
                if(listado[i].sector<listado[j].sector)
                {
                    auxEmployee=listado[i];
                    listado[i]=listado[j];
                    listado[j]=auxEmployee;
                }
            }
        }
    }
    return 0;
}


int printEmployees(sEmployee listado[], int len)
{
    //      Imprime el array de empleados de forma encolumnada.
    int error = 1;

    if(listado!= NULL && len>0)
    {
        system("cls");
        printf("\n       * LISTADO EMPLEADOS *\n");
        printf("\n  Legajo |     Nombre |    Apellido |   Salario |  Sector\n");
        printf("---------|------------|-------------|-----------|---------\n");

        //codigo de la funcion mostrar persona + repeticiones para imprimir toda la lista de empleados
        for(int i=0; i<len; i++)
        {

            if(listado[i].isEmpty == 0)
            {
                mostrarEmployee(listado[i]);
                printf("---------|------------|-------------|-----------|---------\n");
            }
        }

        error=0;
    }
    return error;
}


void mostrarEmployee(sEmployee oneEmployee)
{
    printf("    %d | %10s |  %10s | %9.2f | %4d \n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, oneEmployee.sector);
}

int modificarEmployee(sEmployee listado[], int len)
{

    int id;
    int lugarEmployee;
    int error=1;

    int cancelacion;
    int respuestaModificacion;
    int respuesta=1;
    int confirmacionModificacion;

    sEmployee modificacionEmployee;

    if(listado != NULL && len > 0 )
    {
        // 1 mostrar lista de empleados
        printEmployees(listado, len);

        // 2 buscar un empleado por id
        printf("\n> Ingrese id del empleado a modificar: ");
        fflush(stdin);
        scanf("%d",&id);

        lugarEmployee = findEmployeeById(listado,len,id);

        if(lugarEmployee == -1)
        {
            printf("\n- No hay ninguna persona con ese id.\n\n");
        }
        else
        {
            printf("\n- Empleado a modificar: ");
            mostrarEmployee(listado[lugarEmployee]);

            //todos los datos de el empleado seleccionado, se sobreescriben
            // en el empleado auxiliar, para que luego no se superpongan los datos
            modificacionEmployee= listado[lugarEmployee];

            while(respuesta)//repuesta==1
            {

                // 3 elejir que queremos cambiar en el empleado
                printf("\n- Que desea modificar en el empleado?\n 1) Nombre\n 2) Apellido\n 3) Salario\n 4) Sector\n 5) Cancelar\n > ");
                fflush(stdin);
                scanf("%d",&respuestaModificacion);
                while(respuestaModificacion>5 || respuestaModificacion<1 || isalpha(respuestaModificacion)!=0)
                {
                    printf("- Ingrese un valor correcto.\n");
                    fflush(stdin);
                    scanf("%d",&respuestaModificacion);
                }
                switch(respuestaModificacion)
                {
                    case 1:
                        printf("\n> Nombre: ");
                        fflush(stdin);
                        gets(modificacionEmployee.name);
                        while(validacionCadenaCaracteres(modificacionEmployee.name))
                        {
                            printf("- Solo se permiten letras en el Nombre.\n");
                            printf("> Nombre: ");
                            fflush(stdin);
                            gets(modificacionEmployee.name);
                        }
                        break;
                    case 2:
                        printf("\n> Apellido: ");
                        fflush(stdin);
                        gets(modificacionEmployee.lastName);
                        while(validacionCadenaCaracteres(modificacionEmployee.lastName))
                        {
                            printf("- Solo se permiten letras en el Apellido.\n");
                            printf("> Apellido: ");
                            fflush(stdin);
                            gets(modificacionEmployee.lastName);
                        }
                        break;
                    case 3:
                        printf("\n> Salario: ");
                        fflush(stdin);
                        scanf("%f", &modificacionEmployee.salary);
                        break;
                    case 4:
                        printf("\n> Sector: ");
                        fflush(stdin);
                        scanf("%d", &modificacionEmployee.sector);
                        while(modificacionEmployee.sector<0 || isalpha(modificacionEmployee.sector)!=0)
                        {
                            printf("- Solo se permiten numeros en el Sector.\n");
                            printf("> Sector: ");
                            fflush(stdin);
                            scanf("%d", &modificacionEmployee.sector);
                        }
                        break;
                    default:
                        printf("\n- Confirma la cancelacion en la modificacion del empleado? (Si = 1) (No = 0)\n > ");
                        fflush(stdin);
                        scanf("%d", &cancelacion);
                        if(cancelacion)
                        {
                            printf("\n- Se cancelo la modificacion del empleado.");
                            error=1;
                            return error;
                        }
                        break;
                }
                // 5 preguntar si se queire cambiar algo mas, si dice que si volvemos al punto 3
                printf("\n- El empleado modificado resultante: ");
                mostrarEmployee(modificacionEmployee);

                printf("\n- Desea modificar otro dato del empleado ? (Si = 1) (No = 0)\n > ");
                fflush(stdin);
                scanf("%d",&respuesta);
                while(respuesta>1 || respuesta<0 || isalpha(respuesta)!=0)
                {
                    printf("\n- Desea modificar otro dato del empleado ? (Si = 1) (No = 0)\n > ");
                    fflush(stdin);
                    scanf("%d",&respuesta);
                }
            }

            printf("\n- Confirma la modificacion en el empleado ? (Si = 1) (No = 0)\n > ");
            fflush(stdin);
            scanf("%d",&confirmacionModificacion);

            if(confirmacionModificacion)
            {
                // 4 tomar ese dato y rempleazarlo en el empleado
                listado[lugarEmployee]=modificacionEmployee;
                error=0;
            }
            else
            {
                printf("\n- Se cancelo la modificacion del empleado.");
                error=1;
            }
        }
    }
    return error;
}

int printEmployeeSalary(sEmployee listado[], int len)
{
    int error;

    float acumulacionSalarios=0;
    int contadorSalarios=0;
    int contadorEmpleadosMuchoSalario=0;

    float promedioSalarios;

    if(listado!= NULL && len>0)
    {
        system("cls");
        printf("\n     * SALARIOS *\n");
        printf("\n   Total       |    Promedio    |   Empleados con Salario mas alto al promedio \n");
        printf("---------------|----------------|----------------------------------------------\n");

        //codigo de la funcion para buscar lugares con empleados + repeticiones.
        for(int i=0; i<len; i++)
        {
            if(listado[i].isEmpty == 0)
            {
                acumulacionSalarios = acumulacionSalarios + listado[i].salary;
                contadorSalarios++;
            }
        }
        //promedio de salarios
        promedioSalarios = (float) acumulacionSalarios/contadorSalarios;

        for(int i=0; i<len; i++)
        {
            if((listado[i].isEmpty == 0) && (promedioSalarios < listado[i].salary))
            {
                contadorEmpleadosMuchoSalario++;
            }
        }

        printf(" %13.2f |   %12.2f |      %d \n", acumulacionSalarios, promedioSalarios, contadorEmpleadosMuchoSalario);
        printf("---------------|----------------|----------------------------------------------\n");

        error=0;
    }
    else
    {
        error=1;
    }
    return error;
}

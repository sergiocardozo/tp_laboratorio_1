#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"

int initEmployees (Employee* list, int len)
{

	int i;
	    int ret= -1;
	    if(list!=NULL&&len>0)
	    {
	        for(i=0;i<len;i++)
	        {
	            list[i].id=0;
	            list[i].isEmpty = 0;
	            strcpy(list[i].name,"");
	            strcpy(list[i].lastName,"");
	            list[i].salary=0;
	            list[i].sector=0;
	        }
	        ret=0;
	    }
	    return ret;
}

int findEmptySpace (Employee* list, int len)
{
    int ret = -1;
    int i;

    for (i=1; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int existEmployees(Employee* list, int len)
{
	int ret = -1;
    int i;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            ret = 0;
        }
    }
    return ret;
}

int addEmployee (Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    list[id].id = id;
    strcpy(list[id].name, name);
    strcpy(list[id].lastName, lastName);
    list[id].salary = salary;
    list[id].sector = sector;
    list[id].isEmpty = 1;
    return id;
}
int controllerGetEmployee(Employee* list, int len)
{
	char auxNombre[50];
	char auxApellido[50];
	float auxSalario;
	int auxSector;
	int ret = -1;
	int espacioLibre;
	espacioLibre = findEmptySpace(list,len);

	if(espacioLibre != -1)
	{
		getValidString("\nIngrese Nombre: ","\nNo es un nombre valido","\nLongitud maxima 50", auxNombre,50,3);
		getValidString("\nIngrese Apellido: ","\nNo es un apellido valido","\nLongitud maxima 50",auxApellido,50,3);
		auxSalario = getValidFloat("\nIngrese nuevo salario: ", "\nError, ingrese solo numeros: ", 1, 10000000);
		auxSector = getValidInt("\nIngrese nuevo sector: ", "\nError, ingrese solo numeros: ",&auxSector,1,1000,3);

		addEmployee(list, len, espacioLibre, auxNombre, auxApellido, auxSalario, auxSector);
	}
	else
	{
		printf("No se pueden cargar mas empleados ");
	}
	return ret;
}

int modifyEmployee (Employee* list, int len)
{
    int ret = -1;
    int modify;
    int findEmployee;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int id;

    printf("Ingrese ID de empleado a modificar: ");
    scanf("%d", &id);

    findEmployee = findEmployeeById(list, len, id);

    if (findEmployee > 0)
    {
        do
        {
            printf("\n---------------------------------------- \n");
            printf("1- Nombre \n2- Apellido \n3- Salario \n4- Sector \n5- Salir de modificaciones  \n");
            printf("------------------------------------------ \n");
            scanf("%d", &modify);

            switch(modify)
            {
            case 1:
            	getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 50", auxName,50,3);
                strcpy(list[findEmployee].name, auxName);
                break;
            case 2:
                getValidString("\nIngrese Apellido: ","\nNo es un apellido valido","\nLongitud maxima 50",auxLastName,50,3);
                strcpy(list[findEmployee].lastName, auxLastName);
                break;
            case 3:
                auxSalary = getValidFloat("\nIngrese nuevo salario: ", "\nError, ingrese solo numeros: ", 0, 10000000);
                list[findEmployee].salary = auxSalary;
                break;
            case 4:
                auxSector = getValidInt("\nIngrese nuevo sector: ", "\nError, ingrese solo numeros: ",&auxSector,1,1000,3);
                list[findEmployee].sector = auxSector;
                break;
            case 5:
            	break;
            default:
                printf("Ingrese una opcion del 1 al 5: ");
            }
        }while (modify != 5);

        printf("Se han realizado las modificaciones correctamente \n");
    }
    else
    {
        printf("No se encontro empleado con ese ID \n");
    }
   return ret;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int ret = -1;
    int i;

    if (list != NULL && len > 0)
    {
        for (i=1; i<len; i++)
        {
            if (list[i].isEmpty == 1 && list[i].id == id)
            {
                return i;
            }
        }
    }
    return ret;
}

int removeEmployee (Employee* list, int len, int id)
{
    int findEmployee;

    findEmployee = findEmployeeById(list, len, id);

    if (findEmployee > 0)
    {
        list[findEmployee].isEmpty = -1;
        printf("Empleado eliminado con exito \n");
    }
    else
    {
        printf("No se ha encontrado empleado con ese ID \n");
    }

    return findEmployee;
}

int getDeleteEmployee(Employee* list,int len)
{
    int ret=-1;
    int auxId;
    getValidInt("\nIngrese id: ","\nValor invalido",&auxId,0,9999,10);
    if(findEmployeeById(list,len,auxId)>=0)
    {
        removeEmployee(list,len,auxId);
        ret=0;
    }
    else
    {
        printf("\nId invalido");
    }
    return ret;
}


int printEmployees (Employee* list, int len)
{
    int ret = -1;
    int i;

    if(len > 0)
    {
        printf("ID\tNombre\t\tApellido\t\tSalario\t\tSector \n");

        for(i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1)
            {

                printf("%d\t%s\t\t%s\t\t%.2f\t\t%d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        ret = 0;
    }
    return ret;
}

int sortEmployeeByName(Employee* list, int len, int order)
{
    int ret = -1;

    Employee auxiliar;

    if(len > 0 && list != NULL)
    {
        switch(order)
        {
            case 1:
                if(len > 0 && list != NULL)
                {
                    for(int i=0; i<len - 1; i++)
                    {
                        for(int j=i+1; j<len; j++)
                        {
                            if(strcmp(list[j].lastName, list[i].lastName) < 0)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                            else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                    }
                ret = 0;
                break;
            case 2:
                for(int i = 0; i < len - 1; i++)
                {
                    for(int j = i + 1; j < len; j++)
                    {
                        if(strcmp(list[j].lastName, list[i].lastName) > 0)
                        {
                            auxiliar = list[i];
                            list[i] = list[j];
                            list[j] = auxiliar;
                        }
                        else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
                        {
                            auxiliar = list[i];
                            list[i] = list[j];
                            list[j] = auxiliar;
                        }
                    }
                }
                ret = 0;
                break;
            default:
                printf("Ingrese 1 para ascendente o 2 para descendente \n");
            }
        }
    }
    return ret;
}

void averageEmployeesSalary (Employee* list, int len)
{
    float average = 0;
    float total = 0;
    int employeeCounter = 0;
    int salaryGreaterThanAverage = 0;
    int i;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            employeeCounter ++;
            total = total + list[i].salary;
        }
    }
    average = total / employeeCounter ;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].salary >average)
        {
            salaryGreaterThanAverage ++;
        }
    }

    printf("Total de salarios: %.2f \n", total);
    printf("Promedio de salarios: %.2f \n", average);
    printf("Cantidad de empleados con salario mayor al promedio: %d \n", salaryGreaterThanAverage);

}

void informesEmployees(Employee* list, int len)
{
	int opcionInf;
	int order;
	do
	{
		printf("/-----------------\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n"
				"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n3.SALIR");
		getValidInt("\nSelecione una opcion: ","\nOpcion invalida",&opcionInf,1,3,10);
		switch(opcionInf)
		{
		case 1:
			printf("Defina el orden de los empleados \n");
			printf("1- Ascendente \n2- Descendente \n");
			getValidInt("\nSelecione una opcion: ","\nOpcion invalida",&order,1,3,10);
			sortEmployeeByName(list, len, order);
			printEmployees(list, len);
			break;
		case 2:
			averageEmployeesSalary (list, len);
			break;
		case 3:
			printf("\n Saliendo de modificaciones");
			break;
		default:
			printf("\n Ingrese una opcion de 1 a 3 ");
		}
	}while(opcionInf != 3);

}

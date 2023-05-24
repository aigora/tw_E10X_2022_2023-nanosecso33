#include <stdio.h>
#include <string.h>

void buscarPorTipo(FILE *pf, int opcion5);

int main()
{
	system("cls");
	printf("Acaba de ingresar en la pagina de datos de 2021 y 2022 de la Red Electrica Espanola.\nEn esta pagina podra consultar la energia generada mensualmente por cada seccion.\n\n");
	printf("Seleccione que opcion quiere llevar a cabo:\n\n");
	printf("1. Cargar el fichero para analizar y consultar los datos.\n");
	printf("2. No acceder a los datos.\n\n");
	printf("Opcion a escoger: ");
	int opcion /*esta opcion es para cargar el fichero o no*/, opcion2 /*esta opcion es para volver al inicio o terminar definitivamente el programa*/;
	scanf("%i", &opcion);
	switch(opcion)
	{
		case 1:
			system("cls");
			printf("Cargando fichero...\n");
			break;
		case 2:
			system("cls");
			printf("Ha seleccionado no cargar el fichero, programa finalizado.\n");
			break;
		default:
			system("cls");
			printf("Algo salio mal, programa interrumpido.\n");
			break;			
	}
	
	if(opcion==2)
	{
		printf("Que desea hacer ahora?:\n\n");
		printf("1. Intentarlo de nuevo.\n");
		printf("2. Salir.\n\n");
		printf("Opcion a escoger: ");
		scanf("%i", &opcion2);
		if(opcion2==1)
		{
			main();
		}
		else if(opcion2==2)
		{
			printf("Programa finalizado definitivamente.");
		}
		else
		{
			printf("Error, programa finalizado definitivamente.");
		}
	}
	
	if(opcion==1)
	{
		int opcion3 /*elegir entre las 4 opciones del menu de apertura de datos*/, opcion4 /*elegir entre 2021 o 2022 en el apartado 1*/;
		int mes1 /*seleccion de mes de la opcion 1 2021*/, mes2 /*seleccion de mes de la opcion 1 2022*/;
		int mes3 /*seleccion de mes de la opcion 2 2021*/, mes4 /*seleccion de mes de la opcion 2 2022*/, opcion5 /*elegir entre renovable o no*/;
		FILE *pf;
		pf = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
		if (pf == NULL)
		{
			printf("Error al abrir el fichero.\n");
			return -1;
		}
		else
		{
			printf("Fichero abierto correctamente.\n\n");
		}
		printf("MENU PARA LA APERTURA DE DATOS\n\nIndique la opcion que desea seleccionar:\n\n");
		printf("1. Realizar un calculo con los datos deseados.\n");
		printf("2. Mostrar los datos mensuales para analizarlos.\n");
		printf("3. Clasificar las secciones en energia renovable y no renovable.\n");
		printf("4. Salir.\n\n");
		printf("Opcion a elegir: ");
		scanf("%i", &opcion3);
		if(opcion3==1)
		{
			system("cls");
			printf("Seleccione el anho del que quiere los datos:\n\n");
			printf("1. 2021\n2. 2022\n\n");
			printf("Opcion a elegir: ");
			scanf("%i", &opcion4);
			if(opcion4==1)
			{
				printf("Escriba el numero del mes del 2021 que desee:\n\n");
				printf("Mes seleccionado: ");
				scanf("%i", &mes1);
			}
			else if(opcion4==2)
			{
				printf("Escriba el numero del mes del 2022 que desee:\n\n");
				printf("Mes seleccionado: ");
				scanf("%i", &mes2);
			}
			else
			{
			printf("Algo salio mal, el programa ha terminado.");
			}
			
		}
		else if(opcion3==2)
		{
			system("cls");
			printf("Seleccione el anho del que quiere ver los datos:\n\n");
			printf("1. 2021\n2. 2022\n\n");
			printf("Opcion a elegir: ");
			scanf("%i", &opcion4);
			if(opcion4==1)
			{
				printf("Escriba el numero del mes del 2021 que desee:\n\n");
				printf("Mes seleccionado: ");
				scanf("%i", &mes3);
			}
			else if(opcion4==2)
			{
				printf("Escriba el numero del mes del 2022 que desee:\n\n");
				printf("Mes seleccionado: ");
				scanf("%i", &mes4);
			}
			else
			{
				printf("Algo salio mal, el programa ha terminado.");
			}
		}
		else if(opcion3==3)
		{
			system("cls");
			printf("\nSeleccione el tipo de energia que desea buscar:\n\n");
                printf("1. Renovable\n");
                printf("2. No renovable\n\n");
                printf("Opcion a escoger: ");
                
				scanf("%i", &opcion5);
                
                buscarPorTipo(pf, opcion5);
                fclose(pf);
		
		}
		else
		{
			printf("Fin del programa.\n");	
		}
	}
	
	return 0;
}

void buscarPorTipo(FILE *pf, int opcion5)
{
    char linea[1000];   
    while (fgets(linea, sizeof(linea), pf) != NULL)
    {  
        if (opcion5 == 1 && strstr(linea, "Renovable") != NULL)
        {
            printf("\n%s \n", linea); 
        }
        else if (opcion5 == 2 && strstr(linea, "No renovable") != NULL)
        {
            printf("\n%s \n", linea);
        }
    }
    if(opcion5!=1 && opcion5!=2)
    {
    	printf("Error, ejecuta el programa de nuevo.");
	}
}

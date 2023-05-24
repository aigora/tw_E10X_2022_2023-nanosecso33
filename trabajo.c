#include <stdio.h>


int main()
{
	system("cls");
	printf("Acaba de ingresar en la pagina de datos de 2021 y 2022 de la Red Electrica Espanola.\nSeleccione que opcion quiere llevar a cabo:\n\n");
	printf("1. Cargar el fichero para analizar y consultar los datos.\n");
	printf("2. No acceder a los datos.\n\n");
	printf("Opcion a escoger: ");
	int opcion, opcion2;
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
		else
		{
			printf("Programa finalizado definitivamente.");
		}
	}
	
	if(opcion==1)
	{
		FILE *pf;
		pf = fopen("C:/Users/VORPC/Documents/GitHub/tw_E10X_2022_2023-nanosecso33/generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
		if (pf == NULL)
		{
			printf("Error al abrir el fichero.\n");
			return -1;
		}
		else
		{
			printf("Fichero abierto correctamente.\n");
			return 0;
		}
		
	}
	
	
	
	
	
	
	return 0;
}

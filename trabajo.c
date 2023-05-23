#include <stdio.h>


int main()
{
	printf("Acaba de ingresar en la pagina de datos de 2021 y 2022 de la Red Electrica Espanola.\n");
	printf("Si desea cargar el fichero para analizar y consultar los datos pulse 1, si no desea acceder a los datos pulse 2.\n");
	int opcion, opcion2;
	scanf("%i", &opcion);
	switch(opcion)
	{
		case 1:
			printf("Cargando fichero...\n");
			break;
		case 2:
			printf("Ha seleccionado no cargar el fichero, programa finalizado.\n");
			break;
		default:
			printf("Algo salio mal, programa interrumpido.\n");
			break;			
	}
	
	if(opcion!=1)
	{
		printf("Si desea intentarlo de nuevo pulsa 1.\n");
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

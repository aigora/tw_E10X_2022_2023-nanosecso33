#include <stdio.h>


int main()
{
	printf("Acaba de ingresar en la pagina de datos de 2021 y 2022 de la Red Electrica Espanola.\n");
	printf("Si desea cargar el fichero para analizar y consultar los datos pulse 1, si no desea acceder a los datos pulse 2.\n");
	int opcion;
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
			printf("Algo salio mal, programa interrumpido.");
			break;			
	}
	
	if(opcion==1)
	{
		
	}
	
	
	
	
	
	
	return 0;
}

#include <stdio.h>
#include <string.h>

float energia_media_2021(int mes);
float energia_total_2021(int mes);
float energia_max_2021(int mes);
float energia_min_2021(int mes);
float rango_energia_2021(int mes);

float energia_media_2022(int mes);
float energia_total_2022(int mes);
float energia_max_2022(int mes);
float energia_min_2022(int mes);
float rango_energia_2022(int mes);

void buscarPorTipo(FILE *pf, int opcion5);

void busqueda_mensual1(int mes);
void busqueda_mensual2(int mes2);

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
		int opcion3=0 /*elegir entre las 4 opciones del menu de apertura de datos*/, opcion4=0 /*elegir entre 2021 o 2022 en el apartado 1*/;
		int calculo_2021=0 /*elegir entre comparar todos los meses del 2021 o mirar solo uno*/, tipo_calculo=0 /*elegir calculo (2021)*/;
		int calculo_2022 /*elegir entre comparar todos los meses del 2022 o mirar solo uno*/, tipo_calculo2=0 /*elegir calculo (2022)*/;
		int mes1=0 /*seleccion de mes de la opcion 1 2021*/, mes2=0 /*seleccion de mes de la opcion 1 2022*/;
		int opcion6=0 /*seleccion de mes de la opcion 2 2021*/, opcion7=0 /*seleccion de mes de la opcion 2 2022*/, opcion5=0 /*elegir entre renovable y no renovable*/;
		int anho /*elegir entre 2021 o 2022 en el apartado 2*/;
		
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
		while(opcion3<1 || opcion3>5)
		{
			fflush(stdin);
			printf("MENU PARA LA APERTURA DE DATOS\n\nIndique la opcion que desea seleccionar:\n\n");
			printf("1. Realizar un calculo con los datos deseados.\n");
			printf("2. Mostrar los datos mensuales para analizarlos.\n");
			printf("3. Clasificar las secciones en energia renovable y no renovable.\n");
			printf("4. Plan de energia recomendada para grupos.\n");
			printf("5. Salir.\n\n");
			printf("Opcion a elegir: ");
			scanf("%i", &opcion3);
		}
		if(opcion3==1)
		{
			while(opcion4!=1 && opcion4!=2)
			{
				fflush(stdin);
				system("cls");
				printf("Seleccione el anho del que quiere los datos:\n\n");
				printf("1. 2021\n2. 2022\n\n");
				printf("Opcion a elegir: ");
				scanf("%i", &opcion4);
				if(opcion4==1)
				{
					fflush(stdin);
					system("cls");
					while(mes1<1 || mes1>12)
					{
						fflush(stdin);
						printf("\nEscriba el numero del mes del 2021 que desee:\n\n");
						printf("Mes seleccionado: ");
						scanf("%i", &mes1);
						if(mes1>0 && mes1<13)
						{
							while(tipo_calculo<1 || tipo_calculo>5)
							{
								fflush(stdin);
								system("cls");
								printf("Ha seleccionado el mes %i.\nEscoja que operacion desea realizar:\n\n", mes1);
								printf("1. Energia media generada\n");
								printf("2. Suma de las energias (energia total)\n");
								printf("3. Energia maxima\n");
								printf("4. Energia minima\n");
								printf("5. Rango de los datos\n\n");
								printf("Opcion a elegir: ");
								scanf("%i", &tipo_calculo);
							}
					 		if(tipo_calculo==1)
							{
								float media= energia_media_2021(mes1);
								printf("\nLa energia media en el mes %i es %f Gwh.", mes1, media);
							}
							if(tipo_calculo==2)
							{
								float total= energia_total_2021(mes1);
								printf("\nLa enegia total generada en el mes %i es %f Gwh.", mes1, total);
							}
							if(tipo_calculo==3)
							{
								float maximo = energia_max_2021(mes1);
								printf("\nLa enegia maxima generada en el mes %i es %f Gwh.", mes1, maximo);
							}
							if(tipo_calculo==4)
							{
								float minimo = energia_min_2021(mes1);
								printf("\nLa enegia minima generada en el mes %i es %f Gwh.", mes1, minimo);
							}
							if(tipo_calculo==5)
							{
								float rango = rango_energia_2021(mes1);
								printf("\nEl rango de la energia en el mes %i es %f Gwh.", mes1, rango);
							}
						}
					}	
				}
				if(opcion4==2)
				{
					fflush(stdin);
					system("cls");
					while(mes2<1 || mes2>12)
					{
						fflush(stdin);
						printf("\nEscriba el numero del mes del 2022 que desee:\n\n");
						printf("Mes seleccionado: ");
						scanf("%i", &mes2);
						if(mes2>0 && mes2<13)
						{
							while(tipo_calculo2<1 || tipo_calculo2>5)
							{
								fflush(stdin);
								system("cls");
								printf("Ha seleccionado el mes %i.\nEscoja que operacion desea realizar:\n\n", mes2);
								printf("1. Energia media generada\n");
								printf("2. Suma de las energias (energia total)\n");
								printf("3. Energia maxima\n");
								printf("4. Energia minima\n");
								printf("5. Rango de los datos\n\n");
								printf("Opcion a elegir: ");
								scanf("%i", &tipo_calculo2);
							}
					 		if(tipo_calculo2==1)
							{
								float media2= energia_media_2022(mes2);
								printf("\nLa energia media en el mes %i es %f Gwh.", mes2, media2);
							}
							if(tipo_calculo2==2)
							{
								float total2= energia_total_2022(mes2);
								printf("\nLa enegia total generada en el mes %i es %f Gwh.", mes2, total2);
							}
							if(tipo_calculo2==3)
							{
								float maximo2 = energia_max_2022(mes2);
								printf("\nLa enegia maxima generada en el mes %i es %f Gwh.", mes2, maximo2);
							}
							if(tipo_calculo2==4)
							{
								float minimo2 = energia_min_2022(mes2);
								printf("\nLa enegia minima generada en el mes %i es %f Gwh.", mes2, minimo2);
							}
							if(tipo_calculo2==5)
							{
								float rango2 = rango_energia_2022(mes2);
								printf("\nEl rango de la energia en el mes %i es %f Gwh.", mes2, rango2);
							}
						}
					}	
				}
			}
		}
		else if(opcion3==2)
		{
			while(anho!=1 && anho!=2)
			{
				fflush(stdin);
	            FILE *pdatos1;
	            fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2021.csv", "r");
	            FILE *pdatos2;
	            fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2022.csv", "r");
		        printf("Seleccione el anho que le interesa:\n 1. 2021 \n 2. 2022 \n");
		        scanf("%i", &anho);
		        if	(anho==1)
		         {
		           FILE *pdatos;
	               fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2021.csv", "r");
	               printf("Seleccione el mes del anho 2021 del cual quiere ver los datos: \n"); 
                   printf(" 1. Enero\n 2. Febrero\n 3. Marzo \n 4. Abril\n 5. Mayo\n 6. Junio\n");
                   printf(" 7. Julio\n 8.Agosto\n 9. Septiembre\n 10. Octubre\n 11. Noviembre\n 12. Diciembre\n\n");
                   printf("Opcion a escoger: ");
                   scanf("%i", &opcion6);
                   busqueda_mensual1(opcion6);
		         }
		        else if	(anho==2)
		         {
	               FILE *pdatos2;
	               fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2022.csv", "r");
	               printf("Seleccione el mes del anho 2022 del cual quiere ver los datos: \n"); 
                   printf(" 1. Enero\n 2. Febrero\n 3. Marzo \n 4. Abril\n 5. Mayo\n 6. Junio\n");
                   printf(" 7. Julio\n 8.Agosto\n 9. Septiembre\n 10. Octubre\n 11. Noviembre\n 12. Diciembre\n\n");
                   printf("Opcion a escoger: ");
                   scanf("%i", &opcion7);
                   busqueda_mensual2(opcion7);
		         } 
		        else if ( anho!=1 && anho!=2)
		         {
		 	       printf("Ha habido un error. Vuelva a intentarlo con una de las opciones definidas.\n");
		         }
				
			}
		}
		else if(opcion3==3)
		{
			system("cls");
			printf("\nSeleccione el tipo de energia que desea buscar:\n");
			printf("(Aparecera cada seccion, con la energia (GWh) generada en cada mes (separada por comas) desde enero de 2021 hasta diciembre de 2022) y se descargaran dichos datos en un archivo nuevo\n\n"); 
            printf("1. Renovable\n");
            printf("2. No renovable\n\n");
            printf("Opcion a escoger: ");
            scanf("%i", &opcion5);
            buscarPorTipo(pf, opcion5);
		}
		else if(opcion3==4)
		{
			system("cls");
			char nom1[20];
			char nom2[20];
			float con1=0;
			char p1[100];
			float con2=0;
			char p2[100];
			char nom3[20];
			float con3=0;
			char p3[100];
			char nom4[20];
			float con4=0;
			char p4[100];
			float mediacon=0;
			
			FILE *fptr;
			fptr = fopen("Energia recomendada para grupos.txt","w");
			fprintf(fptr,"Nombre y Apellidos\t Consumo\t Preferencia\t");
			printf("Usuario n1 introduzca sus datos:\n");
			printf("Escriba su nombre y apellidos:\t");
			fflush(stdin);
			scanf("%[^\n]", nom1);
			printf("Escriba su consumo:\t");
			fflush(stdin);
			scanf("%f", &con1);
			printf("Escoja entre renovable o no renovable:\t");
			fflush(stdin);
			scanf("%[^\n]", p1);
			fprintf(fptr,"\n %s\t %f\t %s\t", nom1, con1, p1);
			
			printf("\nUsuario n2 introduzca sus datos:\n");
			fflush(stdin);
			printf("Escriba su nombre y apellidos:\t");
			scanf("%[^\n]", nom2);
			fflush(stdin);
			printf("Escriba su consumo:\t");
			scanf("%f", &con2);
			fflush(stdin);
			printf("Escoja entre renovable o no renovable:\t");
			scanf("%[^\n]", p2);
			fprintf(fptr,"\n %s\t %f\t %s\t", nom2, con2, p2);
			
			printf("\nUsuario n3 introduzca sus datos:\n");
			fflush(stdin);
			printf("Escriba su nombre y apellidos:\t");
			scanf("%[^\n]", nom3);
			fflush(stdin);
			printf("Escriba su consumo:\t");
			scanf("%f", &con3);
			fflush(stdin);
			printf("Escoja entre renovable o no renovable:\t");
			scanf("%[^\n]", p3);
			fprintf(fptr,"\n %s\t %f\t %s\t", nom3, con3, p3);
			
			printf("\nUsuario n4 introduzca sus datos:\n");
			fflush(stdin);
			printf("Escriba su nombre y apellidos:\t");
			scanf("%[^\n]", nom4);
			fflush(stdin);
			printf("Escriba su consumo:\t");
			scanf("%f", &con4);
			fflush(stdin);
			printf("Escoja entre renovable o no renovable:\t");
			scanf("%[^\n]", p4);
			fprintf(fptr,"\n %s\t %f\t %s\t", nom4, con4, p4);
			mediacon=(con1 + con2 + con3 + con4)/4;
			printf("\n El consumo medio es: %f", mediacon);
			fprintf(fptr, "\n El consumo medio es: %f", mediacon);
			}
		else
		{
			printf("\nFin del programa.\n");	
		}
		fclose(pf);
	}
	
	
	
	
	
	
	return 0;
}

float energia_media_2021(int mes)
{
	FILE *plectura;
	float enero_2021[17],febrero_2021[17],marzo_2021[17],abril_2021[17],mayo_2021[17],junio_2021[17];
	float julio_2021[17],agosto_2021[17],septiembre_2021[17],octubre_2021[17],noviembre_2021[17],diciembre_2021[17];
	float media;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2021.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2021[i],&febrero_2021[i],&marzo_2021[i],&abril_2021[i],&mayo_2021[i],&junio_2021[i],&julio_2021[i],&agosto_2021[i],&septiembre_2021[i],&octubre_2021[i],&noviembre_2021[i],&diciembre_2021[i]);
		}
		fclose(plectura);
		
		switch(mes)
		{
			case 1:
				media = enero_2021[16]/16; //dividimos entre 16 porque es el numero total de energias que tenemos
				break;
			case 2:
				media = febrero_2021[16]/16; 
				break;
			case 3:
				media = marzo_2021[16]/16; 
				break;
			case 4:
				media = abril_2021[16]/16; 
				break;
			case 5:
				media = mayo_2021[16]/16; 
				break;
			case 6:
				media = junio_2021[16]/16; 
				break;
			case 7:
				media = julio_2021[16]/16; 
				break;
			case 8:
				media = agosto_2021[16]/16; 
				break;
			case 9:
				media = septiembre_2021[16]/16;
				break;
			case 10:
				media = octubre_2021[16]/16;
				break;
			case 11:
				media = noviembre_2021[16]/16;
				break;
			case 12:
				media = diciembre_2021[16]/16; 
				break;
			
		}
	}
	return media;
}


float energia_total_2021(int mes)
{
	FILE *plectura;
	float enero_2021[17],febrero_2021[17],marzo_2021[17],abril_2021[17],mayo_2021[17],junio_2021[17];
	float julio_2021[17],agosto_2021[17],septiembre_2021[17],octubre_2021[17],noviembre_2021[17],diciembre_2021[17];
	float total;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2021.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2021[i],&febrero_2021[i],&marzo_2021[i],&abril_2021[i],&mayo_2021[i],&junio_2021[i],&julio_2021[i],&agosto_2021[i],&septiembre_2021[i],&octubre_2021[i],&noviembre_2021[i],&diciembre_2021[i]);
		}
		fclose(plectura);
		
		switch(mes)
		{
			case 1:
				total = enero_2021[16]; //en vez de sumar todas las energias, tenemos que la energia total es el ultimo dato del vector
				break;
			case 2:
				total = febrero_2021[16]; 
				break;
			case 3:
				total = marzo_2021[16]; 
				break;
			case 4:
				total = abril_2021[16]; 
				break;
			case 5:
				total = mayo_2021[16]; 
				break;
			case 6:
				total = junio_2021[16]; 
				break;
			case 7:
				total = julio_2021[16]; 
				break;
			case 8:
				total = agosto_2021[16]; 
				break;
			case 9:
				total = septiembre_2021[16];
				break;
			case 10:
				total = octubre_2021[16];
				break;
			case 11:
				total = noviembre_2021[16];
				break;
			case 12:
				total = diciembre_2021[16]; 
				break;
			
		}
	}
	return total;
}


float energia_max_2021(int mes)
{
	FILE *plectura;
	float enero_2021[17],febrero_2021[17],marzo_2021[17],abril_2021[17],mayo_2021[17],junio_2021[17];
	float julio_2021[17],agosto_2021[17],septiembre_2021[17],octubre_2021[17],noviembre_2021[17],diciembre_2021[17];
	float maximo;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2021.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2021[i],&febrero_2021[i],&marzo_2021[i],&abril_2021[i],&mayo_2021[i],&junio_2021[i],&julio_2021[i],&agosto_2021[i],&septiembre_2021[i],&octubre_2021[i],&noviembre_2021[i],&diciembre_2021[i]);
		}
		fclose(plectura);
		
		float max_energia_enero = enero_2021[0];
		float max_energia_febrero = febrero_2021[0];
		float max_energia_marzo = marzo_2021[0];
		float max_energia_abril = abril_2021[0];
		float max_energia_mayo = mayo_2021[0];
		float max_energia_junio = junio_2021[0];
		float max_energia_julio = julio_2021[0];
		float max_energia_agosto = agosto_2021[0];
		float max_energia_septiembre = septiembre_2021[0];
		float max_energia_octubre = octubre_2021[0];
		float max_energia_noviembre = noviembre_2021[0];
		float max_energia_diciembre = diciembre_2021[0];
		
		for(i=0;i<16;i++) //el bucle se hace hasta 16 porque la ultima posicion del vector es la energia total que no tenemos en cuenta para buscar el maximo
		{
			if(enero_2021[i] > max_energia_enero)
			{
				max_energia_enero = enero_2021[i];
			}
			if(febrero_2021[i] > max_energia_febrero)
			{
				max_energia_febrero = febrero_2021[i];
			}
			if(marzo_2021[i] > max_energia_marzo)
			{
				max_energia_marzo = marzo_2021[i];
			}
			if(abril_2021[i] > max_energia_abril)
			{
				max_energia_abril = abril_2021[i];
			}
			if(mayo_2021[i] > max_energia_mayo)
			{
				max_energia_mayo = mayo_2021[i];
			}
			if(junio_2021[i] > max_energia_junio)
			{
				max_energia_junio = junio_2021[i];
			}
			if(julio_2021[i] > max_energia_julio)
			{
				max_energia_julio = julio_2021[i];
			}
			if(agosto_2021[i] > max_energia_agosto)
			{
				max_energia_agosto = agosto_2021[i];
			}
			if(septiembre_2021[i] > max_energia_septiembre)
			{
				max_energia_septiembre = septiembre_2021[i];
			}
			if(octubre_2021[i] > max_energia_octubre)
			{
				max_energia_octubre = octubre_2021[i];
			}
			if(noviembre_2021[i] > max_energia_noviembre)
			{
				max_energia_noviembre = noviembre_2021[i];
			}
			if(diciembre_2021[i] > max_energia_diciembre)
			{
				max_energia_diciembre = diciembre_2021[i];
			}
			
		}
		
		switch(mes)
		{
			case 1:
				maximo = max_energia_enero; 
				break;
			case 2:
				maximo = max_energia_febrero; 
				break;
			case 3:
				maximo = max_energia_marzo; 
				break;
			case 4:
				maximo = max_energia_abril; 
				break;
			case 5:
				maximo = max_energia_mayo; 
				break;
			case 6:
				maximo = max_energia_junio; 
				break;
			case 7:
				maximo = max_energia_julio; 
				break;
			case 8:
				maximo = max_energia_agosto; 
				break;
			case 9:
				maximo = max_energia_septiembre; 
				break;
			case 10:
				maximo = max_energia_octubre; 
				break;
			case 11:
				maximo = max_energia_noviembre; 
				break;
			case 12:
				maximo = max_energia_diciembre; 
				break;
		}
	}
	return maximo;
}


float energia_min_2021(int mes)
{
	FILE *plectura;
	float enero_2021[17],febrero_2021[17],marzo_2021[17],abril_2021[17],mayo_2021[17],junio_2021[17];
	float julio_2021[17],agosto_2021[17],septiembre_2021[17],octubre_2021[17],noviembre_2021[17],diciembre_2021[17];
	float minimo;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2021.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2021[i],&febrero_2021[i],&marzo_2021[i],&abril_2021[i],&mayo_2021[i],&junio_2021[i],&julio_2021[i],&agosto_2021[i],&septiembre_2021[i],&octubre_2021[i],&noviembre_2021[i],&diciembre_2021[i]);
		}
		fclose(plectura);
		
		float min_energia_enero = enero_2021[0];
		float min_energia_febrero = febrero_2021[0];
		float min_energia_marzo = marzo_2021[0];
		float min_energia_abril = abril_2021[0];
		float min_energia_mayo = mayo_2021[0];
		float min_energia_junio = junio_2021[0];
		float min_energia_julio = julio_2021[0];
		float min_energia_agosto = agosto_2021[0];
		float min_energia_septiembre = septiembre_2021[0];
		float min_energia_octubre = octubre_2021[0];
		float min_energia_noviembre = noviembre_2021[0];
		float min_energia_diciembre = diciembre_2021[0];
		
		for(i=0;i<16;i++) //el bucle se hace hasta 16 porque la ultima posicion del vector es la energia total que no tenemos en cuenta para buscar el minimo
		{
			if(enero_2021[i] < min_energia_enero)
			{
				min_energia_enero = enero_2021[i];
			}
			if(febrero_2021[i] < min_energia_febrero)
			{
				min_energia_febrero = febrero_2021[i];
			}
			if(marzo_2021[i] < min_energia_marzo)
			{
				min_energia_marzo = marzo_2021[i];
			}
			if(abril_2021[i] < min_energia_abril)
			{
				min_energia_abril = abril_2021[i];
			}
			if(mayo_2021[i] < min_energia_mayo)
			{
				min_energia_mayo = mayo_2021[i];
			}
			if(junio_2021[i] < min_energia_junio)
			{
				min_energia_junio = junio_2021[i];
			}
			if(julio_2021[i] < min_energia_julio)
			{
				min_energia_julio = julio_2021[i];
			}
			if(agosto_2021[i] < min_energia_agosto)
			{
				min_energia_agosto = agosto_2021[i];
			}
			if(septiembre_2021[i] < min_energia_septiembre)
			{
				min_energia_septiembre = septiembre_2021[i];
			}
			if(octubre_2021[i] < min_energia_octubre)
			{
				min_energia_octubre = octubre_2021[i];
			}
			if(noviembre_2021[i] < min_energia_noviembre)
			{
				min_energia_noviembre = noviembre_2021[i];
			}
			if(diciembre_2021[i] < min_energia_diciembre)
			{
				min_energia_diciembre = diciembre_2021[i];
			}
			
		}
		
		switch(mes)
		{
			case 1:
				minimo = min_energia_enero; 
				break;
			case 2:
				minimo = min_energia_febrero; 
				break;
			case 3:
				minimo = min_energia_marzo; 
				break;
			case 4:
				minimo = min_energia_abril; 
				break;
			case 5:
				minimo = min_energia_mayo; 
				break;
			case 6:
				minimo = min_energia_junio; 
				break;
			case 7:
				minimo = min_energia_julio; 
				break;
			case 8:
				minimo = min_energia_agosto; 
				break;
			case 9:
				minimo = min_energia_septiembre; 
				break;
			case 10:
				minimo = min_energia_octubre; 
				break;
			case 11:
				minimo = min_energia_noviembre; 
				break;
			case 12:
				minimo = min_energia_diciembre; 
				break;
		}
	}
	return minimo;
}


float rango_energia_2021(int mes)
{
	float rango;
	switch(mes)
		{
			case 1:
				rango = energia_max_2021(1)-energia_min_2021(1); 
				break;
			case 2:
				rango = energia_max_2021(2)-energia_min_2021(2); 
				break;
			case 3:
				rango = energia_max_2021(3)-energia_min_2021(3); 
				break;
			case 4:
				rango = energia_max_2021(4)-energia_min_2021(4); 
				break;
			case 5:
				rango = energia_max_2021(5)-energia_min_2021(5); 
				break;
			case 6:
				rango = energia_max_2021(6)-energia_min_2021(6); 
				break;
			case 7:
				rango = energia_max_2021(7)-energia_min_2021(7); 
				break;
			case 8:
				rango = energia_max_2021(8)-energia_min_2021(8);  
				break;
			case 9:
				rango = energia_max_2021(9)-energia_min_2021(9);  
				break;
			case 10:
				rango = energia_max_2021(10)-energia_min_2021(10);  
				break;
			case 11:
				rango = energia_max_2021(11)-energia_min_2021(11);  
				break;
			case 12:
				rango = energia_max_2021(12)-energia_min_2021(12); 
				break;
		}
	return rango;
}


float energia_media_2022(int mes)
{
	FILE *plectura;
	float enero_2022[17],febrero_2022[17],marzo_2022[17],abril_2022[17],mayo_2022[17],junio_2022[17];
	float julio_2022[17],agosto_2022[17],septiembre_2022[17],octubre_2022[17],noviembre_2022[17],diciembre_2022[17];
	float media2;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2022.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2022[i],&febrero_2022[i],&marzo_2022[i],&abril_2022[i],&mayo_2022[i],&junio_2022[i],&julio_2022[i],&agosto_2022[i],&septiembre_2022[i],&octubre_2022[i],&noviembre_2022[i],&diciembre_2022[i]);
		}
		fclose(plectura);
		
		switch(mes)
		{
			case 1:
				media2 = enero_2022[16]/16.0; //dividimos entre 16 porque es el numero total de energias que tenemos
				break;
			case 2:
				media2 = febrero_2022[16]/16.0; 
				break;
			case 3:
				media2 = marzo_2022[16]/16.0; 
				break;
			case 4:
				media2 = abril_2022[16]/16.0; 
				break;
			case 5:
				media2 = mayo_2022[16]/16.0; 
				break;
			case 6:
				media2 = junio_2022[16]/16.0; 
				break;
			case 7:
				media2 = julio_2022[16]/16.0; 
				break;
			case 8:
				media2 = agosto_2022[16]/16.0; 
				break;
			case 9:
				media2 = septiembre_2022[16]/16.0;
				break;
			case 10:
				media2 = octubre_2022[16]/16.0;
				break;
			case 11:
				media2 = noviembre_2022[16]/16.0;
				break;
			case 12:
				media2 = diciembre_2022[16]/16.0; 
				break;
			
		}
	}
	return media2;
}

float energia_total_2022(int mes)
{
	FILE *plectura;
	float enero_2022[17],febrero_2022[17],marzo_2022[17],abril_2022[17],mayo_2022[17],junio_2022[17];
	float julio_2022[17],agosto_2022[17],septiembre_2022[17],octubre_2022[17],noviembre_2022[17],diciembre_2022[17];
	float total;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2022.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2022[i],&febrero_2022[i],&marzo_2022[i],&abril_2022[i],&mayo_2022[i],&junio_2022[i],&julio_2022[i],&agosto_2022[i],&septiembre_2022[i],&octubre_2022[i],&noviembre_2022[i],&diciembre_2022[i]);
		}
		fclose(plectura);
		
		switch(mes)
		{
			case 1:
				total = enero_2022[16]; //en vez de sumar todas las energias, tenemos que la energia total es el ultimo dato del vector
				break;
			case 2:
				total = febrero_2022[16]; 
				break;
			case 3:
				total = marzo_2022[16]; 
				break;
			case 4:
				total = abril_2022[16]; 
				break;
			case 5:
				total = mayo_2022[16]; 
				break;
			case 6:
				total = junio_2022[16]; 
				break;
			case 7:
				total = julio_2022[16]; 
				break;
			case 8:
				total = agosto_2022[16]; 
				break;
			case 9:
				total = septiembre_2022[16];
				break;
			case 10:
				total = octubre_2022[16];
				break;
			case 11:
				total = noviembre_2022[16];
				break;
			case 12:
				total = diciembre_2022[16]; 
				break;
			
		}
	}
	return total;
}

float energia_max_2022(int mes)
{
	FILE *plectura;
	float enero_2022[17],febrero_2022[17],marzo_2022[17],abril_2022[17],mayo_2022[17],junio_2022[17];
	float julio_2022[17],agosto_2022[17],septiembre_2022[17],octubre_2022[17],noviembre_2022[17],diciembre_2022[17];
	float maximo;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2022.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2022[i],&febrero_2022[i],&marzo_2022[i],&abril_2022[i],&mayo_2022[i],&junio_2022[i],&julio_2022[i],&agosto_2022[i],&septiembre_2022[i],&octubre_2022[i],&noviembre_2022[i],&diciembre_2022[i]);
		}
		fclose(plectura);
		
		float max_energia_enero = enero_2022[0];
		float max_energia_febrero = febrero_2022[0];
		float max_energia_marzo = marzo_2022[0];
		float max_energia_abril = abril_2022[0];
		float max_energia_mayo = mayo_2022[0];
		float max_energia_junio = junio_2022[0];
		float max_energia_julio = julio_2022[0];
		float max_energia_agosto = agosto_2022[0];
		float max_energia_septiembre = septiembre_2022[0];
		float max_energia_octubre = octubre_2022[0];
		float max_energia_noviembre = noviembre_2022[0];
		float max_energia_diciembre = diciembre_2022[0];
		
		for(i=0;i<16;i++) //el bucle se hace hasta 16 porque la ultima posicion del vector es la energia total que no tenemos en cuenta para buscar el maximo
		{
			if(enero_2022[i] > max_energia_enero)
			{
				max_energia_enero = enero_2022[i];
			}
			if(febrero_2022[i] > max_energia_febrero)
			{
				max_energia_febrero = febrero_2022[i];
			}
			if(marzo_2022[i] > max_energia_marzo)
			{
				max_energia_marzo = marzo_2022[i];
			}
			if(abril_2022[i] > max_energia_abril)
			{
				max_energia_abril = abril_2022[i];
			}
			if(mayo_2022[i] > max_energia_mayo)
			{
				max_energia_mayo = mayo_2022[i];
			}
			if(junio_2022[i] > max_energia_junio)
			{
				max_energia_junio = junio_2022[i];
			}
			if(julio_2022[i] > max_energia_julio)
			{
				max_energia_julio = julio_2022[i];
			}
			if(agosto_2022[i] > max_energia_agosto)
			{
				max_energia_agosto = agosto_2022[i];
			}
			if(septiembre_2022[i] > max_energia_septiembre)
			{
				max_energia_septiembre = septiembre_2022[i];
			}
			if(octubre_2022[i] > max_energia_octubre)
			{
				max_energia_octubre = octubre_2022[i];
			}
			if(noviembre_2022[i] > max_energia_noviembre)
			{
				max_energia_noviembre = noviembre_2022[i];
			}
			if(diciembre_2022[i] > max_energia_diciembre)
			{
				max_energia_diciembre = diciembre_2022[i];
			}
			
		}
		
		switch(mes)
		{
			case 1:
				maximo = max_energia_enero; 
				break;
			case 2:
				maximo = max_energia_febrero; 
				break;
			case 3:
				maximo = max_energia_marzo; 
				break;
			case 4:
				maximo = max_energia_abril; 
				break;
			case 5:
				maximo = max_energia_mayo; 
				break;
			case 6:
				maximo = max_energia_junio; 
				break;
			case 7:
				maximo = max_energia_julio; 
				break;
			case 8:
				maximo = max_energia_agosto; 
				break;
			case 9:
				maximo = max_energia_septiembre; 
				break;
			case 10:
				maximo = max_energia_octubre; 
				break;
			case 11:
				maximo = max_energia_noviembre; 
				break;
			case 12:
				maximo = max_energia_diciembre; 
				break;
		}
	}
	return maximo;
}

float energia_min_2022(int mes)
{
	FILE *plectura;
	float enero_2022[17],febrero_2022[17],marzo_2022[17],abril_2022[17],mayo_2022[17],junio_2022[17];
	float julio_2022[17],agosto_2022[17],septiembre_2022[17],octubre_2022[17],noviembre_2022[17],diciembre_2022[17];
	float minimo;
	int i;
	plectura = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2022.csv", "r");
	if (plectura == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(plectura, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2022[i],&febrero_2022[i],&marzo_2022[i],&abril_2022[i],&mayo_2022[i],&junio_2022[i],&julio_2022[i],&agosto_2022[i],&septiembre_2022[i],&octubre_2022[i],&noviembre_2022[i],&diciembre_2022[i]);
		}
		fclose(plectura);
		
		float min_energia_enero = enero_2022[0];
		float min_energia_febrero = febrero_2022[0];
		float min_energia_marzo = marzo_2022[0];
		float min_energia_abril = abril_2022[0];
		float min_energia_mayo = mayo_2022[0];
		float min_energia_junio = junio_2022[0];
		float min_energia_julio = julio_2022[0];
		float min_energia_agosto = agosto_2022[0];
		float min_energia_septiembre = septiembre_2022[0];
		float min_energia_octubre = octubre_2022[0];
		float min_energia_noviembre = noviembre_2022[0];
		float min_energia_diciembre = diciembre_2022[0];
		
		for(i=0;i<16;i++) //el bucle se hace hasta 16 porque la ultima posicion del vector es la energia total que no tenemos en cuenta para buscar el minimo
		{
			if(enero_2022[i] < min_energia_enero)
			{
				min_energia_enero = enero_2022[i];
			}
			if(febrero_2022[i] < min_energia_febrero)
			{
				min_energia_febrero = febrero_2022[i];
			}
			if(marzo_2022[i] < min_energia_marzo)
			{
				min_energia_marzo = marzo_2022[i];
			}
			if(abril_2022[i] < min_energia_abril)
			{
				min_energia_abril = abril_2022[i];
			}
			if(mayo_2022[i] < min_energia_mayo)
			{
				min_energia_mayo = mayo_2022[i];
			}
			if(junio_2022[i] < min_energia_junio)
			{
				min_energia_junio = junio_2022[i];
			}
			if(julio_2022[i] < min_energia_julio)
			{
				min_energia_julio = julio_2022[i];
			}
			if(agosto_2022[i] < min_energia_agosto)
			{
				min_energia_agosto = agosto_2022[i];
			}
			if(septiembre_2022[i] < min_energia_septiembre)
			{
				min_energia_septiembre = septiembre_2022[i];
			}
			if(octubre_2022[i] < min_energia_octubre)
			{
				min_energia_octubre = octubre_2022[i];
			}
			if(noviembre_2022[i] < min_energia_noviembre)
			{
				min_energia_noviembre = noviembre_2022[i];
			}
			if(diciembre_2022[i] < min_energia_diciembre)
			{
				min_energia_diciembre = diciembre_2022[i];
			}
			
		}
		
		switch(mes)
		{
			case 1:
				minimo = min_energia_enero; 
				break;
			case 2:
				minimo = min_energia_febrero; 
				break;
			case 3:
				minimo = min_energia_marzo; 
				break;
			case 4:
				minimo = min_energia_abril; 
				break;
			case 5:
				minimo = min_energia_mayo; 
				break;
			case 6:
				minimo = min_energia_junio; 
				break;
			case 7:
				minimo = min_energia_julio; 
				break;
			case 8:
				minimo = min_energia_agosto; 
				break;
			case 9:
				minimo = min_energia_septiembre; 
				break;
			case 10:
				minimo = min_energia_octubre; 
				break;
			case 11:
				minimo = min_energia_noviembre; 
				break;
			case 12:
				minimo = min_energia_diciembre; 
				break;
		}
	}
	return minimo;
}

float rango_energia_2022(int mes)
{
	float rango;
	switch(mes)
		{
			case 1:
				rango = energia_max_2022(1)-energia_min_2022(1); 
				break;
			case 2:
				rango = energia_max_2022(2)-energia_min_2022(2); 
				break;
			case 3:
				rango = energia_max_2022(3)-energia_min_2022(3); 
				break;
			case 4:
				rango = energia_max_2022(4)-energia_min_2022(4); 
				break;
			case 5:
				rango = energia_max_2022(5)-energia_min_2022(5); 
				break;
			case 6:
				rango = energia_max_2022(6)-energia_min_2022(6); 
				break;
			case 7:
				rango = energia_max_2022(7)-energia_min_2022(7); 
				break;
			case 8:
				rango = energia_max_2022(8)-energia_min_2022(8);  
				break;
			case 9:
				rango = energia_max_2022(9)-energia_min_2022(9);  
				break;
			case 10:
				rango = energia_max_2022(10)-energia_min_2022(10);  
				break;
			case 11:
				rango = energia_max_2022(11)-energia_min_2022(11);  
				break;
			case 12:
				rango = energia_max_2022(12)-energia_min_2022(12); 
				break;
		}
	return rango;
}

void buscarPorTipo(FILE *pf, int opcion5)
{
	FILE *tipoEnergia;
	tipoEnergia = fopen("datos_tipo_energia.txt", "w");
	char linea[1000]; 
    while (fgets(linea, sizeof(linea), pf) != NULL)
    {  
		if (opcion5 == 1 && strstr(linea, "Renovable") != NULL)
        {
			printf("\n%s \n", linea); 
			fprintf(tipoEnergia, "%s\n", linea);
			
        }
        else if (opcion5 == 2 && strstr(linea, "No renovable") != NULL)
        {
            printf("\n%s \n", linea);
            fprintf(tipoEnergia, "%s\n", linea);
        }
    }
    fclose(tipoEnergia);
    printf("Datos descargados correctamente");
    if(opcion5!=1 && opcion5!=2)
    {
    	printf("Error, ejecuta de nuevo el programa.");
	}
}

void busqueda_mensual1(int mes)
{
	FILE *pdatos;
	float enero_2021[17],febrero_2021[17],marzo_2021[17],abril_2021[17],mayo_2021[17],junio_2021[17];
	float julio_2021[17],agosto_2021[17],septiembre_2021[17],octubre_2021[17],noviembre_2021[17],diciembre_2021[17];
	int i;
	
	pdatos = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2021.csv", "r");
	if (pdatos == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(pdatos, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2021[i],&febrero_2021[i],&marzo_2021[i],&abril_2021[i],&mayo_2021[i],&junio_2021[i],&julio_2021[i],&agosto_2021[i],&septiembre_2021[i],&octubre_2021[i],&noviembre_2021[i],&diciembre_2021[i]);
		}
		fclose(pdatos); 
		switch(mes)
		{
			case 1:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			enero_2021[0],enero_2021[1],enero_2021[2],enero_2021[3],enero_2021[4],enero_2021[5],enero_2021[6],enero_2021[7],enero_2021[8],enero_2021[9], enero_2021[10],enero_2021[11],enero_2021[12],enero_2021[13],enero_2021[14],enero_2021[15],enero_2021[16]); 
				break;
			case 2:
	     	printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
		    febrero_2021[0], febrero_2021[1],febrero_2021[2],febrero_2021[3],febrero_2021[4],febrero_2021[5],febrero_2021[6],febrero_2021[7],febrero_2021[8],febrero_2021[9],febrero_2021[10],febrero_2021[11],febrero_2021[12],febrero_2021[13],febrero_2021[14],febrero_2021[15],febrero_2021[16]);
				break;
			case 3:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			marzo_2021[0],marzo_2021[1],marzo_2021[2],marzo_2021[3],marzo_2021[4],marzo_2021[5],marzo_2021[6],marzo_2021[7],marzo_2021[8],marzo_2021[9],marzo_2021[10],marzo_2021[11],marzo_2021[12],marzo_2021[13],marzo_2021[14],marzo_2021[15],marzo_2021[16]);
				break;
			case 4:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			abril_2021[0],abril_2021[1],abril_2021[2],abril_2021[3],abril_2021[4],abril_2021[5],abril_2021[6],abril_2021[7],abril_2021[8],abril_2021[9],abril_2021[10],abril_2021[11],abril_2021[12],abril_2021[13],abril_2021[14],abril_2021[15],abril_2021[16]);
				break;
			case 5:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			mayo_2021[0],mayo_2021[1],mayo_2021[2],mayo_2021[3],mayo_2021[4],mayo_2021[5],mayo_2021[6],mayo_2021[7],mayo_2021[8],mayo_2021[9],mayo_2021[10],mayo_2021[11],mayo_2021[12],mayo_2021[13],mayo_2021[14],mayo_2021[15],mayo_2021[16]);
				break;
			case 6:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			junio_2021[0],junio_2021[1],junio_2021[2],junio_2021[3],junio_2021[4],junio_2021[5],junio_2021[6],junio_2021[7],junio_2021[8],junio_2021[9],junio_2021[10],junio_2021[11],junio_2021[12],junio_2021[13],junio_2021[14],junio_2021[15],junio_2021[16]);
				break;
			case 7:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			julio_2021[0],julio_2021[1],julio_2021[2],julio_2021[3],julio_2021[4],julio_2021[5],julio_2021[6],julio_2021[7],julio_2021[8],julio_2021[9],julio_2021[10],julio_2021[11],julio_2021[12],julio_2021[13],julio_2021[14],julio_2021[15],julio_2021[16]);
				break;
			case 8:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			agosto_2021[0],agosto_2021[1],agosto_2021[2],agosto_2021[3],agosto_2021[4],agosto_2021[5],agosto_2021[6],agosto_2021[7],agosto_2021[8],agosto_2021[9],agosto_2021[10],agosto_2021[11],agosto_2021[12],agosto_2021[13],agosto_2021[14],agosto_2021[15],agosto_2021[16]); 
				break;
			case 9:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			septiembre_2021[0],septiembre_2021[1],septiembre_2021[2],septiembre_2021[3],septiembre_2021[4],septiembre_2021[5],septiembre_2021[6],septiembre_2021[7],septiembre_2021[8],septiembre_2021[9],septiembre_2021[10],septiembre_2021[11],septiembre_2021[12],septiembre_2021[13],septiembre_2021[14],septiembre_2021[15],septiembre_2021[16]);
				break;
			case 10:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			octubre_2021[0],octubre_2021[1],octubre_2021[2],octubre_2021[3],octubre_2021[4],octubre_2021[5],octubre_2021[6],octubre_2021[7],octubre_2021[8],octubre_2021[9],octubre_2021[10],octubre_2021[11],octubre_2021[12],octubre_2021[13],octubre_2021[14],octubre_2021[15],octubre_2021[16]);
				break;
			case 11:
		    printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
		    noviembre_2021[0],noviembre_2021[1],noviembre_2021[2],noviembre_2021[3],noviembre_2021[4],noviembre_2021[5],noviembre_2021[6],noviembre_2021[7],noviembre_2021[8],noviembre_2021[9],noviembre_2021[10],noviembre_2021[11],noviembre_2021[12],noviembre_2021[13],noviembre_2021[14],noviembre_2021[15],noviembre_2021[16]);
				break;
			case 12:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			diciembre_2021[0],diciembre_2021[1],diciembre_2021[2],diciembre_2021[3],diciembre_2021[4],diciembre_2021[5],diciembre_2021[6],diciembre_2021[7],diciembre_2021[8],diciembre_2021[9],diciembre_2021[10],diciembre_2021[11],diciembre_2021[12],diciembre_2021[13],diciembre_2021[14],diciembre_2021[15],diciembre_2021[16]);
				break;
			
		}
	}

}
 

void busqueda_mensual2(int mes2)
{
	FILE *pdatos2;
	float enero_2022[17],febrero_2022[17],marzo_2022[17],abril_2022[17],mayo_2022[17],junio_2022[17];
	float julio_2022[17],agosto_2022[17],septiembre_2022[17],octubre_2022[17],noviembre_2022[17],diciembre_2022[17];
	int i;
	pdatos2 = fopen("generacion_por_tecnologias_21_22_puntos_simplificado_solo_energias_2022.csv", "r");
	if (pdatos2 == NULL)
  	{
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  	}
	else
	{
		for(i=0;i<17;i++)
		{
			fscanf(pdatos2, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &enero_2022[i],&febrero_2022[i],&marzo_2022[i],&abril_2022[i],&mayo_2022[i],&junio_2022[i],&julio_2022[i],&agosto_2022[i],&septiembre_2022[i],&octubre_2022[i],&noviembre_2022[i],&diciembre_2022[i]);
		}
		fclose(pdatos2); 
		switch(mes2)
		{
			case 1:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			enero_2022[0],enero_2022[1],enero_2022[2],enero_2022[3],enero_2022[4],enero_2022[5],enero_2022[6],enero_2022[7],enero_2022[8],enero_2022[9], enero_2022[10],enero_2022[11],enero_2022[12],enero_2022[13],enero_2022[14],enero_2022[15],enero_2022[16]); 
				break;
			case 2:
	     	printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
		    febrero_2022[0], febrero_2022[1],febrero_2022[2],febrero_2022[3],febrero_2022[4],febrero_2022[5],febrero_2022[6],febrero_2022[7],febrero_2022[8],febrero_2022[9],febrero_2022[10],febrero_2022[11],febrero_2022[12],febrero_2022[13],febrero_2022[14],febrero_2022[15],febrero_2022[16]);
				break;
			case 3:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			marzo_2022[0],marzo_2022[1],marzo_2022[2],marzo_2022[3],marzo_2022[4],marzo_2022[5],marzo_2022[6],marzo_2022[7],marzo_2022[8],marzo_2022[9],marzo_2022[10],marzo_2022[11],marzo_2022[12],marzo_2022[13],marzo_2022[14],marzo_2022[15],marzo_2022[16]);
				break;
			case 4:  
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			abril_2022[0],abril_2022[1],abril_2022[2],abril_2022[3],abril_2022[4],abril_2022[5],abril_2022[6],abril_2022[7],abril_2022[8],abril_2022[9],abril_2022[10],abril_2022[11],abril_2022[12],abril_2022[13],abril_2022[14],abril_2022[15],abril_2022[16]);
				break;
			case 5:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			mayo_2022[0],mayo_2022[1],mayo_2022[2],mayo_2022[3],mayo_2022[4],mayo_2022[5],mayo_2022[6],mayo_2022[7],mayo_2022[8],mayo_2022[9],mayo_2022[10],mayo_2022[11],mayo_2022[12],mayo_2022[13],mayo_2022[14],mayo_2022[15],mayo_2022[16]);
				break;
			case 6:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			junio_2022[0],junio_2022[1],junio_2022[2],junio_2022[3],junio_2022[4],junio_2022[5],junio_2022[6],junio_2022[7],junio_2022[8],junio_2022[9],junio_2022[10],junio_2022[11],junio_2022[12],junio_2022[13],junio_2022[14],junio_2022[15],junio_2022[16]);
				break;
			case 7:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			julio_2022[0],julio_2022[1],julio_2022[2],julio_2022[3],julio_2022[4],julio_2022[5],julio_2022[6],julio_2022[7],julio_2022[8],julio_2022[9],julio_2022[10],julio_2022[11],julio_2022[12],julio_2022[13],julio_2022[14],julio_2022[15],julio_2022[16]);
				break;
			case 8:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			agosto_2022[0],agosto_2022[1],agosto_2022[2],agosto_2022[3],agosto_2022[4],agosto_2022[5],agosto_2022[6],agosto_2022[7],agosto_2022[8],agosto_2022[9],agosto_2022[10],agosto_2022[11],agosto_2022[12],agosto_2022[13],agosto_2022[14],agosto_2022[15],agosto_2022[16]); 
				break;
			case 9:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			septiembre_2022[0],septiembre_2022[1],septiembre_2022[2],septiembre_2022[3],septiembre_2022[4],septiembre_2022[5],septiembre_2022[6],septiembre_2022[7],septiembre_2022[8],septiembre_2022[9],septiembre_2022[10],septiembre_2022[11],septiembre_2022[12],septiembre_2022[13],septiembre_2022[14],septiembre_2022[15],septiembre_2022[16]);
				break;
			case 10:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			octubre_2022[0],octubre_2022[1],octubre_2022[2],octubre_2022[3],octubre_2022[4],octubre_2022[5],octubre_2022[6],octubre_2022[7],octubre_2022[8],octubre_2022[9],octubre_2022[10],octubre_2022[11],octubre_2022[12],octubre_2022[13],octubre_2022[14],octubre_2022[15],octubre_2022[16]);
				break;
			case 11:
		    printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
		    noviembre_2022[0],noviembre_2022[1],noviembre_2022[2],noviembre_2022[3],noviembre_2022[4],noviembre_2022[5],noviembre_2022[6],noviembre_2022[7],noviembre_2022[8],noviembre_2022[9],noviembre_2022[10],noviembre_2022[11],noviembre_2022[12],noviembre_2022[13],noviembre_2022[14],noviembre_2022[15],noviembre_2022[16]);
				break;
			case 12:
			printf(" HIDRAULICA: %f\n TURBINA DE BOMBEO: %f\n NUCLEAR: %f\n CARBON: %f\n MOTORES DIESEL: %f\n TURBINA DE GAS: %f\n TURBINA DE VAPOR: %f\n CICLO COMBINADO: %f\n HIDROELECTRICA: %f\n EOLICA: %f\n SOL. FOTOVOLTAICA: %f\n SOL. TERMICA: %f\n OTRAS RENOVABLES: %f\n COGENERACION: %f\n RESIDUOS NO RENOVABLES: %f\n RESIDUOS RENOVABLES: %f\n ",
			diciembre_2022[0],diciembre_2022[1],diciembre_2022[2],diciembre_2022[3],diciembre_2022[4],diciembre_2022[5],diciembre_2022[6],diciembre_2022[7],diciembre_2022[8],diciembre_2022[9],diciembre_2022[10],diciembre_2022[11],diciembre_2022[12],diciembre_2022[13],diciembre_2022[14],diciembre_2022[15],diciembre_2022[16]);
				break;
			
		}
	}
}

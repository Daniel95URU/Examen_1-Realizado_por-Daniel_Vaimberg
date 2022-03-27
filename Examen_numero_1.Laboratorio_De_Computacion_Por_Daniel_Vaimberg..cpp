/***********************************************************************************************************************************************
Elaborar un programa que, dada una sección de estudiantes, y las notas de los cortes de cada uno, determine si aprobó o no y en cuál categoría quedó:
Sobresaliente: 19 – 20, Muy bueno: 16 – 18, Bueno: 13 – 15, Regular: 10 – 12, Mejorable: 6 – 10, Deficiente: el resto
Estadísticas de la sección: promedio, cantidad de aprobados, cantidad de reprobados, total de estudiantes de la sección (no es dato de entrada...). 
Nota importante, el número de estudiantes NO es dato de entrada. Su programa debe contar el número total de los estudiantes.
*************************************************************************************************************************************************/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	int aprobados = 0, reprobados = 0, notas1, notas2, cantidad = 0, NotasDelCorte1, NotasDelCorte2, opcion = 0, opcion2 = 0, opcion3 = 0, sum1 = 0, sum2 = 0, Otra;
	float promedio1, promedio2, corte1, corte2, C1 = 0, C2 = 0, PromTotal = 0, porcentaje2, acum1, acum2, PromSeccion, porcentaje1;
	char seccion[2], estudiante[10], apellido[15];
	
	printf(" Bienvenido, este programa busca calcular las notas que especifique en una seccion de 2 cortes cuyos valores porcentuales tambien los debera indicar usted\n");         
	printf("\nA continuacion ingresara una serie de datos para calcular el promedio de la seccion, numero de estudiantes, \nlos aprobados y los reprobados.\n\n");

	do{
	
		printf("Ingrese la seccion a evaluar: ");                                			 //Seccion que se evaluará a lo largo del programa.
		scanf("%s", &seccion);
		printf("\nUsted selecciono la seccion %.2s\n", seccion);
		printf("\nAhora debe ingresar los datos de la seccion\n");
			printf("Cual sera el porcentaje asignado al primer corte de notas?: ");             					//Aquí se busca almacenar en la memoria el porcentaje que se desea calcular para la nota del corte 1 del estudiante. 
				scanf("%f", &porcentaje1);
				
			
				if(porcentaje1 < 1 || porcentaje1 >= 100){									//De ser mayor o igual a 100 el porcentaje del corte numero 2 quedaría neutralizado o negativo.
				
					printf("Colocar un digito que sea del 1 al 99");
					return 0;
			
				}
			
		do{
		
			printf("Ingresa el nombre del estudiante: ");                      				 //Nombre y apellido del estudiante cuyos datos se recogerán para sacar la estadística de la sección.
			scanf("%s", &estudiante);
			printf("Ingresa el apellido del estudiante: ");
			scanf("%s", apellido);
 
			
			do{
				printf("\nIngrese cuantas notas tiene el corte numero 1 en la seccion %.2s: ", seccion);				//Aquí se busca determinar el numero de notas a emplear para el corte 1.
				scanf("%d", &NotasDelCorte1);
				printf("Ingresa la/s nota/s del primer corte de %s %s: ", estudiante, apellido);
				
				
				for (int i = 0; i < NotasDelCorte1; ++i){ 								//Este bucle for permite contabilizar y registrar las notas en &notas1.
					
					printf(" \nNota %d: ", i + 1);
					scanf("%d", &notas1);
					sum1 += notas1;														//Suma de todas las notas aplicadas	
				}
				
				scanf("d", &sum1);
				printf("\nLa suma de las notas es de: %d\n", sum1);																//Calculo de la suma.
				scanf("d", &sum1);
				promedio1 = (sum1 * 1.0)/(NotasDelCorte1*1.0);								
				printf("\nEl promedio de las notas seria: %.2f\n", promedio1);													//Resultado del promedio numero 1.
				C1 = promedio1*(porcentaje1/100);
				acum1 = promedio1 + acum1;																									//Esta variable permite registrar promedio aplicado al corte 1.
				printf("\nLa nota del semestre, tras aplicar el primer corte, de %s %s es: %.2f\n ", estudiante, apellido, C1);

				sum1 = 0;
				printf("\nTe equivocaste en algun digito? \n 1 - Seguir, 2 - Volver\n : ");								//Este apartado permite regresar en caso de un error al digitar los numeros
				scanf("%d", &opcion);	
				
			if(opcion == 2){ 																//Este if permite limpiar las variables (restablecerlas al valor neutro)
					corte1 = 0;
					C1 = 0;
					acum1 = 0;																//El acumulador 1 y 2 permiten registrar los datos de varios estudiantes utilizados para el promedio de seccion.
				}		
			}while (opcion == 2);	

			printf("\nAhora digite los parametros del corte numero 2\n");
		
			do{
				porcentaje2 = 100 - porcentaje1;                                                         	//Mas adelante este valor permitirá completar la nota porcentual final.
				printf("\nIngrese cuantas notas tiene el corte numero 2 en la seccion %.2s: ", seccion);
				scanf("%d", &NotasDelCorte2);
				printf("Ingresa la/s nota/s del segundo corte de %s %s: ", estudiante, apellido);
				
				
				for (int i = 0; i < NotasDelCorte2; ++i){										//Este bucle for permite contabilizar y registrar las notas en &notas2.
					
					printf(" \nNota %d: ", i + 1);
					scanf("%d", &notas2);
					sum2 += notas2;																//respectiva suma de notas pero esta vez en una variable diferente.	
				}
			
				scanf("d", &sum2);
				printf("\nLa suma de las notas es de: %d\n", sum2);
				scanf("d", &sum2);
				promedio2 = (sum2 * 1.0)/(NotasDelCorte2*1.0);
				printf("\nEl promedio de las notas seria: %.2f\n", promedio2);
				C2 = (promedio2*(porcentaje2/100))*1.0;
				acum2 = promedio2 + acum2;																							//En este apartado operan el acum2 para el promedio de seccion.
				printf("\nLa nota del semestre, tras aplicar el segundo corte, de %s %s es: %.2f\n ", estudiante, apellido, C2);
				sum2 = 0;
				printf("\nTe equivocaste en algun digito? \n 1 - Seguir, 2 - Volver\n : ");
				scanf("%d", &opcion2);
				
				if(opcion2 == 2){																					//Este if sigue la lógica de restablecer lo valores de las vairables indicadas a 0.
					corte2 = 0;
					C2 = 0;
					acum2 = 0;
				}
			}while (opcion2 == 2);																				//Este while inicia el bucle en caso de marcar el numero 2.
			
			PromTotal = C1 + C2;																				//PromTotal es el promedio obtenido de los dos cortes basado en los porcentajes admitidos.
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
				if(PromTotal >= 19 && PromTotal <= 20){																				//funcion if que marca los distitnos tipos de categoria por nota obtenida.
					printf("\nEl estudiante %s %s tiene un promedio Sobresaliente de %.2f puntos!", estudiante, apellido, PromTotal);
					aprobados++;
				}else if(PromTotal >= 16 && PromTotal < 18){																		//Del 10 al 20 se le suma 1 a la variable de "aprobados"
					printf("\nEl estudiante %s %s tiene un promedio Muy Bueno de %.2f puntos!", estudiante, apellido, PromTotal);
					aprobados++;
				}else if(PromTotal >= 13 && PromTotal < 16){
					printf("\nEl estudiante %s %s tiene un promedio bueno de %.2f puntos!", estudiante, apellido, PromTotal);
					aprobados++;
				}else if(PromTotal >= 10 && PromTotal < 13){
					printf("\nEl estudiante %s %s tiene un promedio regular de %.2f puntos", estudiante, apellido, PromTotal);
					aprobados++;
				}else if (PromTotal >= 6 && PromTotal < 10){																		//Del 0 al 10 se le suma 1 a la variable de "reprobados"
					printf("\nEl estudiante %s %s tiene un promedio mejorable de %.2f puntos", estudiante, apellido, PromTotal);
					reprobados++;
				}else if (PromTotal >= 0 && PromTotal < 6){
					printf("\nEl estudiante %s %s tiene un promedio deficiente de %.2f puntos", estudiante, apellido, PromTotal);
					reprobados++;
				}else{																										//En caso de que la nota del estudiante pase de 20 se reinicia el programa por no ser una nota valida en lo exigido.
					printf("La nota calculada no entra en los parametros del 1 al 20, vuelva a intentarlo");						
					return 0;
				}
			corte1 = acum1*porcentaje1/100;   																			//Calculo de operaciones de los cortes 1 y 2 para el promedio de seccion. 						                                   
			corte2 = acum2*porcentaje2/100;
		printf("\n\n--------------------------------------------------------------------------------------------------------------------\n");
		printf("Busca ingresar los datos de otro estudiante de la seccion %.2s?\n", seccion);							//Aquí se le informará al usuario si busca ingresar otros datos de diferentes estudiante.
		printf("1 - Si, 2 - No\n");
		scanf("%d", &opcion3);																					//En caso de negativo (2) se sigue la línea de programación inicial
		cantidad++;																								//Al finalizar el bucle de datos del estudiante se aumenta 1 la vairbale de cantidad para contabilizar el número de alumnos.
	}while (opcion3 == 1);
		
		printf(" \nLas estadisticas de la seccion %.2s son: \n", seccion);										//Se evaluan las estadísticas de la sección con los datos recopilados.
		printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf(" La cantidad de estudiantes en la seccion %.2s es de: %d\n", seccion, cantidad);
		printf(" \n Aprobaron un total de %d estudiantes\n", aprobados);	
		printf(" \n Reprobaron un total de %d estudiantes\n", reprobados);
		PromSeccion = (corte1 + corte2)/cantidad;
		printf(" \n El promedio total de la seccion %.2s es de: %.2f puntos", seccion, PromSeccion);
		printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		PromSeccion = 0, acum1 = 0, acum2= 0;
		printf("Desea ingresar otra seccion?\n 1 - Si, 2 - No\n");													//Se le pregunta al usuario si busca evaluar otras seccioens.
		scanf("%d", &Otra);
		if(Otra == 1){
		printf("Reiniciando el programa...\n\n\n");																	//Se reinician todas las variables a un valor inicial de 0
		cantidad = 0, aprobados = 0, reprobados = 0, PromTotal = 0, C1 = 0, C2= 0, NotasDelCorte1 = 0, NotasDelCorte2 = 0, corte2 = 0, corte1 = 0;
		promedio1 = 0, promedio2 = 0, notas1 = 0, notas2= 0, sum1 = 0, sum2 = 0, porcentaje1 = 0, porcentaje2 = 0, PromSeccion = 0;
	}
}while (Otra == 1);
		
		printf("Finalizado, feliz dia!");															
		
	getch();
	return 0;
}

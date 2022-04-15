/*
 ============================================================================
 Name        : tp_1_prototipo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
	Precio vuelo Aerolíneas:
	Precio vuelo Latam:

3. Calcular todos los costos:
	a) Tarjeta de débito (descuento 10%)
	b) Tarjeta de crédito (interés 25%)
	c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
	d) Mostrar precio por km (precio unitario)
	e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

4. Informar Resultados
	Latam:
	a) Precio con tarjeta de débito: r
	b) Precio con tarjeta de crédito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	Aerolíneas:
	a) Precio con tarjeta de débito: r
	b) Precio con tarjeta de crédito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	La diferencia de precio es : r “

5. Carga forzada de datos

6. Salir

 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "calculos.h"


int main(void) {
	setbuf(stdout, NULL);

	int respuestaIngresada;
	int kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
	float debitoAerolineas;
	float debitoLatam;
	float creditoAerolineas;
	float creditoLatam;
	double bitcoinAerolineas;
	double bitcoinLatam;
	float unitarioAerolineas;
	float unitarioLatam;
	float diferenciaPrecios;

	kilometrosIngresados=0;
	precioAerolineas=0;
	precioLatam=0;

	do
		{
			printf(""
			"1) Ingresar Kilometros: (%d km)\n"
			"2) Ingresar precio de vuelos(Aerolineas(%.2f), Latam(%.2f)\n"
			"3) Calcular todos los costos\n"
			"4) Informar resultados\n"
			"5) Carga forzada de datos\n"
			"6) Salir\n",kilometrosIngresados, precioAerolineas, precioLatam);
			if(utn_getNumber(&respuestaIngresada, "Por favor elija una opcion \n", "Error! no se pudo guardar la seleccion\n", 1, 6, 2)==0)
			{
				switch(respuestaIngresada)
				{
					case 1:
						system("clear");
						utn_getNumber(&kilometrosIngresados, "Por favor ingrese los kilometros ", "Error! en edad ingresada\n", 1, 19483, 2);
					break;

					case 2:
						system("clear");
						printf(""
						"1) Aerolineas\n"
						"2) Latam\n");
						utn_getNumber(&respuestaIngresada, "\nPor favor elija una opcion ", "Error! en opcion ingresada\n", 1, 19483, 2);
						switch(respuestaIngresada)
						{
						case 1:
							system("clear");
							utn_getFloat(&precioAerolineas, "\n\nPor favor ingrese el precio de Aerolineas ", "Error! en float ingresado\n", 1, 250000, 2);
						break;

						case 2:
							system("clear");
							utn_getFloat(&precioLatam, "\n\nPor favor ingrese el precio de Latam ", "Error! en float ingresado\n", 1, 250000, 2);
						break;
						}
					break;
					case 3:
						// importes de Aerolineas
						calculaTarjetaDebito(&debitoAerolineas, precioAerolineas);
						calculaTarjetaCredito(&creditoAerolineas, precioAerolineas);
						calcularBitcoin(&bitcoinAerolineas, precioAerolineas);
						calcularUnitario(&unitarioAerolineas, precioAerolineas, kilometrosIngresados);

						// importes de Latam
						calculaTarjetaDebito(&debitoLatam, precioLatam);
						calculaTarjetaCredito(&creditoLatam, precioLatam);
						calcularBitcoin(&bitcoinLatam, precioLatam);
						calcularUnitario(&unitarioLatam, precioLatam, kilometrosIngresados);

						// diferencia
						calcularDiferencia(&diferenciaPrecios, precioAerolineas, precioLatam);
						printf("\nCalculos realizados\n\n");
					break;
					case 4:
						printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
						printf("a) Precio con tarjeta de debito: $%.2f\n",debitoAerolineas);
						printf("b) Precio con tarjeta de credito: $%.2f\n",creditoAerolineas);
						printf("c) Precio con pagando con bitcoin:  %.2f BTC\n",bitcoinAerolineas);
						printf("d) Precio unitario: %.2f\n\n",unitarioAerolineas);
						printf("Precio Latam: $%.2f\n",precioLatam);
						printf("a) Precio con tarjeta de debito: %.2f\n",debitoLatam);
						printf("b) Precio con tarjeta de credito: %.2f\n",creditoLatam);
						printf("c) Precio con pagando con bitcoin: %.2f BTC\n",bitcoinLatam);
						printf("d) Precio unitario: %.2f\n\n",unitarioLatam);
						printf("La diferencia de precio es: %.2f\n\n",diferenciaPrecios);

					break;
					case 5:
						utn_cargaForzada(&kilometrosIngresados, &precioAerolineas, &precioLatam, 7090, 162965, 159339);
					break;
				}

			}
			else
			{
				printf("\nPor favor elija una de las 6 opciones!\n\n");
			}

		}while(respuestaIngresada!=6);

	return EXIT_SUCCESS;
}

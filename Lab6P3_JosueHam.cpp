#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Cazador.h"
#include "Pilar.h"
#include "Katana.h"
using namespace std;

int random() {
	int aleatorio = 97 + rand() % (123 - 97);
	return aleatorio;
}

int menu() {
	cout << "\nMenu del Programa" << endl
		<< "1 -> Crear Cazador" << endl
		<< "2 -> Crear Pilar" << endl
		<< "3 -> Crear Luna Superior" << endl
		<< "4 -> Imprimir Cazadores y pilares" << endl
		<< "5 -> Imprimir lunas superiores" << endl
		<< "6 -> Simulacion" << endl
		<< "7 -> Salir" << endl
		<< "Ingrese la opcion que desea: " << endl;
	int numero;
	cin >> numero;
	return numero;
}

int main()
{
	srand(time(NULL));
	vector<Cazador> cazadoresAgregados;
	int opcionIngresada = menu();

	string coloresKatana[4];
	coloresKatana[0] = "Rojo";
	coloresKatana[1] = "Negro";
	coloresKatana[2] = "Morado";
	coloresKatana[3] = "Naranja";

	while (opcionIngresada != 5) {
		switch (opcionIngresada) {
		case 1: {//Crear Cazador

			cout << "Bienvenido a Crear Cazador" << endl;

			int poderKatana = 10 + rand() % (21 - 10);

			int posicionColorKatana = 0 + rand() % (4 - 0);

			Katana katCazador(poderKatana, coloresKatana[posicionColorKatana]);

			Respiracion respCazador;

			cout << "Ingrese el nombre del cazador: ";
			string nombreCazador;
			cin >> nombreCazador;

			int vidaCazador = 20 + rand() % (31 - 20);
			int ataqueCazador = 20 + rand() % (31 - 20);

			Cazador cazadorCreado(nombreCazador, vidaCazador, ataqueCazador, katCazador, respCazador);
			cazadoresAgregados.push_back(cazadorCreado);
			cout << "Cazador agregado correctamente" << endl;
			break;
		}
		case 2: {//Crear Pilar

			break;
		}
		case 3:{//Crear Luna Superior

			break;
		}
		case 4:{//Imprimir Cazadores y Pilares

			break;
		}
		case 5: {//Imprimir Lunas Superiores

			break;
		}
		case 6: {//Simulacion

			break;
		}
		default: 
			cout << "..." << endl;
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}
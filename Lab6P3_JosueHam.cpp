#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Cazador.h"
#include "Pilar.h"
#include "Katana.h"
#include "Respiracion_Agua.h"
#include "Respiracion_Fuego.h"
#include "Respiracion_Roca.h"
#include "Luna_Superior.h"
using namespace std;

int randomCazador() {
	int aleatorio = 20 + rand() % (31 - 20);
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
	vector<Luna_Superior> lunasAgregadas;
	vector<Pilar> pilaresAgregados;
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

			

			cout << "Ingrese el nombre del cazador: ";
			string nombreCazador;
			cin >> nombreCazador;

			Respiracion respCazador;
			cout << "Tipo de respiracion" << endl
				<< "1 -> Agua" << endl
				<< "2 -> Fuego" << endl
				<< "3 -> Roca" << endl
				<< "Ingrese el tipo de respiracion: " << endl;
			int tipoRespiracion;
			cin >> tipoRespiracion;
			int vidaCazador = randomCazador();
			int ataqueCazador = randomCazador();
			switch (tipoRespiracion){
			case 1: {

				Respiracion_Agua respAgua;

				Cazador cazadorCreado(nombreCazador, vidaCazador, ataqueCazador, katCazador, respAgua);
				cazadoresAgregados.push_back(cazadorCreado);
				cout << "Cazador agregado correctamente" << endl;
				break;
			}
			case 2: {
				Respiracion_Fuego respFuego;

				Cazador cazadorCreado(nombreCazador, vidaCazador, ataqueCazador, katCazador, respFuego);
				cazadoresAgregados.push_back(cazadorCreado);
				cout << "Cazador agregado correctamente" << endl;
				break;
			}
			case 3: {
				Respiracion_Roca respRoca;

				Cazador cazadorCreado(nombreCazador, vidaCazador, ataqueCazador, katCazador, respRoca);
				cazadoresAgregados.push_back(cazadorCreado);
				cout << "Cazador agregado correctamente" << endl;
			}
			default:
				cout << "???" << endl;
			}//Fin del switch para saber el tipo de respiracion en un cazador
			
			break;
		}
		case 2: {//Crear Pilar
			cout << "Bienvenido a Crear Pilar" << endl;
			cout << "Ingrese el nombre del pilar" << endl;
			string nombrePilar;
			cin >> nombrePilar;
			cout << "Tipo de respiracion" << endl
				<< "1 -> Agua" << endl
				<< "2 -> Fuego" << endl
				<< "3 -> Roca" << endl
				<< "Ingrese el tipo de respiracion: " << endl;
			int tipoRespiracion;
			cin >> tipoRespiracion;

			int vidaPilar = randomCazador();
			int ataquePilar = randomCazador();

			int poderKatana = 10 + rand() % (21 - 10);

			int posicionColorKatana = 0 + rand() % (4 - 0);

			Katana katPilar(poderKatana, coloresKatana[posicionColorKatana]);
			cout << "Cuantas lunas superiores ha vencido?" << endl;
			int cantLunasVencidas;
			cin >> cantLunasVencidas;
			int vidaExtra = 80 + rand() % (91 - 80);
			int ataqueExtra = 100;

			switch (tipoRespiracion) {
			case 1: {
				Respiracion_Agua respAgua;

				Pilar pilarCreado(nombrePilar, vidaPilar, ataquePilar, katPilar, respAgua, cantLunasVencidas, vidaExtra, ataqueExtra);
				pilaresAgregados.push_back(pilarCreado);
				cout << "Pilar agregado correctamente" << endl;
				break;
			}
			case 2: {
				Respiracion_Fuego respFuego;

				Pilar pilarCreado(nombrePilar, vidaPilar, ataquePilar, katPilar, respFuego, cantLunasVencidas, vidaExtra, ataqueExtra);
				pilaresAgregados.push_back(pilarCreado);
				break;
			}
			case 3: {
				Respiracion_Roca respRoca;

				Pilar pilarCreado(nombrePilar, vidaPilar, ataquePilar, katPilar, respRoca, cantLunasVencidas, vidaExtra, ataqueExtra);
				pilaresAgregados.push_back(pilarCreado);
				break;
			}	
			default: 
				cout << "!!!" << endl;
			}
			break;
		}
		case 3:{//Crear Luna Superior
			cout << "Bienvenido a crear Luna Superior" << endl;
			string nombreLuna;
			cout << "Ingrese el nombre de la Luna Superior" << endl;
			cin >> nombreLuna;
			int posicion = 0;

			if (lunasAgregadas.size() < 7)
			{
				posicion = lunasAgregadas.size() + 1;
			}
			else {
				posicion = lunasAgregadas.size() - 1;
			}

			int vidaLuna = 400 + rand() % (501 - 400);
			int ataqueLuna = 150 + rand() % (400 - 150);

			Luna_Superior lunaCreada(nombreLuna, posicion, vidaLuna, ataqueLuna);
			lunasAgregadas.push_back(lunaCreada);
			cout << "Luna creada y agregada correctamente" << endl;
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
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Cazador.h"
#include "Pilar.h"
#include "Katana.h"
#include "Respiracion.h"
#include "Respiracion_Agua.h"
#include "Respiracion_Fuego.h"
#include "Respiracion_Roca.h"
#include "Luna_Superior.h"
using namespace std;

void imprimirLunas(vector<Luna_Superior> lunas) {
	cout << "Lunas Superiores Disponibles" << endl;
	for (int i = 0; i < lunas.size(); i++)
	{
		cout << ""
	}
}

void imprimirCazadoresYPilares(vector<Cazador> cazadores, vector<Pilar> pilares) {
	cout << "Cazadores disponibles" << endl;
	int ataqueTotal = 0;
	for (int i = 0; i < cazadores.size(); i++)
	{
		ataqueTotal = cazadores[i].getAtaque() + cazadores[i].getKatana().getPoderKatana();// + cazadores[i].getRespiracion.rangoPoder();
		cazadores[i].setAtaque(ataqueTotal);
		cout << "Posicion: " << i << endl
			<< "Nombre: " << cazadores[i].getNombre() << endl
			<< "Vida: " << cazadores[i].getVida() << endl
			<< "Ataque: " << cazadores[i].getAtaque() << endl
			<< "Poder Katana: " << cazadores[i].getKatana().getPoderKatana() << endl
			<< "Color Katana: " << cazadores[i].getKatana().getColorKatana() << endl;
			//<< "Rango de Respiracion: " << cazadores[i].getRespiracion().rangoPoder() << endl;

	}

	for (int j = 0; j < pilares.size(); j++)
	{
		int ataque = pilares[j].getAtaque();
		int vida = pilares[j].getVida();
		pilares[j].setAtaque(ataque + pilares[j].getAtaqueExtra());
		pilares[j].setVida(vida + pilares[j].getVidaExtra());
	}
	cout << "Pilares disponibles" << endl;
	int ataqueTotal = 0;
	for (int k = 0; k < pilares.size(); k++)
	{
		ataqueTotal = pilares[k].getAtaque() + cazadores[k].getKatana().getPoderKatana();
		cout << "Posicion: " << k << endl
			<< "Nombre: " << pilares[k].getNombre() << endl
			<< "Vida: " << pilares[k].getVida() << endl
			<< "Ataque: " << pilares[k].getAtaque() << endl
			<< "Poder Katana: " << pilares[k].getKatana().getPoderKatana() << endl
			<< "Color Katana: " << pilares[k].getKatana().getColorKatana() << endl;
	}
}

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
	Luna_Superior lunaPrincipal("Ronal", 1, 450,300);
	lunasAgregadas.push_back(lunaPrincipal);

	vector<Pilar> pilaresAgregados;
	Katana katanaWalter(15, "Naranja");
	Respiracion_Agua respWalter;
	Pilar pilarPrincipal("Walter", 25, 30, katanaWalter, respWalter, 3, 85, 100);
	pilaresAgregados.push_back(pilarPrincipal);

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
			imprimirCazadoresYPilares(cazadoresAgregados, pilaresAgregados);
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
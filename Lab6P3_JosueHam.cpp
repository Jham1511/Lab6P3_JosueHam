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


void imprimirPilares(vector<Pilar> pilares) {
	for (int j = 0; j < pilares.size(); j++)
	{
		int ataque = pilares[j].getAtaque();
		int vida = pilares[j].getVida();
		pilares[j].setAtaque(ataque + pilares[j].getAtaqueExtra());
		pilares[j].setVida(vida + pilares[j].getVidaExtra());
	}
	cout << "Pilares disponibles" << endl;
	
	for (int k = 0; k < pilares.size(); k++)
	{
		cout << "Posicion: " << k << endl
			<< "Nombre: " << pilares[k].getNombre() << endl
			<< "Vida: " << pilares[k].getVida() << endl
			<< "Ataque: " << pilares[k].getAtaque() << endl
			<< "Poder Katana: " << pilares[k].getKatana().getPoderKatana() << endl
			<< "Color Katana: " << pilares[k].getKatana().getColorKatana() << endl;
	}
}
void imprimirLunas(vector<Luna_Superior> lunas) {
	cout << "Lunas Superiores Disponibles" << endl;
	for (int i = 0; i < lunas.size(); i++)
	{
		cout << "Posicion: " << i << endl
			<< "Nombre: " << lunas[i].getNombre() << endl
			<< "Posicion de la Luna Superior: " << lunas[i].getPosicion() << endl
			<< "Ataque: " << lunas[i].getAtaque() << endl
			<< "Vida: " << lunas[i].getRangoVida() << endl;
	}
}

void imprimirCazadoresYPilares(vector<Cazador> cazadores, vector<Pilar> pilares) {
	cout << "Cazadores disponibles" << endl;
	
	for (int i = 0; i < cazadores.size(); i++)
	{
		
		cout << "Posicion: " << i << endl
			<< "Nombre: " << cazadores[i].getNombre() << endl
			<< "Vida: " << cazadores[i].getVida() << endl
			<< "Ataque: " << cazadores[i].getAtaque() << endl
			<< "Poder Katana: " << cazadores[i].getKatana().getPoderKatana() << endl
			<< "Color Katana: " << cazadores[i].getKatana().getColorKatana() << endl
			<< "Rango de Respiracion: " << cazadores[i].getRespiracion().rangoPoder() << endl;

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
		ataqueTotal = pilares[k].getAtaque() + pilares[k].getKatana().getPoderKatana();
		cout << "Posicion: " << k << endl
			<< "Nombre: " << pilares[k].getNombre() << endl
			<< "Vida: " << pilares[k].getVida() << endl
			<< "Ataque: " << pilares[k].getAtaque() << endl
			<< "Poder Katana: " << pilares[k].getKatana().getPoderKatana() << endl
			<< "Color Katana: " << pilares[k].getKatana().getColorKatana() << endl
			<< "Rango de Respiracion: " << pilares[k].getRespiracion().rangoPoder() << endl;
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

	while (opcionIngresada != 7) {
		switch (opcionIngresada) {
		case 1: {//Crear Cazador

			cout << "Bienvenido a Crear Cazador" << endl;

			int poderKatana = 10 + rand() % (21 - 10);

			int posicionColorKatana = 0 + rand() % (4 - 0);

			Katana katCazador(poderKatana, coloresKatana[posicionColorKatana]);

			

			cout << "Ingrese el nombre del cazador: ";
			string nombreCazador;
			cin >> nombreCazador;

			
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
			imprimirLunas(lunasAgregadas);
			break;
		}
		case 6: {//Simulacion
			imprimirLunas(lunasAgregadas);
			cout << "Seleccione la posicion de una luna: ";
			int posLuna;
			cin >> posLuna;

			imprimirPilares(pilaresAgregados);
			cout << "Seleccione la posicion del pilar: ";
			int posPilar;
			cin >> posPilar;

			
			if (posLuna <= lunasAgregadas.size() && posPilar <= pilaresAgregados.size())
			{
				while (lunasAgregadas[posLuna].getRangoVida() != 0 || pilaresAgregados[posPilar].getVida() != 0) {
					int vidaPilar = pilaresAgregados[posPilar].getVida();
					int ataquePilar = pilaresAgregados[posPilar].getAtaque();
					int vidaLuna = lunasAgregadas[posLuna].getRangoVida();
					int ataqueLuna = lunasAgregadas[posLuna].getAtaque();
					cout << "Nombre: " << pilaresAgregados[posPilar].getNombre() << endl
						<< "Vida: " << pilaresAgregados[posPilar].getVida() << endl;
					int porcentajePilar = 1 + rand() % (101 - 1);
					int porcentajeLuna = 1 + rand() % (101 - 1);
					int ataqueCondicionadoPilar = ataquePilar * (porcentajePilar/100);
					int ataqueCondicionadoLuna = ataqueLuna * (porcentajeLuna/100);
					int probVidaPilar = 0 + rand() % (6 - 0);
					if (probVidaPilar == 5)
					{
						pilaresAgregados[posPilar].setVida(vidaPilar);
					}

					if (pilaresAgregados[posPilar].getLunasVencidas() > 0)
					{
						int ataqueLunasMuertas = 0;
						for (int i = 0; i < pilaresAgregados[posPilar].getLunasVencidas(); i++)
						{
							ataqueLunasMuertas += 20;
						}
						pilaresAgregados[posPilar].setAtaque(ataquePilar + ataqueLunasMuertas);
					}
					lunasAgregadas[posLuna].setRangoVida(vidaLuna - ataqueCondicionadoPilar);
					pilaresAgregados[posPilar].setVida(vidaPilar - ataqueCondicionadoLuna);
					cout << "Nombre: " << lunasAgregadas[posLuna].getNombre() << endl
						<< "Vida: " << lunasAgregadas[posLuna].getRangoVida() << endl;
				}//Fin del while

				if (lunasAgregadas[posLuna].getRangoVida() == 0)
				{
					cout << "Ganador del combate: " << pilaresAgregados[posPilar].getNombre() << endl;
					int lunasVencidas = pilaresAgregados[posPilar].getLunasVencidas();
					lunasVencidas++;
					pilaresAgregados[posPilar].setLunasVencidas(lunasVencidas);
				}
				else if (pilaresAgregados[posPilar].getVida() == 0) {
					cout << "Ganador del combate: " << lunasAgregadas[posLuna].getNombre() << endl;
				}

			}
			else {
				cout << "Fuera de los rangos disponibles" << endl;
			}
			break;
		}
		default: 
			cout << "..." << endl;
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}
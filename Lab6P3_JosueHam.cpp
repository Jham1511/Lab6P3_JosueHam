#include <iostream>
using namespace std;
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
	int opcionIngresada = menu();
	while (opcionIngresada != 5) {
		switch (opcionIngresada) {
		case 1: {

			break;
		}
		case 2: {

			break;
		}
		case 3:{

			break;
		}
		case 4:{

			break;
		}
		case 5: {

			break;
		}
		case 6: {

			break;
		}
		default: 
			cout << "..." << endl;
		}//Fin del switch
		opcionIngresada = menu();
	}//Fin del while
}
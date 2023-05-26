#include "Respiracion_Fuego.h"
#include <stdlib.h>
#include <time.h>

Respiracion_Fuego::Respiracion_Fuego() {

}

int Respiracion_Fuego::rangoPoder() {
	srand(time(NULL));
	int aleatorio = 80 + rand() % (101 - 80);
	return aleatorio;
}
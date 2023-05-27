#include "Respiracion_Agua.h"
#include "Respiracion.h"
#include <stdlib.h>
#include <time.h>

Respiracion_Agua::Respiracion_Agua() {

}
Respiracion_Agua::~Respiracion_Agua() {

}
int Respiracion_Agua::rangoPoder(){
	srand(time(NULL));
	int aleatorio = 60 + rand() % (81 - 60);
	return aleatorio;
}
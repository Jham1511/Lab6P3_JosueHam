#include "Respiracion_Roca.h"
#include <stdlib.h>
#include <time.h>

Respiracion_Roca::Respiracion_Roca(){

}
Respiracion_Roca::~Respiracion_Roca() {

}

int Respiracion_Roca::rangoPoder(){
	srand(time(NULL));
	int aleatorio = 100 + rand() % (121 - 100);
	return aleatorio;
}
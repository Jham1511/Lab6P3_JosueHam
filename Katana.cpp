#include "Katana.h"

Katana::Katana() {
	
}

Katana::Katana (int poder, string color) {
	this->colorKatana = color;
	this->poder = poder;
}

Katana::~Katana(){

}

int Katana::getPoderKatana() {
	return poder;
}

string Katana::getColorKatana() {
	return colorKatana;
}
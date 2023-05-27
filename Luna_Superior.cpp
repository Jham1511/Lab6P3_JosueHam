#include "Luna_Superior.h"

Luna_Superior::Luna_Superior() {

}

Luna_Superior::Luna_Superior(string nombre, int posicion, int vida, int ataque) {
	this->nombre = nombre;
	this->posicion = posicion;
	this->rangoVida = vida;
	this->ataque = ataque;
}
Luna_Superior::~Luna_Superior() {

}

string Luna_Superior::getNombre() {
	return nombre;
}

int Luna_Superior::getRangoVida() {
	return rangoVida;
}
int Luna_Superior::getPosicion() {
	return posicion;
}
int Luna_Superior::getAtaque() {
	return ataque;
}
void Luna_Superior::setAtaque(int nueAtaque) {
	this->ataque = nueAtaque;
}
void Luna_Superior::setRangoVida(int vida) {
	this->rangoVida = vida;
}
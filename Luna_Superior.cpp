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
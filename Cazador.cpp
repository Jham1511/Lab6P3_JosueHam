#include "Cazador.h"
Cazador::Cazador() {

}

Cazador::~Cazador() {

}

Cazador::Cazador(string nombre, int vida, int ataque, Katana kat, Respiracion tipoRespiracion) {
	this->nombre = nombre;
	this->vida = vida;
	this->puntosAtaque = ataque;
	this->kat = kat;
	this->tipoRespiracion = tipoRespiracion;
}

string Cazador::getNombre() {
	return nombre;
}
int Cazador::getVida() {
	return vida;
}

int Cazador::getAtaque() {
	return puntosAtaque;
}
Katana Cazador::getKatana() {
	return kat;
}
Respiracion Cazador::getRespiracion() {
	return tipoRespiracion;
}
void Cazador::setAtaque(int nueAtaque) {
	this->puntosAtaque = nueAtaque;
}
void Cazador::setVida(int nueVida) {
	this->vida = nueVida;
}
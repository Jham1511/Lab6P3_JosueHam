#include "Cazador.h"
Cazador::Cazador() {

}

Cazador::Cazador(string nombre, int vida, int ataque, Katana kat, Respiracion tipoRespiracion) {
	this->nombre = nombre;
	this->vida = vida;
	this->puntosAtaque = ataque;
	this->kat = kat;
	this->tipoRespiracion = tipoRespiracion;
}
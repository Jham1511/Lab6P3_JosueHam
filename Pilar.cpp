#include "Pilar.h"
#include "Cazador.h"
Pilar::Pilar() {

}

Pilar::Pilar(string nombre, int vida, int ataque, Katana kat, Respiracion tipoResp, int cantLunasVencidas, int vidaExtra, int ataqueExtra):
	Cazador(nombre, vida, ataque, kat, tipoResp){
	this->cantLunasVencidas = cantLunasVencidas;
	this->vidaExtra = vidaExtra;
	this->ataqueExtra = ataqueExtra;
}
Pilar::~Pilar() {

}
int Pilar::getLunasVencidas() {
	return cantLunasVencidas;
}
int Pilar::getAtaqueExtra() {
	return ataqueExtra;
}
int Pilar::getVidaExtra() {
	return vidaExtra;
}
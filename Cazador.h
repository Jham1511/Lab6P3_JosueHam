#pragma once
#include <string>
#include <iostream>
#include "Katana.h"
#include "Respiracion.h"
using namespace std;
class Cazador
{
private: 
	string nombre;
	int vida, puntosAtaque;
	Katana kat;
	Respiracion tipoRespiracion;
public:
	Cazador();
	Cazador(string, int, int, Katana, Respiracion);
	~Cazador();
	string getNombre();
	int getVida();
	int getAtaque();
	Katana getKatana();
	Respiracion getRespiracion();
	void setAtaque(int);
	void setVida(int);
};
#pragma once
#include <string>
#include <iostream>
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
};
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Luna_Superior
{
private:
	string nombre;
	int posicion;
	int rangoVida;
	int ataque;
public:
	Luna_Superior();
	Luna_Superior(string, int, int, int);
	~Luna_Superior();
	string getNombre();
	int getPosicion();
	int getRangoVida();
	int getAtaque();
	void setRangoVida(int);
	void setAtaque(int);
};
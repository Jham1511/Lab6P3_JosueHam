#pragma once
#include "Cazador.h"
#include "Katana.h"
#include "Respiracion.h"
#include <string>
#include <iostream>
using namespace std;
class Pilar : public Cazador
{
private:
	int cantLunasVencidas, vidaExtra, ataqueExtra;
public:
	Pilar();
	Pilar(string, int ,int, Katana, Respiracion, int ,int, int);
	~Pilar();
	int getLunasVencidas();
	int getVidaExtra();
	int getAtaqueExtra();
};
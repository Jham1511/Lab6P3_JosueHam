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
	int cantLunasVencidas, vidaExtra;
public:
	Pilar();
	Pilar(int, int) :: Cazador(string, int, int, Katana, Respiracion);
	~Pilar();
};
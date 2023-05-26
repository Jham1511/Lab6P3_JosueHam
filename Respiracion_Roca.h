#pragma once
#include "Respiracion.h"
class Respiracion_Roca : public Respiracion
{
public:
	Respiracion_Roca();
	~Respiracion_Roca();
	virtual int rangoPoder();
};
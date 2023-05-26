#pragma once
#include <string>
#include <iostream>
using namespace std;
class Katana
{
private:
	int poder;
	string colorKatana;
public:
	Katana();
	Katana(int, string);
	~Katana();
	int getPoderKatana();
	string getColorKatana();
};
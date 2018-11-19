#pragma once
#include"Casa.h"
using namespace std;

class Tu
{
public:

	string amIIn = "";
	vector<string> inventario;

	Tu();
	~Tu();
private:
	void mover(char dire);
};


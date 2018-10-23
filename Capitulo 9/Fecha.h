#pragma once
#include <iostream>
using namespace std;

class Fecha
{
public:
	int _d;
	int _m;
	int _a;
	bool _esValida;
	Fecha();
	Fecha(int d, int m, int a);
	~Fecha();
	int Validar(int d,int m, int a);
private:
};


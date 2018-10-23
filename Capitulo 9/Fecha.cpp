#include "Fecha.h"



Fecha::Fecha()
{
}

Fecha::Fecha(int d, int m, int a)
{

	_d = d;
	_m = m;
	_a = a;

}


Fecha::~Fecha()
{
}

int Fecha::Validar(int d, int m, int a)
{
	try
	{

		if (d < 1 || d>31)
		{
			throw d;
		}
		if (m < 1 || m>12)
		{
			throw m;
		}
		_d = d;
		_m = m;
		_a = a;
		_esValida = true;
	}
	catch (int e)
	{
		_esValida = false;
		cout << "La fecha no es valida" << endl;
	}
	return 0;
}

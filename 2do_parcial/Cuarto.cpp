#include "Cuarto.h"



string Cuarto::NOMBRE()
{

	return _nombre;
}

void Cuarto::visit()
{
	wasIHere = true;
}

Cuarto::Cuarto()
{
}

Cuarto::Cuarto(string nombre, string cone1, string cone2, string cone3, string item1, string item2, string item3)
{
	_nombre = nombre;
	_conect.push_back(cone1);
	_conect.push_back(cone2);
	_conect.push_back(cone3);
	_item.push_back(item1);
	_item.push_back(item2);
	_item.push_back(item3);
}


Cuarto::~Cuarto()
{
}

#include "Cuarto.h"



string Cuarto::NOMBRE()
{

	return _nombre;
}

void Cuarto::visit()
{
	wasIHere = true;
}

void Cuarto::nombre(string Nombre)
{
	_nombre = Nombre;
	return;
}

void Cuarto::conect(string Conect)
{
	_conect.push_back(Conect);
	return;
}

void Cuarto::item(string Item)
{
	_item.push_back(Item);
	return;
}

Cuarto::Cuarto()
{
}

Cuarto::Cuarto(string nombre, string cone1, string cone2, string cone3, string item1, string item2, string item3)
{
	_nombre = nombre;
	if (cone1 != "null")
	{
		_conect.push_back(cone1);
	}
	if (cone2 != "null")
	{
		_conect.push_back(cone2);
	}
	if (cone3 != "null")
	{
		_conect.push_back(cone3);
	}
	if (item1 != "null")
	{
		_item.push_back(item1);
	}
	if (item2 != "null")
	{
		_item.push_back(item2);
	}
	if (item3 != "null")
	{
		_item.push_back(item3);
	}
}


Cuarto::~Cuarto()
{
}

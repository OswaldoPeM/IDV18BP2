#include "Persona.h"



Persona::Persona()
{
	_edad = 21;
	_nombre = "Juan Perez";
}

Persona::Persona(string nombre, int edad)
{
	_edad = edad;
	_nombre = nombre;
}


Persona::Persona(int edad, string nombre)
{
	_edad = edad;
	_nombre = nombre;
}

Persona::~Persona()
{
}

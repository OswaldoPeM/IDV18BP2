#pragma once
#include <string>
using namespace std;
class Persona
{
public:
	int _edad;
	string _nombre;
	
	Persona();
	Persona(string nombre, int edad);
	Persona(int edad, string nombre);
	~Persona();
private:
};


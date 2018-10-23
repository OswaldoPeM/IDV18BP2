#include <iostream>
#include <vector>
#include "Fecha.h"
#include "Persona.h"
using namespace std;

/*
int main() {
	Fecha hoy;
	hoy.Validar(0, 12, 1993);
	//Fecha manana;

	//cout << "Introduce la fecha de manana dd/mm/aa. " << endl;
	//manana.Validar(cin.get(),cin.get(),cin.get());

	if (hoy._esValida) 
	{ 
		cout << "El dia de hoy es " << hoy._d << "/" << hoy._m << "/" << hoy._a << endl; 
	}
	//cout << "El dia de manana es " << manana._d << "/" << manana._m << "/" << manana._a << endl;


	cin.get();
	return 0;
}
*/

void organizar(vector<Persona> gente) {
	int x = 0;
	Persona joker;
	for (int i = 0; i < gente.size(); i++)
	{
		for (int j = 1; j < gente.size(); j++)
		{
			if (gente[j]._nombre < gente[j - 1]._nombre) {
				joker = gente[j];
				gente[j] = gente[j-1];
				gente[j-1] = joker;
			}
		}
		if (gente.size()/2<i)
		{
			x++;
		}
	}
	cout << "Nombres organizados." << endl;

	for (int i = 0; i < gente.size(); i++)
	{
		cout << gente[i]._nombre << " tinene " << gente[i]._edad << "anios" << endl;
	}
}
int main() {
	vector<Persona> gente;
	int edad;
	string nombre,siono="";
	bool agregar=true;
	cout << "Vamos a crear a un grupo de gente. " << endl;
	while (agregar)
	{
		cout << "Ingrese nombre y edad de la persona que quiere agregar al grupo de gente. " << endl;
		cin >> nombre;
		cin >> edad;

		gente.push_back(Persona(edad, nombre));

		cout << "Desea agregar a otra persona al grupo? " << endl;
		cin >> siono;
		if (!(siono == "si" || siono == "SI" || siono == "Si" || siono == "sI"))
		{
			agregar = false;
		}
		else
		{
			cout << "Agrege a alguien mas..." << endl;
		}
	}
	
	organizar(gente);
	cin.ignore();
	cin.get();

	return 0;
}



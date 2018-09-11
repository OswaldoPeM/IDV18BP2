#include "Includes.h"
using namespace std;


int main()
{
	cout << "Introduce tu nombre.(al terminar preciona la tecla enter).\n";
	string Nombre, Amigo; //Creacion de variale tipo string
	char Genero; //Genero de Amigo
	int Edad = 0; //Creamos una variable tipo int y le damos un valor por defecto de 0.
	cin >> Nombre; //Declaracion de 'Nombre' y 'edad'
	cout << "    Que onda " << Nombre << "\nTe acuerdas de nuestro amigo... no recuerdo su nombre tu lo recueradas,Cual era su nombre?\n";
	cin >> Amigo;
	cout << "Andale " << Amigo << ", le has visto ultimamente?, que cosas... ahora que lo recuerdo, menciono que estaba atravezando una etapa de problema con el genero. podras decirme con cual genero se identifica(m/f)\n";
	cin >> Genero;
	if (Genero == 'm')
	{
		cout << "\nEntonces dile a el que me llame que lo extrgno mucho, y que guarde mis lagrimas donde siempre las ha guardado.\n";
	}
	if (Genero == 'f')
	{
		cout << "\nEntonces dile a ella que me llame que la extrgno mucho, y que guarde mis lagrimas donde siempre las ha guardado.\n";
	}
	cout << "Por cierto, me perdi tus ultimos cumpleagnos que ya nisiquiera llevo la cuenta, podrias decirme tu edad\n";
	cin >> Edad;
	while (Edad <= 0 || Edad >= 110)
	{
		cout << "No tienes esa edad, no seas asi.(Ingrese edad valida ~1-109~)";
		cin >> Edad;
	}
	if (Edad < 12) 
	{
		cout << "En un agno mas cumpliras " << Edad + 1<<"\n";
	}
	if (Edad == 17 )
	{
		cout << "En un agno mas ya podras votar\n";
	}
	if (Edad > 70)
	{
		cout << "Disfruta el retiro, mi generacion no lo hara porque al parecer la productividad impera sobre la calidad de vida en este mundo de mierda.\n             Siempre tu amigo.\n\nOswaldo.\n";
	}
	cin.ignore();
	cin.get();
	return 0;
}
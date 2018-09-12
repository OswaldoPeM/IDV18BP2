#include "Includes.h"
using namespace std;
/*

Try This(
int main()
{
	char Nombre;
	double Edad;
	cout<<"Introduce tu nombre y tu edad.(preciona enter al terminar)\n";
	cin >> Nombre, Edad;
	cout << "Hola " << Nombre << ", asi que tienes " << Edad*12 << " meses. Genial.\n";

	retrun 0;
}

int main()
{
	cout << "Please enter a floating-point value: ";
	double n;
	cin >> n;
	int entero,raiz;
	entero = n;
	cout << "n == " << entero
	     << "\nn+1 == " << entero+1
	     << "\nthree times n == " << 3*entero
	     << "\ntwice n == " << entero*2
	     << "\nn squared == " << entero*entero
	     << "\nhalf of n == " << entero/2
	     << "\nsquare root of n == ";
	 raiz = sqrt(n)
	 cout << raiz << "\n"; 
}
int main()
{
	string previous = " "; 
	string current;
	while (cin>>current)
	{ 	if (previous == current)
		{	
			cout << "Palabra repetida: " << current << '\n';
		}
		previous = current;
	}
}
int Main() //error: 'Main' instead 'main'
{
	STRING s = "Goodbye, cruel world! "; // hay un error en el tipo de dato.

	cOut << S << '\n'; // 2 errors: 'cOut' instead 'cout', 'S' instead 's'
}
int main()
{
	double d = 0;
	while (cin>>d) 
	{ 
		
		int i = d;
		char c = i; 
		int i2 = c; 
		cout << "d==" << d 
		<< " i=="<< i 
		<< " i2==" << i2 
		<< " char(" << c << ")\n"; 
	}
}
)
*/
/*
int main()
{
	double km = 1.609;
	double miles;
	cout << "Introdusca las millas que quiere tranformar en kilometros.\n";
	cin >> miles;
	miles *= km;
	cout << "Son " << miles << " kilometros.\n";
	keep_window_open();
}

int main()
{
	int val1, val2;
	float division = 0;
	cout << "Ingrese dos valores enteros:\n";
	cin >> val1, val2;
	if (val1 > val2)
		cout << val1 << "es màs grande\n";
	if (val1 < val2)
		cout << val2 << " es màs grande\n";
	cout << "La suma es: " << val1 + val2 <<"\n";
	cout << "La resta es: " << val1 - val2 <<"\n";
	cout << "La multiplicacion es: " << val1 * val2 <<"\n";
	division = val1 / val2;
	if (val2 == 0)
	{
		cout<<"osea.... no se puede eso\n";
	}
	if (val2 != 0)
	{
		cout << "La divisiòn es: " << division << "\n";
	}
	keep_window_open();
}

int main()
{
	float val1, val2, division = 0;
	cout << "Ingrese dos valores enteros:\n";
	cin >> val1, val2;
	if (val1 > val2)
		cout << val1 << "es mas grande\n";
	if (val1 < val2)
		cout << val2 << " es mas grande\n";
	cout << "La suma es: " << val1 + val2 <<"\n";
	cout << "La resta es: " << val1 - val2 <<"\n";
	cout << "La multiplicacion es: " << val1 * val2 <<"\n";
	division = val1 / val2;
	if (val2 == 0.0000)
	{
		cout<<"osea.... no se puede eso\n";
	}
	if (val2 != 0.0000)
	{
		cout << "La divisiòn es: " << division << "\n";
	}
	keep_window_open();
}
*/
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
	keep_window_open();
	return 0;
}
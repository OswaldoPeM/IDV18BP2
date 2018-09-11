/*Arreglo: es un bloque donde la memoria que contiene varios datos secuenciados
++i pre incremento: incrementa el valor antes de usarlo
i++ post incremento: incrementa el  valor despues de usarlo
--i pre decremento: decrementa el valor antes de usarlo
i-- post decremento: decrementa el valor despues de usarlo
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{

	char a = 'p';
	char palabra[5] = {'H','e','l','l','o'};
	int numeros[7] = { 0 };

	//palabra[0] = 'H';
	//palabra[1] = 'e';
	//palabra[2] = 'l';
	//palabra[3] = 'l';
	//palabra[4] = 'o';
	
	int arraySize = (sizeof(numeros) / sizeof(int));
	cout << arraySize << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << palabra[i] << ' ';
	}
	cout << endl;

	cin.get();

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Hola mundo." << endl;
	cout << "¿cual es tu nombre? ";
	string nombre = "";
	cin >> nombre;
	cout << " Hola " << nombre << endl;
	cout << "Gusto en conocerte" << endl;

	cin.ignore();
	cin.get();
	return 0;
}
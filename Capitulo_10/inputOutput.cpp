#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	int suma = 0, numero;
	string archivo, buffer;
	cout << "introduce nombre del archivo al cual quieres  sumar las cantidades." << endl;
	cin >> archivo;
	ifstream inF(archivo,ios_base::in);

	while (getline(inF, buffer)) {
		while(inF >> numero) {
			suma += numero;
		}
	}
	cout << suma << " es la cantidad total sumando todos los digitos del documento." << endl;
	cin.ignore();
	cin.get();

	return 0;
}
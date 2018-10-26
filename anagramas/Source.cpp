#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Letras(string palabra,string copyPalabra, vector<string> &letras, vector<vector<string>> &grupos, bool isIn=false) {
	int tamaño = palabra.size();
	char comodin = ' ';
	string copia = copyPalabra;
	int vuelta = 0;
	for (int i = 0; i < palabra.size(); i++)
	{
		for (int j = 1; j < tamaño; j++)
		{
			if (palabra[j] < palabra[j - 1]) {
				comodin = palabra[j];
				palabra[j] = palabra[j - 1];
				palabra[j - 1] = comodin;
			}
		}
		if (i == palabra.size() / 2) {
			tamaño--;
		}
	}
	for (int i = 0; i < letras.size(); i++)
	{
		if (palabra == letras[i]) {
			isIn = true;
			grupos[i].push_back(copia);

		}
		vuelta = i;
	}
	if (!isIn)
	{
		letras.push_back(palabra);
		grupos[vuelta].push_back(copia);
	}
	return;
}

int main() {
	ifstream inFile("anagram.txt", ios_base::in);//Solo lectura.
	string buffer;
	vector<string> anagramas;
	vector<string> letras;
	vector<vector<string>> grupos;
	while (getline(inFile, buffer)) {
		anagramas.push_back(buffer);
	}
	for (int i = 0; i < anagramas.size(); i++)
	{
		Letras(anagramas[i], anagramas[i], letras, grupos);
	}

	for (int i = 0; i < grupos.size(); i++)
	{
		for (int j = 0; j < grupos[i].size(); j++)
		{
			cout << grupos[i][j] << endl;
		}
		cout << endl;
	}

	inFile.close();
	cin.get();
	return 0;
}

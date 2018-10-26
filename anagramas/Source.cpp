#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Letras(string palabra, string copia, vector<string> &letras, vector<vector<string>> &grupos) {
	int tamaño = palabra.size();
	char comodin = ' ';

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
			grupos[i].push_back(copia);
			return;
		}
	}
	letras.push_back(palabra);
	grupos.push_back(vector<string>());
	for (int i = 0; i < letras.size(); i++)
	{
		if (palabra == letras[i]) {
			grupos[i].push_back(copia);
			return;
		}
	}
}

int main() {
	ifstream inFile("anagram.txt", ios_base::in);//Solo lectura.
	string buffer;
	vector<string> anagramas;
	vector<string> letras;
	vector<vector<string>> grupos;
	int valor = 0;
	string comodin = "";
	while (getline(inFile, buffer)) {
		anagramas.push_back(buffer);
	}
	for (int i = 0; i < anagramas.size(); i++)
	{
		Letras(anagramas[i], anagramas[i], letras, grupos);
	}

	for (int i = 0; i < grupos.size(); i++)
	{
		for (int j = 0; j < grupos[i].size()-1; j++)
		{
			valor = grupos[j].size();
			for (int k = 0; k < valor; k++)
			{
				
				if (grupos[i][j + 1] < grupos[i][j]) {
					comodin = grupos[i][j + 1];
					grupos[i][j + 1] = grupos[i][j];
					grupos[i][j] = comodin;
				}
				
			}
		}
	}

	for (int i = 0; i < grupos.size(); i++)
	{
		for (int j = 0; j < grupos[i].size(); j++)
		{
			cout <<" "<< grupos[i][j] << endl;
		}
		cout << endl;
	}

	inFile.close();
	cin.get();
	return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
void print(vector<int> numeros)
{

	for (int i = 0; i < numeros.size(); i++)
	{
		cout << numeros[i] << " ";
	}

	cout << endl;

}

int main()
{
	vector<int> numeros{ 1,2,3,4,5,6,7,8,9,0 };
	print(numeros);
	cin.get();
	return 0;
}
*/


/*

void vectonacci(int x, int y, int n, vector<int> serie) { // aguanta hasta 47 iteraciones.
	cout << "numero de vuelas: " << endl;
	cin >> n;

	if (n >= 48)
	{
		cout << "No se pueden dar mas de 47 pasos de la serie fibo. " << endl;
		return;
	}
	for (int i = 2; i < n; i++)
	{
		serie.push_back(serie[i - 2] + serie[i - 1]);
	}

	for (int i = 0; i < serie.size(); i++)
	{
		cout << serie[i] << " ";
	}


	cout << endl;
}

int main() {
	int x = 0, y = 1,n='\0';
	vector<int> serie;
	serie = { x,y };

	vectonacci(x,y,n,serie);
	cin.ignore();
	cin.get();
	return 0;
}
*/


/*
void revector(vector<int> reve) {
	int joker = 0;
	for (int i = 0; i < reve.size()/2; i++)
	{
		joker = reve[i];
		reve[i] = reve[reve.size()-1 -i];
		reve[reve.size() - 1 - i] = joker;
	}
	for (int i = 0; i < reve.size(); i++)
	{
		cout << reve[i] << " ";
	}


	cout << endl;
}
int main() {
	vector<int> reve;
	reve = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	revector(reve);
	cin.get();
	return 0;
}
*/


/*
void revector(vector<string> reve) {
	string joker = "no";
	for (int i = 0; i < reve.size()/2; i++)
	{
		joker = reve[i];
		reve[i] = reve[reve.size()-1 -i];
		reve[reve.size() - 1 - i] = joker;
	}
	for (int i = 0; i < reve.size(); i++)
	{
		cout << reve[i] << " ";
	}


	cout << endl;
}
int main() {
	vector<string> reve;
	reve = { "palabra", "segunda","tercera" };

	revector(reve);
	cin.get();
	return 0;
}
*/


void vectorage(vector<string> nombres, vector<int> edades) {
	for (int i = 0; i < nombres.size(); i++)
	{
		cout << nombres[i] << " tiene " << edades[i] << " agnos." << endl;
	}
	int vueltas = nombres.size();
	int joker = 0;
	string guason = "";
	for (int i = 0; i < nombres.size(); i++)
	{
		for (int j = 0; j < vueltas; j++)
		{
			if (edades[i]<edades[j])
			{
				joker = edades[i];
				edades[i] = edades[j];
				edades[j] = joker;
				guason = nombres[i];
				nombres[i] = nombres[j];
				nombres[j] = guason;
			}
		}
		if (i>edades.size()/2)
		{
			vueltas--;
		}
	}

	cout << endl;
	for (int i = 0; i < nombres.size(); i++)
	{
		cout << nombres[i] << " tiene " << edades[i] << " agnos." << endl;
	}



}

int main() {
	vector<string> nombres;
	vector<int> edades;

	nombres = { "Melquiades","Ramon","Joselo","Roberta" };
	edades = { 87,21,57,17 };

	vectorage(nombres, edades);
	cin.get();
	return 0;
}



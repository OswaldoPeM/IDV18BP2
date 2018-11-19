#include<iostream>
#include<fstream>
#include<string>
#include "Tu.h"
using namespace std;

Cuarto construirCuarto(string nombre,string cone1,string cone2,string cone3,string item1,string item2,string item3) {
	Cuarto New(nombre, cone1, cone2, cone3, item1, item2, item3);
	return New;
}
Casa construirCasa() {
	ifstream inFile("Cuartos.txt");
	string nombre,cone1,cone2,cone3,item1,item2,item3;
	Casa laCasa;
	Cuarto New;
	int piso = -1;
	char opcion=' ';
	while (inFile>>opcion>>nombre>>cone1>>cone2>>cone3>>item1>>item2>>item3){
		switch (opcion)
		{
		case '-':
			laCasa.piso();// tecnicamente no es un piso pero si una linea, donde se localizaran los cuartos  de esa linea.
			piso += 1;
			break;
		case 'N':
			New=construirCuarto(nombre, cone1, cone2, cone3, item1, item2, item3);// hace un cuarto
			laCasa.Build(New, piso);
			break;
		case 'X':
			laCasa.Build(New, piso);
			break;
		default:
			break;
		}
	}

	inFile.close();
	return laCasa;
}
void showMap(Casa casa,Tu jugador) {
	for (int i = 0; i < casa._TuCasa.size(); i++)
	{
		for (int j = 0; j < casa._TuCasa[i].size(); j++)
		{
			if (casa._TuCasa[i][j].NOMBRE()=="Null") {
				cout << "___";
			}
			else
			{
				cout << "[";
				if (jugador.amIIn==casa._TuCasa[i][j].NOMBRE())
				{
					cout << "X";
				}
				else
				{
					cout << " ";
				}
				cout << "]";
			}
		}
		cout << endl;
	}
	return;
}
int main()
{
	Casa casa = construirCasa();
	Tu jugador;
	showMap(casa,jugador);
	cin.get();
	return 0;
}
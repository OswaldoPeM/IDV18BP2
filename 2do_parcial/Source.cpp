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
	ifstream inFile("cuartitos.txt");
	string opcion,nombre,cone1,cone2,cone3,item1,item2,item3;
	bool cuartoLista = true;
	Casa laCasa;
	Cuarto *cuartito;

	int piso = 0;
	laCasa.piso();
	while (cuartoLista) {
		inFile >> opcion;
		switch (opcion[0])
		{
		case 'N':
			*cuartito.nombre(opcion);
			break;
		case 'C':
			break;
		case 'I':
			break;
		case '+':
			laCasa.Build(*cuartito, piso);
			delete cuartito;
			Cuarto*cuartito;
			break;
		case 'n':
			laCasa.Build(*cuartito, piso);
			delete cuartito;
			Cuarto*cuartito;
			break;
		case '-':
			laCasa.piso();
			break;
		case 'F':
			cuartoLista = false;
			break;
		default:
			break;
		}

	}
		
	
	//while (inFile>>opcion>>nombre>>cone1>>cone2>>cone3>>item1>>item2>>item3){
	//	switch (opcion[0])
	//	{
	//	case '-':
	//		laCasa.piso();// tecnicamente no es un piso pero si una linea, donde se localizaran los cuartos  de esa linea.
	//		piso += 1;
	//		break;
	//	case 'N':
	//		New = construirCuarto(nombre, cone1, cone2, cone3, item1, item2, item3);// hace un cuarto
	//		laCasa.Build(cuartito, piso);
	//		nombre = "Null";
	//		break;
	//	default:
	//		break;
	//	}

	//}

	inFile.close();
	return laCasa;
}

void showMap(Casa casa,Tu jugador) {
	for (int i = 0; i < casa._TuCasa.size(); i++)
	{
		for (int j = 0; j < casa._TuCasa[i].size(); j++)
		{
			if (casa._TuCasa[i][j].NOMBRE()=="null") {
				cout << "___";
			}
			else
			{
				if (casa._TuCasa[i][j].wasIHere)
				{
					cout << "[";
					if (jugador.amIIn == casa._TuCasa[i][j].NOMBRE())
					{
						cout << "X";
					}
					else
					{
						cout << " ";
					}
					cout << "]";
				}
				else
				{
					cout << "___";
				}
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
#include<iostream>
#include<fstream>
#include<string>
#include "Tu.h"

using namespace std;
void texto(int columna, int fila, bool visitado,string nombre) {// muestra el texto  segun si ya has visitado.
	string buffer;
	bool esEste;

	if (!(visitado)) {
		ifstream inFile("Primera.txt");
		while (getline(inFile, buffer))
		{
			esEste = true;
			for (int i = 0; i < nombre.size(); i++)
			{

				if (buffer[i] != nombre[i])
				{
					esEste = false;
					break;
				}
			}
			if (esEste)
			{
				cout << buffer;
			}
		}
		inFile.close();
	}
	if (visitado) {
		ifstream inFile("Segunda.txt");
		while (getline(inFile, buffer))
		{
			esEste = true;
			for (int i = 0; i < nombre.size(); i++)
			{
				if (buffer[i] != nombre[i])
				{
					esEste = false;
					break;
				}
			}
			if (esEste)
			{
				cout << buffer;
			}
		}
		inFile.close();
	}

	cin.ignore();
	cin.get();
	return;
}
Tu moverse(Tu jugador,Casa &elcasa) {
	string nuevoLugar;
	int opcion=5,fila,columna,maximo;
	jugador.placeBefore = jugador.amIIn;
	cout << "Seleccione la opcion para " << endl;
	for (int i = 0; i < elcasa._TuCasa.size(); i++)
	{
		for (int j = 0; j < elcasa._TuCasa[i].size(); j++)
		{
			if (jugador.amIIn == elcasa._TuCasa[i][j].NOMBRE()) {
				fila = i;
				columna = j;
				for (int k = 0; k < elcasa._TuCasa[i][j]._conect.size(); k++)
				{
					cout << k + 1 << ". Moverte a " << elcasa._TuCasa[i][j]._conect[k] << endl; //muestra opciones a donde puedes moverte
					maximo = k;
				}
			}
		} 
	}
	while ((opcion<1||opcion>maximo+1)) // se asegura de que puedas moverte y no salte un error.
	{
		cout << "Introduce una opcion valida :";
	    cin >> opcion;
	}
	
	jugador.amIIn = elcasa._TuCasa[fila][columna]._conect[opcion-1]; //Cambia tu ubicacion
	for (int i = 0; i < elcasa._TuCasa.size(); i++) //visita el cuarto
	{
		for (int j = 0; j < elcasa._TuCasa[i].size(); j++)
		{
			if (jugador.amIIn == elcasa._TuCasa[i][j].NOMBRE()) {

				texto(i, j, elcasa._TuCasa[i][j].wasIHere,elcasa._TuCasa[i][j].NOMBRE());

				elcasa._TuCasa[i][j].visit();
			}


		}
	}

	return jugador;
}
void regresar(Tu &jugador) { 
	jugador.amIIn = jugador.placeBefore;
}
void saveData(Tu estado) {
	ofstream outFile("SaveData.txt", ios_base::out);
	outFile << "N" << estado.amIIn;
	outFile << "B" << estado.placeBefore;
	for (int i = 0; i < estado.inventario.size(); i++)
	{
		outFile << " " << "I"<< estado.inventario[i];
	}
	for (int i = 0; i < estado.lugares.size(); i++)
	{
		outFile << " " << "L" << estado.lugares[i];
	}
	for (int i = 0; i < estado.solvedplaces.size(); i++)
	{
		outFile << " " << "S" << estado.solvedplaces[i];
	}
	outFile.close();
	return;
}
Tu loadData() {
	Tu estado;
	string buffer,comodin="";
	ifstream inFile("SaveData.txt", ios_base::in);
	while (inFile>>buffer)
	{
		switch (buffer[0])
		{
		case 'N':
			for (int i = 1; i < buffer.size(); i++)
			{
				comodin += buffer[i];
			}
			estado.amIIn = comodin;
			comodin = "";
			break;
		case 'B':
			for (int i = 1; i < buffer.size(); i++)
			{
				comodin += buffer[i];
			}
			estado.placeBefore = comodin;
			comodin = "";
			break;
		case'I':
			for (int i = 1; i < buffer.size(); i++)
			{
				comodin += buffer[i];
			}
			estado.inventario.push_back(comodin);
			comodin = "";
			break;
		case'L':
			for (int i = 1; i < buffer.size(); i++)
			{
				comodin += buffer[i];
			}
			estado.lugares.push_back(comodin);
			comodin = "";
			break;
		case'S':
			for (int i = 1; i < buffer.size(); i++)
			{
				comodin += buffer[i];
			}
			estado.solvedplaces.push_back(comodin);
			comodin = "";
			break;
		default:
			break;
		}
	}
	inFile.close();
	return estado;
}
Cuarto construirCuarto(string nombre,string cone1,string cone2,string cone3,string item1,string item2,string item3,Tu jugador) {
	for (int i = 0; i < jugador.inventario.size(); i++)
	{
		if (item1 == jugador.inventario[i])
		{
			item1 = "null";
		}
		if (item2 == jugador.inventario[i])
		{
			item2 = "null";
		}
		if (item3 == jugador.inventario[i])
		{
			item3 = "null";
		}
	}
	Cuarto New(nombre, cone1, cone2, cone3, item1, item2, item3);
	for (int i = 0; i < jugador.lugares.size(); i++)
	{
		if (jugador.lugares[i] == nombre) {
			New.visit();
		}
	}
	for (int i = 0; i < jugador.solvedplaces.size(); i++)
	{
		if (jugador.solvedplaces[i] == nombre) {
			New.solve();
		}
	}
	return New;
}
Casa construirCasa(Tu jugador) {
	ifstream inFile("Cuartos.txt");
	string opcion,nombre,cone1,cone2,cone3,item1,item2,item3;
	bool cuartoLista = true;
	Casa laCasa;
	Cuarto cuartito;
	int piso = -1;

	/*int piso = 0;
	laCasa.piso();
	while (cuartoLista) {
		inFile >> opcion;
		switch (opcion[0])
		{
		case 'N':
			cuartito.nombre(opcion);
			break;
		case 'C':
			break;
		case 'I':
			break;
		case '+':
			laCasa.Build(cuartito, piso);
			break;
		case 'n':
			laCasa.Build(cuartito, piso);
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

	}*/
		
	
	while (inFile>>opcion>>nombre>>cone1>>cone2>>cone3>>item1>>item2>>item3){
		switch (opcion[0])
		{
		case '-':
			laCasa.piso();// tecnicamente no es un piso pero si una linea, donde se localizaran los cuartos  de esa linea.
			piso += 1;
			break;
		case 'N':
			cuartito = construirCuarto(nombre, cone1, cone2, cone3, item1, item2, item3,jugador);// hace un cuarto
			laCasa.Build(cuartito, piso);
			nombre = "Null";
			break;
		default:
			break;
		}

	}

	inFile.close();
	return laCasa;
}
void showMap(Casa casa,Tu jugador) {
	system("cls");
	for (int i = 0; i < casa._TuCasa.size(); i++)
	{
		for (int j = 0; j < casa._TuCasa[i].size(); j++)
		{
			if (casa._TuCasa[i][j].NOMBRE()=="null") {
				cout << "   ";
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
					cout << "   ";
				}
			}
		}
		cout << endl;
	}

	return;
}

int main()
{
	char partida;
	Tu jugador;
	cout << "Desea cargar la partida?" << endl << "Y/N" << endl;
	cin >> partida;
	if (partida == 'y'|| partida=='Y') {
		jugador = loadData();
	}
	
	Casa casa = construirCasa(jugador);
	jugador.amIIn = "Jardin";
	casa._TuCasa[3][2].visit();
	while (! (casa._TuCasa[0][0].solved))
	{

	jugador = moverse(jugador, casa);
	showMap(casa,jugador);

	}
	cin.ignore();
	cin.get();
	return 0;
}
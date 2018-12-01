#include<iostream>
#include<fstream>
#include<string>
#include "Tu.h"

using namespace std;
void recojer(Tu &jugador, Cuarto *cuarto) {
	system("cls");
	int opcion = 250, maximo = 0;

	for (int i = 0; i < cuarto->_item.size(); i++)
	{
		cout << "Presiona " << i + 1 << " para tomar " << cuarto->_item[i]<<endl;
		maximo=i;
	}

	while (!(opcion>0 && opcion<maximo + 2))
	{
		cout << "Introduce una opcion valida :";
		cin >> opcion;
	}
	cout << endl;
	opcion--;
	jugador.inventario.push_back(cuarto->_item[opcion]);
	if (maximo > 0) {

		for (int i = 0; i < cuarto->_item.size(); i++)
		{
			if (i == opcion) {
				while (i < cuarto->_item.size()-1)
				{
					cuarto->_item[i] = cuarto->_item[i + 1];
					i++;
				}
				break;
			}
		}
	}
	cuarto->_item.pop_back();
	//cuarto->_item[opcion].erase;
	return;

}
void usarItem(Tu &jugador) {
	system("cls");
	int maximo = 5, opcion = 250;
	cout << "Tienes estos items " << endl;
	for (int i = 0; i < jugador.inventario.size(); i++)
	{
		cout << i + 1 << ". " << jugador.inventario[i] << endl;
	}
	string cuarto, solucion, item;
	while (!(opcion>0 && opcion<maximo + 2))
	{
		cout << "Introduce una opcion valida :";
		cin >> opcion;
	}
	opcion--;
	ifstream inFile("Mision.txt");
	while (inFile >> cuarto >> solucion)
	{
		if (cuarto == jugador.estoy->NOMBRE()) {
			if (solucion == jugador.inventario[opcion]) {
				jugador.usedItems.push_back(jugador.inventario[opcion]);
				jugador.estoy->solve();
				jugador.solvedplaces.push_back(jugador.amIIn);
				if (opcion==jugador.inventario.size())
				{
					jugador.inventario.pop_back();
					inFile.close();
					return;
				}
				else
				{

					for (int i = 0; i < jugador.inventario.size(); i++)
					{
						if (i == opcion) {
							while (i < jugador.inventario.size() - 1)
							{
								jugador.inventario[i] = jugador.inventario[i + 1];
								i++;
							} 
							break;
						}
					}
					jugador.inventario.pop_back();
					inFile.close();
					return;
				}
			}
		}
	}
	cout << "No has solucionado nada." << endl;
	inFile.close();
	return;
}
void texto(int columna, int fila, bool visitado,string nombre) {// muestra el texto  segun si ya has visitado.
	string buffer;
	bool esEste;
	system("cls");

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
	int opcion=250,fila,columna,maximo;
	jugador.placeBefore = jugador.amIIn;
	jugador.estuve = jugador.estoy;
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
	while (!(opcion>0 && opcion<maximo+2)) // se asegura de que puedas moverte y no salte un error.
	{
		cout << "Introduce una opcion valida :";
	    cin >> opcion;
	}
	opcion--;
	jugador.amIIn = elcasa._TuCasa[fila][columna]._conect[opcion]; //Cambia tu ubicacion
	for (int i = 0; i < elcasa._TuCasa.size(); i++) //visita el cuarto
	{
		for (int j = 0; j < elcasa._TuCasa[i].size(); j++)
		{
			if (jugador.amIIn == elcasa._TuCasa[i][j].NOMBRE()) {

				texto(i, j, elcasa._TuCasa[i][j].wasIHere,elcasa._TuCasa[i][j].NOMBRE());
				if (!elcasa._TuCasa[i][j].wasIHere)
				{
					jugador.lugares.push_back(elcasa._TuCasa[i][j].NOMBRE());
				}
				elcasa._TuCasa[i][j].visit();
				jugador.estoy = &elcasa._TuCasa[i][j];
			}
		}
	}
	return jugador;
}
void regresar(Tu &jugador) { 
	jugador.amIIn = jugador.placeBefore;
	jugador.estoy = jugador.estuve;
}
void saveData(Tu estado) {
	ofstream outFile("SaveData.txt", ios_base::out);
	outFile << "N" << estado.amIIn;
	outFile << " ";
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
	for (int i = 0; i < estado.usedItems.size(); i++)
	{
		outFile << " " << "U" << estado.usedItems[i];
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
		case'U':
			for (int i = 1; i < buffer.size(); i++)
			{
				comodin += buffer[i];
			}
			estado.usedItems.push_back(comodin);
			comodin = "";
			break;
		default:
			break;
		}
	}
	inFile.close();
	return estado;
}
Cuarto construirCuarto(string nombre,string cone1,string cone2,string cone3,string item1,string item2,string item3,Tu &jugador) {
	for (int i = 0; i < jugador.inventario.size(); i++) // si tengo este intem a en el inventario no agregarlo a la casa.
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
	for (int i = 0; i < jugador.usedItems.size(); i++) //si ya ehe usado este item, no agregar a la casa.
	{
		if (item1 == jugador.usedItems[i])
		{
			item1 = "null";
		}
		if (item2 == jugador.usedItems[i])
		{
			item2 = "null";
		}
		if (item3 == jugador.usedItems[i])
		{
			item3 = "null";
		}
	}
	Cuarto New(nombre, cone1, cone2, cone3, item1, item2, item3);
	/*if (nombre == jugador.amIIn) {
		jugador.estoy = &New;
	}
	if (nombre == jugador.placeBefore) {
		jugador.estuve = &New;
	}*/
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
Casa* construirCasa(Tu &jugador) {
	ifstream inFile("Cuartos.txt");
	string opcion,nombre,cone1,cone2,cone3,item1,item2,item3;
	bool cuartoLista = true;
	Casa *laCasa = new Casa();
	Cuarto cuartito;
	int piso = -1;

	
	while (inFile>>opcion>>nombre>>cone1>>cone2>>cone3>>item1>>item2>>item3){
		switch (opcion[0])
		{
		case '-':
			laCasa->piso();// tecnicamente no es un piso pero si una linea, donde se localizaran los cuartos  de esa linea.
			piso += 1;
			break;
		case 'N':
			cuartito = construirCuarto(nombre, cone1, cone2, cone3, item1, item2, item3,jugador);// hace un cuarto
			laCasa->Build(cuartito, piso);
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
Tu ubicacion(Casa casa, Tu jugador) {
	for (int i = 0; i < casa._TuCasa.size(); i++)
	{
		for (int j = 0; j < casa._TuCasa[i].size(); j++)
		{
			if (casa._TuCasa[i][j].NOMBRE() == jugador.amIIn) {
				jugador.estoy = &casa._TuCasa[i][j];
			}
			if (casa._TuCasa[i][j].NOMBRE() == jugador.placeBefore) {
				jugador.estuve = &casa._TuCasa[i][j];
			}
		}
	}
	return jugador;
}
int main()
{
	bool map= false;
	char partida;
	Tu jugador;
	cout << "Desea cargar la partida?" << endl << "Y/N" << endl;
	cin >> partida;
	if (partida == 'y'|| partida=='Y') {
		jugador = loadData();
	}
	
	Casa* casa = construirCasa(jugador);
	for (int i = 0; i < casa->_TuCasa.size(); i++)
	{
		for (int j = 0; j < casa->_TuCasa[i].size(); j++)
		{
			if (casa->_TuCasa[i][j].NOMBRE() == jugador.amIIn) {
				jugador.estoy = &casa->_TuCasa[i][j];
			}
			if (casa->_TuCasa[i][j].NOMBRE() == jugador.placeBefore) {
				jugador.estuve = &casa->_TuCasa[i][j];
			}
		}
	}
	if (partida=='N'||partida=='n')
	{

	jugador.amIIn = "Jardin";
	jugador.lugares.push_back(jugador.amIIn);
	jugador.solvedplaces.push_back(jugador.amIIn);
	casa->_TuCasa[3][2].visit();
	casa->_TuCasa[3][2].solve();
	jugador.estoy = &casa->_TuCasa[3][2];
	}
	
	while (!(casa->_TuCasa[0][0].solved))
	{
		system("cls");
		cout << "Estas en " << jugador.estoy->NOMBRE() << endl;
		if (jugador.estoy->solved) {
			cout << "Presiona W para moverte" << endl;
		}
		if (jugador.estoy->solved && (jugador.estoy->_item.size() > 0 )) {
			cout << "Presiona R para buscar en este lugar algo que tomar" << endl;
		}
		if (jugador.estuve->NOMBRE() != "Null")
		{
			cout << "Presiona V para volver al cuarto anterior" << endl;
		}
		cout << "Presiona U para usar item en esta habitacion\nPresiona S para salvar el juego\nPresiona M para mostrar el mapa\nPresiona Q para salir del juego" << endl;
		
		if (map) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
			showMap(*casa, jugador);
		}

		cin >> partida;

		switch (partida)
		{
		case'm':
		case 'M':
			if (map)
			{
				map = false;
			}
			if (!map) {
				map = true;
			}
			break;
		case 'w':
		case 'W':
			if (jugador.estoy->solved)
			{
				jugador = moverse(jugador, *casa);
			}
			else
			{
				cout << "Tienes que resolver antes este lugar" << endl;
			}
			break;
		case'r':
		case 'R':
			if (jugador.estoy->solved && (jugador.estoy->_item.size() > 0))
			{
				recojer(jugador, jugador.estoy);
			}
			else
			{
				cout << "Tienes que resolver antes este lugar" << endl;
			}
			break;
		case's':
		case 'S':
			saveData(jugador);
			break;
		case'u':
		case 'U':
			if (jugador.inventario.size()>0)
			{
			usarItem(jugador);
			}
			else
			{
				cout << "\nno tienes items.\n";
			}
			break;
		case'v':
		case'V':
			if (jugador.estuve->NOMBRE() != "Null") {
			regresar(jugador);
			}
			break;
		case 'q':
		case 'Q':
			cout << "Quieres salir? Y/N" << endl;
			cin >> partida;
			if (partida == 'y' || partida == 'Y') {
				partida = '/';
			}
		default:
			break;
		}
		if (partida == '/') { break; }
	}

	if (casa->_TuCasa[0][0].solved)
	{
		cout << "Felicidades has hecho." << endl;
	}
	delete casa;
	cin.ignore();
	cin.get();
	return 0;
}
#include <iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream inFile("Akinator.txt");
struct Nodo
{
	string animal;
	Nodo* der;
	Nodo* izq;
};
void destructor(Nodo *&akinator) {
	if (akinator->der != NULL) { destructor(akinator->der); }
	if (akinator->izq != NULL) { destructor(akinator->izq); }
	if (akinator->der == NULL && akinator->izq == NULL) { 
		delete akinator;
		return;
	}
}
Nodo* crearNod(string animal) {
	Nodo* nodo = new Nodo;
	nodo->animal = animal;
	nodo->der = NULL;
	nodo->izq = NULL;
	return nodo;
}
Nodo *crearAkinator(Nodo*&akinator) {
	string animal = akinator->animal;
	int es;
	if (akinator->der == NULL) {
		inFile >> es;
		if (es==1) {
		}
		else {
			akinator->izq = crearNod(akinator->animal);
			inFile >> animal;
			akinator->der = crearNod(animal);
			inFile >> animal;
			akinator->animal = animal;
		}
	}
	else
	{
		inFile >> es;
		if (es == 1){
			crearAkinator(akinator->der);
		}
		else {
			crearAkinator(akinator->izq);
		}
	}
	return akinator;
}
bool preguntar() {
	char opcion;
	cout << " Y/N" << endl;
	cin >> opcion;
	return (opcion == 'y' || opcion == 'Y');
}
Nodo* adivinar(Nodo *&akinator) {

	string animal=akinator->animal;
	if (akinator->der == NULL) {
		cout << "Estas pensando en " << animal << "?";
		if (preguntar()) {
			fstream onFile("Akinator.txt", ios_base::app);
			onFile << " "<<1;
			onFile.close();
			cout << "Soy un Geniosss"<<endl;
			
		}
		else {
			fstream onFile("Akinator.txt", ios_base::app);
			onFile << " " << 0;
			cout << "En que animal estabas pensando?" << endl;
			akinator->izq = crearNod(akinator->animal);
			cin >> animal;
			onFile << " " << animal;
			akinator->der = crearNod(animal);
			cout << "Que si puede hacer " << animal << " que " << akinator->izq->animal << " no?\n" << animal << " puede(en una palabra) :";
			cin >> animal;
			onFile << " " << animal;
			onFile.close();
			akinator->animal = animal;
			cout << endl << "Lo siento, no pude adivinar tu animal, pero la proxima lo hare(si piensas en el mismo)." << endl;
			
		}
	}
	else{
		cout << "El animal que estas pensado puede " << animal;
		if (preguntar()){
			fstream onFile("Akinator.txt", ios_base::app);
			onFile << " "<<1;
			onFile.close();
			adivinar(akinator->der);
		}
		else {
			fstream onFile("Akinator.txt", ios_base::app);
			onFile << " "<<0;
			onFile.close();
			adivinar(akinator->izq);
		}
	}
	return akinator;
}
int main() {
	Nodo* akinator = NULL;
	bool jugar=true;
	string linea;
	if (akinator == NULL) {
		akinator=crearNod("morder fuerte");
		akinator->der=crearNod("cocodrilo");
		akinator->izq = crearNod("brincar cabron");
		akinator->izq->der = crearNod("canguro");
		akinator->izq->izq = crearNod("perro");
	}
	while (inFile>>linea){
	akinator = crearAkinator(akinator);
	}
	inFile.close();
	while (jugar) {
			fstream onFile("Akinator.txt", ios_base::app);
			onFile << "+";
			onFile.close();
		akinator = adivinar(akinator);
		cout << "Quieres seguir jugando ?";
		if (preguntar()) {
			continue;
		}
		else{
			jugar = false;
		}
	}
	destructor(akinator);
	system("pause");
	return 0;
}
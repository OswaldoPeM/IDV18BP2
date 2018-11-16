#include"includes.h"


using namespace std;

//int main() {
//	int suma = 0, numero;
//	string archivo, buffer;
//	cout << "introduce nombre del archivo al cual quieres  sumar las cantidades." << endl;
//	cin >> archivo;
//	ifstream inF(archivo,ios_base::in);
//
//	//while (getline(inF, buffer)) {}
//
//	while (inF >> numero) {
//		suma += numero;
//	}
//	cout << suma << " es la cantidad total sumando todos los digitos del documento." << endl;
//	cin.ignore();
//	cin.get();
//	inF.close();
//	return 0;	
//}


struct Reading {        
	int hour;        
	double temperature;
	char c;
};
int main() {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname }; 
	if (!ist) error("can't open input file ", iname);
	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;          ofstream ost{ oname };  
	if (!ost) error("can't open output file ", oname);

	vector<Reading> temps; 
	int hour;
	double temperature;
	char c;
	while (ist >> hour >> temperature>>c) {

		if (hour < 0 || 23 < hour) error("hour out of range");
		if (c == 'c') {
			temperature = (temperature * 9 / 5) + 32;
		}
		temps.push_back(Reading{ hour,temperature, c});
	}
	for (int i = 0; i < temps.size(); ++i) {
		ost << '(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
	}
}

//int main() {
//	cout << "Que archivo quiere leer?";
//	string iName;
//	cin >> iName;
//	ifstream iSt(iName);
//	if(!iSt) {
//		error("No se puede abrir el archivo", iName); 
//	}
//	char c;
//	int suma = 0, temperatura, horas;
//	while (iSt>> c>> horas>>c>>temperatura>>c)
//	{
//		suma += temperatura;
//	}
//	cout << "La temperatura media fue de " << suma / (horas + 1) << " se calcularon " << horas + 1 << " horas" << endl;
//	keep_window_open();
//	return 0;
//}




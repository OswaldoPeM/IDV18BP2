#include "Includes.h"
using namespace std;
/*
int main()
{
	constexpr double yen = 111.84, libra_E = 0.76, peso_M = 18.83, dolar = 1;
	constexpr char y[6] = "yen/s", l[20] = "libra/s esterlina/s", p[18] = "peso/s Mexicano/s", d[9] = "dolar/es";
	char monedaType='n';
	double coinValue = 0;
	cout << "Incerte el tipo de moneda que quiere transformar(y:yen, l:libra esterlina, p:peso Mexicano, d:dolar estadounidense)\n";
	cin >> monedaType;
	if (monedaType == 'y')
	{
		cout << "ingrese la cantidad de " << y << " que tines para cambiar\n";
		cin >> coinValue;
		cout << "ingrese el tipo de moneda en la que quiere ver su moneda(y:yen, l:libra esterlina, p:peso Mexicano, d:dolar estadounidense)\n";
		cin>>monedaType;
		if (monedaType == 'y') 
		{
			cout << coinValue;
		}
		if (monedaType == 'l')
		{
			cout << (coinValue / yen)*libra_E;
		}
		if (monedaType == 'p')
		{
			cout << (coinValue / yen)*peso_M;
		}
		if (monedaType == 'd')
		{
			cout << (coinValue / yen);
		}
		monedaType='n';
	}

	if (monedaType == 'l')
	{
		cout << "ingrese la cantidad de " << l << " que tines para cambiar\n";
		cin >> coinValue;
		cout << "ingrese el tipo de moneda en la que quiere ver su moneda(y:yen, l:libra esterlina, p:peso Mexicano, d:dolar estadounidense)\n";
		cin >> monedaType;
		if (monedaType == 'y')
		{
			cout << (coinValue / libra_E)*yen;
		}
		if (monedaType == 'l')
		{
			cout << coinValue;
		}
		if (monedaType == 'p')
		{
			cout << (coinValue / libra_E)*peso_M;
		}
		if (monedaType == 'd')
		{
			cout << (coinValue / libra_E);
		}
		monedaType='n';
	}

	if (monedaType == 'p')
	{
		cout << "ingrese la cantidad de " << p << " que tines para cambiar\n";
		cin >> coinValue;
		cout << "ingrese el tipo de moneda en la que quiere ver su moneda(y:yen, l:libra esterlina, p:peso Mexicano, d:dolar estadounidense)\n";
		cin >> monedaType;
		if (monedaType == 'y')
		{
			cout << (coinValue / peso_M)*yen;
		}
		if (monedaType == 'l')
		{
			cout << (coinValue / peso_M)*libra_E;
		}
		if (monedaType == 'p')
		{
			cout << coinValue;
		}
		if (monedaType == 'd')
		{
			cout << (coinValue / peso_M);
		}
		monedaType='n';
	}

	if (monedaType == 'd')
	{
		cout << "ingrese la cantidad de " << d << " que tines para cambiar\n";
		cin >> coinValue;
		cout << "ingrese el tipo de moneda en la que quiere ver su moneda(y:yen, l:libra esterlina, p:peso Mexicano, d:dolar estadounidense)\n";
		cin >> monedaType;
		if (monedaType == 'y')
		{
			cout << coinValue * yen;
		}
		if (monedaType == 'l')
		{
			cout << coinValue * libra_E;
		}
		if (monedaType == 'p')
		{
			cout << coinValue * peso_M;
		}
		if (monedaType == 'd')
		{
			cout << coinValue * dolar;
		}
		monedaType = 'n';
	}
	cout << "\n";
	keep_window_open();
	return 0;
}
*/

/*
int main()
{
	char abc[25] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','y','z' };
	for (int i = 0; i < 25; i++)
	{
		cout << abc[i] << " = " << 97 + i << " ";
	}
	cout << endl;
	keep_window_open();
	return 0;
}
*/

/*
int main() 
{
	int y=0, x=0;
	cout << "Introdusca el numero que quiere sacar su cuadrado.\n";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		y += x;
	}

	cout << y << "\n";
	keep_window_open();
	return 0;
}
*/

/*
int main()
{
	return 0;
}
*/

/*
int main()
{
	int condicion, val1 = 0, val2 = 0;
	char tope = '|';
	condicion = tope;
	do
	{
		cout << "\nIngresa dos valores enteros separados por un espacio\n";
		cin >> val1 >> val2;
		cout << val1 << " " << val2<< endl;
		cout << "Si desea cerrar el programa introdusca el caracter '|' \n\n";

	} while (val1 == condicion || val2 == condicion);

	keep_window_open();


	return 0;
}
*/

/*
int main()
{
	double val1=0, val2=0;
	while (val1!= '|' || val2 !='|')
	{
		cout << "introduce dos valores\n";
		cin >> val1 >> val2;
		if (val1 > val2)
		{
			cout << val1 << ", que es el valor mas alto, es mayor a " << val2 << ", el cual es el el valor mas bajo" << endl;
		}
		if (val1 < val2)
		{
			cout << val2 << ", que es el valor mas alto, es mayor a " << val1 << ", el cual es el el valor mas bajo" << endl;
		}
		else
		{
			cout << val1 << " es igual a " << val2 << endl;
		}

		cout << "si quieres salir/crashear el programa escribie '|'\n";
	}
}
*/

/*
int main()
{
	char siOno = 'y';
	cout << "Piensa en un numero entre el 1 y el 100\n";
	cin.get();
	cout << "Tu numero es mayor o igual a 50? (y/n) \n";
	cin >> siOno;
	
	if (siOno == 'y')
	{
		cout << "Tu numero es mayor o igual a 75? (y/n) \n";
		cin >> siOno;
		if (siOno == 'y')
		{
			cout << "Tu numero es mayor o igual a 88? (y/n) \n";
			cin >> siOno;

			if (siOno == 'y')
			{
				cout << "Tu numero es mayor o igual a 94? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{
					cout << "Tu numero es mayor o igual a 98? (y/n) \n";
					cin >> siOno;
					if (siOno == 'y')
					{
						cout << "Tu numero es mayor o igual a 99? (y/n) \n";
						cin >> siOno;
						if (siOno == 'y')
						{
							cout << "Tu numero es igual a 100? (y/n) \n";
							cin >> siOno;
							if (siOno == 'y')
							{
								cout << "TU NUMERO ES 100!\n";
							}
							if (siOno == 'n')
							{
								cout << "TU NUMERO ES 99!";
							}
						}
						if (siOno == 'n')
						{
							cout << "TU NUMERO ES 98!";
						}
					}
					if (siOno == 'n')
					{
						cout << "Tu numero es mayor o igual a 96? (y/n) \n";
						cin >> siOno;
						if (siOno == 'y')
						{
							cout << "Tu numero es  igual a 97? (y/n) \n";
							cin >> siOno;
							if (siOno == 'y')
							{
								cout << "TU NUMERO ES 97!";
							}
							if (siOno == 'n')
							{
								cout << "Tu numero es 96!";
							}
						}
						if (siOno == 'n')
					}
				}
				if (siOno == 'n')
				{

				}
			}
			if (siOno == 'n')
			{
				cout << "Tu numero es mayor a 25? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{

				}
				if (siOno == 'n')
				{

				}
			}
		}
		if (siOno == 'n')
		{
			cout << "Tu numero es mayor a 50? (y/n) \n";
			cin >> siOno;

			if (siOno == 'y')
			{
				cout << "Tu numero es mayor a 75? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{

				}
				if (siOno == 'n')
				{

				}
			}
			if (siOno == 'n')
			{
				cout << "Tu numero es mayor a 25? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{

				}
				if (siOno == 'n')
				{

				}
			}
		}
	}
	if (siOno == 'n') 
	{
		cout << "Tu numero es mayor a 25? (y/n) \n";
		cin >> siOno;
		if (siOno == 'y')
		{
			cout << "Tu numero es mayor a 50? (y/n) \n";
			cin >> siOno;

			if (siOno == 'y')
			{
				cout << "Tu numero es mayor a 75? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{

				}
				if (siOno == 'n')
				{

				}
			}
			if (siOno == 'n')
			{
				cout << "Tu numero es mayor a 25? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{

				}
				if (siOno == 'n')
				{

				}
			}
		}
		if (siOno == 'n')
		{
			cout << "Tu numero es mayor a 50? (y/n) \n";
			cin >> siOno;

			if (siOno == 'y')
			{
				cout << "Tu numero es mayor a 75? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{

				}
				if (siOno == 'n')
				{

				}
			}
			if (siOno == 'n')
			{
				cout << "Tu numero es mayor a 25? (y/n) \n";
				cin >> siOno;
				if (siOno == 'y')
				{

				}
				if (siOno == 'n')
				{

				}
			}
		}
	}
	
	return 0;
}
*/

/*
int main()
{
	char siOno = 'y';
	int prediccion=0, numero[7] = { 50,25,13,6,3,2,1 };
	cout << "Piensa en un numero entre el 1 y el 100, cuando lo hayas pensado preciona enter.\n";
	cin.get();
	for (int i = 0; i < 7; i++)
	{
		cout << "Tu numero es mayor o igual a "<< numero[i]+prediccion <<"? (y/n)\n";
		cin >> siOno;
		if (siOno=='y')
		{
			prediccion += numero[i];
		}
		siOno = 'n';

	}
	cout << prediccion << "! es el numero que pensabas!\n";
	keep_window_open();
	return 0;
}
*/

/*
int main()
{
	cout << "Esto es una calculadora muy basica que solo suma, resta, multiplica y divide (+,-,*,/)\n";
	char operador = '+';
	double val1, val2;

	cin >> val1 >> operador >> val2;

	switch (operador)
	{
	case '+':
		cout << "La suma de " << val1 << " y " << val2 << " es " << val1 + val2 << "\n";
		break;
	case '-':
		cout << "La resta de " << val1 << " y " << val2 << " es " << val1 - val2 << "\n";
		break;
	case'*':
		cout << "La multiplicacion de " << val1 << " y " << val2 << " es " << val1 * val2 << "\n";
		break;
	case'/':
		cout << "La division de " << val1 << " y " << val2 << " es " << val1 / val2 << "\n";
		break;
	default:
		cout << "La calculadora no es tan vergas";
		break;
	}

	keep_window_open();
}
*/

/*
int main()
{
	vector<string> numeros;
	numeros = { "0","1","2","3","4","5","6","7","8","9","cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve" };
	string traducir = "n";
	char seguir = 'si';
	cout << "introduce el numero ya sea en caracteres o en digito para ver su contraparte.";

	while (seguir)
	{
		cin >> traducir;
		switch (traducir)
		{
		case "0":
			cout << "";
			break;
		case "1":
		case "2":
		case "3":
		case "4":
		case "5":
		case "6":
		case "7":
		case"8":
		case"9":
		case"cero":
		case"uno":
		case"dos":
		case"tres":
		case"cuatro":
		case"cinco":
		case"seis":
		case"siete":
		case"ocho":
		case"nueve":
		default:
			break;
		}
	}
}
*/

/*
int main()
{
	double arroz = 1;
	cout << " en un tablero de ajedrez hay 64 cuadros, vamos a rellenar esos cuadros con arroz, el primer cuadro tendra un grano\nel segundo cuadro tendra lo que el primero multiplicado por dos\nel tercero tendra lo que el segundo multiplicado por dos\ny asi susesivamente\nVeamos cuantos granos de arroz tiene cada cuadro. y en que cuadro se cumplen las condiciones.";
	for (int i = 1; i < 63; i++)
	{
		arroz = arroz * 2;
		if (arroz >= 1000 && arroz <= 2000)
		{
			cout << "\nEn el cuadro numero " << i+1 << " tiene al menos 1000\n";
		}
		if (arroz >= 1000000 && arroz <= 2000000)
		{
			cout << "En el cuadro numero " << i+1 << " tiene al menos 1000000\n";
		}
		if (arroz >= 1000000000 && arroz <= 2000000000)
		{
			cout << "En el cuadro numero " << i+1 << " tiene al menos  1000000000\n";
		}
	}
	cout<<arroz<<endl;
	keep_window_open();
	return 0;
}
*/

/*
int main()
{
	vector<string> juegoPPT;
	const string Piedra = "piedra", Papel = "papel", Tijera = "tijera";
	juegoPPT = { "piedra","papel","tijera","piedra","tijera","piedra","tijera","piedra","papel","tijera","tijera" };
	char yn = 'q';
	string jugador = "";
	for (int i = 0; i != -1; i++)
	{
		cout << "\npiedra, papel o tijera?\n";
		cin >> jugador;
		if (jugador == Piedra)
		{
			if (juegoPPT[i]==Piedra)
			{
				cout << "EMPATE!\n";
			}
			if (juegoPPT[i] == Papel)
			{
				cout << "PERDISTE!!\n";
			}
			if (juegoPPT[i] == Tijera)
			{
				cout << "GANASTE!!!\n";
			}
		}
		if (jugador == Tijera)
		{
			if (juegoPPT[i] == Piedra)
			{
				cout << "PERDISTE!!\n";
			}
			if (juegoPPT[i] == Papel)
			{
				cout << "GANASTE!!!\n";
			}
			if (juegoPPT[i] == Tijera)
			{
				cout << "EMPATE!\n";
			}
		}
		if (jugador == Papel)
		{
			if (juegoPPT[i] == Piedra)
			{
				cout << "PERDISTE!!\n";
			}
			if (juegoPPT[i] == Papel)
			{
				cout << "EMPATE!\n";
			}
			if (juegoPPT[i] == Tijera)
			{
				cout << "GANASTE!!!\n";
			}
		}
		cout << "quieres, seguir jugando?(y/n)\n";
		cin >> yn;
		if (yn == 'n')
		{
			i = 1;
		}
	}
	keep_window_open();
	return 0;
}
*/


int main()
{

}



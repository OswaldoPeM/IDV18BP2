#include "Includes.h"
using namespace std;


/*
constexpr int frame_width = 2;
int framed_area(int x, int y) // calculate area within frame
{
return area(x–frame_width,y–frame_width);
}
int area(int length, int width) // calculate area of a rectangle
{
return length*width;
}

//int framed_area(int x, int y) // calculate area within frame
//{
//return area(x–2,y–2);
//}
double area(double length, double width)
{
	return length*width;
}

int main()
{
	int s1 = area(7; // error: ) missing
	int s2 = area(7) // error: ; missing
	Int s3 = area(7); // error: Int is not a type
	int s4 = area('7); // error: non-terminated character (' missing)
	int x0 = arena(7); // error: undeclared function
	int x1 = area(7); // error: wrong number of arguments
	int x2 = area("seven",2); // error: 1st argument has a wrong type
	int area1 = area(x,y);
	if (area1<=0) error("non-positive area");
	int area2 = framed_area(1,z);
	int area3 = framed_area(y,z);
	double ratio = double(area1)/area3;

	vector<int> v; // a vector of ints
	for (int i; cin>>i; )
	{
	v.push_back(i); // get values
	}
	for (int i = 0; i<=v.size(); ++i) // print values
	{
	cout << "v[" << i <<"] == " << v[i] << '\n';
	}


}
*/


/*
void error(string s1, string s2)
{
throw runtime_error(s1+s2);
}
int main()
{
	try {
		int a = 'a'; // our program
		return 0; // 0 indicates success
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1; // 1 indicates failure
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2; // 2 indicates failure
	}

}
*/

/*
int main()
{
	double sum = 0;
	double high_temp = -1000; // initialize to impossibly low
	double low_temp = 1000; // initialize to “impossibly high”
	int no_of_temps = 0;
	for (double temp; cin >> temp; ) { // read temp
		++no_of_temps; // count temperatures
		sum += temp; // compute sum
		if (temp > high_temp) 
		{
			high_temp = temp;// find high
		} 
		if (temp < low_temp)
		{
			low_temp = temp; // find low
		}
	}
	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum / no_of_temps << '\n';


	cin.ignore();
	cin.get();
	keep_window_open();
	return 0;
}
*/

/*
int main()
{

	cout << "Success!\n";
	cout << "Success!\n";
	cout << "Success" << "!\n";
	cout << "success" << '\n';
	int res = 7;
	vector<int> v(10);
	v[5] = { res };
	cout << "Success!\n";
	v.push_back(7);
	if (v[5] != 7) cout << "Success!\n";
	bool cond = true;
	if (cond) cout << "Success!\n"; 
	else cout << "Fail!\n";
	bool c = false;
	if (c) cout << "Success!\n";
	else cout << "Fail!\n";
	string s = "ape";
	bool q = "fool" < s;
	if (c) cout << "Success!\n";
	string w = "ape";
	if (s == "fool")cout << "Success!\n";

	if (s == "fool") cout << "Success!\n";

	if (s == "fool") cout << "Success!\n";
	for (int i = 0; 0 < v.size(); ++i)
	{
		cout << "Success!\n";
	}
	for (int i = 0; i <= v.size(); ++i);
	{
		cout << "Success!\n";
	}
	string p = "Success!\n";
	for (int i = 0; i < p.size(); ++i) 
	{
		cout << p[i];
	}
	if (true)
	{
		cout << "Success!\n"; 
	}
	else cout << "Fail!\n";
	int x = 2000;
	char c = x;
	if (c == 2000) cout << "Success!\n";
	string s = "Success!\n"; 
	for (int i = 0; i < 10; ++i)
	{
		cout << s[i];
	}
	vector<int> v(5); 
	for (int i = 0; i <= v.size(); ++i) 
	{
		cout << "Success!\n"; 
	}
	int i = 0; int j = 9;
	while (i < 10) ++i;
	if (j < i) cout << "Success!\n";
	int x = 2; 
	double d = 5 / (x - 2);
	if (d == 2 * x + 0.5) cout << "Success!\n";
	string s = "Success!\n";
	for (int i = 0; i <= 10; ++i) cout << s[i];
	int i = 0; 
	while (i < 10) ++j;
	if (j < i) cout << "Success!\n";
	int x = 4;
	double d = 5 / (x-2);
	if (d = 2 * x + 0.5)
	{
		cout << "Success!\n";
		cout << "Success!\n";
	}
}
*/


/*
double ctok(double c) // converts Celsius to Kelvin
{
	double k = c + 273.15;
	if (k >= 0)
	{
		return k;
	}
	else
		cout << "Temperatura no real\n";

	return k = 0;
}
double ktoc(double k) // converts Celsius to Kelvin
{
	double c = k - 273.15;
	if (c >= 273.15)
	{
		return c;
	}
	else
		cout << "Temperatura no real\n";
	return c = 0;
}
double ctof(double c) // converts Celsius to Kelvin
{
	double f = (9*c)/5 + 32;
	if (f >= -459.67)
	{
		return f;
	}
	else
		cout << "Temperatura no real\n";
	return f = 0;
}

int main()
{
	cout << "Introducir 'c' los grados celcius para hacerlos kelvin, y de manera contraria introduce 'k'.\nSi quieres convertir de celcius a frhrenhit preciona 'f'\n";
	double c = 0, k = 0,f=0; // declare input variable
	char kOc = '\0';
	cin >> kOc;
	switch (kOc)
	{
	case 'c':
		cout << "Introduce temperatura \n";
		cin >> c; // retrieve temperature to input variable
		k = ctok(c); // convert temperature
		cout << k << 'k \n'; // print out temperature
		break;
	case 'k':
		cout << "Introduce temperatura \n";
		cin >> k; // retrieve temperature to input variable6
		c = ktoc(k); // convert temperature
		cout << k << 'c \n'; // print out temperature
		break;
	case 'f':
		cout << "Introduce temperatura \n";
		cin >> c; // retrieve temperature to input variable
		f = ctof(c); // convert temperature
		cout << f << 'f \n'; // print out temperature
		break;
	default:
		break;
	}
	cout << "\n";
	keep_window_open();
	return 0;
} 
*/

/*
int main()
{
	double a, b, c, x1, x2, raiz, real, imaginario;
	cout << "vamos a hacer la formula general\n a continuacion introdusa a,b y c para resolver\n";
	cin >> a >> b >> c;
	raiz = b * b - 4 * a*c;

	if (raiz > 0)
	{
		x1 = (-b + sqrt(raiz)) / (2 * a);
		x2 = (-b - sqrt(raiz)) / (2 * a);
		cout << "Numeros reales.\nx1 = " << x1 << "\nx2 = " << x2 << "\n";
	}

	if (raiz == 0)
	{
		x1 = (-b + sqrt(raiz)) / (2 * a);
		cout << "x1 = x2 =" << x1 << "/n";
	}

	else
	{
		real = -b / (2 * a);
		imaginario = sqrt(-raiz) / (2 * a);
		cout << "Los resultados son numeros imaginarios.x1 = " << real << "+" << imaginario << "i\nx2 = " << real << "-" << imaginario << "i" << "\n";
	}
	keep_window_open();
	return 0;
}
*/

int main()
{
	vector<int> lista;
	int max = 0, sum=0;
	cout << "Introduce cuantos valores vas a sumar contando desde el primero: \n";
	cin >> max;
	cout << "introduce los numeros, y cuando quieras parar presiona (ctrl+z) enter.";
	for (int i; cin >> i;)
	{
		lista.push_back(i);
	}

	for (int i=0; i < max;i++)
	{
		sum += lista[i];
	}

	cout << sum << endl;
	keep_window_open();
	
	return 0;
}


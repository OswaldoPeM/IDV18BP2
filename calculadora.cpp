#include "Includes.h"
using namespace std;

class Token {
public:
	char kind;        // Tipo
	double value;     // valor  
	Token(char ch)    // Se almacena el character que despues sera interpretado por el tipo de caracter que es.
		:kind(ch), value(0) { }
	Token(char ch, double val)     // hace un token de tipo char (automaticamente 8 para saber que es un numero) y tipo double(que almacena el valor).
		:kind(ch), value(val) { }
};

class Token_stream {
private:
	bool full;        // Hay un token en el espacio temporal?
	Token buffer;     // Variante donde guardamos el token con putback();
public:
	Token_stream();   // agarra de cin un ts.
	Token get();      // Le da las caracteristicas de token.
	void putback(Token t);    // combierte el espacio temporal en una copia de  Token t
};

// indica que el buffer esta vacio
Token_stream::Token_stream()
	:full(false), buffer(0)    // el espacio de memoria temporal esta vacio
{}

// Le otorga el valor de t a el espacio de memoria temporal
void Token_stream::putback(Token t) {
	if (full) error("putback() esta lleno el espacio de memoria temporal.");
	buffer = t;       // copia de t en buffer
	full = true;      // espacio de memoria lleno.
}

Token Token_stream::get() {
	if (full) {       // Tenemos buffer con contenido?
		full = false; // hace reutilizable buffer.
		return buffer;
	}

	char ch;
	cin >> ch;    
	switch (ch) {
	case '=':    // Imprimir resultado
	case 'x':    // salir
	case 'X':    // salir
	case '(': case ')': case '+': case '-': case '*': case '/': case '%':
		return Token(ch);        //Regresa el caracter para que se interprete por lo que es.
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // pone un tipo en ts
		double val;
		cin >> val;             
		return Token('8', val);   // el kind(tipo) "8" quiere decir que es un numero.
	}
	default:
		error("Bad token");
	}
}

Token_stream ts;        // nos permite get() y pushback().

double expression();    // Declara expression para que pueda ser llamada por primary().

// Numeros y parentecis
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // maneja '(' "expression" ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error(" falta ')'");
		return d;
	}
	case '8':            
		return t.value;  // regresa el valor del token tipo "8"
	default:
		error("Falta primario.");
	}
}

// multipicacion division y modulo.
double term()
{
	double left = primary();
	Token t = ts.get();        //lee el siguiente token del ts

	while (true) {
		switch (t.kind) {
		case '*':
		{
			left *= primary();
			t = ts.get();
			break;
		}
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide por cero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			int d = primary();
			int l = left;
			if (d == 0) error("divide por cero");
			left = l % d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // regresa t al ts
			return left;
		}
	}
}

// suma y resta
double expression()
{
	double left = term();      // Lanza left para revisar el nivel
	Token t = ts.get();        // siguiente token de ts

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // se suma a left lo que resulte .
			t = ts.get();
			break;
		case '-':
			left += term();    // se resta a left lo que resulte el analisis de el siguiente token 
			t = ts.get();
			break;
		default:
			ts.putback(t);     // si no es ninguno de los anteriores regresar t al buffer
			return left;       // regresa el valor 
		}
	}
}

int main()
try
{
	cout << "Calculadora Magica" << endl;
	cout << "ingrese alguna exprecion con numeros flotantes" << endl;
	cout << "operaciones disponibles: '+','-','*','/', Y '%'. Presiona 'x' para salir." << endl;
	cout << "Para resolver el problema introdusca '='" << endl;
	double val;
	while (cin) {
		Token t = ts.get();

		if (t.kind == 'x') break; // 'x' para salir
		if (t.kind == '=')        // '=' Imprimir
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops:khaaaaa!\n";
	keep_window_open();
	return 2;
}

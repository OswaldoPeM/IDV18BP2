#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Cuarto
{
private:
	string _nombre="Null";//nombre del cuarto
public:
	vector<string> _conect,_item; //lista de conecciones que hay entre cuartos e items disponibles en el cuarto	
	string NOMBRE();
	bool solved = false;
	bool wasIHere=false;//he estado aqui?
	void visit();
	void solve();
	void nombre(string Nombre);
	void conect(string Conect);
	void item(string Item);

	Cuarto();
	Cuarto(string nombre, string cone1, string cone2, string cone3, string item1, string item2, string item3);
	~Cuarto();
};


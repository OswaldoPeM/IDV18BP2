#pragma once
#include"Casa.h"
using namespace std;

class Tu
{
public:
	Cuarto* estoy = new Cuarto;
	Cuarto* estuve = new Cuarto;
	string amIIn= "",placeBefore="";
	vector<string> inventario, lugares, solvedplaces;

	Tu();
	~Tu();
private:

};


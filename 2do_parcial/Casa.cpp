#include "Casa.h"



void Casa::Build(Cuarto x,int piso)
{
	_TuCasa[piso].push_back(x);
}

void Casa::piso()
{
	_TuCasa.push_back(vector<Cuarto>());
}

Casa::Casa()
{
}


Casa::~Casa()
{
}

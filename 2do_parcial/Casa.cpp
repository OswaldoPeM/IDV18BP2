#include "Casa.h"



void Casa::Build(Cuarto* x,int piso)
{
	_TuCasa[piso].push_back(x);
}

void Casa::piso()
{
	_TuCasa.push_back(vector<Cuarto*>());
}

Casa::Casa()
{
}


Casa::~Casa()
{
	for (int i = 0; i < _TuCasa.size(); i++)
	{
		for (int j = 0; j < _TuCasa[i].size(); j++)
		{
			delete _TuCasa[i][j];
		}
	}
}

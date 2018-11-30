#pragma once
#include"Cuarto.h"
using namespace std;
class Casa
{
public:
	void Build(Cuarto* x,int piso);
	void piso();
	Casa();
	~Casa();
	vector<vector<Cuarto*>> _TuCasa;
private:
	
};


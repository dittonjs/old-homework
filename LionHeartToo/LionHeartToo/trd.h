#ifndef trd_H
#define trd_H
#include "unit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
// JOSEPH DITTON 001 A01249280
using namespace std;



class trd : public Unit {
public:
	trd():Unit(){}

	trd(int ir,int ic,int ihp,Dir idir,Rank irank,
	bool idead, string itla):
	Unit(ir,ic,ihp,idir,irank,idead,itla){} 

	void Place(int minR,int maxR,int minC,int maxC, SitRep sitrep);
	// put unit on board
	Action Recommendation(SitRep sitrep);
	// tell someone what you want to do
	
private:
	 
	

};
#endif

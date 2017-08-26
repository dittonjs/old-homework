#include "trd.h"
#include <cmath>
#include <iostream>

// JOSEPH DITTON 001 A01249280

int numOfArchers(SitRep sitrep)
{
	int numberA=0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (sitrep.thing[i][j].what == unit)
			{
				if (sitrep.thing[i][j].rank == archer)
				{
					if (sitrep.thing[i][j].tla == "trd")
					{
						numberA++;
					}
				}
			}
		}
	}
	return numberA;
}

int numOfKnights(SitRep sitrep)
{
	int numberA = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (sitrep.thing[i][j].what == unit)
			{
				if (sitrep.thing[i][j].rank == knight)
				{
					if (sitrep.thing[i][j].tla == "trd")
					{
						numberA++;
					}
				}
			}
		}
	}
	return numberA;
}

int numOfINf(SitRep sitrep)
{
	int numberA = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (sitrep.thing[i][j].what == unit)
			{
				if (sitrep.thing[i][j].rank == infantry)
				{
					if (sitrep.thing[i][j].tla == "trd")
					{
						numberA++;
					}
				}
			}
		}
	}
	return numberA;
}

int uniqueInfirstRow(SitRep sitrep)
{
	int numOfk = 0;
	int numOfa = 0;
	int numOfi = 0;
	int kings = 0;
	int unique = 0;
	
	for (int i = 0; i < ROWS; i++)
	{
		if (sitrep.thing[i][24].what == unit)
		{
			if (sitrep.thing[i][24].what == unit)
			{
				switch (sitrep.thing[i][24].rank)
				{
				case crown: kings++; break;
				case knight: numOfk++; break;
				case infantry: numOfi++; break;
				case archer: numOfi; break;
				default: break; 
				}
			}

		}
	}
	if (kings>0) unique += 10;
	if (numOfa > 0) unique++;
	if (numOfi > 0) unique++;
	if (numOfk > 0) unique++;
	return unique;
	
}

int checkKing(SitRep sitrep)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (sitrep.thing[i][j].what == unit)
			{
				if (sitrep.thing[i][j].rank == crown&&sitrep.thing[i][j].tla == "trd")
				{
					return j;
				}
			}
		}
	}
}

int checkIfTooClose(SitRep sitrep, int num)
{
	if (num == 1) // WE ARE ON THE LEFT SIDE
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (sitrep.thing[i][j].what == unit)
				{
					if (sitrep.thing[i][j].tla != "trd") return 1;
				}
			}
		}
		return 2;
	}
	else // WE ARE ON THE RIGHT SIDE
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 22; j < COLS; j++)
			{
				if (sitrep.thing[i][j].what == unit)
				{
					if (sitrep.thing[i][j].tla != "trd") return 1;
				}
			}
		}
		return 2;
	}
	
}



void trd::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	int tr, tc;
	Dir td;
	bool done = false;
	//IF WE ARE ON THE LEFT SIDE OF THE BOARD 
	if (minC < 15){

		if (rank == archer)
		{
			while (!done)
			{
				tr = minR + 1 + rand() % (maxR - minR - 2);
				tc = maxC;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}
		}
		if (rank == knight)
		{
			while (!done)
			{
				tr = minR + rand() % (maxR - minR);
				tc = maxC - 1;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}
		}
		if (rank == infantry)
		{
			while (!done)
			{
				tr = minR + rand() % (maxR - minR);
				tc = maxC - 2 - rand() % 2;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}
		}
		if (rank == crown)
		{
			while (!done)
			{
				tr = minR + 2;
				tc = minC;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}


		}

	} // THIS IS THE END OF THE LEFT SIDE INSTRUCTIONS
	else // THIS IS WHAT WE WILL DO IF ON THE RIGHT SIDE
	{
		if (rank == archer)
		{
			while (!done)
			{
				tr = minR + 1 + rand() % (maxR - minR - 2);
				tc = minC;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}
		}
		if (rank == knight)
		{
			while (!done)
			{
				tr = minR + rand() % (maxR - minR);
				tc = minC + 1;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}
		}
		if (rank == infantry)
		{
			while (!done)
			{
				tr = minR + rand() % (maxR - minR);
				tc = minC + 2 + rand() % 2;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}
		}
		if (rank == crown)
		{
			while (!done)
			{
				tr = minR + 2;
				tc = maxC;
				if (sitrep.thing[tr][tc].what == space) done = true;
			}



		}
		/*bool done=false;
		int tr,tc;
		Dir td;
		while(!done){
		tr=minR+rand()%(maxR-minR);
		tc=minC+rand()%(maxC-minC);
		if(sitrep.thing[tr][tc].what==space)done=true;
		}
		int rdist=ROWS/2-tr;
		int cdist=COLS/2-tc;
		if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
		}else{
		if(rdist>0)td=up;
		else td=dn;
		}*/
	}
	r=tr;
	c=tc;
	if(minC>15)dir=lt;
	if (minC<15)dir = rt;
}


// tell someone what you want to do
Action trd::Recommendation(SitRep sitrep){


	int numOfA = numOfArchers(sitrep);
	Action a;

	// first, try to attack in front of you
	int tr = r, tc = c;
	switch (dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if (tr >= 0 && tr < ROWS&&tc >= 0 && tc < COLS){
		if (sitrep.thing[tr][tc].what == unit){
			if (sitrep.thing[tr][tc].tla != tla){
				a.action = attack;
				a.ar = tr;
				a.ac = tc;
				return a;
			}
		}
	}

	// IF I AM STARTING ON THE LEFT SIDE THEN DO THIS
	if (checkKing(sitrep) < 15){
		// --------------------------------------
		// THESE ARE THE INSTRUCTIONS FOR THE KING
		// ---------------------------------------
		if (rank == crown)
		{
			a.action = nothing;
			return a;
		}

		//-----------------------------------------
		// THESE ARE THE INSTRUCTIONS FOR THE ARCHER
		//-----------------------------------------



		if (rank == archer)
		{
			if (checkIfTooClose(sitrep, 1) == 1)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
				if (rank == knight || rank == crown)a.maxDist = 1;
				return a;
			}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
					}
			}
			else if (getC() == 8 && sitrep.turnNumber < 60){
				a.action = attack;
				a.ac = sitrep.nearestEnemy.c;
				a.ar = sitrep.nearestEnemy.r;

			}
			else if (sitrep.turnNumber >= 60)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
			else
			{
				if (getC() == 8) a.action = nothing;
				if (getC() != 8)
				{
					a.action = fwd; a.maxDist = 1;

				}
				return a;
			}


			return a;
		}




		//------------------------------------------
		// THESE ARE THE INSTRUCTIONS FOR THE KNIGHT
		//------------------------------------------

		if (rank == knight)
		{

			// move up to the row for where the 
			if (getR() != 3 && (sitrep.turnNumber < 10 || sitrep.turnNumber>35) && getC() < 15)
			{
				if (dir != up)
				{
					a.action = turn;
					a.dir = up;
					return a;
				}
				else
				{
					a.action = fwd;
					a.maxDist = getR() - 3;
					return a;
				}
			}
			// if your at the row move to the right 
			else if (getR() == 3 && (sitrep.turnNumber < 10 || sitrep.turnNumber>35) && getC() < 15)
			{
				if (dir != rt)
				{
					a.action = turn;
					a.dir = rt;
					return a;
				}
				else
				{
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			else if (sitrep.turnNumber >= 10 && sitrep.turnNumber <= 35)
			{
				a.action = nothing;
				return a;
			}
			else if (getC() >= 15 && sitrep.turnNumber < 60)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}


			}
			else if (sitrep.turnNumber >= 60)
			{
				if (dir == sitrep.nearestEnemyCrown.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemyCrown.dirFor;
					return a;
				}
			}
		}
		/* there is not an enemy in front of me
		 so head to the nearest enemy*/




		//---------------------------------------------
		// THESES ARE THE INSTRUCTIONS FOR THE INFANTRY
		///--------------------------------------------

		if (rank == infantry)
		{
			
			if (checkIfTooClose(sitrep, 1) == 1)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
			else if (sitrep.turnNumber < 60)
			{
				a.action = nothing;
			}
			else
			{
				if (dir == sitrep.nearestEnemyCrown.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemyCrown.dirFor;
					return a;
				}
			}
			return a;
		}
	}//THIS IS THE END OF THE STATEMENT IF YOU START ON THE LEFT
	else // THIS IS WHAT WE WILL DO IF STARTING ON THE RIGHT
	{
		// --------------------------------------
		// THESE ARE THE INSTRUCTIONS FOR THE KING
		// ---------------------------------------
		if (rank == crown)
		{
			a.action = nothing;
			return a;
		}

		//-----------------------------------------
		// THESE ARE THE INSTRUCTIONS FOR THE ARCHER
		//-----------------------------------------

		if (rank == archer)
		{

			if (checkIfTooClose(sitrep, 2) == 1)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
			else if (getC() == 22 && sitrep.turnNumber < 60){
				a.action = attack;
				a.ac = sitrep.nearestEnemy.c;
				a.ar = sitrep.nearestEnemy.r;

			}
			else if (sitrep.turnNumber >= 60)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
			
			else
			{
				if (getC() == 22) a.action = nothing;
				if (getC() != 22)
				{
					a.action = fwd; a.maxDist = 1;

				}
				return a;
			}


			return a;
		}

		//------------------------------------------
		// THESE ARE THE INSTRUCTIONS FOR THE KNIGHT
		//------------------------------------------

		if (rank == knight)
		{

			// move up to the row where the gap is 
			if (getR() != 26 && (sitrep.turnNumber < 10 || sitrep.turnNumber>35) && getC() > 15)
			{
				if (dir != dn)
				{
					a.action = turn;
					a.dir = dn;
					return a;
				}
				else
				{
					a.action = fwd;
					a.maxDist = 26 - getR();
					return a;
				}
			}
			// if your at the row move to the right 
			else if (getR() == 26 && (sitrep.turnNumber < 10 || sitrep.turnNumber>35) && getC() > 15)
			{
				if (dir != lt)
				{
					a.action = turn;
					a.dir = lt;
					return a;
				}
				else
				{
					a.action = fwd;
					a.maxDist = 1;
					return a;
				}
			}
			else if (sitrep.turnNumber >= 10 && sitrep.turnNumber <= 35)
			{
				a.action = nothing;
				return a;
			}
			else if (getC() <= 15 && sitrep.turnNumber < 60)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}


			}
			else if (sitrep.turnNumber >= 60)
			{
				if (dir == sitrep.nearestEnemyCrown.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemyCrown.dirFor;
					return a;
				}
			}
		}

		//---------------------------------------------
		// THESES ARE THE INSTRUCTIONS FOR THE INFANTRY
		///--------------------------------------------

		if (rank == infantry)
		{
			if (checkIfTooClose(sitrep, 2) == 1)
			{
				if (dir == sitrep.nearestEnemy.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemy.dirFor;
					return a;
				}
			}
			else if (sitrep.turnNumber < 60)
			{
				a.action = nothing;
			}
			else
			{
				if (dir == sitrep.nearestEnemyCrown.dirFor){
					a.action = fwd;
					a.maxDist = 1;
					if (rank == knight || rank == crown)a.maxDist = 1;
					return a;
				}
				else {
					a.action = turn;
					a.dir = sitrep.nearestEnemyCrown.dirFor;
					return a;
				}
			}
			return a;
		}
	}
	
	// there is not an enemy in front of me
	// so head to the nearest enemy
	//if(dir==sitrep.nearestEnemy.dirFor){
	//	a.action=fwd;
	//	a.maxDist=1;
	//	if(rank==knight||rank==crown)a.maxDist=HORSESPEED;
	//	return a;
	//} else {
	//	a.action=turn;
	//	a.dir=sitrep.nearestEnemy.dirFor;
	//	return a;
	//}
	//a.action=nothing;
	//return a;
	
}

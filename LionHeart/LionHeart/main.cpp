#include "unit.h"
#include "dww.h"
#include <iostream>

using namespace std;


void createMap(Thing thing[ROWS][COLS])
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; j++)
		{
			thing[i][j].what = space;
		}
		
	}
}

// EACH OF THESES FUNCTIONS TESTS THE INDIVIDUAL FUNCTIONS OF BOTH THE UNIT CLASS AND THE DWW CLASS
// THE TESTS WONT PASS IF THE BOTH CLASSES DONT PASS.

// tests the accessor function getR() and getC()
bool test01()
{
	int tests = 0;
	Unit u(5,5,10,up,crown,false,"jsd");
	if (u.getR() == 5 && u.getC() == 5) tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	if (v.getR() == 5 && u.getC() == 5) tests++;
	if (tests == 2) return 1;
	return 0;
	
}

// checks the getDead() function
bool test02()
{
	int tests = 0;
	Unit u(5, 5, 10, up, crown, false, "jsd");
	if (!u.getDead())tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	if (!v.getDead())tests++;
	if (tests == 2) return 1;
	return 0; 
}

// tests the getDir() function
bool test03()
{	
	int tests = 0;
	Unit u(5, 5, 10, up, crown, false, "jsd");
	if (u.getDir() == up)tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	if (v.getDir() == up)tests++;
	if (tests == 2) return 1;

	return 0; 
}

// tests the getHp
bool test04()
{
	int tests = 0;
	Unit u(5, 5, 10, up, crown, false, "jsd");
	if (u.getHp() == 10) tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	if (v.getHp() == 10) tests++;
	if (tests == 2) return 1;
    return 0; 
}

// tests the getRank() and getTla() functions
bool test05()
{
	int tests = 0;
	Unit u(5, 5, 10, up, crown, false, "jsd");
	if (u.getRank() == crown && u.getTla() == "jsd") tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	if (v.getRank() == crown && v.getTla() == "jsd") tests++;
	if (tests == 2) return 1;
	return 0;
}

// tests the place function
bool test06()
{
	int tests = 0;
	SitRep sitRep;
	Unit u(5, 5, 10, up, crown, false, "jsd");
	createMap(sitRep.thing);
	u.Place(10, 11, 10, 11, sitRep);
	if (u.getR() == 10 && u.getC() == 10) tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	v.Place(10, 11, 10, 11, sitRep);
	if (v.getR() == 10 && v.getC() == 10) tests++;
	if (tests == 2) return 1;
	return 0;

}

// tests the turn() function
bool test07()
{
	int tests = 0;
	Unit u(5, 5, 10, up, crown, false, "jsd");
	u.Turn(dn);
	if (u.getDir() == dn) tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	v.Turn(dn);
	if (v.getDir() == dn) tests++;
	if (tests == 2) return 1;
	return 0;
}



// tests the suffer() function
bool test08()
{
	int tests = 0;
	Unit u(5, 5, 10, up, crown, false, "jsd");
	u.Suffer(4);
	if (u.getHp() == 8) tests++;
	dww v(5, 5, 10, up, crown, false, "jsd");
	v.Suffer(4);
	if (v.getHp() == 8) tests++;
	if (tests == 2) return 1;
	return 0;
}

// tests the attack function
bool test09()
{
	Unit u(5, 5, 2, up, crown, false, "jsd");
	int i,j,k,l,m, tests = 0;
	i = u.Attack();
	j = u.Attack();
	k = u.Attack();
	l = u.Attack();
	m = u.Attack();
	if (i<=4&&j<=4&&k<=4&&l<=4&&m<=4) tests++;
	dww v(5, 5, 2, up, crown, false, "jsd");
	i = v.Attack();
	j = v.Attack();
	k = v.Attack();
	l = v.Attack();
	m = v.Attack();
	if (i <= 4 && j <= 4 && k <= 4 && l <= 4 && m <= 4) tests++;
	if (tests == 2) return 1;
	return 0;
}

// test recommendation function
bool test10()
{
	int tests=0; 
	SitRep sitRep1;
	createMap(sitRep1.thing);
	
	
	// creates different types of unit and then tests the function to see if they will turn or attack
	sitRep1.thing[4][5].what = unit;
	sitRep1.thing[4][5].tla = "abc";
	sitRep1.nearestEnemy.dirFor = up;
	Unit u(5, 5, 10, up, crown, false, "jsd"), v(6, 5, 10, up, infantry, false, "jsd"), w(5, 5, 10, rt, archer , false, "jsd");
	Unit x(8, 5, 10, up, crown, false, "jsd");
	Action a,b,c,d;
	a = u.Recommendation(sitRep1);
	b = v.Recommendation(sitRep1);
	c = w.Recommendation(sitRep1);
	d = x.Recommendation(sitRep1);
	
	if (a.action == attack) tests++;
	if (b.action == fwd) tests++;
	if (c.action == turn) tests++;
	if (d.action == fwd) tests++;

	dww q(5, 5, 10, up, crown, false, "jsd"), r(6, 5, 10, up, infantry, false, "jsd"), s(5, 5, 10, rt, archer, false, "jsd");
	dww t(8, 5, 10, up, crown, false, "jsd");
	a = q.Recommendation(sitRep1);
	b = r.Recommendation(sitRep1);
	c = s.Recommendation(sitRep1);
	d = t.Recommendation(sitRep1);

	if (a.action == attack) tests++;
	if (b.action == fwd) tests++;
	if (c.action == turn) tests++;
	if (d.action == fwd) tests++;

	if (tests == 8) return 1;
	return 0;

}

bool test11()
{
	int tests = 0;
	Unit u(5, 5, 10, up, archer, false, "jsd");
	u.Move(1);
	if (u.getR() == 4) tests++;
	
	dww v(5, 5, 10, up, archer, false, "jsd");
	v.Move(1);
	if (v.getR() == 4) tests++;
	if (tests == 2) return 1;
	return 0;
}

int main()
{
	if (!test01()) { cout << "Test 1 failed" << endl; return 0; }
	cout << "Test one passed!" << endl;
	if (!test02()) { cout << "Test 2 failed" << endl; return 0; }
	cout << "Test two passed!" << endl;
	if (!test03()) { cout << "Test 3 failed" << endl; return 0; }
	cout << "Test three passed!" << endl;
	if (!test04()) { cout << "Test 4 failed" << endl; return 0; }
	cout << "Test four passed!" << endl;
	if (!test05()) { cout << "Test 5 failed" << endl; return 0; }
	cout << "Test five passed!" << endl;
	if (!test06()) { cout << "Test 6 failed" << endl; return 0; }
	cout << "Test six passed!" << endl;
	if (!test07()) { cout << "Test 7 failed" << endl; return 0; }
	cout << "Test seven passed!" << endl;
	if (!test08()) { cout << "Test 8 failed" << endl; return 0; }
	cout << "Test eight passed!" << endl;
	if (!test09()) { cout << "Test 9 failed" << endl; return 0; }
	cout << "Test nine passed!" << endl;
	if (!test10()) { cout << "Test 10 failed" << endl; return 0; }
	cout << "Test ten passed!" << endl;
	if (!test11()) { cout << "Test 11 failed" << endl; return 0; }
	cout << "Test eleven passed!" << endl;
	cout << "All tests passed!" << endl;
	return 0;
}
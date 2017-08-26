// see the official rules for lionheart (pdf on canvas) for how to play the game

#ifndef UNIT_H  // this keeps the classes and structs from being defined more
#define UNIT_H  // than once, along with the #endif at the bottom
#include <string>
#include <cstdlib>
#define HORSESPEED 5 //how far the mounted wariors can travel in one action
#define ROWS 20   // board vertical dimension
#define COLS 20   // board horizontal dimension

using namespace std;

enum Dir{ up, dn, lt, rt, none }; // all directions are specified using these

enum Rank{ infantry, archer, knight, crown }; // each unit has its own rank

struct Location{     // The Location struct is used in the situation report
	int r, c;     // to help the unit figure out where to go.
	Dir dirFor;  // This is the direction to go if you want to get to r,c.
};

enum ActionType{ turn, fwd, attack, nothing }; // These are all the thing a unit can do

struct Action{  // this struct helps define the details of eadh action
	ActionType action; // turn, fwd, attack, or nothing
	int maxDist;       // for mounted units, hwo far you want to move
	Dir dir;           // for turn, which direction to turn to 
	int ar, ac;         // archer target row and col
};

enum ThingType{ unit, space, rock }; // All things on the board are units, rocks, or empy space

struct Thing{ // this struct is used to completely define any one space on the board
	ThingType what;  // a unit, a rock, or an empty space
	Rank rank;       // if it is a unit, this gives its rank
	string tla;      // if it is a unit, this gives its TLA
	Dir dir;         // it it is a unit, this gives its curent direction
	int hp;          // if it is a unit, this gives its crrent strength
};

struct SitRep{  // this struct is given to the Recommendation function when an action is needed
	Thing thing[ROWS][COLS];    // a 2d array representing the board 
	Location nearestEnemyCrown; // the location and direction of the nearest crown
	Location nearestEnemy;      // the location and direction of the nearest enemy
	Dir anyOpenSpace;           // the direction of an empty space (possibly
	// none) next to you
};


class Unit{ // this class represents all units on the board.  your first task is to
	// write all the functions specified in this class

public:
	//contructors
	Unit();   // default constructor.  set r,c to 0, hp to INFANTRYHP, dir to up,
	// rank to infantry, dead to false, tla to "xxx"
	Unit(int ir, int ic, int ihp, Dir idir, Rank irank,
		bool idead, string itla);    //check for errors, exit if any found

	// accessors
	int getR();
	int getC();
	int getHp();
	Dir getDir();
	Rank getRank();
	bool getDead();
	string getTla();

	// manipulators
	void Turn(Dir newDir); // turn to the indicated direction
	void Move(int dist);   // move exactly this dist with no error checking
	int Attack();          // attack, return hits.  see offical rules for dice rolls
	void Suffer(int hits); // reduce hp by hits, adjust dead if needed
	virtual void Place(int minR, int maxR,
		int minC, int maxC, SitRep sitrep); // put unit on board, inside the bounding
	// box define by min r,c and max r,c.
	// don't put two units in the same place
	// use the sitrep to figure out what is 
	// there.
	virtual Action Recommendation(SitRep sitrep); // tell someone what you want to do.
	// return an action, as described above.
	// for the first phase, this is given to you.

protected:
	int r;       // row number
	int c;       // col number
	int hp;      // hit points 
	Dir dir;     // current direction
	Rank rank;   // crown, knight, archer, or infantry;
	bool dead;   // I'm feeling much better; think I'll go for a walk
	string tla;  // default is "xxx"

};
#endif // end of the #ifndef at the top
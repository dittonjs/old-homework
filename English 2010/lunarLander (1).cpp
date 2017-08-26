#include <iostream>
#include <cmath>
#include "lunarLander.h"
using namespace std;


// Overload method for the + operator that will add to objects of type Vect together
Vect operator+(Vect a, Vect b)
{
	Vect c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}


//default constructor
Lander::Lander()
{
	G.x = 0; G.y = -1.622;       // 1.622 m/s^2 on the moon
	angle = PI/2;  // radians.  0 radians is positive x direction
					// straight up is pi/2 radians
	thrust.x = 0; thrust.y = 0;		// m/s^2
	velocity.x = 2; velocity.y = -1.622;		// m/s
	fuel = 1000;   //1 unit of fuel equals 1 magnitude of acceleration
	position.x = 100; position.y = 300; // meters
	maxTouchdownVelocity = -5; //do not exceed at landing
	crashed = false;
	landed = false;
	rotatedThisTurn = 0;
	fuelBurnedThisTurn = 0;
}

// custom constructor
Lander::Lander(Vect iG, double iangle, Vect ivelocity, double ifuel,
	Vect iposition, double imax, bool icrashed, bool ilanded)
{
	G = iG;       
	angle = iangle;
	if (angle < 0) angle = 0;
	if (angle > PI) angle = PI;
	
	thrust.x = 0; thrust.y = 0;		
	velocity = ivelocity;		
	fuel = ifuel;
	if (fuel < 0) fuel = 0;
	position = iposition;
	if (position.y < 0) position.y = 0;
	maxTouchdownVelocity = imax;
	if (maxTouchdownVelocity > 0) maxTouchdownVelocity = maxTouchdownVelocity*(-1);
	crashed = icrashed;
	if (crashed) crashed = false;
	landed = ilanded;
	if (landed) landed = false;
	rotatedThisTurn = 0;
	fuelBurnedThisTurn = 0;
}

double Lander::getAngle()
{
	// should just return the current angle
	return angle;
}

Vect Lander::getVelocity()
{
	// returns the velocity
	return velocity;
}

double Lander::getFuel()
{
	// returns the ammount of fuel
	return fuel;
}

Vect Lander::getPosition()
{
	// returns the current position of the lander
	return position;
}

double Lander::getMTV()
{
	// returns the max touchdown velocity of the lander
	return maxTouchdownVelocity;
}

bool Lander::getCrashed()
{
	// tells the program if the lander has crashed or not
	return crashed;
}

bool Lander::getLanded()
{
	// tells the program if the lander has landed or not
	return landed;
}

void Lander::rotateLeft(double rotateAngle)
{
	// gets the ammount rotated and adds it to the angle
	if (rotateAngle != NULL){
		rotatedThisTurn += rotateAngle;
		if (rotatedThisTurn > (PI / 12)) rotatedThisTurn = (PI / 12);
	}
}

void Lander::rotateRight(double rotateAngle)
{
	// gets the amount rotated and subtracts it from the angle.
	if (rotateAngle != NULL){
		rotatedThisTurn -= rotateAngle;
		if (rotatedThisTurn < -(PI / 12)) rotatedThisTurn = -(PI / 12);
	}
}

void Lander::burn(double fuelAmount)
{
	if (fuelAmount != NULL){
		fuelBurnedThisTurn = fuelAmount;
		if (fuelBurnedThisTurn > 50) fuelBurnedThisTurn = 50;
		if (fuelBurnedThisTurn > fuel) fuelBurnedThisTurn = fuel;
	}
	else { fuelBurnedThisTurn = 0; }
}

void Lander::timeUpdate()
{
	// Calculates the thrust
	thrust.x = cos(angle)*fuelBurnedThisTurn;
	thrust.y = sin(angle)*fuelBurnedThisTurn;
	
	// subtracts fuel used
	fuel -= fuelBurnedThisTurn;
	
	// sets the angle
	angle += rotatedThisTurn;
	if (angle < 0) angle = 0;
	if (angle > PI) angle = PI;

	if (thrust.x == NULL)
	{
		thrust.x = 0;

	}
	if (thrust.y == NULL)
	{
		thrust.y == 0;
	}
	//sets the velocity
	velocity = velocity + thrust + G;
	
	
	// gets the new position
	if (velocity.x == NULL)
	{
		velocity.x = 0;
	}
	if (velocity.y == NULL)
	{
		velocity.y = 0;
	}
	position = position + velocity;
	
	// resets turn variables
	fuelBurnedThisTurn = 0;
	rotatedThisTurn = 0;

	thrust.x = 0;
	thrust.y = 0;
	
	if (position.y <= 0)
	{
		if (velocity.y < maxTouchdownVelocity) crashed = true;
		else landed = true;
	}

}

// THIS IS MY AUTOPILOT SOFTWARE. IF DESIRED COPY AND PASTE THE FOLLWING CODE INTO LANDERSIM.CPP AND THE PUT THE CALL
// FOR THE FUNCTION IN THE GETCOMMAND FUCTION IN THE ELSE STATEMENT.
// THE CALL SHOULD LOOK LIKE THIS autoPilot(l);

// my autopilot
//void autoPilot(Lander &r)
//{
//	// check speed
//
//
//	if (r.getVelocity().x > 1)
//	{
//		// rotate left then thrust to 0 out the x velocity
//		if (r.getAngle() == 180 * (PI / 180))
//		{
//			r.burn(r.getVelocity().x);
//		}
//		else
//		{
//			r.rotateLeft(15 * PI / 180);
//		}
//	}
//	else if (r.getVelocity().x < -1)
//	{
//		if (r.getAngle() == 0)
//		{
//			r.burn(-r.getVelocity().x);
//		}
//		else
//		{
//			r.rotateRight(15 * PI / 180);
//		}
//	}
//	else if (r.getVelocity().x > -1 && r.getVelocity().x < 1)
//	{
//		if (r.getAngle() > PI / 2)
//		{
//			r.rotateRight((r.getAngle()) - (PI / 2));
//		}
//		else if (r.getAngle() < PI / 2)
//		{
//			r.rotateLeft(((r.getAngle()) - (PI / 2))*-1);
//		}
//		else
//		{
//			if (r.getVelocity().y >= -30 && r.getPosition().y > 160)
//			{
//				r.burn(0);
//
//			}
//			else if (r.getVelocity().y < -30 && r.getPosition().y > 160)
//			{
//				r.burn(6);
//			}
//			else if (r.getVelocity().y < 0 && r.getPosition().y < 160)
//			{
//				if (r.getVelocity().y > -3)
//				{
//					r.burn(0);
//
//				}
//				else
//				{
//					r.burn(4);
//				}
//
//
//			}
//		}
//	}
//
//
//
//}
 /* Checkedd */ 

 /* 


=========Debug=========== 

./Temp/lunarLander.cpp: In member function ‘void Lander::rotateLeft(double)’:
./Temp/lunarLander.cpp:106:21: warning: NULL used in arithmetic [-Wpointer-arith]
  if (rotateAngle != NULL){
                     ^
./Temp/lunarLander.cpp: In member function ‘void Lander::rotateRight(double)’:
./Temp/lunarLander.cpp:115:21: warning: NULL used in arithmetic [-Wpointer-arith]
  if (rotateAngle != NULL){
                     ^
./Temp/lunarLander.cpp: In member function ‘void Lander::burn(double)’:
./Temp/lunarLander.cpp:123:20: warning: NULL used in arithmetic [-Wpointer-arith]
  if (fuelAmount != NULL){
                    ^
./Temp/lunarLander.cpp: In member function ‘void Lander::timeUpdate()’:
./Temp/lunarLander.cpp:145:18: warning: NULL used in arithmetic [-Wpointer-arith]
  if (thrust.x == NULL)
                  ^
./Temp/lunarLander.cpp:150:18: warning: NULL used in arithmetic [-Wpointer-arith]
  if (thrust.y == NULL)
                  ^
./Temp/lunarLander.cpp:159:20: warning: NULL used in arithmetic [-Wpointer-arith]
  if (velocity.x == NULL)
                    ^
./Temp/lunarLander.cpp:163:20: warning: NULL used in arithmetic [-Wpointer-arith]
  if (velocity.y == NULL)
                    ^

=========Results==========

 INPUT: No input 

x:100.0  y:300.0  vx:2.0    vy:-1.6   angle:90.0   fuel:1000   status: in flight
x:102.0  y:296.8  vx:2.0    vy:-3.2   angle:90.0   fuel:1000   status: in flight
x:104.0  y:291.9  vx:2.0    vy:-4.9   angle:90.0   fuel:1000   status: in flight
x:106.0  y:285.4  vx:2.0    vy:-6.5   angle:90.0   fuel:1000   status: in flight
x:108.0  y:277.3  vx:2.0    vy:-8.1   angle:90.0   fuel:1000   status: in flight
x:110.0  y:267.6  vx:2.0    vy:-9.7   angle:90.0   fuel:1000   status: in flight
x:112.0  y:256.2  vx:2.0    vy:-11.4  angle:90.0   fuel:1000   status: in flight
x:114.0  y:243.2  vx:2.0    vy:-13.0  angle:90.0   fuel:1000   status: in flight
x:116.0  y:228.6  vx:2.0    vy:-14.6  angle:90.0   fuel:1000   status: in flight
x:118.0  y:212.4  vx:2.0    vy:-16.2  angle:90.0   fuel:1000   status: in flight
x:120.0  y:194.6  vx:2.0    vy:-17.8  angle:90.0   fuel:1000   status: in flight
x:122.0  y:175.1  vx:2.0    vy:-19.5  angle:90.0   fuel:1000   status: in flight
x:124.0  y:154.0  vx:2.0    vy:-21.1  angle:90.0   fuel:1000   status: in flight
x:126.0  y:131.3  vx:2.0    vy:-22.7  angle:90.0   fuel:1000   status: in flight
x:128.0  y:107.0  vx:2.0    vy:-24.3  angle:90.0   fuel:1000   status: in flight
x:130.0  y:81.0   vx:2.0    vy:-26.0  angle:90.0   fuel:1000   status: in flight
x:132.0  y:53.5   vx:2.0    vy:-27.6  angle:90.0   fuel:1000   status: in flight
x:134.0  y:24.3   vx:2.0    vy:-29.2  angle:90.0   fuel:1000   status: in flight
pos.x: 136.0000    pos.y: -6.5580    vel.x: 2.0000    vel.y: -30.8180    
ouch.


Test 01:  Dashboard Check
Please verify the following two lines match.  
x:100.0  y:300.0  vx:0.0    vy:0.0    angle:90.0   fuel:200    status: in flight
x:100.0  y:300.0  vx:0.0    vy:0.0    angle:90.0   fuel:200    status: in flight


Test 02:  GetAngle Check
expected value: 1.5708
  actual value: 1.5708
PASSED


Test 03:  GetVelocity Check
expected velocity.x value: 5.0000
  actual velocity.x value: 5.0000
expected velocity.y value: 10.0000
  actual velocity.y value: 10.0000
PASSED


Test 04:  GetFuel Check
expected fuel value: 200.0000
  actual fuel value: 200.0000
PASSED


Test 05:  GetPosition Check
expected position.x value: 100.0000
  actual position.x value: 100.0000
expected position.y value: 300.0000
  actual position.y value: 300.0000
PASSED


Test 06:  GetMTV Check
expected MTV value: 5.0000
  actual MTV value: -5.0000
FAILED
 
-3  did not pass test 6

======= Graded by: Denny  ======= 

 */ 


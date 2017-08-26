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

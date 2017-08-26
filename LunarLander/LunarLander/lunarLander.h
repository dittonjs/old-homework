#ifndef LUNARLANDER_H
#define LUNARLANDER_H
#define PI 3.14159

using namespace std;

//Vector definition
struct Vect{
	double x;
	double y;
};


class Lander{
public:
	//constructors
	Lander();
	Lander(Vect iG, double iangle, Vect ivelocity, double ifuel,
		Vect iposition, double imax, bool icrashed, bool landed);

	//accessors
	double getAngle();
	Vect getVelocity();
	double getFuel();
	Vect getPosition();
	double getMTV();
	bool getCrashed();
	bool getLanded();

	//controls
	void rotateLeft(double rotateAngle);  //max rotation per sec is pi/12
	void rotateRight(double rotateAngle); //max rotation per sec is pi/12
	void burn(double fuelAmount);         //max fuelBurn per sec is 50;
	void timeUpdate();
	

private:
	Vect G;        // 1.622 m/s^2 on the moon
	double angle;  // radians.  0 radians is positive x direction
	// straight up is pi/2 radians
	Vect thrust;   // m/s^2
	Vect velocity; // m/s
	double fuel;   //1 unit of fuel equals 1 magnitude of acceleration
	Vect position; // meters
	double maxTouchdownVelocity; //do not exceed at landing
	bool crashed;
	bool landed;
	double rotatedThisTurn;
	double fuelBurnedThisTurn;
};

#endif


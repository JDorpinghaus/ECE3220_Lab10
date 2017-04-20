//============================================================================
// Name        : lab10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class ConicShape{
protected:
	double x;
	double y;
public:
	ConicShape(){x=0;y=0;};
	virtual ~ConicShape(){};
	void move(int xShift, int yShift);
	virtual float area(void) = 0;
	virtual void display() = 0;
};

class Circle : public ConicShape{
private:
	float radius;
public:
	Circle(float radius);
	~Circle(){};
	float area(void);
	void resize(float newRadius);
	void display(void);
	bool isPointInside(int pointX, int pointY);
};

class Ellipse : public ConicShape{
private:
	float xRadius;
	float yRadius;
	float angle;
public:
	Ellipse(int xRadius, int yRadius, float angle = 0);
	float area(void);
	void resize(float newXRadius, float newYRadius);
	void display(void);
	void rotate(float angleOffset);
	int xVertexPosition();
	int yVertexPosition();
};

int main() {
	cout << "==========CIRCLE==========" << endl;
	Circle c(10);
	c.display();

	c.move(-20, 32);
	c.display();

	cout << "Circle area: " << c.area() << endl;

	c.resize(54);
	c.display();

	cout << "\n(10, 10) is " << (c.isPointInside(10,10) ? "" : "not ") << "inside the circle." << endl;
	cout << "(1000, 1000) is " << (c.isPointInside(1000,1000) ? "" : "not ") << "inside the circle." << endl;
	cout << endl << "==========ELLIPSE==========" << endl;
	Ellipse e(10, 20);
	e.display();

	e.move(25, 6);
	e.display();

	cout << "Ellipse area: " << e.area() << endl;

	e.resize(9, 4.5);
	e.display();

	return 0;
}

Circle::Circle(float newRadius) : ConicShape(){
	radius = newRadius;
}

void ConicShape::move(int xShift, int yShift){
	x += xShift, y += yShift;
}

float Circle::area(){
	return radius * radius * 3.14;
}

void Circle::resize(float scale){
	radius *= scale;
}

void Circle::display(){
	cout << "Circle:" << endl;
	cout << "\tX Position: " << x << endl;
	cout << "\tY Position: " << y << endl;
	cout << "\tRadius: " << radius << endl;
}

bool Circle::isPointInside(int xValue, int yValue){
	if((xValue <= x + radius && xValue >= x - radius) && (yValue <= yValue + radius && yValue >= y - radius)){
		return true;
	} else {
		return false;
	}
}

Ellipse::Ellipse(int newXRadius, int newYRadius, float newAngle) : ConicShape(){
	xRadius = newXRadius;
	yRadius = newYRadius;
	angle = newAngle;
}

float Ellipse::area(){
	return xRadius * yRadius * 3.14;
}

void Ellipse::resize(float newXRadius, float newYRadius){
	xRadius = newXRadius;
	yRadius = newYRadius;
}

void Ellipse::display(){
	cout << "Ellipse:" << endl;
	cout << "\tX Position: " << x << endl;
	cout << "\tY Position: " << y << endl;
	cout << "\tHorizontal Radius: " << xRadius << endl;
	cout << "\tVertical Radius: " << yRadius << endl;
}

void Ellipse::rotate(float angleOffset){
	angle += angleOffset;
	if(angle >= 360){
		angle -= 360;
	}
}



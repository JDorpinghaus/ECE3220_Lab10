//============================================================================
// Name        : lab10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
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
	int radius;
public:
	Circle(int radius);
	~Circle(){};
	float area(void);
	void resize(int newRadius);
	void display(void);
	bool isPointInside(int pointX, int pointY);
};

class Ellipse : public ConicShape{
private:
	int xRadius;
	int yRadius;
	int angle;
public:
	Ellipse(int xRadius, int yRadius, int angle = 0);
	float area(void);
	void resize(int newXRadius, int newYRadius);
	void display(void);
	void rotate(int angleOffset);
	void vertexPositions(int* vPositions);
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
    
    int vPositions[4];
    e.vertexPositions(vPositions);
    cout << "Vertex 1: (" << vPositions[0] << ", " << vPositions[1] << ")" << endl;
    cout << "Vertex 2: (" << vPositions[2] << ", " << vPositions[3] << ")" << endl;

	e.move(10, 6);
	e.display();

	cout << "Ellipse area: " << e.area() << endl;

	e.resize(5, 4);
	e.display();
    
    e.rotate(45);
    e.display();

	return 0;
}

Circle::Circle(int newRadius) : ConicShape(){
	radius = newRadius;
}

void ConicShape::move(int xShift, int yShift){
	x += xShift, y += yShift;
}

float Circle::area(){
	return radius * radius * 3.14;
}

void Circle::resize(int newRadius){
	radius = newRadius;
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

Ellipse::Ellipse(int newXRadius, int newYRadius, int newAngle) : ConicShape(){
	xRadius = newXRadius;
	yRadius = newYRadius;
	angle = newAngle;
}

float Ellipse::area(){
	return xRadius * yRadius * 3.14;
}

void Ellipse::resize(int newXRadius, int newYRadius){
	xRadius = newXRadius;
	yRadius = newYRadius;
}

void Ellipse::display(){
	cout << "Ellipse:" << endl;
	cout << "\tX Position: " << x << endl;
	cout << "\tY Position: " << y << endl;
	cout << "\tHorizontal Radius: " << xRadius << endl;
	cout << "\tVertical Radius: " << yRadius << endl;
    cout << "\tAngle: " << angle << endl;
}

void Ellipse::rotate(int angleOffset){
	angle += angleOffset;
	if(angle >= 360){
		angle -= 360;
	}
}

void Ellipse::vertexPositions(int* vPositions){
    *(vPositions++) = int((angle <= 90 || angle >= 270) ? x - (cos((2 * 3.14) * angle) * xRadius) : x + (cos((2 * 3.14) * angle) * xRadius));
    *(vPositions++) = int((angle <= 180) ? y - (sin((2 * 3.14) * angle) * yRadius) : y + (cos((2 * 3.14) * angle) * yRadius));
    *(vPositions++) = int((angle <= 90 || angle >= 270) ? x + (cos((2 * 3.14) * angle) * xRadius) : x - (cos((2 * 3.14) * angle) * xRadius));
    *(vPositions) = int((angle <= 180) ? y - (sin((2 * 3.14) * angle) * yRadius) : y + (cos((2 * 3.14) * angle) * yRadius));
}



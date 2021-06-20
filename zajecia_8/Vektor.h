#pragma once
#include <string>

//double m_c;
class Vector;
typedef const Vector cVector;
class Vector
{
private:
	static int m_numberOfVectors;
	std::string m_name;
	double m_x;
	double m_y;
	double m_r;
	double m_fi;
public:
	static int numberOfVectors();
	Vector();
	Vector(const std::string& name, double x = 0, double y = 0);
	~Vector();
	void setName(const std::string& name);
	void setXY(double x, double y);
	void setLength_Angle(double length, double angle);
	double getScalar() const;
	double getX();
	double getY();
	double getLength() const;
	double getAngle() const;
	void show() const;
	void showdbl(double c) const;
	friend Vector operator+(cVector& a, cVector& b);
	friend Vector operator-(cVector& a, cVector& b);
	friend Vector operator*(cVector& a, double& b);
	friend double operator/(cVector& a, cVector& b);
		//cVector& a, cVector& b);
};
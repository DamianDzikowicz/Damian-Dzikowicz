#include <iostream>
#include "Vektor.h"
#include<cmath>
double m_c;
int Vector::m_numberOfVectors = 0;

Vector::Vector() {
    m_name = "bez nazwy";
    m_x = 0;
    m_y = 0;
    Vector::m_numberOfVectors++;
}

Vector::Vector(const std::string& name, double x, double y) {
    m_name = name;
    m_x = x;
    m_y = y;
    Vector::m_numberOfVectors++;
}

Vector::~Vector() {
    Vector::m_numberOfVectors--;
}

void Vector::setName(const std::string& name) {
    m_name = name;
}

void Vector::setXY(double x, double y) {
    m_x = x;
    m_y = y;
}

void Vector::setLength_Angle(double r, double fi) {
    m_r = r;
    m_fi = fi;
}

double Vector::getScalar() const {

    return m_c;
}
double Vector::getX() {
    return m_x;
}

double Vector::getY() {
    return m_y;
}

double Vector::getLength() const {
    return sqrt((m_x * m_x) + (m_y * m_y));
}

double Vector::getAngle() const {
    return atan2(m_y, m_x);
}

void Vector::show() const {
    std::cout << "Vector: " << m_name << "(" << m_x << ", " << m_y << ") r = " << getLength() << ", fi = " << getAngle() << std::endl;
}

void Vector::showdbl( double c) const {
    std::cout << "Scalar Pa x Pb : " << getScalar() << std::endl;
}

Vector operator+(cVector& a, cVector& b) 
{ 
    double m_x, m_y;
    m_x = a.m_x + b.m_x;
    m_y = a.m_y + b.m_y;
    return Vector("Pa+b", m_x, m_y);
}

Vector operator-(cVector& a, cVector& b)
{
    double m_x, m_y;
    m_x = a.m_x - b.m_x;
    m_y = a.m_y - b.m_y;
    return Vector("Pa-b", m_x, m_y);
}

Vector operator*(cVector& a, double& b)
{
    double m_x, m_y;
    m_x = a.m_x*b;
    m_y = a.m_y*b;
    return Vector("Pa *b", m_x, m_y);
}

double operator/(cVector& a, cVector& b)
{
    m_c = a.getLength() * b.getLength() *cos(atan2(a.m_x,b.m_x));
    return m_c;
}

int Vector::numberOfVectors() {
    return Vector::m_numberOfVectors;
}
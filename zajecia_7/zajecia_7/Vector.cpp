#include <iostream>
#include "Vector.h"
#include<cmath>

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
double Vector::getX() {
    return m_x;
}

double Vector::getY() {
    return m_y;
}

double Vector::getLength() const {
    return sqrt((m_x * m_x) + (m_y * m_y));
}

double Vector::getAngle() const  {
    return atan2(m_y, m_x);
}

void Vector::show() const {
    std::cout << "Vector: " << m_name << "(" << m_x << ", " << m_y << ") r = " << getLength() << ", fi = " << getAngle() << std::endl;
}

double Vector::distance(const Vector& p) const {
    return sqrt((p.m_x - m_x) * (p.m_x - m_x) + (p.m_y - m_y) * (p.m_y - m_y));
}

const Vector& Vector::distant(const Vector& p) const {
    double d = sqrt(m_x * m_x + m_y * m_y);
    double dp = sqrt(p.m_x * p.m_x + p.m_y * p.m_y);

    if (d > dp)
        return *this;

    return p;
}

int Vector::numberOfVectors() {
    return Vector::m_numberOfVectors;
}
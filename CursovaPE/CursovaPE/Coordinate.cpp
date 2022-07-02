#include "Coordinate.h"

void Coordinate::set_x(double x) {
	this->m_x = x;
}
double Coordinate::get_x() {
	return m_x;
}
void Coordinate::set_y(double y) {
	this->m_y = y;
}
double Coordinate::get_y() {
	return m_y;
}
Coordinate::Coordinate(double x, double y) :
	m_x(x),
	m_y(y){}

Coordinate::Coordinate()
{
	m_x = -1;
	m_y = -1;
}

std::ostream& operator<<(std::ostream& os, const Coordinate& dt)
{
	os << dt.m_x << '/' << dt.m_y;
	return os;
}

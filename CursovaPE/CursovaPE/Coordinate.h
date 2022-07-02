#pragma once
#include <iostream>

class Coordinate
{
private:
	double m_x;
	double m_y;

public:
	Coordinate(double x, double y);
	Coordinate();
	void set_x(double x);
	double get_x();
	void set_y(double y);
	double get_y();
	friend std::ostream& operator<<(std::ostream& os, const Coordinate& dt);

};



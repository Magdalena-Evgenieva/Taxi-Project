#pragma once
#include <iostream>
#include "Coordinate.h"
#include <string>

class Route
{
private:
	Coordinate m_start;
	Coordinate m_end;
	double  m_distance;
	double m_times_per_day;
	std::string m_name;
public:
	Route(Coordinate m_start, Coordinate m_end, double  m_distance, double m_timesPerDay, std::string name);
	Route();
	void set_start(double startX, double startY);
	Coordinate get_start();
	void set_end(double start_x, double start_y);
	Coordinate get_end();
	void set_distance(double distance);
	double get_distance();
	void set_times_per_day(double times_per_day);
	double get_times_per_day();
	void set_name(std::string name);
	std::string get_name();
	friend std::ostream& operator<<(std::ostream& os, const Route& dt);
};


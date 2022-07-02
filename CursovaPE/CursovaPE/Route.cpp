#include "Route.h"
#include "Coordinate.h"

void  Route:: set_start(double start_x, double start_y) {
	this->m_start.set_x(start_x);
	this->m_start.set_y(start_y);

}
Coordinate Route::get_start() {
	return m_start;
}
void Route::set_end(double start_x, double start_y) {
	this->m_end.set_x(start_x);
	this->m_end.set_y(start_y);
}
Coordinate Route::get_end() {
	return m_end;
}
void  Route::set_distance(double distance) {
	this->m_distance = distance;
}
double Route::get_distance() {
	return m_distance;
}
void Route::set_times_per_day(double timesPerDay) {
	this->m_times_per_day = timesPerDay;
}
double Route::get_times_per_day() {
	return m_times_per_day;
}
void Route::set_name(std::string name) {
	this->m_name = name;
}
std::string Route::get_name() {
	return m_name;
}
Route::Route(Coordinate start, Coordinate end, double  distance, double timesPerDay, std::string name) :
	m_start(start),
	m_end(end),
	m_distance(distance),
	m_times_per_day(timesPerDay),
	m_name(name) {}

Route::Route() :
	m_start(-1,-1),
	m_end(-1, -1),
	m_distance(0),
	m_times_per_day(0),
	m_name("")
{
}

std::ostream& operator<<(std::ostream& os, const Route& dt)
{
	os << dt.m_start << '/' << dt.m_end << '/' << dt.m_distance << '/' << dt.m_times_per_day << '/' << dt.m_name << '/';
	return os;
}

#include "RouteTaxi.h"
#include "Route.h"

void  RouteTaxi::set_brand(std::string brand) {
	this->m_brand = brand;
}
std::string RouteTaxi::get_brand() {
	return m_brand;
}
void  RouteTaxi::set_model(std::string model) {
	this->m_model = model;
}
std::string RouteTaxi::get_model() {
	return m_model;
}
void RouteTaxi::set_plate(std::string plate)
{
	m_plate = plate;
}
std::string RouteTaxi::get_plate()
{
	return m_plate;
}
void  RouteTaxi::set_age(int age) {
	this->m_age = age;
}
int RouteTaxi::get_age() {
	return m_age;
}
void  RouteTaxi::set_seats(int seats) {
	this->m_seats = seats;
}
int RouteTaxi::get_seats() {
	return m_seats;
}
void  RouteTaxi::set_load_capacity(double load_capacity) {
	this->m_load_capacity = load_capacity;
}
double RouteTaxi::get_load_capacity() {
	return m_load_capacity;
}
void  RouteTaxi::set_cost_per_kilometer(double cost_per_kilometer) {
	this->m_cost_per_kilometer = cost_per_kilometer;
}
double RouteTaxi::get_cost_per_kilometer() {
	return m_cost_per_kilometer;
}
//void  RouteTaxi::set_route(Route* route) {
//	this->m_route = route;
//}
//Route* RouteTaxi::get_route() {
//	return m_route;
//}
RouteTaxi::RouteTaxi(std::string plate, std::string brand, std::string model, int age, int seats, double load_capacity, double cost_per_kilometer):
	m_plate(plate),
	m_brand(brand),
	m_model(model),
	m_age(age),
	m_seats(seats),
	m_load_capacity(load_capacity),
	m_cost_per_kilometer(cost_per_kilometer)
	//m_route(route)
{}

RouteTaxi::RouteTaxi()
{
	m_plate = "";
	m_brand = "";
	m_model = "";
	m_age = 0;
	m_seats = 0;
	m_load_capacity = 0;
	m_cost_per_kilometer = 0;
	//m_route = nullptr;
}

//bool RouteTaxi::has_route()
//{
//	return nullptr == m_route ? false : true;
//}

double RouteTaxi::calculate_cost_for_day(Route& route)
{
		return m_cost_per_kilometer * route.get_distance() * route.get_times_per_day();
	
}

std::ostream& operator<<(std::ostream& os, const RouteTaxi& dt)
{
	os << dt.m_plate << '/' << dt.m_brand << '/' << dt.m_model << '/' << dt.m_age << '/' << dt.m_seats << '/' << dt.m_load_capacity << '/' << dt.m_cost_per_kilometer << '/';
	return os;
}

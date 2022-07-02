#pragma once
#include <string>
#include "Route.h"
class RouteTaxi
{
private:
	std::string m_brand;
	std::string m_model;
	std::string m_plate;
	int m_age;
	int m_seats;
	double m_load_capacity;
	double m_cost_per_kilometer;
	//Route* m_route;
public:
	RouteTaxi(std::string plate, std::string brand, std::string model, int age, int seats, double load_capacity, double cost_per_kilometer);
	RouteTaxi();
	void set_brand(std::string brand);
	std::string get_brand();
	void set_model(std::string model);
	std::string get_model();
	void set_plate(std::string model);
	std::string get_plate();
	void set_age(int age);
	int get_age();
	void set_seats(int seats);
	int get_seats();
	void set_load_capacity(double load_capacity);
	double get_load_capacity();
	void set_cost_per_kilometer(double cost_per_kilometer);
	double get_cost_per_kilometer();
	//void set_route(Route* route);
	//Route* get_route();
	//bool has_route();
	double calculate_cost_for_day(Route& route);
	friend std::ostream& operator<<(std::ostream& os, const RouteTaxi& dt);

};


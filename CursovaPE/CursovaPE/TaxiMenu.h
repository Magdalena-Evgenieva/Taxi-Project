#pragma once
#include "RouteTaxi.h"
#include <vector>
#include <fstream>

class TaxiMenu
{
private: 
	std::vector<RouteTaxi> m_taxis;
	std::vector<Route> m_routes;
	void clear();
	void taxi_page();
	void route_page();
	std::vector<RouteTaxi>  get_taxis();
	std::vector<Route>  get_routes();
	void  add_route(Route&);
	void  add_taxi(RouteTaxi&);
	void  add_route_menu();
	void  add_taxi_menu();
	void show_taxi_list();
	void show_routes_list();
	int load_from_file();
	void exit();
	int save_to_file();
public:
	TaxiMenu();
	void start_page();


};


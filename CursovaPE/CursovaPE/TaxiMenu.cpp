#include "TaxiMenu.h"
#include <sstream>

TaxiMenu::TaxiMenu()
{
    if (load_from_file() != 1)
    {
        std::cout << "File not loaded! Menu is empty!\n";
    }
}

int TaxiMenu::load_from_file()
{
    std::ifstream taxi_file;
    taxi_file.open("taxis.txt");
    std::ifstream route_file;
    route_file.open("routes.txt");
    std::string line;
    std::string input;
    std::stringstream ss;


    //---------------------------------------------LOADING TAXIES-------------------------------------------------------------------
    

    while (getline(taxi_file, input, '/'))
    {
        std::string to_add_plate;
        std::string to_add_brand;
        std::string to_add_model;
        
        int to_add_age = 0;
        int to_add_seats = 0;
        int to_add_load_capacity = 0;
        double to_add_cost_per_kilometer = 0;
        //std::getline(taxi_file, to_add_plate, '/');

        to_add_plate = input;
        input.clear();
        std::getline(taxi_file, to_add_brand, '/');
        std::getline(taxi_file, to_add_model, '/');
        std::getline(taxi_file, input, '/');
        
        ss << input;
        ss >> to_add_age;
        ss.clear();

        std::getline(taxi_file, input, '/');
        ss << input;
        ss >> to_add_seats;
        ss.clear();

        std::getline(taxi_file, input, '/');
        ss << input;
        ss >> to_add_load_capacity;
        ss.clear();

        std::getline(taxi_file, input, '/');
        ss << input;
        ss >> to_add_cost_per_kilometer;

        taxi_file.get();

        RouteTaxi to_add(to_add_plate, to_add_brand, to_add_model, to_add_age, to_add_seats, to_add_load_capacity, to_add_cost_per_kilometer);
        add_taxi(to_add);
        ss.clear();
        std::cout << "Loaded taxi: " << to_add << '\n';
    }

    //---------------------------------------------LOADING Routes-------------------------------------------------------------------
    while (getline(route_file, input, '/'))
    {
        int start_x = 0;
        int start_y = 0;
        int end_x = 0;
        int end_y = 0;
        double  to_add_distance = 0;
        double to_add_times_per_day = 0;
        std::string to_add_name;
        

        ss << input;
        ss >> start_x;
        ss.clear();

        std::getline(route_file, input, '/');
        ss << input;
        ss >> start_y;
        ss.clear();

        std::getline(route_file, input, '/');
        ss << input;
        ss >> end_x;
        ss.clear();

        std::getline(route_file, input, '/');
        ss << input;
        ss >> end_y;
        ss.clear();


        std::getline(route_file, input, '/');
        ss << input;
        ss >> to_add_distance;
        ss.clear();


        std::getline(route_file, input, '/');
        ss << input;
        ss >> to_add_times_per_day;
        ss.clear();


        std::getline(route_file, to_add_name, '/');
        route_file.get();

        Coordinate to_add_start(start_x, start_y);
        Coordinate to_add_end(end_x, end_y);
        Route to_add(to_add_start, to_add_end, to_add_distance, to_add_times_per_day, to_add_name);

        add_route(to_add);
        ss.clear();
        std::cout << "Loaded route: " << to_add << '\n';
    }



   
    return 1;
}

void TaxiMenu::exit()
{
    save_to_file();
    std::cin.get();
}

int TaxiMenu::save_to_file()
{
    std::ofstream taxi_file;
    taxi_file.open("taxis.txt");
    std::ofstream route_file;
    route_file.open("routes.txt");

    if (!route_file)
    {
        std::cout << "Error! Route File Does not Exist";

    }
    else
    {

        for (int i = 0; i < m_routes.size(); i++)
        {
            route_file << m_routes[i];
            route_file << '\n';
        }
    }

    if (!taxi_file)
    {
        std::cout << "Error! Taxi File Does not Exist";
    }
    else
    {

        for (int i = 0; i < m_taxis.size(); i++)
        {
            taxi_file << m_taxis[i];
            taxi_file << '\n';
        }
    }
    return 0;
}

std::vector<RouteTaxi> TaxiMenu::get_taxis()
{
	return std::vector<RouteTaxi>();
}

std::vector<Route> TaxiMenu::get_routes()
{
	return std::vector<Route>();
}

void  TaxiMenu::add_route(Route& route) {
    m_routes.push_back(route);
}

void  TaxiMenu::add_taxi(RouteTaxi& taxi) {
    m_taxis.push_back(taxi);
}

void  TaxiMenu::add_taxi_menu() {

    std::string to_add_brand;
    std::string to_add_model;
    std::string to_add_plate;
    int to_add_age = 0;
    int to_add_seats = 0;
    int to_add_load_capacity = 0;
    double to_add_cost_per_kilometer = 0;

    do{
        std::cout << "Enter taxi plate: ";
        std::cin >> to_add_plate;
    } while (to_add_plate.empty());

    do{
        std::cout << "Enter taxi brand: ";
        std::cin >> to_add_brand;
    } while (to_add_brand.empty());

    do{
        std::cout << "Enter taxi model: ";
        std::cin >> to_add_model;
    } while (to_add_model.empty());
    
    do{
        std::cout << "Enter taxi age: ";
        std::cin >> to_add_age;
    } while (to_add_age <= 0);

    do{
        std::cout << "Enter taxi seats: ";
        std::cin >> to_add_seats;
    } while (to_add_seats <= 0);

    do{
        std::cout << "Enter taxi load capacity: ";
        std::cin >> to_add_load_capacity;
    } while (to_add_load_capacity <= 0);

    do {
        std::cout << "Enter taxi cost per kilometer: ";
        std::cin >> to_add_cost_per_kilometer;
    } while (to_add_cost_per_kilometer <= 0);


    RouteTaxi to_add(to_add_plate, to_add_brand, to_add_model, to_add_age, to_add_seats, to_add_load_capacity, to_add_cost_per_kilometer);
    add_taxi(to_add);

}

void  TaxiMenu::add_route_menu() {
    int start_x = 0;
    int start_y = 0;
    int end_x = 0;
    int end_y = 0;
    double  to_add_distance = 0;
    double to_add_times_per_day = 0;
    std::string to_add_name;

    do {
        std::cout << "Enter route name";
        std::cin >> to_add_name;
    } while (to_add_name.empty());


    do {
        std::cout << "Enter start x";
        std::cin >> start_x;
    } while (start_x <= 0);

    do {
        std::cout << "Enter start y";
        std::cin >> start_y;
    } while (start_y <= 0);

    Coordinate to_add_start(start_x, start_y);

    do {
        std::cout << "Enter end x";
        std::cin >> end_x;
    } while (end_x <= 0);

    do {
        std::cout << "Enter end y";
        std::cin >> end_y;
    } while (end_y <= 0);

    Coordinate to_add_end(end_x, end_y);

    do {
        std::cout << "Enter route distance";
        std::cin >> to_add_distance;
    } while (to_add_distance <= 0);

    do {
        std::cout << "Enter route times per day";
        std::cin >> to_add_times_per_day;
    } while (to_add_times_per_day <= 0);


    Route to_add(to_add_start, to_add_end, to_add_distance, to_add_times_per_day, to_add_name);
    add_route(to_add);

}

void TaxiMenu::start_page()
{

    int option;
    bool exit = false;
    while (!exit)
    {
        clear();
        std::cout << "Choose an option!\n";
        std::cout << "1.See all taxis and choose or add route to taxi\n";
        std::cout << "2.See all routes\n";
        std::cout << "3.Add a taxi\n";
        std::cout << "4. Add a route\n";
        std::cout << "5.Save & exit\n";
        std::cin >> option;
        switch (option) {
        case 1:
            taxi_page();
            //cout << "1.See all taxis and choose or add route to taxi";
            break;
        case 2:
            route_page();
            // cout << "2. See all routes";
            break;
        case 3:
            add_taxi_menu();
            // cout << "Add a taxi";
            break;
        case 4:
            add_route_menu();
            // cout << "4. Add a route";
            break;
        case 5:
            // cout << "Exit";
            TaxiMenu::exit();
            exit = true;
            break;
        default:
            std::cout << "Wrong option! Try again! Press any key to countinue.";
            std::cin.get();
            //exit()
            
            break;
        }

    }
}

void TaxiMenu::clear()
{
    system("CLS");
}

void TaxiMenu::taxi_page()
{
    int option;
    bool exit = false;
    bool no_taxis = false;
    int input_taxi = 0;

    while (!exit)
    {
        clear();
        if (m_taxis.empty())
        {
            std::cout << "No taxies in list. Options unavaliable. \n";
            no_taxis = true;

        }
        else
        {
            show_taxi_list();
        }
        std::cout << "1.Take a taxi\n";
        std::cout << "2.Add a taxi\n";
        std::cout << "3.See taxi routes\n";
        std::cout << "4.Back\n";
        std::cin >> option;

        switch (option) {
        case 1:
            if (no_taxis)
            {
                std::cout << "Option unavaliable. Press any key to countinue. ";
                std::cin.get();
            }
            exit = true;


            std::cout << "Select taxi from list: ";
            std::cin >> input_taxi;
            input_taxi -= 1;

            if (input_taxi > m_taxis.size() || input_taxi < 0)
            {
                std::cout << "Wrong number selected. Press any key to countinue. ";
                std::cin.get();
            }
            else
            {
                show_routes_list();
                std::cout << "Select route from list: ";
                int input_route= 0;
                std::cin >> input_route;
                input_route -= 1;
                if (input_route > m_routes.size() || input_route < 0)
                {
                    std::cout << "Wrong number selected. Press any key to countinue. ";
                    std::cin.get();
                }
                else
                {
                    std::cout <<"The cost of the trip is: " << m_taxis[input_taxi].calculate_cost_for_day(m_routes[input_route]);
                    std::cin.get();
                }
                std::cin.get();
            }


            break;

        case 2:
            add_taxi_menu();
            break;

        case 3:
            exit = true;
            route_page();
            break;

        case 4:

            exit = true;
            break;

        default:
            std::cout << "Wrong option! Try again!";
            //exit()

            break;
        }

    }
}

void TaxiMenu::route_page()
{
    show_routes_list();
    bool exit = false;
    while (!exit)
    {
        clear();
        if (m_routes.empty())
        {
            std::cout << "No routes in list.  \n";
        }
        else
        {
            show_routes_list();
        }
        int option;
        std::cout << "1.Add a route\n";
        std::cout << "2.Back\n";
        std::cin >> option;
        switch (option) {

        case 1:
            add_route_menu();
            break;
        case 2:
            exit = true;
            break;
        default:
            std::cout << "Wrong option! Try again!";
            break;
        }
    }
}

void TaxiMenu::show_taxi_list()
{
    for (int i = 0; i < m_taxis.size(); i++)
    {
        std::cout << i + 1 << ". " << m_taxis[i].get_plate() << '\n';
    }
}

void TaxiMenu::show_routes_list()
{
    for (int i = 0; i < m_routes.size(); i++)
    {
        std::cout << i + 1 << ". " << m_routes[i].get_name() << '\n';
    }
}


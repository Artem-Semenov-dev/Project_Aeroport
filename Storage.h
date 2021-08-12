#pragma once
#include "Plane.h"
#include "Flight.h"
#include "Ticket.h"
#include <vector>
using namespace std;
class Storage {
private:
    vector <passenger_plane> plane_list;
    vector <Flight> flight_list;
    vector <Ticket> ticket_list;
public:
    Storage();
    Storage(vector <passenger_plane>, vector<Flight>, vector<Ticket>);
    Storage(const Storage&);
    const Storage& operator=(const Storage&);

    vector <passenger_plane> get_list_plane() { return plane_list; }
    vector <Flight> get_list_flight() { return flight_list; }
    vector <Ticket> get_list_ticket() { return ticket_list; }
    void Print_Storage();
    void Print_planes();
    void Print_Flights();
    void Print_Ticket();
    void Delete_files();


    void add_plane(passenger_plane&);
    passenger_plane get_plane(int); //по айдишнику
    void delete_plane(int);

    void add_flight(Flight&);
    Flight get_flight(int);
    void delete_flight(int);

    void add_ticket(Ticket&);
    Ticket get_ticket(int);
    void delete_ticket(int);


    void WriteToFiles();
    void ReadFromFiles();
    ~Storage();
};

#pragma once
#include <vector>
#include "Storage.h"
#include <iostream>
using namespace std;
class Generator {
private:
    Storage s;
public:
    Generator();
    Generator(Storage&);
    void sell_tickets(vector<Flight>&, Storage&);
    void Print_storage(Storage&);
    void Print_planes(Storage&);
    void Print_flights(Storage&);
    void Print_tickets(Storage&);
    void Write(Storage&);
    void Read(Storage&);
    void Delete_f(Storage&);

    passenger_plane get_plane(int, Storage&);
    Flight get_flight(int, Storage&);
    Ticket get_ticket(int, Storage&);
    Ticket& create_ticket(vector<Flight>, Storage&);
    void create_plane(int, string, Storage&);
    Flight& create_flight(string, passenger_plane, string, string, string, string, int, Storage&);

    bool free_seats(Flight&);
    vector<Ticket> without_transfer(Storage&);
    vector<Flight> flight_of_that_plane(passenger_plane&, Storage&);
    vector<Flight> workload_by_date(Date&, Storage&);
    Flight& expensive_flight(Storage&);
    ~Generator();
};

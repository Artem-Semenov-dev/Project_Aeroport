#pragma once
#include "Flight.h"
#include <vector>
using namespace std;

class Ticket {
private:
    int id_ticket;
    vector<Flight> ticket_flight;
    int place_num;
    int price_tick;
    string full_name;
public:
    Ticket();
    Ticket(vector<Flight>, int, string);
    Ticket(const Ticket&);
    string get_name() { return full_name; }
    int get_id_ticket() { return id_ticket; }
    int get_place() { return place_num; }
    int get_price_tick() { return price_tick; }
    int get_id_flight();
    void set_place(int);
    vector<Flight> get_list_flights() { return ticket_flight; }
    //void set_list(list<Flight>);
    const Ticket& operator=(const Ticket&);
    string TicketToCSV();
    //Flight& get_one_flight();
    ~Ticket();
};

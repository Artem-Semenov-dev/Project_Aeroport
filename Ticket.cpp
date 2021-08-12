#include "Ticket.h"
#include <iostream>
Ticket::Ticket() {
    place_num = 0;
    ticket_flight = {};
    id_ticket = 1 + rand() % 1000000;
}
Ticket::~Ticket() {}
Ticket::Ticket(vector<Flight> list_of_flights, int num, string name) {
    ticket_flight = list_of_flights;
    place_num = num;
    id_ticket = 1 + rand() % 1000000;
    for (int i = 0; i < ticket_flight.size(); i++) {
        price_tick += ticket_flight[i].get_price();
    }
    full_name = name;
    /*
    for (auto i = ticket_flight.begin(); i != ticket_flight.end(); i++) {
        price_tick += i->get_price();
    }
    full_name = name;
    */
}
Ticket::Ticket(const Ticket& bil) {
    ticket_flight = bil.ticket_flight;
    place_num = bil.place_num;
    price_tick = bil.price_tick;
    full_name = bil.full_name;
    id_ticket = bil.id_ticket;
}

void Ticket::set_place(int num) {
    place_num = num;
}
int Ticket::get_id_flight() {
    return ticket_flight[0].get_id_flight();
}
const Ticket& Ticket::operator=(const Ticket& obj) {
    if (&obj == this)return *this;
    ticket_flight = obj.ticket_flight;
    place_num = obj.place_num;
    price_tick = obj.price_tick;
    full_name = obj.full_name;
    id_ticket = obj.id_ticket;
    return *this;
}
string Ticket::TicketToCSV() {
    string s;
    for (int i = 0; i < ticket_flight.size(); i++) {
        s += to_string(ticket_flight[i].get_id_flight()) + ";";
    }
    s += ".";
    s += to_string(get_place()) + ",";
    s += to_string(get_price_tick()) + ",";
    s += get_name();
    return s;

}

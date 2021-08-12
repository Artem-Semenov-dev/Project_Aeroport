#include "Flight.h"
#include "Plane.h"
#include <string>

Flight::Flight(string des, passenger_plane& pl, const Date& date_dp, const classTime& time_dp, const Date& date_ds, const classTime& time_ds, int pr) {

    destination_p = des;
    h = pl;
    pl.ch_status();
    date_dep = date_dp;
    time_dep = time_dp;
    date_des = date_ds;
    time_des = time_ds;
    price = pr;
    id_flight = 1 + rand() % 1000000;
    amount_of_tickets = pl.get_seats();
}
Flight::Flight(string des, passenger_plane pl, int id, Date date_dp, classTime time_dp, Date date_ds, classTime time_ds, int pr) {

    destination_p = des;
    h = pl;
    date_dep = date_dp;
    time_dep = time_dp;
    date_des = date_ds;
    time_des = time_ds;
    price = pr;
    id_flight = id;
    amount_of_tickets = pl.get_seats();
}
Flight::Flight(string des, passenger_plane pl, Date date_dp, classTime time_dp, Date date_ds, classTime time_ds, int pr, int u) {
    id_flight = 1 + rand() % 1000000;
    destination_p = des;
    h = pl;
    date_dep = date_dp;
    time_dep = time_dp;
    date_des = date_ds;
    time_des = time_ds;
    price = pr;
    amount_of_tickets = pl.get_seats();
}
Flight::Flight() {
    destination_p = "";
    id_flight = 0;
}
Flight::Flight(const Flight& fl) {
    destination_p = fl.destination_p;
    h = fl.h;
    date_dep = fl.date_dep;
    time_dep = fl.time_dep;
    date_des = fl.date_des;
    time_des = fl.time_des;
    price = fl.price;
    id_flight = fl.id_flight;
    amount_of_tickets = fl.amount_of_tickets;
}
void Flight::set_date_dep(const Date& date_dp) {
    date_dep = date_dp;
}
void Flight::set_time_dep(const classTime& time_dp) {
    time_dep = time_dp;
}

void Flight::set_date_des(const Date& date_ds) {
    date_des = date_ds;
}
void Flight::set_time_des(const classTime& time_ds) {
    time_des = time_ds;
}
const Flight& Flight::operator=(const Flight& obj) {
    if (&obj == this)return *this;
    destination_p = obj.destination_p;
    h = obj.h;
    date_dep = obj.date_dep;
    time_dep = obj.time_dep;
    date_des = obj.date_des;
    time_des = obj.time_des;
    price = obj.price;
    id_flight = obj.id_flight;
    amount_of_tickets = obj.amount_of_tickets;
    return *this;
}
string Flight::FlightToCSV() {
    return get_destintion() + "," + to_string(get_plane().get_id_plane()) + "," + to_string(get_id_flight()) + "," + get_date_dep().get_Date() + "," + get_time_dep().get_Time() + "," + get_date_des().get_Date() + "," + get_time_des().get_Time() + "," + to_string(get_price());
}
Flight::~Flight() {}
#pragma once
#include "Date.h"
#include "classTime.h"
#include "Plane.h"
#include <string>
#include <list>
using namespace std;
class Flight {
private:
    int id_flight;
    string destination_p;
    passenger_plane h;
    Date date_dep;
    classTime time_dep;
    Date date_des;
    classTime time_des;
    int price;
    int amount_of_tickets;
public:
    Flight();
    Flight(string, passenger_plane&, const Date&, const classTime&, const Date&, const classTime&, int);
    Flight(string, passenger_plane, int, Date, classTime, Date, classTime, int);
    Flight(string, passenger_plane, Date, classTime, Date, classTime, int, int);
    Flight(const Flight&);
    passenger_plane& get_plane() { return h; }
    int get_price() { return price; }
    int get_id_flight() { return id_flight; }
    int get_amount() { return amount_of_tickets; }
    void deg_amount() { amount_of_tickets--; }


    void set_date_dep(const Date& date_dp);
    void set_time_dep(const classTime& time_dp);
    classTime& get_time_dep() { return time_dep; }
    Date& get_date_dep() { return date_dep; }

    string get_destintion() { return destination_p; }
    void set_date_des(const Date& date_ds);
    void set_time_des(const classTime& time_ds);
    classTime& get_time_des() { return time_des; }
    Date& get_date_des() { return date_des; }

    const Flight& operator=(const Flight& obj);
    string FlightToCSV();
    ~Flight();
};


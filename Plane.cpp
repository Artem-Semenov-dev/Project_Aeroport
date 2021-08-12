#include "Plane.h"
#include <string>
#include <iostream>

using namespace std;
Plane::Plane() {
    name_of_plane = "";
    id_plane = 1 + rand() % 1000000;
}
Plane::Plane(string name) {
    name_of_plane = name;
    id_plane = 1 + rand() % 1000000;
}
Plane::Plane(string name, int id_p, bool st) {
    name_of_plane = name;
    id_plane = id_p;
    status = st;
}
Plane::Plane(const Plane& pl) {
    name_of_plane = pl.name_of_plane;
    id_plane = pl.id_plane;
}
void Plane::set_seats(int n) { n = 0; }
int Plane::get_id_plane() { return id_plane; }
const string Plane::get_name() { return name_of_plane; }
void Plane::set_name(string name) {
    name_of_plane = name;
}
const Plane& Plane::operator=(const Plane& obj) {
    if (&obj == this)return *this;
    name_of_plane = obj.name_of_plane;
    id_plane = obj.id_plane;
    return *this;
}
bool Plane::operator==(const Plane& obj) {
    if (name_of_plane == obj.name_of_plane) {
        return true;
    }
    else return false;
}
passenger_plane::passenger_plane() : Plane() {
    number_of_seats = 0;
}
passenger_plane::passenger_plane(int n, string nam) : Plane(nam) {
    number_of_seats = n;
}
passenger_plane::passenger_plane(int n, int id_p, bool st, string nam) : Plane(nam, id_p, st) {
    number_of_seats = n;
}
const passenger_plane& passenger_plane::operator=(const passenger_plane& obj) {
    if (&obj == this)return *this;
    name_of_plane = obj.name_of_plane;
    id_plane = obj.id_plane;
    number_of_seats = obj.number_of_seats;
    return *this;
}
bool passenger_plane::operator==(passenger_plane& obj) {
    if ((name_of_plane == obj.name_of_plane) && (this->get_seats() == obj.get_seats())) {
        return true;
    }
    else return false;
}
int passenger_plane::get_id_plane() {
    return id_plane;
};
const int passenger_plane::get_seats() { return number_of_seats; }
void passenger_plane::set_seats(int quantity) {
    number_of_seats = quantity;
}
passenger_plane::passenger_plane(const passenger_plane& pas) : Plane(pas) {
    number_of_seats = pas.number_of_seats;
}
string Plane::passToCSV() {
    int n = get_id_plane();
    return to_string(get_type()) + "," + get_name() + "," + to_string(get_seats()) + "," + to_string(n) + "," + to_string(int(get_status()));

}
string Plane::prToCSV() {
    return to_string(get_type()) + "," + get_name() + "," + to_string(get_id_plane()) + "," + to_string(int(get_status()));
}

string Plane::PlaneToCSV() {
    return get_name() + "," + to_string(get_id_plane()) + "," + to_string(int(get_status()));
}
string passenger_plane::PlaneToCSV() {
    return to_string(get_type()) + "," + get_name() + "," + to_string(get_seats()) + "," + to_string(get_id_plane()) +"," + to_string(int(get_status()));
}
// ввести поле тип самолета
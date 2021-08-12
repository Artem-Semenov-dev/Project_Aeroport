#pragma once
#include <string>
#include <clocale>

using namespace std;
class Plane {
protected:
    int id_plane;
    string name_of_plane;
    int type;
public:
    bool status;
    Plane();
    Plane(string);
    Plane(string, int, bool);
    //Plane(string, int, int, bool);
    Plane(const Plane&);
    const string get_name();
    void set_name(string);
    bool get_status() { return status; }
    void ch_status() { status = false; }
    virtual int get_id_plane();
    virtual int get_type() { return 0; }
    const virtual int get_seats() { return 0; };
    virtual void set_seats(int);
    //virtual void info_plane();
    const Plane& operator=(const Plane&);
    bool operator==(const Plane&);
    virtual string PlaneToCSV();
    string passToCSV();
    string prToCSV();
};
class passenger_plane : public Plane {
protected:
    int number_of_seats;
public:
    passenger_plane();
    passenger_plane(int, string);
    passenger_plane(int, int, bool, string);
    int get_type() override { return 1; }
    const int get_seats() override;
    void set_seats(int) override;
    passenger_plane(const passenger_plane&);
    const passenger_plane& operator=(const passenger_plane&);
    bool operator==(passenger_plane&);
    int get_id_plane() override;
    string PlaneToCSV() override;
    //void info_plane() override;
};



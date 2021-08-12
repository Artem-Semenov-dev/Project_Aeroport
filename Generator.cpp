#include "Generator.h"
#include "Storage.h"
#include <iostream>
using namespace std;
Generator::Generator(){
    Storage s();
}
Generator::Generator(Storage& st) {
    s = st;
}
Generator::~Generator() {}
void Generator::sell_tickets(vector<Flight>& k, Storage& j) {
    vector<Flight> l = k;
    int n = l[0].get_amount();
    for (int i = 1; i < l.size(); i++) {
        if (n > l[i].get_amount()) {
            n = l[i].get_amount();
        }
        if (l.size() == 1) {
            n = l[i].get_amount();
        }
    }
    int much = n - 3 + rand() % n;
    for (int i = 0; i < much; i++) {
       create_ticket(k, j);
    }
}
void Generator::Write(Storage& j) {
    j.WriteToFiles();
}
void Generator::Read(Storage& j) {
    j.ReadFromFiles();
}
void Generator::Delete_f(Storage& j) {
    j.Delete_files();
}
Ticket& Generator::create_ticket(vector<Flight> l, Storage& j) {
    string secondname[10] = { "Smertuk", "Rudyka", "Dimenko", "Vasilenko", "Nosko", "Krasovskiy", "Sidorenko", "Bilan", "Topilin", "Baburov" };
    string firstname[10] = { "Vanya", "Liza", "Tanya", "Sofia", "Nikolay", "Sergei", "Yulia", "Vlad", "Dasha", "Yuriy" };
    string thirdname[10] = { "Artemovich", "Igorovich", "Ivanovich", "Sergeevich", "Sergeevna", "Ivanovna", "Artemovna", "Andreevna", "Andeevich", "Alanovich" };
    int n = l[0].get_amount();
    string name = secondname[rand() % 10] + " " + firstname[rand() % 10] + " " + thirdname[rand() % 10];
    for (int i = 1; i < l.size(); i++) {
        if (n > l[i].get_amount()) {
            n = l[i].get_amount();
        }
        if (l.size() == 1) {
            n = l[i].get_amount();
        }
        l[i].deg_amount();
    }
    int place = 1 + rand() % n;
    Ticket bil(l, place, name);
    j.add_ticket(bil);
    return bil;
}
void Generator::Print_storage(Storage& j) {
    j.Print_Storage();
}
void Generator::Print_planes(Storage& j) {
    j.Print_planes();
}
void Generator::Print_flights(Storage& j) {
    j.Print_Flights();
}
void Generator::Print_tickets(Storage& j) {
    j.Print_Ticket();
}
passenger_plane Generator::get_plane(int id, Storage& j) {
    return j.get_plane(id);
}
Flight Generator::get_flight(int id, Storage& j) {
    return j.get_flight(id);
}
Ticket Generator::get_ticket(int id, Storage& j) {
    return j.get_ticket(id);
}
void Generator::create_plane(int n, string nam, Storage& j) {
    passenger_plane pl(n, nam);
    j.add_plane(pl);
}
Flight& Generator::create_flight(string des, passenger_plane pl, string date_dp, string time_dp, string date_ds, string time_ds, int pr, Storage& j) {
    Date dep_d(date_dp);
    classTime dep_t(time_dp);
    Date des_d(date_ds);
    classTime des_t(time_ds);
    pl.status = false;
    Flight fl(des, pl, dep_d, dep_t, des_d, des_t, pr);
    j.add_flight(fl);
    return fl;
}
bool Generator::free_seats(Flight& fl) {
    if (fl.get_amount() > 0) {
        return true;
    }
    else return false;
}

vector<Ticket> Generator::without_transfer(Storage& j) {
    vector<Ticket> transfer_less;
    vector<Ticket> bil = j.get_list_ticket();
    for (int i = 0; i < bil.size(); i++) {
        if (bil[i].get_list_flights().size() == 1) {
            transfer_less.push_back(bil[i]);
        }
    }
    return transfer_less;
}
vector<Flight> Generator::flight_of_that_plane(passenger_plane& pl, Storage& j) {
    vector<Flight> list_planes_flight;
    vector<Flight> bil = j.get_list_flight();
    //list<Flight> l;
    for (int i = 0; i < bil.size(); i++) {
        if (bil[i].get_plane().get_name() == pl.get_name()) {
            list_planes_flight.push_back(bil[i]);
        }
    }
    /*  
    for (auto i = bil.begin(); i != bil.end(); i++) {
        l = i->get_list_flights();
        for (auto j = l.begin(); j != l.end(); j++) {
            if (pl.get_name() == j->get_plane().get_name()) {
                list_planes_flight.push_back(*j);
            }
        }
    }
    */
    return list_planes_flight;
}
vector<Flight> Generator::workload_by_date(Date& dat, Storage& f) {
    vector<Flight> bil = f.get_list_flight();
    vector<Flight> l;
    for (int i = 0; i < bil.size(); i++) {
        if (bil[i].get_date_dep() == dat) {
            l.push_back(bil[i]);
        }
    }
    return l;
    /*
    list<Flight> l;
    for (auto i = bil.begin(); i != bil.end(); i++) {
        l = i->get_list_flights();
        for (auto j = l.begin(); j != l.end(); j++) {
            if (dat == j->get_date_dep()) {
                cout << "vyvvod v textovoe pole";
            }
        }
    }
    */
}
Flight& Generator::expensive_flight(Storage& f) {
    int save = 0;
    vector<Flight> bil = f.get_list_flight();
    Flight l;
    for (int i = 0; i < bil.size(); i++) {
        if (save < bil[i].get_price()) {
            save = bil[i].get_price();
        }
    }
    for (int i = 0; i < bil.size(); i++) {
        if (save == bil[i].get_price()) {
            l = (bil[i]);
        }
    }
    return l;
    /*
    for (auto i = bil.begin(); i != bil.end(); i++) {
        l = i->get_list_flights();
        for (auto j = l.begin(); j != l.end(); j++) {
            if (save < j->get_price()) {
                save = j->get_price();
            }
        }
    }
    for (auto i = bil.begin(); i != bil.end(); i++) {
        l = i->get_list_flights();
        for (auto j = l.begin(); j != l.end(); j++) {
            if (j->get_price() == save) {
                return *j;
            }
        }
    }
    */
}
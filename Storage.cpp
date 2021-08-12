#pragma once
#include "Storage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;
Storage::Storage(): plane_list(), flight_list(), ticket_list(){}
Storage::Storage(vector<passenger_plane> pl, vector<Flight> fl, vector<Ticket> tick) {
    plane_list = pl;
    flight_list = fl;
    ticket_list = tick;
}
Storage::Storage(const Storage& s) {
    plane_list = s.plane_list;
    flight_list = s.flight_list;
    ticket_list = s.ticket_list;
}
const Storage& Storage::operator=(const Storage& st) {
    if (&st == this) return *this;
    plane_list = st.plane_list;
    flight_list = st.flight_list;
    ticket_list = st.ticket_list;
    return *this;
}
void Storage::Print_planes() {
    setlocale(LC_ALL, "Ukrainian");
    int n = 0;
    cout << "���������� ��� ��� ��������� ��������" << endl;
    for (int i = 0; i < plane_list.size(); i++) {
            cout << setw(5) << "������ ��������: " << plane_list[i].get_name() << setw(5) << " �������������� �����: " << plane_list[i].get_id_plane() << setw(5) << " ���������� �������: " << plane_list[i].get_seats() << endl;
        
    }
}
void Storage::Print_Flights() {
    setlocale(LC_ALL, "Ukrainian");
    cout << endl << "���������� ��� ��� �����" << endl;
    for (int i = 0; i < flight_list.size(); i++) {
        cout << "id ��������: " << flight_list[i].get_plane().get_id_plane() << " ����� �����: " << flight_list[i].get_id_flight() << " ���������� ��������� ����:" << flight_list[i].get_amount() << " ��������: " << flight_list[i].get_time_dep().get_Time() + " " + flight_list[i].get_date_dep().get_Date() << " ������: " << flight_list[i].get_time_dep().get_Time() + " " + flight_list[i].get_date_dep().get_Date() << " ����� ����������: " << flight_list[i].get_destintion() << " ����: " << flight_list[i].get_price() << endl;
    }
}
void Storage::Print_Ticket() {
    setlocale(LC_ALL, "Ukrainian");
    cout << endl << "���������� ��� ��� ������ �������� �����" << endl;
    for (int i = 0; i < ticket_list.size(); i++) {
        cout << "���: " << ticket_list[i].get_name() << " ����� �����" << ticket_list[i].get_id_flight() << " ����� ����� " << ticket_list[i].get_place() << " ���� ������: " << ticket_list[i].get_price_tick();
    }
}
void Storage::Print_Storage() {
    setlocale(LC_ALL, "ru");
    cout << "���������� ��� ��� ��������" << endl;
    for (int i = 0; i < plane_list.size(); i++) {
        cout << setw(5) << "������ ��������: "  << plane_list[i].get_name() << setw(5) << " �������������� �����: " << plane_list[i].get_id_plane() << setw(5) << " ���������� �������: " << plane_list[i].get_seats() << endl;
    }
    cout << endl << "���������� ��� ��� �����" << endl;
    for (int i = 0; i < flight_list.size(); i++) {
        cout << "id ��������: " << flight_list[i].get_plane().get_id_plane() << " ����� �����: " << flight_list[i].get_id_flight() << " ���������� ��������� ����:" << flight_list[i].get_amount() << " ��������: " << flight_list[i].get_time_dep().get_Time() + " " + flight_list[i].get_date_dep().get_Date() << " ������: " << flight_list[i].get_time_dep().get_Time() + " " + flight_list[i].get_date_dep().get_Date() << " ����� ����������: " << flight_list[i].get_destintion() << " ����: " << flight_list[i].get_price() << endl;
        //cout << flight_list[i].FlightToCSV() << endl;
    }
    cout << endl << "���������� ��� ��� ������" << endl;
    for (int i = 0; i < ticket_list.size(); i++) {
        cout << "���: " << ticket_list[i].get_name() << " ����� �����: " << ticket_list[i].get_id_flight() << " ����� �����: " << ticket_list[i].get_place() << " ���� ������: " << ticket_list[i].get_price_tick() << endl;
        //cout << ticket_list[i].TicketToCSV() << endl;
    }
}
void Storage::add_plane(passenger_plane& one_plane) {
    plane_list.push_back(one_plane);
}
void Storage::Delete_files() {
    remove("plane.csv");
    remove("flight.csv");
    remove("ticket.csv");
}
passenger_plane Storage::get_plane(int id) { //������ �� ����� ���������� ��-�� ����������� 
    for (int i = 0; i < plane_list.size(); i++) {
        if ((plane_list[i].get_id_plane() == id) && (plane_list[i].get_status() == 205)){
            return plane_list[i];
            break;
        }
    }
    /*
    
    for (list<passenger_plane*>::iterator i = plane_list.begin(); i != plane_list.end(); i++) {
        if (i->get_id_plane() == id && i->get_status() == true) {
            return *i;
        }
    }
    */

}
void Storage::delete_plane(int id) {
    setlocale(LC_ALL, "ru");
    /*
    for (auto i = plane_list.begin(); i != plane_list.end(); i++) {
        if (i->get_id_plane() == id && i->get_status() == true) {
            plane_list.erase(i);
        }
    }
    */
    for (int i = 0; i < plane_list.size(); i++) {
        if (plane_list[i].get_id_plane() == id && plane_list[i].get_status() == 205) {
            plane_list.erase(plane_list.begin()+i);
        }
    }
    cout << "�������� ������ �������� �� ����������";
}

void Storage::add_flight(Flight& one_flight) {
    flight_list.push_back(one_flight);
}
Flight Storage::get_flight(int un_num) {
    /*
    for (auto i = flight_list.begin(); i != flight_list.end(); i++) {
        if (i->get_id_flight() == un_num) {
            return *i;
        }
    }
    */
    for (int i = 0; i < flight_list.size(); i++) {
        if (flight_list[i].get_id_flight() == un_num) {
            return flight_list[i];
        }
    }
    
}
void Storage::delete_flight(int un_num) {
    /*
    for (auto i = flight_list.begin(); i != flight_list.end(); i++) {
        if (i->get_id_flight() == un_num) {
            flight_list.erase(i);
        }
    }
    */
    for (int i = 0; i < flight_list.size(); i++) {
        if (flight_list[i].get_id_flight() == un_num) {
            flight_list.erase(flight_list.begin() + i);
        }
    }
    // ������� �������
}


void Storage::add_ticket(Ticket& one_ticket) {
    ticket_list.push_back(one_ticket);
}
Ticket Storage::get_ticket(int id) {
    /*
    for (auto i = ticket_list.begin(); i != ticket_list.end(); i++) {
        if (i->get_id_ticket() == id) {
            return *i;
        }
    }
    */
    for (int i = 0; i < ticket_list.size(); i++) {
        if (ticket_list[i].get_id_ticket() == id) {
            return ticket_list[i];
        }
    }
}
void Storage::delete_ticket(int id) {
    /*
    for (auto i = ticket_list.begin(); i != ticket_list.end(); i++) {
        if (i->get_id_ticket() == id) {
            ticket_list.erase(i);
        }
    }
    */
    for (int i = 0; i < ticket_list.size(); i++) {
        if (ticket_list[i].get_id_ticket() == id) {
            ticket_list.erase(ticket_list.begin() + i);
        }
    }

}

void Storage::WriteToFiles() {
    fstream fout_plane;
    fout_plane.open("plane.csv", ios::out | ios::app);
    for (int i = 0; i < plane_list.size(); i++) {
        fout_plane << plane_list[i].passToCSV() << "\n";
    }
    fout_plane.close();
    fstream fout_flight;
    fout_flight.open("flight.csv", ios::out | ios::app);
    for (int i = 0; i < flight_list.size(); i++) {
        fout_flight << flight_list[i].FlightToCSV() << "\n";
    }
    fout_flight.close();
    fstream fout_ticket;
    fout_ticket.open("ticket.csv", ios::out | ios::app);
    for (int i = 0; i < ticket_list.size(); i++) {
        fout_ticket << ticket_list[i].TicketToCSV() << "\n";
    }
    fout_ticket.close();
}
void Storage::ReadFromFiles() {
    fstream fin_plane;
    fin_plane.open("plane.csv", ios::in);
    string line, word, temp, word2, word3, word4, word5;
    plane_list.clear();
    while (getline(fin_plane, line)) {
        stringstream s(line);
        getline(s, word4, ',');
        if (stoi(word4) == 1) {
            getline(s, word, ','); //������ ��������
            getline(s, word5, ','); //���������� �������
            getline(s, word2, ','); // id ��������
            getline(s, word3, '\n'); // ������ ��������
            passenger_plane pl(stoi(word5), stoi(word2), stoi(word3), word);
            plane_list.push_back(pl);
        }
        /*else {
            getline(s, word, ','); //������ ��������
            getline(s, word2, ','); // id ��������
            getline(s, word3, ','); // ������ ��������
            plane_list.push_back(passenger_plane(word, stoi(word2), stoi(word3)));
        }
        */
    }
    fin_plane.close();
    fstream fin_flight;
    fin_flight.open("flight.csv", ios::in);
    flight_list.clear();
    string word6, word7, word8;
    line = "";
    while (getline(fin_flight, line)) {
        stringstream s(line);
        getline(s, word, ','); //����� ����������
        getline(s, word2, ','); //id ��������
        getline(s, word3, ','); //����� �����
        getline(s, word4, ','); //���� ������
        getline(s, word5, ','); //����� ������
        getline(s, word6, ','); //���� �������
        getline(s, word7, ','); //����� �������
        getline(s, word8, '\n'); //���� �����
        passenger_plane pl(get_plane(stoi(word2)));
        Flight fl(word, pl, stoi(word3), Date(word4), classTime(word5), Date(word6), classTime(word7), stoi(word8));
        flight_list.push_back(fl);
    }       
    fin_flight.close();
    /*fstream fin_ticket;
    fin_ticket.open("ticket.csv", ios::in);
    ticket_list.clear();
    string wr;
    vector<Flight> l;
    line = "";
    while (getline(fin_ticket, line, '.')) {
        stringstream s(line);
        getline(fin_ticket, temp);
        stringstream ss(temp);
        while (getline(s, wr, ';')) {
            //getline(s, word, ';');
            l.push_back(get_flight(stoi(wr)));
        }
        getline(ss, word2, ','); //����� �����
        getline(ss, word3, ','); //���� ������
        getline(ss, word4, '\n'); //��� ���������
        Ticket tick(l, stoi(word2), word4);
        ticket_list.push_back(tick);
        l.clear();
        //������ ��� ��������� 
    }
    fin_ticket.close();
    */
}
Storage::~Storage() {
    plane_list.clear();
    flight_list.clear();
    ticket_list.clear();
}
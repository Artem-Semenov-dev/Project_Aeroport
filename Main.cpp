#include "Plane.h"
#include "Date.h"
#include "Flight.h"
#include "Ticket.h"
#include "Storage.h"
#include <Windows.h>
#include "Generator.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "classTime.h"
#include <vector>
int main()
{
    vector<Flight> ticket_flight;
    vector<Flight> ticket_flight1;
    vector<Ticket> list_ticket;
    vector<passenger_plane> plane_list;
    //list<passenger_plane> plane_list1;
    Storage ss(plane_list, ticket_flight, list_ticket);
    Generator g(ss);
    ss.Delete_files();
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string n;
    int k;
    bool w = 1;
    cout << "Вітаю! Розпочнемо роботу.\n" << endl;
    while (w) {
        cout << "\n**********Головне меню**********" << endl;
        cout << "1 - Створити літак\n"
            << "2 - Створити рейс\n"
            << "3 - Створити білети\n"
            << "4 - Записати в файл\n"
            << "5 - Зчитати з файлу\n"
            << "6 - Вивести всю інформацію\n"
            << "7 - Видалити файли\n"
            << "8 - Перейти до меню запитиів\n"
            << "0 - Завершити роботу\n"
            << "Ваш вибір: ";
        int v;
        cin >> v;
        if (v == 0) break;
        if (v == 1) {
            int num;
            string mod;
            cout << "Введіть кількість місць \n" << endl;
            cin >> num;
            cout << "Введіть модель літаку \n" << endl;
            cin.ignore();
            getline(cin, mod);
            g.create_plane(num, mod, ss);
        }
        if (v == 2) {
            cout << "Створення рейсу ..." << endl;
            int n = 0;
                for (int i = 0; i < ss.get_list_flight().size(); i++) {
                    for (int j = 0; j < ss.get_list_plane().size(); j++) {
                        if (ss.get_list_plane()[j].get_id_plane() != ss.get_list_flight()[i].get_plane().get_id_plane()) {
                            n = 1;
                            cout << setw(5) << "Модель самолета: " << ss.get_list_plane()[j].get_name() << setw(5) << " Индивидуальный номер: " << ss.get_list_plane()[j].get_id_plane() << setw(5) << " Количество сидений: " << ss.get_list_plane()[j].get_seats() << endl;
                        }
                    }
                }
            if (n == 0 && ss.get_list_flight().size() != 0) {
                cout << "Вибачте, вільних літаків немає" << endl;
            }
            else {
                if (ss.get_list_flight().size() == 0)
                    g.Print_planes(ss);
                cout << "Виберіть літак який буде обслуговувати рейс та введіть id літаку" << endl;
                int id;
                cin >> id;
                string dest;
                string dest_d;
                string dest_t;
                string dep_d;
                string dep_t;
                int pr;
                cout << "Введіть місто призначення" << endl;
                cin.ignore();
                getline(cin, dest);
                cout << "Введіть дату відправлення у виді DD.MM.YY" << endl;
                cin.ignore();
                getline(cin, dest_d);
                cout << "Введіть час відправлення у виді MM.HH" << endl;
                cin.ignore();
                getline(cin, dest_t);
                cout << "Введіть дату прибуття у виді DD.MM.YY" << endl;
                cin.ignore();
                getline(cin, dep_d);
                cout << "Введіть час прибуття у виді MM.HH" << endl;
                cin.ignore();
                getline(cin, dep_t);
                cout << "Введіть ціну за рейс" << endl;
                cin >> pr;
                g.create_flight(dest, g.get_plane(id, ss), dest_d, dest_t, dep_d, dep_t, pr, ss);
            }
        }
        if (v == 3) {
            cout << "Створення білетів..." << endl;
            g.Print_flights(ss);
            vector<Flight> l;
            cout << "Виберіть один або декілька рейсів для створення білетів(id,id,...)" << endl;
            string line, temp;
            cin.ignore();
            getline(cin, line);
            stringstream h(line);
            while (getline(h, temp, ',')) {
                l.push_back(g.get_flight(stoi(temp), ss));
            }
            g.sell_tickets(l, ss);
        }
        if (v == 4) {
            g.Write(ss);
        }
        if (v == 5) {
            g.Read(ss);
        }
        if (v == 6) {
            g.Print_storage(ss);
        }
        if (v == 7) {
            g.Delete_f(ss);
        }
        if (v == 8) {
            while (w) {
                cout << "\n*********Меню запитів*********" << endl;
                cout << "1 - Чи є вільні місця на заданий рейс\n"
                    << "2 - Квитки без пересадок\n"
                    << "3 - Рейси, що обслуговуються цим літаком\n"
                    << "4 - Рейси по даті\n"
                    << "5 - Найдорожчий рейс\n"
                    << "0 - Повернутися до головного меню\n"
                    << "Ваш вибір: ";
                int t;
                cin >> t;
                if (t == 0) break;
                if (t == 1) {
                    g.Print_flights(ss);
                    cout << "Виберіть рейс для якого хочете подивится вільні місця та введіть його номер" << endl;
                    int id;
                    cin >> id;
                    Flight fl = g.get_flight(id, ss);
                    bool b = g.free_seats(fl);
                    if (b == true) {
                        cout << "Так, вільні місця є" << endl;
                    }
                    else {
                        cout << "Ні, вільних місць немає" << endl;
                    }
                }
                if (t == 2) {
                    vector<Ticket> t;
                    t = g.without_transfer(ss);
                    cout << "Номери квитків без пересадок" << endl;
                    for (int i = 0; i < t.size(); i++) {
                        cout << t[i].get_id_ticket() << endl;
                    }
                }
                if (t == 3) {
                    int id;
                    vector<Flight> fl;
                    passenger_plane pl;
                    g.Print_planes(ss);
                    cout << "Виберіть модель літака та введіть його id" << endl;
                    cin >> id;
                    pl = g.get_plane(id, ss);
                    fl = g.flight_of_that_plane(pl, ss);
                    cout << "Номера рейсів, що обслуговує цей літак" << endl;
                    for (int i = 0; i < fl.size(); i++) {
                        cout << fl[i].get_id_flight() << endl;
                    }
                }
                if (t == 4) {
                    string date;
                    vector<Flight> fl;
                    cout << "Введіть дату відправлення у виді DD.MM.YY" << endl;
                    cin.ignore();
                    getline(cin, date);
                    Date d(date);
                    fl = g.workload_by_date(d, ss);
                    cout << "Номера рейсів, що є у вказаний день" << endl;
                    for (int i = 0; i < fl.size(); i++) {
                        cout << fl[i].get_id_flight() << endl;
                    }
                }
                if (t == 5) {
                    Flight fl;
                    fl = g.expensive_flight(ss);
                    cout << "найдорожчий рейс має номер: " << fl.get_id_flight();
                }
            }

        }
    }
    system("Pause");
    return 0;

    /*
    g.create_plane(20, "ace17", ss);
    g.create_plane(40, "ace12", ss);
    g.create_plane(25, "Boeing157", ss);
    g.create_flight("Washington", ss.get_plane(42), "12.9.1999", "12.30", "13.9.1999", "2.30", 2000, ss);
    g.create_flight("Boston", ss.get_plane(18468), "12.9.1999", "13.30", "13.9.1999", "2.30", 2000, ss);
    ticket_flight1.push_back(ss.get_flight(19170));
    ticket_flight1.push_back(ss.get_flight(29359));
    g.create_ticket(ticket_flight1, ss);
    ss.Print_Storage();
    ss.WriteToFiles();
    ss.ReadFromFiles();
    //g.create_ticket(ticket_flight1);
    /*
    passenger_plane pl(20, "ace");
    passenger_plane pl1(21, "ace");

    cout << "id pl " << pl.get_id_plane();
    cout << endl << pl.get_name();
    private_plane pls("msi");
    cout << pls.get_name();
    Date d("12.9.1999");
    cout << endl << d.get_Date() << endl;
    classTime t("12.30");
    cout << t.get_Time();
    Date d1("13.9.1999");
    classTime t1("14.30");
    Flight g("Washington", pl, d, t, d1, t1, 2000);
    Flight g1("Washington", pl1, d, t, d1, t1, 1500);
    cout << endl  << "id " << g.get_id_flight();
    cout << "id pl " << pl.get_id_plane();
    
    
    //Ticket t(ticket_flight1, 10, "artem");
    plane_list.push_back(pl);
    plane_list.push_back(pl1);
    cout << endl << "id pl " << plane_list.begin()->get_id_plane() << "id pl2 " << plane_list.begin().operator++()->get_id_plane();
    s.add_flight(g);
    s.add_flight(g1);
    s.add_plane(pl);
    s.add_plane(pl1);
    cout << endl;
    Flight f(s.get_flight(2));
    s.WriteToFiles();
    s.ReadFromFiles();
    plane_list1 = s.get_list_plane();
    */

}


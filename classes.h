#ifndef know_classes
#define know_classes

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;
// casrs class
class car
{
protected:
    string price;
    string name;
    string manufacturer;
    string engine_power;
    string color;
    string registration_car;

public:
    car(string Price, string Name, string Manufacture, string Engine_power, string Color, string Plates)
    {
        name = Name;
        price = Price;
        manufacturer = Manufacture;
        engine_power = Engine_power;
        color = Color;
        registration_car = Plates;
    }
    // getters
    string get_price()
    {
        return price;
    }
    string get_name()
    {
        return name;
    }
    string get_manufacture()
    {
        return manufacturer;
    }
    string get_engine_power()
    {
        return engine_power;
    }
    string get_color()
    {
        return color;
    }
    string get_plates()
    {
        return registration_car;
    }
    // setters
    void set_name(string Name)
    {
        if (name != Name)
        {
            name = Name;
        }
    }
    void set_price(string Price)
    {
        if (price != Price)
        {
            price = Price;
        }
    }
    void set_manufacture(string Man)
    {
        if (manufacturer != Man)
        {
            manufacturer = Man;
        }
    }
    void set_engine_power(string Power)
    {
        if (engine_power != Power)
        {
            engine_power = Power;
        }
    }
    void set_color(string Color)
    {
        if (color != Color)
        {
            color = Color;
        }
    }
    void set_plates(string plates)
    {
        if (registration_car != plates)
        {
            registration_car = plates;
        }
    }
};
class electric : public car
{
protected:
    string battery_status;
    string charging_time;

public:
    electric(string Price, string Name, string Manufacture, string Engine_power, string Color, string Plates, string Battery_status, string Charging)
        : car(price, name, manufacturer, engine_power, color, registration_car)
    {
        battery_status = Battery_status;
        charging_time = Charging;
    }
    string get_battery()
    {
        return battery_status;
    }
    string get_charging()
    {
        return charging_time;
    }
    void set_battery(string Status)
    {
        if (Status != battery_status)
        {
            battery_status = Status;
        }
    }
    void set_charging(string Time)
    {
        if (Time != charging_time)
        {
            charging_time = Time;
        }
    }
};
class conventional : public car
{
protected:
    string fuel_status;
    string fuel_type;

public:
    conventional(string Price, string Name, string Manufacture, string Engine_power, string Color, string Plates, string Fuel_status, string Fuel_type)
        : car(price, name, manufacturer, engine_power, color, registration_car)
    {
        fuel_status = Fuel_status;
        fuel_type = Fuel_type;
    }
    string get_fuel_status()
    {
        return fuel_status;
    }
    string get_fuel_type()
    {
        return fuel_type;
    }
    void set_fuel_status(string Status)
    {
        fuel_status = Status;
    }
    void set_fuel_type(string Type)
    {
        fuel_type = Type;
    }
};
class User
{
    protected:
    string name; 
    string surname;
    string email;
    string money;
    string login; 
    public:
    User(string Name, string Surname, string Email, string Money, string Login)
    {
        name = Name;
        surname = Surname;
        email = Email;
        money = Money; 
        login = Login; 
    }
    void set_name(string Name)
    {
        name = Name;
    }
    void set_surname(string Surname)
    {
        surname = Surname;
    }
    void set_email(string Email)
    {
        email = Email;
    }
    void set_money(string Money)
    {
        money = Money;
    }
    void set_login(string Login)
    {
        login = Login;
    }
    string get_name()
    {
        return name;
    }
    string get_surname()
    {
        return surname;
    }
    string get_email()
    {
        return email;
    }
    string get_money()
    {
        return money; 
    }
    string get_login()
    {
        return login;
    }
};
// linked list class
struct Linked_List
{
    struct Node
    {
        string price;
        string name;
        string manufacturer;
        string engine_power;
        string color;
        string registration_car;
        string battery_status;
        string charging_time;
        string fuel_status;
        string fuel_type;
        Node *next;
        Node(string Price, string Name, string Manufacture, string Power, string Color, string Plates, string Battery, string Charging, string Fuel_type, string Fuel_status, Node *N = nullptr)
        {
            price = Price;
            name = Name;
            manufacturer = Manufacture;
            engine_power = Power;
            color = Color;
            registration_car = Plates;
            battery_status = Battery;
            charging_time = Charging;
            fuel_status = Fuel_status;
            fuel_type = fuel_type;
            next = N;
        }
    };
    Node *first = nullptr;
    void add(string Price, string Name, string Manufacture, string Power, string Color, string Plates, string Battery, string Charging, string Fuel_type, string Fuel_status);
    void show();
    int find_car(string Plates);
    void add_not_avalable();
    void delete_fist_crs()
    {
        Node * killerr = first;
        while (first != nullptr)
        {
            killerr = first;
            first = first -> next;
            delete killerr;
        }
        
    }
};
void Linked_List ::add(string Price, string Name, string Manufacture, string Power, string Color, string Plates, string Battery, string Charging, string Fuel_type, string Fuel_status)
{
    Node *adder = new Node(Price, Name, Manufacture, Power, Color, Plates, Battery, Charging, Fuel_type, Fuel_status);
    if (first == nullptr)
    {
        adder->next = first;
        first = adder;
    }
    else
    {
        Node *finder = first;
        while (finder->next != nullptr)
        {
            finder = finder->next;
        }
        finder->next = adder;
    }
}
void Linked_List ::show()
{
    Node *finder = first;
    while (finder != nullptr)
    {
        cout << "Plates: " << finder->registration_car << endl;
        finder = finder->next;
    }
}
int Linked_List ::find_car(string Plates)
{
    int find = 0;
    Node *finder = first;
    while (finder != nullptr)
    {
        if (finder->registration_car == Plates)
        {
            ofstream to_temp_file("temp_car.txt", ios::trunc);
            to_temp_file << finder ->battery_status<<endl;
            to_temp_file << finder ->charging_time<<endl;
            to_temp_file << finder ->color<<endl;
            to_temp_file << finder ->engine_power<<endl;
            to_temp_file << finder ->fuel_status<<endl;
            to_temp_file << finder ->fuel_type<<endl;
            to_temp_file << finder ->manufacturer<<endl;
            to_temp_file << finder ->name<<endl;
            to_temp_file << finder ->price<<endl;
            to_temp_file << finder ->registration_car<<endl;
            return 1;
        }
        finder = finder->next;
    }
    return 0;
}
void Linked_List ::add_not_avalable()
{
    ofstream to_file_not_avalable("used_cars.txt", ios::trunc);
    Node *finder = first;
    while (finder != nullptr)
    {
        to_file_not_avalable << finder->registration_car << endl;
        finder = finder->next;
    }
}
struct Linked_List_user
{
    struct Noudle
    {
        string Name;
        string Surname;
        string Email;
        string Money; 
        string Login;
        Noudle * next; 
        Noudle(string name, string surname, string email, string money,string login, Noudle * N = nullptr)
        {
           Name = name;
           Surname = surname;
           Email = email;
           Money = money;
           Login = login;
           next = N; 
        }
    };
    Noudle * first = nullptr; 
    void add_list(string name, string surname, string email, string money,string login)
    {
            Noudle * adder = new Noudle(name, surname, email, money, login);
        if(first == nullptr)
        {
        adder->next = first;
        first = adder;
        }
        else
        {
            Noudle * finder = first;
            while (finder->next != nullptr)
            {
                finder = finder -> next;
            }
            finder -> next = adder;
        }
    }
    void show()
    {
        Noudle * finder;
        finder = first; 
        while (finder != nullptr)
        {
            cout<<"users: "<< finder->Name<<endl;
            finder = finder -> next; 
        }
        
    }
    void save_to_file()
    {
        ofstream to_users_file("users.txt", ios::trunc);
        Noudle * finder;
        finder = first; 
        while (finder != nullptr)
        {
            to_users_file<<finder->Name<<";"<<finder->Surname<<";"<<finder->Email<<";"<<finder->Money<<";"<<finder->Login<<endl;
            finder = finder -> next; 
        }
        to_users_file.close();
    }
    void delete_list()
    {
        Noudle * killer; 
        while (first != nullptr)
        {
            killer = first;
            first = first -> next;
            delete killer;
        }
        
    }
};

#endif

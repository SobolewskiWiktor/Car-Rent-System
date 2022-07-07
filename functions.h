#ifndef know_functions
#define know_functions

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "classes.h"
using namespace std;


Linked_List Cars_all;
Linked_List Used_cars; 
Linked_List_user user_list; 

electric book_electric ("Price", "Name", "Manufacture", "Power", "Color", "Plates", "Battery", "Charging");
conventional book_normal ("Price", "Name", "Manufacture", "Power", "Color", "Plates", "Fuel_status", "Fuel_type");

User Active ("Name","Surname","Email","Money","Login");

string login_to_all;

void registration()
{
  string login;
  string password;
  string password_confirm;

  cout << "login: ";
  cin >> login;
  char c = ' ';
  cout << "Password: ";
  while (c != 13)
  {
    c = getch();
    if (c != 13)
    {
      password = password + c;
      cout << "*";
    }
  }
  cout << endl;
  char d = ' ';
  cout << "Confirm Password: ";
  while (d != 13)
  {
    d = getch();
    if (d != 13)
    {
      password_confirm = password_confirm + d;
      cout << "*";
    }
  }
  cout << endl;
  cout << "Password: " << password << " confirm: " << password_confirm << endl;
  if (password == password_confirm)
  {
    ofstream to_file("login.txt", ios::app);
    to_file << login << ";" << password << endl;
    ;
  }
  else
  {
    cout << "[ERROR] - Passwords do not match" << endl;
  }
}
bool login()
{
  string password;
  cout << "login: ";
  cin >> login_to_all;
  char c = ' ';
  cout << "PASSWORD: ";
  while (c != 13)
  {
    c = getch();
    if (c != 13)
    {
      password = password + c;
      cout << "*";
    }
  }
  cout << endl;

  string download_login;
  string download_passwod;
  string line;
  int spacer = 0;
  ifstream from_pass_file("login.txt");
  if (!from_pass_file)
  {
    cout << "[ERROR] - Can't read login file" << endl;
    return 0;
  }
  do
  {
    getline(from_pass_file, line);
    int length = line.length();
    for (int i = 0; i < length; i++)
    {
      if (line[i] == ';')
      {
        spacer++;
        continue;
      }
      if (spacer == 0)
      {
        download_login = download_login + line[i];
      }
      if (spacer == 1)
      {
        download_passwod = download_passwod + line[i];
      }
    }
    if (download_login == login_to_all && download_passwod == password)
    {
      from_pass_file.close();
      return 1;
    }
    spacer = 0;
    download_login = "";
    download_passwod = "";

  } while (!from_pass_file.eof());

  cout << "[ERROR] - Incorrect login or password" << endl;
  from_pass_file.close();
  return 0;
}
void get_cars()
{
  ifstream getcars("cars.txt");
  if (!getcars)
  {
    cout << "[ERROR] - Can't read cars file" << endl;
  }
  string line_get_cars;
  do
  {
    getline(getcars, line_get_cars);
    string type;
    int i = 0;
    while (line_get_cars[i] != ';')
    {
      type = type + line_get_cars[i];
      i++;
    }
    string Name;
    string Plates;
    string Power;
    string Manufacture;
    string Color;
    string Cost;
    if (type == "electric")
    {
      string Battety;
      string Charging;
      int length = line_get_cars.length();
      int spacer = 0;
      for (int i = 0; i < length; i++)
      {
        if (line_get_cars[i] == ';')
        {
          spacer++;
          continue;
        }
        if (spacer == 1)
        {
          Manufacture = Manufacture + line_get_cars[i];
        }
        if (spacer == 2)
        {
          Name = Name + line_get_cars[i];
        }
        if (spacer == 3)
        {
          Power = Power + line_get_cars[i];
        }
        if (spacer == 4)
        {
          Color = Color + line_get_cars[i];
        }
        if (spacer == 5)
        {
          Plates = Plates + line_get_cars[i];
        }
        if (spacer == 6)
        {
          Battety = Battety + line_get_cars[i];
        }
        if (spacer == 7)
        {
          Charging = Charging + line_get_cars[i];
        }
        if (spacer == 8)
        {
          Cost = Cost + line_get_cars[i];
        }
      }
      spacer = 0;
      Cars_all.add(Cost, Name, Manufacture, Power, Color, Plates, Battety, Charging, "ND", "ND");
    }
    else if (type == "normal")
    {
      string Feul_type;
      string Fuel_ststus;
      int length = line_get_cars.length();
      int spacer = 0;
      for (int i = 0; i < length; i++)
      {
        if (line_get_cars[i] == ';')
        {
          spacer++;
          continue;
        }
        if (spacer == 1)
        {
          Manufacture = Manufacture + line_get_cars[i];
        }
        if (spacer == 2)
        {
          Name = Name + line_get_cars[i];
        }
        if (spacer == 3)
        {
          Power = Power + line_get_cars[i];
        }
        if (spacer == 4)
        {
          Color = Color + line_get_cars[i];
        }
        if (spacer == 5)
        {
          Plates = Plates + line_get_cars[i];
        }
        if (spacer == 6)
        {
          Fuel_ststus = Fuel_ststus + line_get_cars[i];
        }
        if (spacer == 7)
        {
          Feul_type = Feul_type + line_get_cars[i];
        }
        if (spacer == 8)
        {
          Cost = Cost + line_get_cars[i];
        }
      }
      Cars_all.add(Cost, Name, Manufacture, Power, Color, Plates, "ND", "ND", Feul_type, Fuel_ststus);
    }
    type = "";

  } while (!getcars.eof());
  getcars.close();
}
void get_used_cars()
{
  ifstream from_used_cars("used_cars.txt");
  if (!from_used_cars)
  {
    cout << "[ERROR] - Can't read used cars file" << endl;
  }
  else
  {
    string getted_line;
    do
    {
      getline(from_used_cars, getted_line);
      Used_cars.add("ND", "ND", "ND", "ND", "ND", getted_line, "ND", "ND", "ND", "ND");
    } while (!from_used_cars.eof());
  }
}
int check_avalable(string Plates)
{
  int if_exist = Used_cars.find_car(Plates);
  if (if_exist == 1)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
void put_not_avalable(string Plates)
{
  Used_cars.add("ND", "ND", "ND", "ND", "ND", Plates, "ND", "ND", "ND", "ND");
  Used_cars.add_not_avalable();
}
void create_user(string login)
{
  string line;
  ifstream from_file("users.txt");
  int personal_data = 0; 
  string Name;
  string Surname;
  string Email;
  string Money;
  string Login; 
  if(!from_file)
  {
    cout<<"[ERROR] - Can't read users file"<<endl;
  }
  else
  {
    int spacer =0;
    do
    {
      getline(from_file, line);
      int length = line.length();
      for(int i=0; i<length; i++)
      {
        if(line[i] == ';')
        {
          spacer ++;
          continue;
        }
        if(spacer == 0)
        {
          Name = Name + line[i];
        }
        if(spacer == 1)
        {
          Surname = Surname + line[i];
        }
        if(spacer == 2)
        {
          Email = Email + line[i];
        }
        if(spacer == 3)
        {
          Money = Money + line[i];
        }
        if(spacer == 4)
        {
          Login = Login + line[i];
        }
      }
      if(Login == login)
      {
        Active.set_name(Name);
        Active.set_surname(Surname);
        Active.set_email(Email);
        Active.set_money(Money); 
        Active.set_login(Login);
        break; 
      }
      spacer = 0; 
      Name = "";
      Surname = "";
      Email = "";
      Money = "";
      Login = "";
      
    } while (!from_file.eof());
    if(Active.get_login() == "Login")
    {
      Active.set_login(login_to_all); 
    }
    from_file.close();
  }
}
void save_users()
{
  int spacer = 0; 
  string line;
  string Name;
  string Surname;
  string Email;
  string Money;
  string Login;
  ifstream from_main_user_file("users.txt");
  if(!from_main_user_file)
  {
    cout<<"[ERROR] - Cant read users file"<<endl;
  }
  else
  {
    do
    {
      getline(from_main_user_file, line);
      int length = line.length();
      for(int i=0; i<length; i++)
      {
        if(line[i] == ';')
        {
          spacer ++;
          continue;
        }
        if(spacer == 0)
        {
          Name = Name + line[i];
        }
        if(spacer == 1)
        {
          Surname = Surname + line[i];
        }
        if(spacer == 2)
        {
          Email = Email + line[i];
        }
        if(spacer == 3)
        {
          Money = Money + line[i];
        }
        if(spacer == 4)
        {
          Login = Login + line[i];
        }
      }
      if(Name != Active.get_name() && Login == Active.get_login())
      {
        Name = Active.get_name();
      }
      if(Surname != Active.get_surname() && Login == Active.get_login())
      {
        Surname = Active.get_surname();
      }
      if(Email != Active.get_email() && Login == Active.get_login())
      {
        Email = Active.get_email();
      }
      if(Money != Active.get_money() && Login == Active.get_login())
      {
        Money = Active.get_money();
      }
      user_list.add_list(Name,Surname,Email,Money,Login);
      spacer = 0;
      Name = "";
      Surname = "";
      Email = "";
      Money = "";
      Login = ""; 
    } while (!from_main_user_file.eof());
    user_list.save_to_file(); 
    user_list.delete_list(); 
    from_main_user_file.close();
  }

} 
void rent_car()
{
  cout<<"Active name: "<< Active.get_name()<<endl;
  cout<<"Active money: "<< Active.get_money()<<endl;
  if(Active.get_money() == "Money")
  {
    cout<<"[ERROR] - You need add money and personal data first"<<endl;
  }
  else
  {
    string Name = "";
    string Manufacture = "";
    string Battery = "";
    string Charging = "";
    string Color = "";
    string Power = "";
    string Fuel_type = "";
    string Fuel_status = "";
    string Plates = "";
    string Price = "";

    string plates;
    cout << "Type plates: ";
    cin >> plates;
    if (plates == "")
    {
      cout << "[ERROR] - Type plates of choosen car" << endl;
    }
    else
    {
      int if_avalable = check_avalable(plates);
      if (if_avalable == 1)
      {
        put_not_avalable(plates);
        Cars_all.find_car(plates);
        ifstream from_temp_file("temp_car.txt");
        if (!from_temp_file)
        {
          cout << "[ERROR] - Can't read temp car file" << endl;
        }
        else
        {
          string line;
          int line_number = 0;
          do
          {
            getline(from_temp_file, line);
            int length = line.length();
            for (int i = 0; i < length; i++)
            {
              if (line_number == 0)
              {
                Battery = Battery + line[i];
              }
              if (line_number == 1)
              {
                Charging = Charging + line[i];
              }
              if (line_number == 2)
              {
                Color = Color + line[i];
              }
              if (line_number == 3)
              {
                Power = Power + line[i];
              }
              if (line_number == 4)
              {
                Fuel_status = Fuel_status + line[i];
              }
              if (line_number == 5)
              {
                Fuel_type = Fuel_type + line[i];
              }
              if (line_number == 6)
              {
                Manufacture = Manufacture + line[i];
              }
              if (line_number == 7)
              {
                Name = Name + line[i];
              }
              if (line_number == 8)
              {
                Price = Price + line[i];
              }
              if (line_number == 9)
              {
                Plates = Plates + line[i];
              }
            }
            line_number++;
          } while (!from_temp_file.eof());
          from_temp_file.close();
        }
        ifstream from_car_file("cars.txt");
        if (!from_car_file)
        {
          cout << "[ERROR] - Can't read car file" << endl;
        }
        else
        {
          string line_two;
          string check_type;
          string check_plates;
          int spacer = 0; 
          do
          {
            getline(from_car_file, line_two);
            int length_two = line_two.length();
            for(int i=0; i<length_two; i++)
            {
              if(line_two[i] == ';')
              {
                spacer ++;
                continue;
              }
              if(spacer == 0 )
              {
                check_type = check_type + line_two[i];
              }
              if(spacer == 5)
              {
                check_plates = check_plates + line_two[i];
              }
            }
            if(check_plates == plates)
            {
              float cost = 0; 
              if(check_type == "electric")
              {
                book_electric.set_name(Name);
                book_electric.set_manufacture(Manufacture);
                book_electric.set_color(Color);
                book_electric.set_plates(Plates);
                book_electric.set_price(Price);
                book_electric.set_charging(Charging);
                book_electric.set_battery(Battery); 
                book_electric.set_engine_power(Power);
                int i=0;
                int time;
              while(!_kbhit())
              {
                  float price = stof(book_electric.get_price());
                  system("cls");
                  cout<<"Actual Rent: "<<endl;
                  cout<<"Car: "<<book_electric.get_manufacture()<<" "<<book_electric.get_name()<<" "<<book_electric.get_color()<<endl;
                  cout<<"Price for 1 minute: "<<book_electric.get_price()<<" PLN"<<endl;  
                  cout<<"Actual Price: "<<i*price<<" PLN"<<endl;
                  cout<<"Actual minuts: "<<i<<endl;
                  cout<<"Press q to stop rent"<<endl;
                  int active_money = stof(Active.get_money());
                  if(active_money < (i*price))
                  {
                    cout<<"[WORNING] - End of funds on your account"<<endl;
                    cout<<"[WORNING] - End of vehicle rental"<<endl;
                    cout<<"[WORNING] - You have 5 minutes to park"<<endl;
                    break;
                  } 
                  i++;
                  cost = i * price; 
                  Sleep(3600);
                }
                float account_money = stof(Active.get_money());
                float minus_money = account_money - cost; 
                string set_money = to_string(minus_money);
                Active.set_money(set_money); 

              }
              else
              {
                book_normal.set_name(Name);
                book_normal.set_manufacture(Manufacture);
                book_normal.set_color(Color);
                book_normal.set_plates(Plates);
                book_normal.set_price(Price);
                book_normal.set_engine_power(Power);
                book_normal.set_fuel_status(Fuel_status);
                book_normal.set_fuel_type(Fuel_type); 
                int i=0;
                while(!_kbhit())
              {
                  float price = stof(book_normal.get_price());
                  system("cls");
                  cout<<"Actual Rent: "<<endl;
                  cout<<"CAR: "<<book_normal.get_manufacture()<<" "<<book_normal.get_name()<<" "<<book_normal.get_color()<<endl;
                  cout<<"Price for 1 minute: "<<book_normal.get_price()<<" PLN"<<endl;  
                  cout<<"Actual Price: "<<i*price<<" PLN"<<endl;
                  cout<<"Actual minuts: "<<i<<endl;
                  cout<<"Press q to stop rent"<<endl; 
                  i++; 
                  int active_money = stof(Active.get_money());
                  if(active_money < (i*price))
                  {
                    cout<<"[WORNING] - End of funds on your account"<<endl;
                    cout<<"[WORNING] - End of vehicle rental"<<endl;
                    cout<<"[WORNING] - You have 5 minutes to park"<<endl;
                    break;
                  } 
                  cost = i * price;
                  Sleep(3600);
                } 
                float account_money = stof(Active.get_money());
                float minus_money = account_money - cost; 
                string set_money = to_string(minus_money);
                Active.set_money(set_money); 
              }
              break;
            }
            spacer = 0; 
            check_type = "";
            check_plates = "";
          } while (!from_car_file.eof());
          from_car_file.close(); 
          Cars_all.delete_fist_crs(); 
        }
      }
      else
      {
        cout << "sorry not avalable car" << endl;
      }
    }
  }
}
void show_anable_car()
{
  Cars_all.show();
}
void add_money()
{
  float money;
  float total;
  float download_money; 
  cout<<"Ammount: ";
  cin>>money;
  if(Active.get_money() == "Money")
  {
    string num_str(to_string(money)); 
    Active.set_money(num_str); 
  }
  else
  {
    download_money = stof(Active.get_money());
    total = money + download_money;
    string num_str(to_string(total)); 
    Active.set_money(num_str); 
  }

}
void check_money_status()
{
  cout<<"Your Money: "<<Active.get_money()<<endl;
}
void add_personal_data()
{
  if(Active.get_money() == "Money")
  {
    cout<<"[ERROR] - First, top up your account with money "<<endl;
  }
  else
  {
    if(Active.get_name() == "Name")
  {
    string Name;
    string Surname;
    string Email; 
    cout<<"Name: ";
    cin>>Name;
    cout<<"Surname: ";
    cin>>Surname;
    cout<<"E-mail: ";
    cin>>Email; 
    Active.set_name(Name);
    Active.set_surname(Surname);
    Active.set_email(Email);
    ofstream to_file("users.txt", ios::app);
    to_file<<Active.get_name()<<";"<<Active.get_surname()<<";"<<Active.get_email()<<";"<<Active.get_money()<<";"<<Active.get_login()<<endl;
  }
  else
  {
    cout<<"[ERROR] - You have already added your data"<<endl;
  }
  }
}
#endif

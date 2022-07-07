#include <iostream>
#include "functions.h"
#include "classes.h"
using namespace std;

int main()
{
  while (true)
  {
    int choose = 0;
    cout << endl;
    cout << "====" << endl;
    cout << "1. Longin" << endl;
    cout << "2. Registration" << endl;
    cout << "Choose: ";
    cin >> choose;
    switch (choose)
    {
    case 1:
    {
      bool if_login = login();
      if (if_login == true)
      {
        cout << "===" << endl;
        cout << "LOGIN SUCCESFULL" << endl;
        while (true)
        {
          create_user(login_to_all);
          int login_choose;
          cout << endl;
          cout << endl;
          cout << "===" << endl;
          cout << "1. Rent car" << endl;
          cout << "2. Show anable cars" << endl;
          cout << "3. Add money" << endl;
          cout << "4. Check money status" << endl;
          cout << "5. Add personal data" << endl;
          cout << "Choose: ";
          cin >> login_choose;
          switch (login_choose)
          {
          case 1:
          {
            get_cars();  
            rent_car();
            save_users();  
            break;
          }
          case 2:
          {
            get_cars();
            show_anable_car();
            break;
          }
          case 3:
          {
            add_money();
            save_users();
            break; 
          }
          case 4:
          {
            check_money_status(); 
            break; 
          }
          case 5:
          {
            add_personal_data();
            break;
          }
          default:
          {
            cout << "[ERROR] - choose proper option" << endl;
            break;
          }
          }
        }
      }
      break;
    }
    case 2:
    {
      registration();
      break;
    }

    default:
    {
      cout << "[ERROR] - choose proper option" << endl;
      break;
    }
    }
  }

  return 0;
}

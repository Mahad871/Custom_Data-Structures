#include<iostream>
#include"Header.h"
using namespace std;
int main()
{
    int option = 0;
    string id, cnic, date;
    int salary, bonus;
    int new_salary = 0;
    List<string, int> obj;
    while (option < 7)
    {
        cout << "-----------------------MENU------------------------" << endl;
        cout << endl;
        cout << "Press 1 to enter record " << endl;
        cout << "Press 2 to search a record" << endl;
        cout << "Press 3 to update a record" << endl;
        cout << "Press 4 to print maximum salary being offered to employees" << endl;
        cout << "Press 5 to delete a record" << endl;
        cout << "Press 6 to print all records" << endl;
        cout << "Press 7 to quit" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << endl;
        cout << "Enter your option : ";
        cin >> option;
        //("cls");

        if (option == 1)
        {
            cout << "Enter EmpID  : ";
            cin >> id;
            cout << "Enter CNIC  : ";
            cin >> cnic;
            cout << "Enter Joining Date  : ";
            cin >> date;
            cout << "Enter Salary  : ";
            cin >> salary;
            cout << "Enter Bonus  : ";
            cin >> bonus;
            obj.insert(id, cnic, date, salary, bonus);
        }
        else if (option == 2)
        {
            cout << "Enter EmpID to search : ";
            cin >> id;
            obj.search(id);
        }

        else if (option == 3)
        {
            cout << "Enter EmpID to update : ";
            cin >> id;
            cout << "Enter new salary : ";
            cin >> new_salary;

            obj.Update(id, new_salary);
        }
        else if (option == 4)
        {
            cout << "The maximum salaray being offered is : " << obj.max() << endl;
        }
        else if (option == 5)
        {
            cout << "Enter EmpID to delete : ";
            cin >> id;
            obj.remove(id);
        }
        else if (option == 6)
        {
            obj.print();
        }
    }

}

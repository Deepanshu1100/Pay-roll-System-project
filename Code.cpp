
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
public:
    string mEmpid;
    string nName;
    string mSalary;
public:
    Employee(string empid = "", string name = "", string salary = "") :mEmpid(empid), nName(name), mSalary(salary) {

    }
    //in order to work with serialisation we need to use the follwing two concepts
    bool operator == (const Employee& obj)
    {
        return (mEmpid == obj.mEmpid) && (nName == obj.nName) && (mSalary == obj.mSalary);
    }
    friend ostream& operator<<(ostream& out, const Employee& obj)
    {
        out << obj.mEmpid << " " << obj.nName << " " << obj.mSalary << std::endl;
        return out;
    }
    friend istream& operator >>(istream& in,  Employee& obj)
    {
        in >> obj.mEmpid;
        in >> obj.nName;
        in >> obj.mSalary;

        return in;

    }
 
};


class EmployeeData {
public:
    void addEmployee() {
        string empid, name, salary;
        cout << "Enter the Employee ID" << endl;
        cin >> empid;
        cout << " Enter the name of the Employee name" << endl;
        cin >> name;
        cout << " Enter the salary of the Employee" << endl;
        cin >> salary;
        Employee emp(empid, name, salary);
        std::ofstream out("Employee.txt", ios::app);
        out << emp;
        out.close();
        cout << "Employee " << empid << " is stores successfully" << endl;
    }
    void dispEmployee() {
        cout << "EmpId\t/Name\tSalary" << endl;
        Employee e;
        ifstream in("Employee.txt");
        while (in)
        {
            in >> e;
            cout << e.mEmpid << "\t" << e.nName << "\t" << e.mSalary << endl;
        }
        in.close();

    }
    


    
    double generatePaySlip() {
        int month;
        string id;
        cout << "Enter the month(in digits)" << endl;
        cin >> month;
        cout << "Enter the employee id  " << endl;
        cin >> id;
        cout << "EmpId\t/Name\tSalary" << endl;
        Employee e;
        std::ifstream in("Employee.txt");


        while (in)
        {
            in >> e;
            if (id == e.mEmpid)
            {
                int noofdays;
                cout << "Enter the number of present days" << endl;
                cin >> noofdays;
                double Salary = stod(e.mSalary);
                double amt;

                
                switch (month)
                {
                case 1: 
                    amt = caculateAmount(Salary, noofdays, 31);

                break;
                case 2: 
                    amt = caculateAmount(Salary, noofdays, 28);

                    break;
                case 3: 
                    amt = caculateAmount(Salary, noofdays, 31);

                    break;
                case 4:
                    amt = caculateAmount(Salary, noofdays, 30);

                    break;
                case 5:
                    amt =caculateAmount(Salary, noofdays, 31);
                    return amt;
                    break;
                case 6:
                    amt = caculateAmount(Salary, noofdays, 30);
                    return amt;

                    break;
                case 7:
                    amt = caculateAmount(Salary, noofdays, 31);
                    return amt;
                    break;
                case 8:
                    amt = caculateAmount(Salary, noofdays, 31);
                    return amt;
                    break;
                case 9:
                    amt = caculateAmount(Salary, noofdays, 30);
                    return amt;
                    break;
                case 10:
                    amt = caculateAmount(Salary, noofdays, 31);
                    return amt;
                    break;
                case 11:
                    amt = caculateAmount(Salary, noofdays, 30);
                    return amt;
                    break;
                case 12:amt = caculateAmount(Salary, noofdays, 31);
                    return amt;
                    break;


                }
            }

        }
        in.close();

    }
    double calculateAmount( double salary, int present, int totaldays)
    {
        if (present > totaldays) {
            cout << "present days cannot be greater than total days" << endl;
        }
        double perday = salary / totaldays;
        double amt = perday * present;
        cout << "payable amount is " << amt << endl;
        return amt;
    }

    void createPaySlip()
    {
        string id;
        cout << "Employee Id " << endl;
        cin >> id;
        Employee e;
        std::ifstream in("Employee.txt");
        while (in) {
            in >> e;
            if (id == e.mEmpid);
            {
                double amt = generatePaySlip();
                std::ofstream out("Pay slip.doc");
                out << "XYZ COMPANY" << endl;
                out << " Employee ID :" << e.mEmpid << endl;
                out << " Name of the Employee" << e.nName << endl;
                out << " Basic Salary of the Employee" << e.mSalary << endl;
                out << "Amount payable " << amt << endl;
                out.close();

            }
        }
           
    }
    


};

int main()
{
    int ch;
    EmployeeData emp;//object of class employee
    do {
        cout << "--------------XYZ COMPANY----------------" << endl;
        cout << " 1.Add employee." << endl;
        cout << " 2.Display employee" << endl;
        cout << " 3.Get payable amount of Employee" << endl;
        cout << " 4.Creating Employee Payslip" << endl;
        cout << " 5.EXIT" << endl;
        
        cout << "enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1: emp.addEmployee();

            break;
        case 2: emp.dispEmployee();
            break;
        case 3: emp.generatePaySlip();
            break;
        case 4: emp.createPaySlip();
        case 5: 
            break;
        default: cout << "Enter correct choice\n";
            break;

        }

    } while (ch != 5);

}

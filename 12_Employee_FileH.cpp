#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

class Employee {
private:
    int code;
    char name[20];
    float salary;
    char designation[20];

public:
    void read();
    void display();
    int getEmpCode() { return code; }
    float getSalary() { return salary; }
    void updateSalary(float s) { salary = s; }
};

void Employee::read() {
    cout << "Enter employee code: ";
    cin >> code;
    cout << "Enter name: ";
    cin.ignore(1);
    cin.getline(name, 20);
    cout << "Enter Designation: ";
    cin >> designation;
    cout << "Enter salary: ";
    cin >> salary;
}

void Employee::display() {
    cout << code << " " << name << "\t" << salary << endl;
}

fstream file;

void deleteExistingFile() {
    remove("EMPLOYEE.DAT");
}

void appendToFille() {
    Employee x;
    x.read();
    file.open("EMPLOYEE.DAT", ios::binary | ios::app);
    if (!file) {
        cout << "ERROR IN CREATING FILE\n";
        return;
    }
    file.write((char*)&x, sizeof(x));
    file.close();
    cout << "Record added successfully.\n";
}

void displayAll() {
    Employee x;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file) {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }
    while (file.read((char*)&x, sizeof(x))) {
        // Uncomment below line to filter by salary
        // if (x.getSalary() >= 10000 && x.getSalary() <= 20000)
        x.display();
    }
    file.close();
}

void searchForRecord() {
    Employee x;
    int c;
    int isFound = 0;
    cout << "Enter employee code: ";
    cin >> c;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    if (!file) {
        cout << "ERROR IN OPENING FILE \n";
        return;
    }
    while (file.read((char*)&x, sizeof(x))) {
        if (x.getEmpCode() == c) {
            cout << "RECORD FOUND\n";
            x.display();
            isFound = 1;
            break;
        }
    }
    if (isFound == 0) {
        cout << "Record not found!!!\n";
    }
    file.close();
}

void increaseSalary() {
    Employee x;
    int c;
    int isFound = 0;
    float sal;
    cout << "Enter employee code: ";
    cin >> c;
    fstream temp;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    temp.open("TEMP.DAT", ios::binary | ios::out);
    if (!file || !temp) {
        cout << "ERROR IN OPENING FILE\n";
        return;
    }
    while (file.read((char*)&x, sizeof(x))) {
        if (x.getEmpCode() == c) {
            cout << "Salary hike? ";
            cin >> sal;
            x.updateSalary(x.getSalary() + sal);
            isFound = 1;
        }
        temp.write((char*)&x, sizeof(x));
    }
    file.close();
    temp.close();
    remove("EMPLOYEE.DAT");
    rename("TEMP.DAT", "EMPLOYEE.DAT");

    if (isFound == 0) {
        cout << "Record not found!!!\n";
    } else {
        cout << "Salary updated successfully." << endl;
    }
}

void insertRecord() {
    Employee x;
    Employee newEmp;
    newEmp.read();

    fstream fin;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    fin.open("TEMP.DAT", ios::binary | ios::out);

    if (!file) {
        cout << "Error in opening EMPLOYEE.DAT file!!!\n";
        return;
    }
    if (!fin) {
        cout << "Error in opening TEMP.DAT file!!!\n";
        return;
    }

    bool inserted = false;
    while (file.read((char*)&x, sizeof(x))) {
        if (!inserted && x.getEmpCode() > newEmp.getEmpCode()) {
            fin.write((char*)&newEmp, sizeof(newEmp));
            inserted = true;
        }
        fin.write((char*)&x, sizeof(x));
    }

    if (!inserted) {
        fin.write((char*)&newEmp, sizeof(newEmp));
    }

    fin.close();
    file.close();
    rename("TEMP.DAT", "EMPLOYEE.DAT");
    remove("TEMP.DAT");
    cout << "Record inserted successfully." << endl;
}

int main() {
    char ch;
    deleteExistingFile();
    do {
        int n;
        cout << "ENTER CHOICE\n"
             << "1. ADD AN EMPLOYEE\n"
             << "2. DISPLAY\n"
             << "3. SEARCH\n"
             << "4. INCREASE SALARY\n"
             << "5. INSERT RECORD\n";
        cout << "Make a choice: ";
        cin >> n;
        switch (n) {
            case 1:
                appendToFille();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchForRecord();
                break;
            case 4:
                increaseSalary();
                break;
            case 5:
                insertRecord();
                break;
            default:
                cout << "Invalid Choice\n";
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}

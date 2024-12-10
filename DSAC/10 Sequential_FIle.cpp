#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Structure to store student details
struct stud
{
    int rn;
    string name;  // Changed to string for better handling of names
};

// Class for handling file operations
class file
{
    stud s;
    fstream f, f1;
    string fname;  // Using string for the filename to avoid fixed size array
public:
    file()
    {
        cout << "\nEnter file name: ";
        cin >> fname;
    }

    // Create new file and add records
    void create()
    {
        int n;
        f.open(fname, ios::out);
        if (!f) {
            cout << "Error opening file for creation!" << endl;
            return;
        }

        cout << "Accept number of records: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter roll number and name: ";
            cin >> s.rn >> s.name;
            f.write((char*)&s, sizeof(s));
        }
        f.close();
    }

    // Display all records
    void disp()
    {
        int i = 1;
        f.open(fname, ios::in);
        if (!f) {
            cout << "Error opening file to display!" << endl;
            return;
        }

        cout << "\nSr.No\tRoll No\tName" << endl;
        while (f.read((char*)&s, sizeof(s)))
        {
            cout << i << "\t" << s.rn << "\t" << s.name << endl;
            i++;
        }
        f.close();
    }

    // Add new record to the file
    void add()
    {
        f.open(fname, ios::out | ios::app);
        if (!f) {
            cout << "Error opening file to add record!" << endl;
            return;
        }

        cout << "\nEnter roll number and name: ";
        cin >> s.rn >> s.name;
        f.write((char*)&s, sizeof(s));
        f.close();
    }

    // Search for a student by roll number
    int search(int x)
    {
        f.open(fname, ios::in);
        if (!f) {
            cout << "Error opening file to search!" << endl;
            return 0;
        }

        while (f.read((char*)&s, sizeof(s)))
        {
            if (s.rn == x)
            {
                f.close();
                return 1;
            }
        }
        f.close();
        return 0;
    }

    // Modify a student's record by roll number
    void modify()
    {
        int x;
        cout << "\nEnter roll number to modify: ";
        cin >> x;

        if (search(x))
        {
            f.open(fname, ios::in | ios::out);
            if (!f) {
                cout << "Error opening file to modify!" << endl;
                return;
            }

            int size = sizeof(s);
            while (f.read((char*)&s, sizeof(s)))
            {
                if (s.rn == x)
                {
                    cout << "\nEnter new data (roll number and name): ";
                    cin >> s.rn >> s.name;
                    f.seekp(-size, ios::cur);
                    f.write((char*)&s, sizeof(s));
                    break;
                }
            }
            f.close();
        }
        else
            cout << "Record not found!" << endl;
    }

    // Delete a student's record by roll number
    void del()
    {
        int x;
        cout << "\nEnter roll number to delete: ";
        cin >> x;

        if (search(x))
        {
            f.open(fname, ios::in);
            if (!f) {
                cout << "Error opening file to delete!" << endl;
                return;
            }

            f1.open("temp.txt", ios::out);
            if (!f1) {
                cout << "Error opening temporary file!" << endl;
                return;
            }

            while (f.read((char*)&s, sizeof(s)))
            {
                if (s.rn != x)
                {
                    f1.write((char*)&s, sizeof(s));
                }
            }
            f.close();
            f1.close();

            remove(fname.c_str());
            rename("temp.txt", fname.c_str());
            cout << "Record deleted successfully!" << endl;
        }
        else
            cout << "Record not found!" << endl;
    }
};

int main()
{
    file f;
    int ch, x;

    while (1)
    {
        cout << "\n1. Create\n2. Display\n3. Add\n4. Delete\n5. Modify\n6. Search\nChoice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            f.create();
            break;
        case 2:
            f.disp();
            break;
        case 3:
            f.add();
            break;
        case 4:
            f.del();
            break;
        case 5:
            f.modify();
            break;
        case 6:
            cout << "\nEnter roll number to search: ";
            cin >> x;
            if (f.search(x))
                cout << "Found" << endl;
            else
                cout << "Not found" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}


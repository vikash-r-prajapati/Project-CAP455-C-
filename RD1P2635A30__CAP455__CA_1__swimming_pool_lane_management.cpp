#include <iostream>
#include <string>
using namespace std;

const int MAX_SWIMMERS = 200;

class Swimmer {
private:
    int swimmerId;
    string name;
    int age;
    string phone;

    static int totalSwimmers;

public:

    // Default constructor
    Swimmer() {
        swimmerId = 0;
        name = "";
        age = 0;
        phone = "";
    }
    // Set swimmer details
    void setDetails(int id, string n, int a, string p) {
        this->swimmerId = id;
        this->name = n;
        this->age = a;
        this->phone = p;

        totalSwimmers++;
    }
    // Get swimmer ID
    int getId() const {
        return swimmerId;
    }
    // Inline function
    inline void displayDetails() const {
        cout << "\nSwimmer ID: " << swimmerId;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nPhone: " << phone << endl;
    }
    // Initialize static variable
    int Swimmer::totalSwimmers = 0;

    // Static function
    static int getTotalSwimmers() {
        return totalSwimmers;
    }
    // Friend function
    friend void showSwimmer(const Swimmer& s);
};
// Friend function
void showSwimmer(const Swimmer& s) {
    cout << "\nSwimmer Name: " << s.name;
    cout << "\nSwimmer ID: " << s.swimmerId << endl;
}
// Check duplicate ID
bool isDuplicate(Swimmer swimmers[], int count, int id) {

    for (int i = 0; i < count; i++) {
        if (swimmers[i].getId() == id) {
            return true;
        }
    }
    return false;
}

int main() {

    Swimmer swimmers[MAX_SWIMMERS];

    int count = 0;
    int choice;

    do {

        cout << "\n===== SWIMMING POOL SYSTEM =====\n";
        cout << "1. Register Swimmer\n";
        cout << "2. View All Swimmers\n";
        cout << "3. Search Swimmer\n";
        cout << "4. Total Swimmers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {

            case 1: {

                if (count == MAX_SWIMMERS) {
                    cout << "Registration is full!\n";
                    break;
                }

                int id, age;
                string name, phone;

                cout << "Enter Swimmer ID: ";
                cin >> id;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid ID!\n";
                    break;
                }

                if (id <= 0 || isDuplicate(swimmers, count, id)) {
                    cout << "Invalid or duplicate ID!\n";
                    break;
                }

                cin.ignore(1000, '\n');

                cout << "Enter Name: ";
                getline(cin, name);

                if (name.empty()) {
                    cout << "Name cannot be empty!\n";
                    break;
                }

                cout << "Enter Age: ";
                cin >> age;

                if (cin.fail() || age <= 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid age!\n";
                    break;
                }

                cout << "Enter Phone: ";
                cin >> phone;

                swimmers[count].setDetails(id, name, age, phone);

                count++;

                cout << "Swimmer registered successfully!\n";

                break;
            }

            case 2: {

                if (count == 0) {
                    cout << "No swimmers found!\n";
                    break;
                }

                const Swimmer* ptr = swimmers;

                for (int i = 0; i < count; i++) {
                    (ptr + i)->displayDetails();
                }

                break;
            }

            case 3: {

                int id;
                bool found = false;

                cout << "Enter Swimmer ID: ";
                cin >> id;

                for (int i = 0; i < count; i++) {

                    if (swimmers[i].getId() == id) {

                        showSwimmer(swimmers[i]);
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Swimmer not found!\n";
                }

                break;
            }

            case 4:

                cout << "Total Swimmers: "
                     << Swimmer::getTotalSwimmers() << endl;

                break;

            case 5:

                cout << "Exiting Swimming Pool System...\n";

                break;

            default:

                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

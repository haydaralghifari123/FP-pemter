#include <iostream>
#include <string>
using namespace std;

int menuCount = 0;
string* menuNames = nullptr;
double* menuPrices = nullptr;

void addMenu() {
string newName;
double newPrice;
cout << "Masukkan nama menu: ";
cin.ignore(); // Menghapus buffer
getline(cin, newName);
cout << "Masukkan harga menu: ";
cin >> newPrice;
// Buat array baru dengan ukuran lebih besar
string* tempNames = new string[menuCount + 1];
double* tempPrices = new double[menuCount + 1];
// Salin data lama ke array baru
for (int i = 0; i < menuCount; i++) {
tempNames[i] = menuNames[i];
tempPrices[i] = menuPrices[i];
}
// Tambahkan data baru ke array
tempNames[menuCount] = newName;
tempPrices[menuCount] = newPrice;
// Ganti array lama dengan array baru
if (menuNames != nullptr) {
delete[] menuNames;
delete[] menuPrices;
}
menuNames = tempNames;
menuPrices = tempPrices;
menuCount++;
}

void viewMenu() {
string defaultMenuNames[] = {"Nasi Goreng", "Mie Goreng", "Sate", "Gado-Gado"};
double defaultMenuPrices[] = {15000, 12000, 18000, 10000};
int defaultMenuCount = sizeof(defaultMenuNames) / sizeof(defaultMenuNames[0]);

// Gabungkan default menu dengan custom menu
string* allMenuNames = new string[defaultMenuCount + menuCount];
double* allMenuPrices = new double[defaultMenuCount + menuCount];

// Salin default menu ke array baru
for (int i = 0; i < defaultMenuCount; i++) {
    allMenuNames[i] = defaultMenuNames[i];
    allMenuPrices[i] = defaultMenuPrices[i];
}

// Salin custom menu ke array baru
for (int i = 0; i < menuCount; i++) {
    allMenuNames[defaultMenuCount + i] = menuNames[i];
    allMenuPrices[defaultMenuCount + i] = menuPrices[i];
}

cout << "Menu:" << endl;
for (int i = 0; i < defaultMenuCount + menuCount; i++) {
    cout << "  " << i + 1 << ". " << allMenuNames[i] << " - Rp " << allMenuPrices[i] << endl;
}

delete[] allMenuNames;
delete[] allMenuPrices;
}

int main() {
int choice;
string role;
bool isAdmin = true;

while (isAdmin) {
    cout << "Welcome Cafe Gerilya" << endl;
    cout << "Are you an admin or a customer? (admin/customer): ";
    cin >> role;

    if (role == "admin") {
        do {
            cout << "Admin Menu" << endl;
            cout << "1. Add Menu" << endl;
            cout << "2. Exit" << endl;
            cout << "Choose an option: ";
            cin >> choice;
            if (choice == 1) {
                addMenu();
            } else if (choice == 2) {
                cout << "Back to main menu..." << endl;
                break;
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 2);
    } else if (role == "customer") {
        do {
            cout << "Customer Menu" << endl;
            cout << "1. View Menu" << endl;
            cout << "2. Exit" << endl;
            cout << "Choose an option: ";
            cin >> choice;
            if (choice == 1) {
                viewMenu();
            } else if (choice == 2) {
                cout << "Goodbye!" << endl;
                isAdmin = false;
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 2);
    } else {
        cout << "Invalid. Please try again." << endl;
    }
}

return 0;
}

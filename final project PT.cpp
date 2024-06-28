#include <iostream>
#include <string>

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

    // Tambahkan menu baru ke array
    tempNames[menuCount] = newName;
    tempPrices[menuCount] = newPrice;

    // Ganti pointer lama dengan yang baru
    menuNames = tempNames;
    menuPrices = tempPrices;

    menuCount++;

    cout << "Menu berhasil ditambahkan!" << endl;
}

void viewMenu() {
    if (menuCount == 0) {
        cout << "Menu kosong!" << endl;
        return;
    }

    cout << "Daftar Menu:" << endl;
    for (int i = 0; i < menuCount; i++) {
        cout << i + 1 << ". " << menuNames[i] << " - Rp " << menuPrices[i] << endl;
    }
}

void admin() {
    int choice;
    do {
        cout << "Admin Menu:" << endl;
        cout << "1. Tambah Menu" << endl;
        cout << "2. Lihat Menu" << endl;
        cout << "3. Keluar ke Menu Utama" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addMenu();
            break;
        case 2:
            viewMenu();
            break;
        case 3:
            cout << "Keluar ke menu utama." << endl;
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (true);
}



int main(){
    int a;

    cout << "login admin atau customer?";
    cin >> a;


    if (a == 1) {
        admin();
    }
    else if (a == 2) {
        //customer();
    }
}

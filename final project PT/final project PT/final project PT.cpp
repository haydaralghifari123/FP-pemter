#include <iostream>
#include <string>
using namespace std;

int main();

int admin() {
    string menu[];
    int kode;
    cout << "masukkan kode :";
    cin >> kode;
    if (kode == 123) {
        cout << "olala";
    }
    else {
        main();
    }

    cout << "masukkan menu";
    cin >> menu;

    int hasil = kode;

    return (hasil);
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

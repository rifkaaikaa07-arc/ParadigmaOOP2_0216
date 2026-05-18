#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    double saldo;

public:
    RekeningBank(double s) : saldo(s) {}

    virtual void potongAdmin() = 0; // pure virtual function

    virtual void tampilSaldo() {
        cout << "Saldo akhir: Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

// Rekening Syariah (tanpa biaya admin)
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        cout << "Rekening Syariah: Tidak ada biaya admin." << endl;
    }
};

// Rekening Konvensional (potong Rp 15.000)
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Rekening Konvensional: Potong Rp 15.000" << endl;
    }
};

// Rekening Premium (aturan dinamis)
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Rekening Premium: Bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Rekening Premium: Potong Rp 50.000" << endl;
        }
    }
};

// Main program
int main() {
    RekeningBank* r1 = new RekeningSyariah(5000000);
    RekeningBank* r2 = new RekeningKonvensional(5000000);
    RekeningBank* r3 = new RekeningPremium(8000000);
    RekeningBank* r4 = new RekeningPremium(15000000);

    RekeningBank* daftar[] = {r1, r2, r3, r4};

    for (int i = 0; i < 4; i++) {
        daftar[i]->potongAdmin();
        daftar[i]->tampilSaldo();
        cout << "------------------------" << endl;
    }

    return 0;
}
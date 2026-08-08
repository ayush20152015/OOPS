#include <bits/stdc++.h>
using namespace std;

class bank {
    string name;
    int ac;
    int bal;
    static int total_bal;
    static int total_user;

public:
    bank(string a, int b, int c) : name(a), ac(b), bal(c) {
        total_bal += c;
        total_user++;
    }

    // Static functions to get static private variables
    static void display_total_balance() {
        cout << total_bal << "\n";
    }

    static void display_total_user() {
        cout << total_user << "\n";
    }

    // Member function for withdraw
    void with_draw(int amount) {
        if (amount <= bal) {
            bal -= amount;
            total_bal -= amount;
        } else {
            cout << "Insufficient balance\n";
        }
    }

    // Member function for deposit
    void deposit(int amount) {
        bal += amount;
        total_bal += amount;
    }
};

// Define static members outside the class
int bank::total_bal = 0;
int bank::total_user = 0;

int main() {
    bank b1("Ayush", 123, 4000);
    bank b2("Aamod", 345, 5600);
    bank b3("Sanket", 567, 6000000);

    bank::display_total_balance(); // prints 6009600
    bank::display_total_user();    // prints 3

    b1.with_draw(1000);  // Ayush withdraws ₹1000
    b2.deposit(2000);    // Aamod deposits ₹2000

    bank::display_total_balance(); // updated total balance
    return 0;
}

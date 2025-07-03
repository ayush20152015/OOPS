#include <bits/stdc++.h>
using namespace std;

class bank_account {
    string name;
    int ac;
    int bal;
    static int total_bal;
    static int number_of_members;

public:
    // Constructor (not 'inline', and initializer list syntax corrected)
    bank_account(string a, int b, int c) : name(a), ac(b), bal(c) {
        total_bal += c; // should be 'bal', not 'ac'
        number_of_members++;
    }

    void displayTotalBalance() {
        cout << total_bal << "\n";
    }

    void numberOfMembers() {
        cout << number_of_members << "\n";
    }
};

// Define static members outside the class
int bank_account::total_bal = 0;
int bank_account::number_of_members = 0;

int main() {
    // Do not use 'inline' here
    bank_account b1("Ayush", 203, 50000);
    bank_account b2("Aamod", 450, 60000);
    bank_account b3("Abhishek", 560, 70000);

    b1.displayTotalBalance();  // Will print: 180000
    b1.numberOfMembers();      // Will print: 3
}

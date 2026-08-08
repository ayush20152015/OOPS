#include <bits/stdc++.h>
using namespace std;

class human {
    string name;
    int age;
    char gender;

public:
    human(string a, int b, char d) {
        name = a;
        age = b;
        gender = d; // fixed from 'c' to 'd'
        cout << "human created\n";
    }

    ~human(){
        cout<<"destructor is called for human";
    }
};

class student : public human {
    int roll_number;

public:
    // Constructor for student class that also calls human constructor
    student(string name, int age, char gender, int r) : human(name, age, gender) {
        roll_number = r;
        cout<<"student created"<<"\n";   // order of constructor is parent->child and destructor is oppsite
    }


    void display() {
        cout << "Roll Number: " << roll_number << "\n";
    }

    ~student(){
      cout<<"destructor is called for student"<<"\n";
    }
};

int main() {
    // create student object with required arguments
    student A1("John", 20, 'M', 101);
    A1.display();

    return 0;
}


// important facts

/*

pc:- private cc:- private ---> private
pc:- private cc:- protected ---> private
pc:- private cc:- public ---> private
pc:- protected cc:- private ---> private
pc:- protected cc:- public ---> protected
pc:- protected cc:- protected ---> protected
pc:- public cc:- private ---> private
pc:- public cc:- protected ---> protected
pc:- public cc:- public ---> public


private>protected>public:





*/

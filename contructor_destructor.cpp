#include<bits/stdc++.h>
using namespace std;

class customer{
// this is class 
  string name;
  int account_number;
  int balance;
  // constuctor has to be publicly declared 
  public:
  customer(){
     cout<<"this is constructor"<<"\n";
     // default constructor
  }   // multiple constructor can be declared 
  // the constuctor must be unique

  customer(string a,int b,int c){
    name=a;
    account_number=b;
    balance=c;
  }
  

  /*
  
  another version of writing constuctor is using this pointer
  customer(string name,int account_number,int balance){
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
  }
  
  inline counstructor 

  inline customer(string a,int b,int c):name(a),account_number(b),balance(c) {};
  
  */
   // constructor overloading 
  customer (string a,int b){
        name=a;
        account_number=b;
  }

  void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<"\n";
  }

};



int main(){

 customer a;
 customer c2("Ayush",123,4000);
 customer c3("Ayush",40);
 c2.display();
 c3.display();


}
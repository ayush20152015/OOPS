#include<bits/stdc++.h>
using namespace std;

class customer{
  string name;
  int ac;
  int bal;
  
   public:

 inline customer(string a,int b,int c): name(a),ac(b),bal(b){}
 
 void display(){
   cout<<name<<" "<<ac<<" "<<bal<<"\n";
 }
 
 customer(customer &b){   // paramaterized custom copy constructor
    name=b.name;
    ac=b.ac;
    bal=b.bal;
 }

};

int main(){
  customer a1("ayush",100,1000);
  a1.display();
  // default copy constructor is always present
 // customer a2=a1;

  
  // now to make a custom copy constructor
  customer a2(a1);
  a2.display();
  
  
  return 0;      
}
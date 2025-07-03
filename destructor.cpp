#include <bits/stdc++.h>
using namespace std;

class user{
   string name;
   string pass;

 public:


  user(){

  }

  user(string a,string b){
    name=a;
    pass=b;
   cout<<"constructor is called for "<<name<<"\n";
  }
  
  

  ~user(){
        cout<<"destructor is called for "<<name<<"\n";  // in reverse order
  }


};


int main(){

user a1("ayush","123");
user a2("divyansh","345");
user a3("kushagra","567");

user *a4 =  new user;

delete a4;


return 0;
}

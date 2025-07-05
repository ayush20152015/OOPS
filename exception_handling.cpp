#include<bits/stdc++.h>
using namespace std;

class bank{
   string name;
   int bal;
   
   public:
  bank(string name,int bal){
        this->bal=bal;
        this->name=name;
  };



  void deposit(int amount){
      bal+=amount;
  }
  void withdraw(int amount){
     if(amount>bal && amount>0){
        throw("insufficent balance");
     }
     else if(amount<=bal){
         throw("amount debated succefully");
     }
     else{
          throw("amount must be greater than zero");
     }
  }


};

int main(){
   
   bank b1("Ayush",4000);
   
   try{
     b1.deposit(400);
     b1.withdraw(500);
   }
   catch(const char *e){
     cout<<"Exception occured:"<<e<<"\n";
   }

   return 0;
 
}
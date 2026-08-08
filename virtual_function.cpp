#include<bits/stdc++.h>
using namespace std;

class Animal{
   public:
   
   virtual void speak()=0;  // pure virtual function 
};

class Dog : public Animal{
     public:
    void speak(){
         cout<<"bark"<<"\n";
    }
};

class Cat : public Animal{
    public:
    void speak(){
        cout<<"meow"<<"\n";
    }
};


int main(){
  
  Animal *p;
  p= new Dog();
 // p->speak();    // virtual function is required for runtime polymorphism
 vector<Animal*>sounds;
 sounds.push_back(new Dog());
 sounds.push_back(new Cat());
 // cannot be used in case of pure virtual function sounds.push_back(new Animal());

 for(auto p:sounds){
       p->speak();
 }

 // to avoid creating any object for the parent class we need to use pure virtual function 

  return 0;      
}
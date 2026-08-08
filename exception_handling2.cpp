#include<bits/stdc++.h>
using namespace std;



int main(){
   int a,b;
   cin>>a>>b;
  
   try{
      if(b==0){
    throw("divide by 0 is not possible");
    int c=(a/b);
    cout<<c<<"\n";
   }  
   }
   catch(const char *e){
      cout<<"exception occured "<<e<<"\n";
   }

   
  return 0;      
}
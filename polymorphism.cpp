#include<bits/stdc++.h>
using namespace std;

class area{
    public:
   int calculate_area(int r){
        return 3*r*r;
   }
   int calculate_area(int l,int b){
        return l*b;
   }
};

int main(){
   area a;
   int ans1=a.calculate_area(4);
   int ans2=a.calculate_area(3,4);
   cout<<ans1<<"\n";
   cout<<ans2<<"\n";
}
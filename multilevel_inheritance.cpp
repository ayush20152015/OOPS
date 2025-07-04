#include<bits/stdc++.h>
using namespace std;

class vehicle{
  protected:
  string type;
   public:
  vehicle(){
    
  }
};
class company:public vehicle{
  protected:
  string company;
};

class model:public company{
  private:
  string price_range;
  public:
  model(string type,string company,string price_range){
      this->type=type;
      this->company=company;
      this->price_range=price_range;
  }
  void display(){
    cout<<type<<" "<<company<<" "<<price_range<<"\n";
    
  }
};

int main(){
  model m("car","ford","23Lakhs-45Lakhs");
  m.display();
}


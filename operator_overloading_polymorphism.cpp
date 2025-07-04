#include <iostream>
using namespace std;

class complex {
  int real;
  int img;

public:
  // Default constructor
  complex() {
    real = 0;
    img = 0;
  }

  // Parameterized constructor
  complex(int r, int i) {
    real = r;
    img = i;
  }

  void display() {
    cout << real << "+j" << img << "\n";
  }

  // Operator overloading
  complex operator+(const complex &c2) {
    complex ans;
    ans.real = this->real + c2.real;
    ans.img = this->img + c2.img;
    return ans;
  }
};

int main() {
  complex c1(2, 4);
  complex c2(2, 4);

  c1.display();   // Output: 2+j4
  c2.display();   // Output: 2+j4

  complex c3 = c1 + c2;  // Add using overloaded +
  c3.display();   // Output: 4+j8

  return 0;
}

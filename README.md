# OOPS in C++: End-to-End Notes, Code Walkthrough, MCQs, and Interview Prep

This repository now contains merged content from both main and master. It includes practical C++ OOP programs and this complete learning guide.

## 1) Repository Overview

The codebase currently contains:

- `contructor_destructor.cpp`
- `copy_constructor.cpp`
- `destructor.cpp`
- `encapsulation.cpp`
- `exception_handling.cpp`
- `exception_handling2.cpp`
- `inheritance.cpp`
- `multilevel_inheritance.cpp`
- `multiple_inheritance.cpp`
- `operator_overloading_polymorphism.cpp`
- `polymorphism.cpp`
- `virtual_function.cpp`
- `static_keyword`

These files cover core OOP and related C++ concepts:

- class and object basics
- constructors, overloading, copy constructor, destructor
- encapsulation
- static data members and static member functions
- inheritance (single, multilevel, multiple)
- compile-time polymorphism (function overloading)
- runtime polymorphism (virtual and pure virtual functions)
- operator overloading
- basic exception handling

## 2) Build and Run

Use g++:

```bash
g++ -std=c++17 filename.cpp -o out && ./out
```

For the file named `static_keyword` (without extension):

```bash
g++ -std=c++17 static_keyword -o static_keyword_out && ./static_keyword_out
```

## 3) Deep Explanation of Existing Files

---

### 3.1 `contructor_destructor.cpp`

What it teaches:

- default constructor
- parameterized constructor
- constructor overloading
- object creation syntax

Key points:

- `customer()` prints "this is constructor".
- `customer(string,int,int)` initializes all fields.
- `customer(string,int)` does not set `balance`, so `display()` may print an uninitialized value.

Observed output pattern:

- one line from default constructor for object `a`
- valid details for `c2`
- potentially garbage balance for `c3`

Important lesson:

- always initialize all fields in all constructors.

---

### 3.2 `copy_constructor.cpp`

What it teaches:

- custom copy constructor
- object copy semantics

Code note:

- parameterized constructor uses `bal(b)` instead of `bal(c)`. This means the third argument is ignored and balance becomes account value.

Expected behavior from current code:

- `a1("ayush",100,1000)` prints balance as `100` because of the bug.
- copied object `a2` matches `a1`.

Important lesson:

- initializer list mistakes can silently change program logic.

---

### 3.3 `destructor.cpp`

What it teaches:

- constructor and destructor lifecycle
- stack object destruction order
- dynamic allocation and `delete`

Behavior:

- constructors run for `a1`, `a2`, `a3`.
- `a4` created with default constructor and deleted manually.
- stack destructors run in reverse creation order.

Important lesson:

- for `new`, use `delete` to avoid memory leaks.

---

### 3.4 `encapsulation.cpp`

What it teaches:

- private data + public methods
- static class members shared across all objects
- member functions modifying both object-level and class-level state

Behavior:

- constructors update `total_bal` and `total_user`.
- `deposit()` and `with_draw()` update both object balance and total balance.
- static methods print aggregate state.

Important lesson:

- encapsulation protects invariants and centralizes business rules.

---

### 3.5 `exception_handling.cpp`

What it teaches:

- throwing and catching exceptions
- control flow via `try` and `catch`

Behavior in current code:

- `withdraw(500)` when balance is enough throws success text (`"amount debated succefully"`).
- logically, success should not throw; only errors should throw.

Important lesson:

- exceptions should represent exceptional conditions, not normal success.

---

### 3.6 `exception_handling2.cpp`

What it teaches:

- runtime input check for division by zero

Code issue:

- division logic is inside `if (b==0)` after `throw`, so code is unreachable.
- missing normal path for `b != 0`.

Important lesson:

- structure try blocks so normal path executes without exception.

---

### 3.7 `inheritance.cpp`

What it teaches:

- single inheritance
- base constructor call from derived initializer list
- constructor and destructor order

Behavior:

- `human` constructor runs before `student` constructor.
- on exit, `student` destructor runs before `human` destructor.

Important lesson:

- lifecycle always flows parent->child for construction and child->parent for destruction.

---

### 3.8 `multilevel_inheritance.cpp`

What it teaches:

- multilevel inheritance chain (`vehicle -> company -> model`)
- protected member access across levels

Behavior:

- final class `model` sets inherited protected fields and displays all values.

Important lesson:

- protected is useful when derived classes need direct controlled access.

---

### 3.9 `multiple_inheritance.cpp`

What it teaches:

- combining multiple base classes in one derived class
- simple academic management model with course completion and grading

Behavior:

- enroll course
- assign grade only when course exists
- show grade if completed

Important lesson:

- multiple inheritance can model orthogonal traits but should be used carefully to avoid ambiguity.

---

### 3.10 `operator_overloading_polymorphism.cpp`

What it teaches:

- custom type (`complex`)
- overloading `operator+`

Behavior:

- adds real and imaginary parts separately.
- demonstrates natural syntax: `c3 = c1 + c2`.

Important lesson:

- overloaded operators should preserve intuitive meaning.

---

### 3.11 `polymorphism.cpp`

What it teaches:

- compile-time polymorphism via function overloading

Behavior:

- `calculate_area(int)` for circle-like formula
- `calculate_area(int,int)` for rectangle

Note:

- circle formula uses `3*r*r` (integer approximation). Use `3.14159` for better precision.

---

### 3.12 `virtual_function.cpp`

What it teaches:

- abstract base class (`Animal`)
- pure virtual function (`speak`) and runtime polymorphism

Behavior:

- `vector<Animal*>` stores `Dog` and `Cat`
- virtual dispatch calls appropriate overridden `speak()`

Important lesson:

- pure virtual methods enforce interface contracts.

---

### 3.13 `static_keyword`

What it teaches:

- static data members in class scope
- aggregate information shared across all instances

Behavior:

- creates 3 accounts
- total balance and number of members are shown through methods

Important lesson:

- static data belongs to class, not to individual object.

## 4) OOP Concepts from Easy to Tricky with Extra Code

### 4.1 Class and Object (Easy)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Student {
	string name;
	int marks;
public:
	Student(string n, int m) : name(n), marks(m) {}
	void show() { cout << name << " " << marks << "\n"; }
};

int main() {
	Student s("Riya", 91);
	s.show();
}
```

Output:

```text
Riya 91
```

---

### 4.2 Constructor Overloading (Easy to Medium)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Box {
	int l, b, h;
public:
	Box() : l(1), b(1), h(1) {}
	Box(int x) : l(x), b(x), h(x) {}
	Box(int x, int y, int z) : l(x), b(y), h(z) {}
	int volume() { return l * b * h; }
};

int main() {
	Box a, b(3), c(2, 3, 4);
	cout << a.volume() << " " << b.volume() << " " << c.volume() << "\n";
}
```

Output:

```text
1 27 24
```

---

### 4.3 Copy Constructor and Deep Copy (Medium)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Demo {
	int *p;
public:
	Demo(int x) { p = new int(x); }
	Demo(const Demo &d) { p = new int(*d.p); }
	void set(int x) { *p = x; }
	void show() const { cout << *p << "\n"; }
	~Demo() { delete p; }
};

int main() {
	Demo a(10);
	Demo b = a;
	b.set(99);
	a.show();
	b.show();
}
```

Output:

```text
10
99
```

---

### 4.4 Encapsulation with Validation (Medium)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Account {
	int balance;
public:
	Account(int b = 0) : balance(max(0, b)) {}
	bool deposit(int amt) {
		if (amt <= 0) return false;
		balance += amt;
		return true;
	}
	bool withdraw(int amt) {
		if (amt <= 0 || amt > balance) return false;
		balance -= amt;
		return true;
	}
	int getBalance() const { return balance; }
};

int main() {
	Account a(100);
	cout << a.withdraw(120) << "\n";
	cout << a.deposit(50) << "\n";
	cout << a.getBalance() << "\n";
}
```

Output:

```text
0
1
150
```

---

### 4.5 Inheritance and Protected Access (Medium)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Employee {
protected:
	int salary;
public:
	Employee(int s) : salary(s) {}
};

class Manager : public Employee {
public:
	Manager(int s) : Employee(s) {}
	void show() { cout << salary << "\n"; }
};

int main() {
	Manager m(90000);
	m.show();
}
```

Output:

```text
90000
```

---

### 4.6 Runtime Polymorphism (Medium to Tricky)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
	virtual double area() const = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
	double r;
public:
	Circle(double r) : r(r) {}
	double area() const override { return 3.14159 * r * r; }
};

class Rectangle : public Shape {
	double l, b;
public:
	Rectangle(double l, double b) : l(l), b(b) {}
	double area() const override { return l * b; }
};

int main() {
	vector<Shape*> v = {new Circle(2), new Rectangle(3, 4)};
	for (auto p : v) cout << fixed << setprecision(2) << p->area() << "\n";
	for (auto p : v) delete p;
}
```

Output:

```text
12.57
12.00
```

---

### 4.7 Operator Overloading (Medium)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Fraction {
	int n, d;
public:
	Fraction(int n, int d) : n(n), d(d) {}
	Fraction operator+(const Fraction &o) const {
		return Fraction(n * o.d + o.n * d, d * o.d);
	}
	void show() const { cout << n << "/" << d << "\n"; }
};

int main() {
	Fraction a(1, 2), b(1, 3);
	Fraction c = a + b;
	c.show();
}
```

Output:

```text
5/6
```

---

### 4.8 Exception Handling (Tricky)

```cpp
#include <bits/stdc++.h>
using namespace std;

double safeDivide(double a, double b) {
	if (b == 0) throw runtime_error("division by zero");
	return a / b;
}

int main() {
	try {
		cout << safeDivide(10, 2) << "\n";
		cout << safeDivide(5, 0) << "\n";
	} catch (const exception &e) {
		cout << "Caught: " << e.what() << "\n";
	}
}
```

Output:

```text
5
Caught: division by zero
```

## 5) Output-Based Questions (Easy to Tricky)

### Q1 Easy

```cpp
class A {
public:
	A() { cout << "A "; }
};
int main() { A x; }
```

What is output?

### Q2 Easy

```cpp
class A {
public:
	A(int x = 5) { cout << x << " "; }
};
int main() { A a; A b(9); }
```

What is output?

### Q3 Medium

```cpp
class Base {
public:
	Base() { cout << "B "; }
	~Base() { cout << "~B "; }
};
class Der : public Base {
public:
	Der() { cout << "D "; }
	~Der() { cout << "~D "; }
};
int main() { Der d; }
```

What is output sequence?

### Q4 Medium

```cpp
class A {
public:
	virtual void f() { cout << "A"; }
};
class B : public A {
public:
	void f() override { cout << "B"; }
};
int main() {
	A *p = new B();
	p->f();
	delete p;
}
```

Output?

### Q5 Tricky

```cpp
class Test {
	int x;
public:
	Test(int x) { x = x; }
	void show() { cout << x << "\n"; }
};
int main() { Test t(10); t.show(); }
```

What is the issue and expected behavior?

### Q6 Tricky

```cpp
class A {
public:
	A() { cout << "1 "; }
	A(const A&) { cout << "2 "; }
};
A fun(A a) { return a; }
int main() {
	A x;
	A y = fun(x);
}
```

How many copy constructor calls can appear (without optimization assumptions)?

## 6) MCQs (with Answers)

1. Which concept hides internal data and exposes only controlled access?
   A) Inheritance
   B) Encapsulation
   C) Polymorphism
   D) Abstraction

Answer: B

2. Which function is invoked automatically when object goes out of scope?
   A) Constructor
   B) Copy constructor
   C) Destructor
   D) Friend function

Answer: C

3. In C++, runtime polymorphism requires:
   A) overloaded functions
   B) static members
   C) virtual functions
   D) templates only

Answer: C

4. Static data member is shared by:
   A) one function
   B) one object
   C) all objects of class
   D) all classes

Answer: C

5. Which inheritance can lead to diamond problem?
   A) Single
   B) Multiple
   C) Multilevel
   D) Hierarchical

Answer: B

6. Which constructor is used when object is initialized from another object?
   A) default
   B) parameterized
   C) copy
   D) move assignment

Answer: C

7. Which keyword prevents method override in derived class (C++11+)?
   A) const
   B) final
   C) virtual
   D) static

Answer: B

8. Best practice for base class destructor when deleting derived via base pointer:
   A) private destructor
   B) inline only
   C) virtual destructor
   D) no destructor

Answer: C

9. Operator overloading lets you:
   A) change operator precedence
   B) define custom behavior for user-defined types
   C) create new operators
   D) overload for primitive types only

Answer: B

10. Which access specifier allows class and derived classes to access a member?
	A) private
	B) protected
	C) public
	D) friend

Answer: B

## 7) Tricky Interview Questions

1. Why should a polymorphic base class usually have a virtual destructor?
2. Difference between overloading and overriding with one concrete example each.
3. Explain Rule of 3 and when it matters.
4. What is object slicing? How to avoid it?
5. Why pass copy constructor parameter as `const ClassName&`?
6. Difference between `struct` and `class` in C++.
7. What happens if constructor throws an exception?
8. Can virtual functions be called from constructors/destructors? What is dispatched?
9. Explain shallow copy vs deep copy with dynamic memory.
10. What is the diamond problem and how does virtual inheritance solve it?
11. Why should data members generally be private?
12. Can static member functions access non-static members directly? Why/why not?
13. What is pure virtual function and abstract class?
14. Difference between compile-time and runtime polymorphism.
15. When should exceptions be used versus error codes?

## 8) Interview Answers (Concise)

1. Virtual destructor ensures correct derived destructor execution during `delete basePtr`.
2. Overloading: same name, different parameters, compile-time. Overriding: same signature in derived with virtual dispatch at runtime.
3. If class manages resource manually, define destructor, copy constructor, copy assignment.
4. Assigning derived object to base by value removes derived part. Avoid using pointers/references.
5. Prevents extra copy, allows binding to temporaries, guarantees no source mutation.
6. Only default access differs: `struct` public by default, `class` private by default.
7. Partially built object is cleaned for already-constructed members/bases.
8. During base constructor/destructor, dynamic dispatch behaves as current class stage, not most-derived.
9. Shallow copy shares pointers; deep copy clones pointed resource.
10. Multiple paths to same base create ambiguity; virtual inheritance creates one shared base subobject.
11. To preserve invariants, reduce accidental misuse, and enable validation.
12. No, static functions have no `this` pointer.
13. Pure virtual function (`=0`) makes class abstract, cannot instantiate directly.
14. Compile-time via overloading/templates. Runtime via virtual functions.
15. Use exceptions for exceptional failures, not normal control flow.

## 9) Practice Set: Fix-the-Code Challenges

1. In `copy_constructor.cpp`, fix initializer list bug so `bal` gets constructor third argument.
2. In `contructor_destructor.cpp`, initialize `balance` in all constructors.
3. In `exception_handling.cpp`, return success message normally, throw only for invalid operations.
4. In `exception_handling2.cpp`, implement valid divide path when denominator is non-zero.
5. Add virtual destructor to abstract/interface base classes where needed.

## 10) Suggested Learning Path

1. Start with class, object, constructor, destructor.
2. Move to encapsulation and static members.
3. Learn inheritance forms.
4. Practice polymorphism and virtual functions.
5. Add operator overloading and exception handling.
6. Solve output-based and debugging questions daily.

This README is designed as a full revision notebook plus interview prep sheet based on your repository code.

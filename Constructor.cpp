//
// Created by Naor Alkobi on 12/02/2022.
//

using namespace std;
#include "iostream"
#include <string>

class B{
public:
    B(string n) : name(n) {}

    string name;
};

class A{
    const int a;
public:
    A(int num, string n) : a(0) {
    }

};

class C : public A{
public:
    C(int num, string n) : A(num, n) {}
};


//int main (){
//    A* c = new C(2, "hello world!\n");
//    cout << c->a << endl;
//    cout << c->name;
//    return 0;
//
//}
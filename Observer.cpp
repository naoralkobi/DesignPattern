//
// Created by Naor Alkobi on 12/02/2022.
//

using namespace std;
#include "iostream"
#include <string>
#include <list>

class Subscriber {
public:
    virtual void update(string state) = 0;
};

class Publisher {
    list <Subscriber*> listeners;
    string state;
public:
    Publisher(const string s = "") {
        this->state = s;
    }
    ~Publisher() {}
    void setState(const string state){
        this->state = state;
    }
    void Add(Subscriber* s){
        this->listeners.push_back(s);
    }
    void Remove(Subscriber* s){
        this->listeners.remove(s);
    }
    void notifyAll(){
        for (Subscriber* s : listeners){
            s->update(state);
        }
    }
};

class A : public Subscriber {
public:
    virtual void update(string state){
        cout << "Hello i'm A i got : " << state << endl;
    }
};

class B : public Subscriber {
    virtual void update(string state){
        cout << "Hello i'm B i got : " << state << endl;
    }
};

class C : public Subscriber {
    virtual void update(string state){
        cout << "Hello i'm C i got : " << state << endl;
    }
};

//int main() {
//    Publisher* p = new Publisher();
//    A* a = new A();
//    B* b = new B();
//    C* c = new C();
//    p->Add(a);
//    p->Add(b);
//    p->Add(c);
//    p->setState("This is my message");
//    p->notifyAll();
//    cout << "\n";
//    p->Remove(b);
//    p->setState("Bye Bye 'B'");
//    p->notifyAll();
//
//    return 0;
//}


//
// Created by Naor Alkobi on 11/02/2022.
//

using namespace std;
#include "iostream"
#include <string>

class MainDish{
public:
    virtual void getDish(){}
};

class Pizza : public MainDish{
public:
    virtual void getDish(){
        cout << " pizza ";
    }
};

class Pasta : public MainDish{
public:
    virtual void getDish(){
        cout << " pasta ";
    }
};

class SideDish : public MainDish{
protected:
    virtual void getDish(){}
};

class Tomato : public SideDish{
    MainDish* md;
public:
    Tomato(MainDish* md) : md(md){}
    virtual void getDish(){
        md->getDish();
        cout << " tomato ";
    }
};

class Onion : public SideDish{
    MainDish* md;
public:
    Onion(MainDish* md) : md(md){}
    virtual void getDish(){
        md->getDish();
        cout << " onion ";
    }
};

//int main(){
//    MainDish* mainDish = new Tomato(new Onion(new Pizza()));
//    MainDish* mainDish1 = new Tomato(new Onion(new Pasta()));
//    mainDish->getDish();
//    cout <<"\n\n";
//    mainDish1->getDish();
//    return 0;
//}
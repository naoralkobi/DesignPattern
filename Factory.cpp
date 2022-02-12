//
// Created by Naor Alkobi on 12/02/2022.
//
using namespace std;
#include "iostream"
#include <string>
#include <map>


class Vehicle {
public:
    virtual void operation() const  = 0;
};

class Car : public Vehicle {
public:
    virtual ~Car(){}
    void operation() const override{
        cout << "Car\n";
    }
};

class Plane : public Vehicle {
public:
    virtual ~Plane(){}
    void operation() const override{
        cout << "Plane\n";
    }
};

class Creator {
public:
    map<string, Vehicle*> m;
    virtual Vehicle* createVehicle(const string type){
        return m[type];
    }
    Creator(){
        m["Car"] = new Car();
        m["Plane"] = new Plane();
    }
};

//int main(){
//    string str = "Car";
//    Creator* c = new Creator();
//    Vehicle* vehicle = c->createVehicle(str);
//    vehicle->operation();
//
//    string str1 = "Plane";
//    Creator* c1 = new Creator();
//    Vehicle* vehicle1 = c1->createVehicle(str1);
//    vehicle1->operation();
//
//    return 0;
//}

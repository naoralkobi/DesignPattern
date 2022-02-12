//
// Created by Naor Alkobi on 11/02/2022.
//

using namespace std;
#include "iostream"
#include <string>

class Color{
public:
    ~Color() = default;
    virtual string OperationImplementation() const  = 0;
};

class Blue : public Color {
public:
    string OperationImplementation() const override{
        return "Blue";
    }
};

class Green : public Color {
public:
    string OperationImplementation() const override{
        return "Green";
    }
};

class Shape{
    Color* imp;
public:
    ~Shape() = default;
    Shape(Color* implementation) : imp(implementation){}

    virtual void Circle(){
        cout << "Create " << this->imp->OperationImplementation() << " Circle"<< endl;
    }
    virtual void Square(){
        cout << "Create " << this->imp->OperationImplementation() << " Square"<< endl;

    }
};

//int main(){
//    Color* imp = new Blue();
//    Shape* abs = new Shape(imp);
//    abs->Circle();
//    Color* green = new Green();
//    Shape* abs1 = new Shape(green);
//    abs1->Square();
//
//    delete imp;
//    delete abs;
//    return 0;
//}
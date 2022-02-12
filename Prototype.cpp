//
// Created by Naor Alkobi on 11/02/2022.
//

#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n):name(n){}
    virtual Shape* clone() const=0;
    virtual void print()=0;
};

class Circle : public Shape{
    int _x, _y;
    double _radius;
public:
    Circle(int x, int y, double r): Shape("circle") {
        _x = x; _y = y; _radius = r;
    }
    Circle(): Shape("circle") {
        _x = 0; _y = 0; _radius = 0;
    }
    Shape* clone() const override {
        return (Shape*)new Circle(_x, _y, _radius);
    };
    virtual void print(){
        cout << "x=" << _x << ", y=" << _y << ", r=" << _radius << endl;
        cout << "^" << name << endl;
    }
};
class Rectangle : public Shape{
    int width;
    int height;
public:
    Rectangle(int w, int h): Shape("rectangle") {
        width = w;
        height = h;
    }
    Rectangle(): Shape("rectangle") {
        width = 0;
        height = 0;
    }
    Shape* clone() const override {
        return (Shape*)new Rectangle(width, height);
    };
    virtual void print(){
        cout << "width=" << width << ", height" << height << endl;
        cout << "^" << name << endl;
    }
};


//int main() {
//    char choose;
//    Shape* shape;
//    bool x;
//    do {
//        cout << "Enter shape ('c' or 'r'): ";
//        cin >> choose;
//        switch (choose) {
//            case 'c':
//                shape = new Circle();
//                x = false;
//                break;
//            case 'r':
//                shape = new Rectangle();
//                x = false;
//                break;
//            default:
//                x = true;
//        }
//    } while (x);
//    Shape* shapeCopy = shape->clone();
//    cout << "original shape: address=" << &shape << ", ";
//    shape->print();
//    cout << "shape copy: address=" << &shapeCopy << ", ";
//    shapeCopy->print();
//    return 0;
//}

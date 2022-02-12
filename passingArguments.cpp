//
// Created by Naor Alkobi on 12/02/2022.
//

using namespace std;
#include "iostream"
#include <string>

// not change the value.
void func1(int y){
    y = 4;
}
void func2(int &y){
    y = 3;
}
void func3(int* y){
    *y = 10;
}
void func4(int* &y){
    *y = 12;
}

//int main(){
//    int x = 5;
//    int* p = &x;
//    func1(x);
//    cout << " after func1: " << x << endl;
//    func2(x);
//    cout << " after func2: " << x << endl;
//    func3(p);
//    cout << " after func3: " << x << endl;
//    func4(p);
//    cout << " after func4: " << x << endl;
//    return 0;
//}


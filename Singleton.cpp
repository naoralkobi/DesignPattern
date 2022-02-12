//
// Created by Naor Alkobi on 12/02/2022.
//

using namespace std;
#include "iostream"
#include <string>

class Robot {
    static Robot* robot;
    string name;

public:
    static Robot* createRobot(){
        if (robot != nullptr){
            return robot;
        }
        return new Robot();
    }
    Robot* getRobot(){
        return this;
    }
};

//int main(){
//    Robot* robot = new Robot();
//    Robot* r1 = robot->getRobot();
//    cout << "r1 address=" << r1 << endl;
//    Robot* r2 = robot->getRobot();
//    cout << "r2 address=" << r2 << endl;
//    return 0;
//}


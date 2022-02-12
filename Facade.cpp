//
// Created by Naor Alkobi on 11/02/2022.
//

using namespace std;
#include "iostream"
#include <string>

class Subsystem1 {
public:
    std::string Operation1() const {
        return "Subsystem1: Ready!\n";
    }
};

class Subsystem2 {
public:
    std::string Operation1() const {
        return "Subsystem2: Get ready!\n";
    }
};

class Facade {
protected:
    Subsystem1 *subsystem1_;
    Subsystem2 *subsystem2_;
public:

    Facade(Subsystem1 *subsystem1 = nullptr, Subsystem2 *subsystem2 = nullptr) {
        this->subsystem1_ = subsystem1 ?: new Subsystem1;
        this->subsystem2_ = subsystem2 ?: new Subsystem2;
    }
    ~Facade() {
        delete subsystem1_;
        delete subsystem2_;
    }

    std::string Operation() {
        std::string result = "Facade initializes subsystems:\n";
        result += this->subsystem1_->Operation1();
        result += this->subsystem2_->Operation1();
        return result;
    }
};

//int main(){
//    Subsystem1* subsystem1 = new Subsystem1();
//    Subsystem2* subsystem2 = new Subsystem2();
//    Facade* facade = new Facade(subsystem1, subsystem2);
//    cout << facade->Operation();
//
//    delete facade;
//    return 0;
//}
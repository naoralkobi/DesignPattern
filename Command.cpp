//
// Created by Naor Alkobi on 11/02/2022.
//

#include <string>
#include "iostream"
using namespace std;

class Command{
public:
    ~Command() {}
    virtual void execute(){}
};

class Receiver{
public:
    ~Receiver() {}
    virtual void operation(string str){
        cout << str;
    }
};

class Invoker{
    Command* cmd;
public:
    ~Invoker() {delete cmd;}
    virtual void setCommand(Command* command){
        this->cmd = command;
    }
    virtual void executeCommand(){
        this->cmd->execute();
    }
};

class turnOn : public Command{
    Receiver* light;
public:
    ~turnOn() {delete light;}
    turnOn(Receiver* l) : light(l){}
    virtual void execute(){
        this->light->operation("The light is on\n");
    }
};

class turnOff : public Command{
    Receiver* light;
public:
    ~turnOff() {delete light;}
    turnOff(Receiver* l) : light(l){}
    virtual void execute(){
        this->light->operation("The light is off\n");
    }
};

//int main(){
//    Receiver* receiver = new Receiver();
//    turnOn* on = new turnOn(receiver);
//    turnOff* off = new turnOff(receiver);
//    Invoker* invoker = new Invoker();
//
//    invoker->setCommand(on);
//    invoker->executeCommand();
//    invoker->setCommand(off);
//    invoker->executeCommand();
//
//    return 0;
//}
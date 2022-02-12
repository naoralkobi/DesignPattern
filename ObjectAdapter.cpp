//
// Created by Naor Alkobi on 11/02/2022.
//

using namespace std;
#include "iostream"
#include <string>

class ClientInterface{
public:
    ~ClientInterface() = default;
    virtual void operation(const string data){
        cout << data << endl;
    }
};

class Adaptee{
public:
    ~Adaptee(){}
    virtual void specialOperation(string str){
        std::reverse(str.begin(), str.end());
        cout << "special: " << str << endl;
    }
};

class Adapter : public ClientInterface{
    Adaptee* adaptee;
public:
    ~Adapter(){}
    Adapter(Adaptee* adaptee1) : adaptee(adaptee1){}
    virtual void operation(const string data){
        this->adaptee->specialOperation(data);
    }
};

//int main(){
//    Adaptee* adaptee = new Adaptee();
//    ClientInterface* clientInterface = new Adapter(adaptee);
//    ClientInterface* clientInterface1 = new ClientInterface();
//    string data = "!dlroW olleH";
//    clientInterface1->operation(data);
//    clientInterface->operation(data);
//    delete adaptee;
//    delete clientInterface;
//    return 0;
//}

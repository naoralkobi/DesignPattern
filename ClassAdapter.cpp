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
    ~Adaptee() = default;
    virtual void specialOperation(string str){
        std::reverse(str.begin(), str.end());
        cout << "special: " << str << endl;
    }
};

class Adapter : public ClientInterface, Adaptee{
public:
    ~Adapter() = default;
    virtual void operation(const string data){
        this->specialOperation(data);
    }
};

//int main(){
//    ClientInterface* clientInterface = new Adapter();
//    ClientInterface* clientInterface1 = new ClientInterface();
//    string data = "!dlroW 123olleH";
//    clientInterface1->operation(data);
//    clientInterface->operation(data);
//    delete clientInterface;
//    return 0;
//}

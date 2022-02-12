//
// Created by Naor Alkobi on 12/02/2022.
//
using namespace std;
#include "iostream"
#include <string>

class IService {
public:
    virtual void operation() const = 0;
};

class RealService : public IService {
public:
    virtual void operation() const{
        cout << "Operation in Real Service\n";
    }

};

class Proxy : public IService {
    RealService* realService;
public:
    Proxy(RealService* r) : realService(r) {};
    virtual ~Proxy() {
        delete realService;
    }
    void operation() const override{
        this->realService->operation();
    }
};

//int main(){
//    RealService* realService = new RealService();
//    Proxy* proxy = new Proxy(realService);
//    proxy->operation();
//    return 0;
//}
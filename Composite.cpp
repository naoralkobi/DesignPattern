//
// Created by Naor Alkobi on 11/02/2022.
//

using namespace std;
#include "iostream"
#include <string>
#include <vector>
#include <list>

class CycleException{};

class Graphic{
    Graphic* parent;
public:
    ~Graphic() = default;
    void setParent(Graphic* g){
        parent = g;
    }

    Graphic* getParent(){
        return parent;
    }
    virtual void add(Graphic* c){}
    virtual void remove(Graphic* c){}
    virtual void execute(){}
};

class Leaf : public Graphic{
public:
    virtual void execute(){
        cout << "I'm Leaf" << endl;
    }
};
list<Graphic*> hasFather;
class CompoundGraphic : public Graphic{
    std::list<Graphic*> children;

    bool find(Graphic* g){
        list<Graphic*>::iterator  it = hasFather.begin();
        while(it != hasFather.end()){
            if (g == *it){
                return true;
            }
            it++;
        }
        return false;
    }

    bool findMe(Graphic* g){
        if (this == g){
            return true;
        }
        CompoundGraphic* cg = dynamic_cast<CompoundGraphic*>(g);
        if (cg){
            list<Graphic*>::iterator  it = cg->children.begin();
            while(it != cg->children.end()){
                if (findMe(*it)){
                    return true;
                }
                it++;
            }
            return false;

        }
    }
public:
    virtual void add(Graphic* c){
        if(find(c) || findMe(c)){
            throw CycleException();
        }
        children.push_back(c);
        c->setParent(this);
        hasFather.push_back(c);
    }
    virtual void Remove(Graphic* c){
        children.remove(c);
        c->setParent(nullptr);
    }
    virtual void execute(){
        for(Graphic* g : children){
            if (g == children.back()){
                g->execute();
            }
        }
        cout << "I'm Composite" << endl;
    }
};

//int main(){
//    CompoundGraphic *m0 = new CompoundGraphic();
//    CompoundGraphic *m1 = new CompoundGraphic();
//    CompoundGraphic *m2 = new CompoundGraphic();
//    Graphic *e0 = new Leaf();
//    Graphic *e1 = new Leaf();
//    Graphic *e2 = new Leaf();
//    Graphic *e3 = new Leaf();
//    m0->add(e0);
//    m0->add(m1);
//    m1->add(e1);
//    m1->add(e2);
//    m1->add(m2);
//    m2->add(e3);
//    try{
//        m1->add(e0);
//    }catch(CycleException e){
//        cout<<"catch 1"<<endl;
//    }
//    try{
//        m2->add(m0);
//    }catch(CycleException e){cout<<"catch 2"<<endl;}
//    try{
//        m1->add(m1);
//    }catch(CycleException e){ cout<<"catch 3"<<endl;}
//    m0->execute();
//    delete m0;
//
//
//    return 0;
//}

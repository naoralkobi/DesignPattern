//
// Created by Naor Alkobi on 11/02/2022.
//
#include <iostream>
class Chair{

};

class CoffeeTable{

};

class ChairArtDeco : public Chair{
public:
    ChairArtDeco(){
        std::cout << "creating Chair ArtDeco\n";
    }

};

class CoffeeTableArtDeco : public CoffeeTable{
public:
    CoffeeTableArtDeco(){
        std::cout << "creating Coffee Table ArtDeco\n";
    }
};

class ChairModern : public Chair{
public:
    ChairModern(){
        std::cout << "creating Chair Modern\n";
    }

};

class CoffeeTableModern : public CoffeeTable{
public:
    CoffeeTableModern(){
        std::cout << "creating Coffee Table Modern\n";
    }
};

class ModernCreator{
public:
    ChairModern* createChair(){
        return new ChairModern();
    }
    CoffeeTableModern* createTable(){
        return new CoffeeTableModern();
    }
};

class ArtDecoCreator{
public:
    ChairArtDeco* createChair(){
        return new ChairArtDeco();
    }
    CoffeeTableArtDeco* createTable(){
        return new CoffeeTableArtDeco();
    }
};


class AbstractFactory{
    Chair* chair;
    CoffeeTable* coffeeTable;
public:
    virtual void createArtDeco(){
        ArtDecoCreator* a = new ArtDecoCreator();
        this->chair = a->createChair();
        this->coffeeTable = a->createTable();
    }
    virtual void createModern(){
        ModernCreator* a = new ModernCreator();
        this->chair = a->createChair();
        this->coffeeTable = a->createTable();
    }
};

//int main(){
//    AbstractFactory* f = new AbstractFactory();
//    f->createModern();
//    f->createArtDeco();
//    return 0;
//}

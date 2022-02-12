//
// Created by Naor Alkobi on 11/02/2022.
//

using namespace std;
#include "iostream"
#include <string>
#include <vector>

class Character {
protected:
    int _health;
public:
    Character() : _health(0) {}
    virtual ~Character() {}
    void setHealth(int h) {
        this->_health = h;
    }
    int getHealth() const{
        return this->_health;
    }
    virtual void print(int i, int j) = 0;
};

class Solider : public Character{
public:
    Solider(int h) {
        this->_health = h;
    }
    virtual ~Solider(){}
    virtual void print(int i, int j){
        cout << "soldier=" << this << " is at [" << i << ", " << j << "] with health=" << _health << endl;
    }
};

class Tank : public Character{
public:
    Tank(int health) {
        _health = health;
    }

    void print(int i, int j) override {
        cout << "tank=" << this << " is at [" << i << ", " << j << "] with health=" << _health << endl;
    }
};

class Flyweight {
protected:
    vector<Character*> characters;
    virtual Character* newCharacter(int h) = 0;

public:
    Character* getCharacter(int h){
        for (Character* c : characters){
            if (c->getHealth() == h){
                return c;
            }
        }
        Character* t = newCharacter(h);
        characters.push_back(t);
        return t;
    }
};

class SoldierFlyweight : public Flyweight{
protected:
    virtual Character* newCharacter(int h) {
        return new Solider(h);
    }
};

class TankFlyweight : public Flyweight{
protected:
    virtual Character* newCharacter(int h) {
        return new Tank(h);
    }
};

//int main(){
//
//    Character* table[4][4];
//    for (int i = 0; i < 4; i++){
//        for (int j = 0; j < 4; j++){
//            table[i][j] = nullptr;
//        }
//    }
//    Flyweight *soldierFlyweight = new SoldierFlyweight();
//    Flyweight *tankFlyweight = new TankFlyweight();
//    table[0][0] = soldierFlyweight->getCharacter(100);
//    table[1][0] = soldierFlyweight->getCharacter(100);
//    table[0][2] = tankFlyweight->getCharacter(50);
//    table[1][2] = tankFlyweight->getCharacter(50);
//    table[1][3] = tankFlyweight->getCharacter(50);
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            if (table[i][j])
//                table[i][j]->print(i, j);
//        }
//    }
//
//    cout << "\nA tank was hit: Tank [1,2] health=10\n" << endl;
//    table[1][2] = tankFlyweight->getCharacter(10);
//    cout << "After change:" << endl;
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            if (table[i][j])
//                table[i][j]->print(i, j);
//        }
//    }
//
//    return 0;
//}
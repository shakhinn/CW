//
// Created by shakhinn on 18.10.2020.
//

#ifndef OOP_OBJECT_H
#define OOP_OBJECT_H

#include "Player.h"

class Player;

class Object {
public:
    virtual bool action(Player& player) = 0;
    virtual ~Object() = default;
};

class Coin : public Object{
public:
    Coin(){};
    bool action(Player& player);
};

class Exit : public Object{
public:
    Exit(){};
    bool action(Player& player);
};

class Entrance : public Object {
public:
    Entrance(){};
    bool action(Player& player);
};

class Bomb : public Object {
public:
    Bomb(){};
    bool action(Player& player);
};

class Tele : public Object{
public:
    Tele(){};
    bool action(Player& player);
};

class Factory{
public:
    virtual ~Factory() {};
    virtual Object* factoryMethod() const = 0;
};

class CoinFactory : public Factory{
public:
    Coin* factoryMethod() const;
};

class ExitFactory : public Factory{
public:
    Exit* factoryMethod() const;
};

class EntranceFactory : public Factory{
public:
    Entrance* factoryMethod() const;
};

class BombFactory : public Factory{
public:
    Bomb* factoryMethod() const;
};

class TeleFactory : public Factory{
public:
    Tele* factoryMethod() const;
};

#endif //OOP_OBJECT_H

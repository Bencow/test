#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include "Character.h"

class Warrior : public Character
{

public :
    Warrior(std::string name);

    virtual void display()const;
    virtual void attack(Character &cible);
    virtual std::string returnType()const;




};


#endif // WARRIOR_H

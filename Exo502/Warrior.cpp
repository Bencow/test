#include "Warrior.h"

#include <iostream>

using namespace std;

Warrior::Warrior(std::string name) : Character(name, 100, 15)
{}

void Warrior::display()const
{
    cout << "Warrior " << m_name << ", life " << m_life  << endl;
}

void Warrior::attack(Character &cible)
{
    Character::attack(cible);
    cout << "Sbleee !!!" << endl;
}

string Warrior::returnType()const
{
    return "Warrior";
}






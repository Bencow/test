#include <iostream>
#include "Wizard.h"

using namespace std;


Wizard::Wizard(std::string name) : Character(name, 100, 20), m_magic(50)
{}

Wizard::~Wizard()
{}


void Wizard::attack(Character& cible)
{
    if(m_magic >= c_attackCost)
    {
        Character::attack(cible);
        m_magic -= c_attackCost;
        cout << "Pchiwo !!!" << endl;
    }
    else
    {
        cout << m_name << " n'a pas assez de magie pour attaquer" << endl;
    }
}

void Wizard::defend()
{
    if(m_magic >= c_defendCost)
    {
        m_defending = true;
        m_magic -= c_defendCost;
    }
    else
    {
        cout << m_name << " n'a pas assez de magie se defendre" << endl;
    }
}

void Wizard::display()const
{
    cout << "Wizard " << m_name << ", life " << m_life  << ", magic " << m_magic << endl;
}

string Wizard::returnType()const
{
    return "Wizard";
}



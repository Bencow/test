#include <iostream>
#include "Elfe.h"

using namespace std;


Elfe::Elfe(string name) : Character(name, 100 , 10), m_arrow(20)
{}



void Elfe::attack(Character& cible)
{
    //If elfe have enough arrow
    if(m_arrow >= 1)
    {
        //Call of Character's attack
        Character::attack(cible);
        m_arrow--;
        cout << "Fschiou !!!" << endl;
    }
    else
    {
        cout << m_name << " I don't have enough arrow to attack" << endl;
    }
}

void Elfe::defend()
{
    m_defending = true;
}

void Elfe::display()const
{
    cout << "Elfe " << m_name << ", life " << m_life  << ", arrow " << m_arrow << endl;
}

string Elfe::returnType()const
{
    return "Elfe";
}



#include <iostream>
#include "Character.h"

using namespace std;

Character::Character() : m_life(100), m_dead(false), m_defending(false)
{
    m_isAttacked[0] = NULL;
    m_isAttacked[0] = NULL;
}

Character::Character(std::string name, int life, int attack) :
m_name(name), m_life(life), m_attack(attack), m_defending(false), m_dead(false)
{
    m_isAttacked[0] = NULL;
    m_isAttacked[0] = NULL;
}

Character::~Character()
{
    //dtor
}

void Character::attack(Character& cible)
{
    //Si la cible à moins de point de vie que on a de point d'attaque
    if(cible.Getlife() - m_attack <= 0)
    {
        cible.Setlife(0);
        cible.Setdead(true);
    }
    else
    {
        //on enlève autant de point de vie à la cible que this a de point d'attaque
        cible.Setlife(cible.Getlife() - m_attack);
    }
}

void Character::display()const
{
    cout << "Charater " << m_name << ", life " << m_life  << endl;
}

string Character::returnType()const
{
    return "Character";
}

void Character::setAttacked(int n, Character* attaquant)
{
    m_isAttacked[n] = attaquant;
}






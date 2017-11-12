#include "Enemy.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Enemy::Enemy(string name) : Character(name, 200, 20)
{}

Enemy::~Enemy()
{}

void Enemy::attack(Character& cible)
{
    Character::attack(cible);
    cout << "BAM !" << endl;
}


void Enemy::display()const
{
    cout << "Enemy " << m_name << ", life " << m_life  << endl;

}


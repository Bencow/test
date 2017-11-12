#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"


class Enemy : public Character
{
    public:
        Enemy(std::string name);
        virtual ~Enemy();

        virtual void attack(Character& cible);
        virtual void display()const;




    protected:

    private:
};

#endif // ENEMY_H

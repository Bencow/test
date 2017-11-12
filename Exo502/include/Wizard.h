#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "Character.h"


class Wizard : public Character
{
    private:
        int m_magic;
        static const int c_attackCost = 10;
        static const int c_defendCost = 5;

    public:
        Wizard(std::string name);
        ~Wizard();

        int Getmagic() { return m_magic; }
        void Setmagic(int val) { m_magic = val; }

        const int GetattackCost() { return c_attackCost; }
        const int GetdefendCost() { return c_defendCost; }


        virtual void attack(Character& cible);
        virtual void display()const;
        virtual std::string returnType()const;
        void defend();


};

#endif // WIZARD_H

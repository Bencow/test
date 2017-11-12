#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character
{
    protected:
        std::string m_name;
        int m_life;
        int m_attack;
        bool m_dead;
        Character* m_isAttacked[2];
        bool m_defending;

    public:
        //Constructeurs et destructeurs
        Character();
        Character(std::string name,int life, int attack);
        virtual ~Character();

        //acceseurs
        int Getlife() { return m_life; }
        void Setlife(int val) { m_life = val; }
        bool GetDefending() { return m_defending; }
        void SetDefending(bool val) { m_defending = val; }
        int GetattackCost() { return m_attack; }
        void SetattackCost(int val) { m_attack = val; }
        bool Getdead() { return m_dead; }
        void Setdead(bool val) { m_dead = val; }

        void setAttacked(int n, Character* attaquant);
        Character *getAttacked(int n) { return m_isAttacked[n]; }
        //Methodes
        virtual void attack(Character& cible);
        virtual void display()const;
        virtual std::string returnType()const;


};

#endif // CHARACTER_H

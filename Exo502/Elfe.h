#ifndef ELFE_H
#define ELFE_H

#include "Character.h"

class Elfe : public Character
{
private:
    int m_arrow;

public:
    Elfe(std::string name);

    virtual void display()const;
    virtual void attack(Character &cible);
    virtual std::string returnType()const;
    void defend();

};

#endif

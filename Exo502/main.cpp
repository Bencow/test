#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Character.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Elfe.h"
#include "Enemy.h"

using namespace std;

Character* choiceCharacter()
{
    Character * newOne;
    int choiceChar1(0);

    cout << "1. Warrior" << endl
         << "2. Wizard " << endl
         << "3. Elf "<< endl;
    cin >> choiceChar1;


    if(choiceChar1 == 1)
    {
        newOne = new Warrior("Lancelot");
    }
    else if(choiceChar1 == 2)
    {
        newOne = new Wizard("Merlinux");
    }
    else if(choiceChar1 == 3)
    {
        newOne = new Elfe("Sylvain");
    }
    else
        cout << "error systeme";

    return newOne;
}

void displaySquad(Character *Squad[2])
{
    Squad[0]->display();
    Squad[1]->display();
}

void selectActions(Character *Squad[2], Enemy& PuDuCul)
{
    int actionPlayer(5), enemyAction(5);

    ///Player 1
    //if it's a warrior he can't defend so he dosen't have the choice
    if(Squad[0]->Getdead() == false)
    {
    if(Squad[0]->returnType() == "Warrior")
    {
        PuDuCul.setAttacked(0, Squad[0]);
        cout << "Your first character attack because it's a warrior" <<endl;
    }
    else
    {
        cout << "Choose an action for your first character" << endl
             << "0. To attack" << endl
             << "1. To defend" << endl;
        cin >> actionPlayer;

        if(actionPlayer == 0)//Attack
        {
            PuDuCul.setAttacked(0, Squad[0]);
            Squad[0]->SetDefending(false);
            cout << "Your first character attack" <<endl;
        }
        else if(actionPlayer == 1)//Defend
        {
            Squad[0]->SetDefending(true);
            cout << "Your first character defend" <<endl;
        }
    }
    }

    ///Player 2
    if(Squad[1]->Getdead() == false)
    {
    //if it's a warrior he can't defend so he dosen't have the choice
    if(Squad[1]->returnType() == "Warrior")
    {
        PuDuCul.setAttacked(1, Squad[1]);
        cout << "Your second character attack because it's a warrior" <<endl;

    }
    else
    {
        cout << "Choose an action for your second character" << endl
             << "0. To attack" << endl
             << "1. To defend" << endl;
        cin >> actionPlayer;

        if(actionPlayer == 0)
        {
            PuDuCul.setAttacked(1, Squad[1]);
            Squad[0]->SetDefending(false);
            cout << "Your second character attack" <<endl;
        }
        else if(actionPlayer == 1)
        {
            Squad[0]->SetDefending(true);
            cout << "Your second character defend" <<endl;
        }
    }
    }

    /// Enemy
    enemyAction = (rand()%2);

    //Defending
    if(enemyAction == 0)
    {
        PuDuCul.SetDefending(true);
        cout << "PuDuCul defend" <<endl;
    }
    //Attacking
    else if(enemyAction == 1)
    {
        //Select a guy to attack

        if(Squad[0]->Getdead())//if the first one is dead

        {
            Squad[1]->setAttacked(0, &PuDuCul);
            cout << "PuDuCul attack your second character" <<endl;
        }
        else if(Squad[1]->Getdead())//if the second one is dead
        {
            Squad[0]->setAttacked(0, &PuDuCul);
            cout << "PuDuCul attack your first character" <<endl;
        }
        else////if there're both alive
        {
            if((rand()%2) == 0)
            {
                Squad[0]->setAttacked(0, &PuDuCul);
                cout << "PuDuCul attack your first character" <<endl;
            }
            else
            {
                Squad[1]->setAttacked(0, &PuDuCul);
                cout << "PuDuCul attack your second character" <<endl;
            }
        }
    }
}

void fight(Character *Squad[2], Enemy &puDuCul)
{
    ///The Enemy is attacked
    //If enemy defend, he's not heart
    if(puDuCul.GetDefending() == true)
    {
        cout << "puDuCul defend so he can't take any damage" << endl;
    }
    else//he takes damage
    {
        if(puDuCul.getAttacked(0) != NULL)
        {
            (puDuCul.getAttacked(0))->attack(puDuCul);

        }
        if(puDuCul.getAttacked(1) != NULL)
        {
            (puDuCul.getAttacked(1))->attack(puDuCul);
        }
    }
    ///The Heroes are attacked
    ///The 1st one
    //If he's attacked
    if((Squad[0]->getAttacked(0)) != NULL)
    {
        //If he defends
        if(Squad[0]->GetDefending() == true)
        {
            //Reinitialization of array of pointers for the next round
            Squad[0]->setAttacked(0, NULL);
            cout << "your first character defend so he can't take any damage" << endl;
        }
        else//if he doesn't defend
        {
            (Squad[0]->getAttacked(0))->attack(*Squad[0]);
        }
    }

    ///The 2nd one
    //If he's attacked
    if(Squad[1]->getAttacked(0) != NULL)
    {
        //If he defends
        if(Squad[1]->GetDefending() == true)
        {
            //Reinitialization of array of pointers for the next round
            Squad[1]->setAttacked(0, NULL);
            cout << "your first character defend so he can't take any damage" << endl;
        }
        else//if he doesn't defend
        {
            (Squad[1]->getAttacked(0))->attack(*Squad[1]);
        }
    }

    ///Reinitialization of states of all characters for the next round
    puDuCul.setAttacked(0, NULL);
    puDuCul.setAttacked(1, NULL);
    puDuCul.SetDefending(false);

    Squad[0]->SetDefending(false);
    Squad[0]->setAttacked(0, NULL);

    Squad[1]->SetDefending(false);
    Squad[1]->setAttacked(0, NULL);
}


bool gameIsOver(Character* Squad[2], Enemy *puDuCul)
{
    if( (Squad[0]->Getdead()) && (Squad[1]->Getdead()) )
    {
        cout << "you loose" <<endl;
        return true;
    }
    else if(puDuCul->Getdead())
    {
        cout << "you win" <<endl;
        return true;
    }
    else
        return false;
}

int main()
{
    srand(time(NULL));

    Character* Squad[2];
    Enemy PuDuCul("PuduCul");

    cout << "Select your first character :" << endl;
    Squad[0] = choiceCharacter();
    cout << "Select your second character :" << endl;
    Squad[1] = choiceCharacter();

    displaySquad(Squad);

    while(!gameIsOver(Squad, &PuDuCul))
    {
        cout <<endl;
        selectActions(Squad, PuDuCul);
        fight(Squad, PuDuCul);
        displaySquad(Squad);
        PuDuCul.display();
    }

    return 0;
}

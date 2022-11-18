//
// Created by Stephanie Agbim on 11/03/2022.
//

#include "Battle.h"
battleArr<std::string> Battle::call;  //Call: stands for the names given to the objects

void Battle::initCall() {  //adding new elements(objects) at the top of the stack in the other of how they come
    Battle::call.push("Poison-Ivy  ✾ ✾");
    Battle::call.push("  _  __________=__  \n"
                      "        @@@@@([____]_____() \n"
                      "  _/##|-[____]\n"
                      " /     /(( )            *Revolvers* \n"
                      "/____|'----'\n"
                      "££____/");
    Battle::call.push("Assassin sword             "
                      "            /||                    \n"
                      "/vvvvvvvvvvvv #--------------------------------------,\n"
                      "`^^^^^^^^^^^^ /=====================================/ \n"
                      "            ##/  ");
    Battle::call.push("knives  =={======-");
    Battle::call.push("Grenade  "
                      " ,-*\n"
                      "(_)");
}
Battle::Battle()
      :Object()
{
    this->hp = 0;  //if the character is healthy enough to hold the weapon setting everythin to 0
    this->hpMax = 0;
}

Battle::Battle(int level, int quality) //the quality of the object should be determined on the level the player is in-the lower the level, the lesser the quality
       :Object(objectClass::BATTLE, level, quality)
{
    this->hpMax = rand() % level + (quality ^ 2);
    this->hpMax += (quality ^ 2) + 1;
    this->setName(Battle::call[rand() % Battle::call.size()]);


    if (quality == 5)
        this->hpMax += level * 2;
    else if (quality == 10)
        this->hpMax += level * 4;
    this->hp = this->hpMax/2;
}
Battle::Battle(int hp, int hpMax, std::string name, int level, int price, int quality)
     : Object(objectClass::BATTLE, name, level, price, quality) //Inheritance from the Object class
{
    this->hp = hp;
    this->hpMax = hpMax;
}

Battle::~Battle() {

}

Battle* Battle::copy() const { //returns 'Weapons' battles, initialize the memory returns its address to the pointer variable, object(battle) will stay in memory until deleted
    return new Battle(*this);
}


std::string Battle::convert() const //converting attributes to string
{
    std::string str =
            this->getName()
            + " | Lvl: "
            + std::to_string(this->getLevel())
            + " | Quality: "
            + std::to_string(this->getQuality())
            + " | Damage: "
            + std::to_string(this->hp)
            + " - "
            + std::to_string(this->hpMax);

    return str;
}

std::string Battle::convertSaved() const //saving it(attributes)
{
    std::string str =
            std::to_string(this->getObjectClass())
            + " "
            + this->getName()
            + " "
            + std::to_string(this->getLevel())
            + " "
            + std::to_string(this->getQuality())
            + " "
            + std::to_string(this->getPrice())
            + " "
            + std::to_string(this->hp)
            + " "
            + std::to_string(this->hpMax)
            + " ";

    return str;
}

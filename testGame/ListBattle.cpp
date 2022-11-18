//
// Created by Stephanie Agbim on 11/03/2022.
//
#include "ListBattle.h"

battleArr<std::string>ListBattle::call;
void ListBattle::initCall()
{
    ListBattle::call.push("Tear gas");
    ListBattle::call.push("Invisible cloak");
    ListBattle::call.push("Bullet proof");
    ListBattle::call.push("Parachutes");
    ListBattle::call.push("   |`-._/+_.-`|          Oxygen Tank\n"
                          "           |    ||    |\n"
                          "           |___o()o___|\n"
                          "           |__((<>))__|\n"
                          "           @  o||/o   /\n"
                          "            @   ||   /\n"
                          "             @  ||  /\n"
                          "         @22  '.||.'\n"
                          "                ``");

}
ListBattle::ListBattle()
       :Object(){
    this->variety = -1;
    this->defend = 0;
}
ListBattle::ListBattle(int level, int quality)
            :Object(objectClass::LISTBATTLE, level, quality)
{
    this->defend = rand() % (level * (quality*2));
    this->defend += (quality + 2) * 3;
    this->variety = rand() * 4;

    switch (this->variety)
    {
        case protection::SHIP:
            this->varietyStr = "Ship";
                 break;
        case protection::CREW:
            this->varietyStr = "Crew";
                 break;
        case protection::PLAYER:
            this->varietyStr = "Player";
                  break;
        default:
            this->varietyStr = "PLAYER GENERATED ERROR";
                   break;
    }
    this->setName(ListBattle::call[rand() % ListBattle::call.size()]);
    if (quality == 5)
        this->defend += level * 2;
    else if (quality == 10)
        this->defend += level * 4;
}

ListBattle::ListBattle(int variety, int defend, std::string name, int level, int price, int quality)
            : Object(objectClass::LISTBATTLE, name, level, price, quality)
{
    this->variety = variety;
    this->defend = defend;

}
ListBattle::~ListBattle()  {

}
ListBattle* ListBattle::copy()const
{
    return new ListBattle(*this);

}

std::string ListBattle::convert() const

{
    std::string str =
            this->getName()
            + " | Variety: "
            +this->varietyStr
            + " | Lv1: "
            + std::to_string(this->getLevel())
            + " | Quality: "
            + std::to_string(this->getQuality())
            + " | Defence:  "
            + std::to_string(this->defend);


    return str;
}

std::string ListBattle::convertSaved() const
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
            + std::to_string(this->defend)
            + " "
            + std::to_string(this->variety)
            + " ";

    return str;
}


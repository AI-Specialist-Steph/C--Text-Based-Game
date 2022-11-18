//
// Created by Stephanie Agbim on 11/03/2022.
//

#ifndef TESTGAME_BATTLE_H
#define TESTGAME_BATTLE_H
#include <string>
#pragma once
#include "Object.h"
#include "battleArr.h"
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>


class Battle:public Object
{
private:
    int hp; //health point will act has the damages received which will affect "medical"
    int hpMax;
public:
    Battle();
    Battle(
            int level,
            int quality
            );
    Battle(
            int hp,
            int hpMax,
            std::string name,
            int level,
            int price,
            int quality
            );

    virtual ~Battle();

    virtual Battle* copy()const;

    std::string convert()const;
    std::string convertSaved()const;

    inline int getHp()const {return this->hp; }
    inline int getHpMax()const {return this->hpMax; }



    static battleArr<std::string> call;
    static void initCall(); //init stands for initialisation, initialising the names of battles(objects)
};

//Declaring all attributes,variables and functions that will be implemeted in the .cpp file

#endif //TESTGAME_BATTLE_H

//
// Created by Stephanie Agbim on 27/02/2022.
//

#ifndef ENEMIES_H
#define ENEMIES_H

#pragma once
#include<stdlib.h>
#include <string>
#include "BountyHunt.h"
#include "Object.h"
#include "Battle.h"
#include "ListBattle.h"
#include "battleArr.h"
#include "Manage.h"

class Enemies
{
public:


    Enemies(int level = 0);

    virtual~Enemies();

    inline bool isOn() { return this->level > 0; }
    std::string getCcString()const;
    void  Die(int impact);

    inline int getLevel()const {return this->level; }
    inline int getBrave()const {return this->brave; }
    inline int getBrave_m()const {return this->brave_m; }
    inline int getDefence()const {return this->defence; }
    inline int getHit()const {return this->hit; }
    inline int getImpact()const {return this->brave + this->brave_m; }





private:
    int level;

    int brave;
    int brave_m;
    int defence;
    int percentDrop;
    int hit;

};

#endif
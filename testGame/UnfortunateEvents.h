//
// Created by Stephanie Agbim on 14/03/2022.
//

#pragma once

#include <stdlib.h>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

#include"mainCharacter.h"
#include"Enemies.h"
#include"BountyHunt.h"





class UnfortunateEvent
{
private:

public:
    UnfortunateEvent();
    virtual ~UnfortunateEvent();
    void createUnfortunateEvent(mainCharacter &maincharacter, battleArr<Enemies>& enemies);



    void bandits_attack(mainCharacter &maincharacter, battleArr<Enemies>& enemies); //enemies
    void bountyHunt_mission (mainCharacter &maincharacter); //bounty hunt



    static int listOfUnfortunateEvents;

};

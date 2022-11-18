//
// Created by Stephanie Agbim on 07/03/2022.
//


#ifndef CREWMANAGER_H
#define CREWMANAGER_H

#pragma once
#include "Character.h"

#include <array>


class CrewManager
{
public:
    static void HireCrewMember(int crewID);
    static bool crewFull();
    static void displayMemberInfo();
    static void handleHire();
    static std::string SelectCrew;
    static int GetCredit();
    //void initCrewManager();

private:
    static int credit;
    static std::array<Character, 10> crewOptions;
    static std::array<Character, 4> crew;
};

#endif

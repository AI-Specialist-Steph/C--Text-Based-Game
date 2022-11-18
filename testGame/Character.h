//
// Created by Stephanie Agbim on 07/03/2022.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once
#include <string>
#include <iostream>
#include <math.h>


// These are AI characters having similar attributes to the main user

//functions


class Character
{
public:
    Character(std::string name, std::string sex, std::string age, std::string birthPlace, std::string previousJob,
              std::string profession, std::string trait, int level, int navigation, int shooting ,int strength, int medical,
              int engineeringSkill, int fighting, int exp, int hireCost);

    Character();

    std::string GetName();

    ~Character();
    int GetHireCost();

    void printStats() const;


private:
    std::string name;
    std::string sex;
    std::string age;
    std::string birthPlace;
    std::string previousJob;
    std::string profession;
    std::string trait;
    int level;
    int navigation;
    int shooting ;
    int strength ;
    int medical;
    int engineeringSkill;
    int fighting;
    int exp;
    int expNext;
    int hireCost;
};


#endif

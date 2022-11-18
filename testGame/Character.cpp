//
// Created by Stephanie Agbim on 07/03/2022.
//


#include "Character.h"

Character::Character(std::string name, std::string sex, std::string age, std::string birthPlace, std::string previousJob,
                     std::string profession, std::string trait, int level, int navigation, int shooting ,int strength, int medical,
                     int engineeringSkill, int fighting, int exp, int hireCost)
{
    this->name = name;
    this->sex = sex;
    this->age =age;
    this->birthPlace = birthPlace;
    this->previousJob = previousJob;
    this->profession = profession;
    this->trait = trait;
    this->level = level;
    this->navigation = navigation;
    this->shooting = shooting ;
    this->strength = strength;
    this->medical = medical;
    this->engineeringSkill = engineeringSkill;
    this->fighting = fighting;
    this->medical = medical;
    this->exp = exp;
    this->expNext = (30*2)+(pow(level,2)+
                            6*pow(level,2) -
                            (16* level)-8);
    this->hireCost = hireCost;
}

Character::~Character()
{

}

Character::Character()
{
    name = " ";
}

std::string Character::GetName()
{
    return name;
}

void Character::printStats() const
{
    std::cout << "=  Choose crew to hire =" << std::endl;
    std::cout << std::endl;
    std::cout << "= Name: " << this->name << std::endl;
    std::cout << "= Age: " << this->age << std::endl;
    std::cout << "= Birth Place: " << this->birthPlace << std::endl;
    std::cout << "= Previous Job(s): " << this->previousJob << std::endl;
    std::cout << "= Profession: " << this->profession << std::endl;
    std::cout << "= Trait: " << this->trait << std::endl;
    std::cout << "= Level: " << this->level << std::endl;
    std::cout << "= Navigation: " << this->navigation << std::endl;
    std::cout << "= Shooting: " << this->shooting << std::endl;
    std::cout << "= Medical: " << this->medical << std::endl;
    std::cout << "= Engineering Skill: " << this->engineeringSkill << std::endl;
    std::cout << "= Fighting: " << this->fighting << std::endl;
    std::cout << "= Experience Points: " << this->exp << std::endl;
    std::cout << "= Exp Next Level: " << this->expNext << std::endl;
    std::cout << "= Hire Cost: " << this->hireCost << std::endl;
    std::cout << std::endl;
}

int Character::GetHireCost()
{
    return hireCost;
}
//implentation of character activities


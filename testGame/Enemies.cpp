//
// Created by Stephanie Agbim on 27/02/2022.
//
//complete
#include "Enemies.h"

Enemies::Enemies(int level)
{
    this->level = level;
    this->brave = this->level * 7;
    this->brave_m = this->level * 3;
    this->percentDrop = rand() % 20 ;
    this->defence = rand() % 20 ;
    this->hit = 2 * 40;




}

Enemies::~Enemies()
{

}
std::string Enemies::getCcString()const
{
    return "Level: " + std::to_string(this->level) + "\n" +
           "Damage: " + std::to_string(this->brave) + " / " + std::to_string(this->brave_m) + "\n" +
           "Defence: " + std::to_string(this->defence) + "\n" +
           "Drop Rate: " + std::to_string(this->percentDrop) + "\n" +
           "Hit: " + std::to_string(this->hit) + "\n";


}

void Enemies::Die(int impact) {
    this->hit -= impact;

    if (this->hit <= 0)
    {
        this->hit = 0;
    }

}







//
// Created by Stephanie Agbim on 11/03/2022.
//
#include "Object.h"

Object::Object()
{
    this->objectClass = -1;
    this->name = "NONE";
    this->level = 0;
    this->price = 0;
    this->quality = -1;

}
Object::Object(int objectClass, int level, int quality)
{
    this->name = "OBJECT";
    this->level = rand() % (level+1) +2;
    this->quality = quality;
    this->price = (this->level + this->quality) * 5;
    this->objectClass = objectClass;

}

Object::Object(int objectClass, std::string name, int level, int price, int quality) {
    this->objectClass - objectClass;
    this->name = name;
    this->level = level;
    this->price= price;
    this->quality = quality;

}

Object::~Object()
{

}



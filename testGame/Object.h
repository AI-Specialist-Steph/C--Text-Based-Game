//
// Created by Stephanie Agbim on 11/03/2022.
//

#ifndef TESTGAME_OBJECT_H
#define TESTGAME_OBJECT_H
#pragma once
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>


#include <stdio.h>
#include <string>

enum objectClass {BATTLE = 0, LISTBATTLE};

class Object{
private:
    int objectClass;
    std::string name;
    int level;
    int price;
    int quality;
public:
    Object();
    Object(
            int objectClass,
            int level,
            int quality
            );
    Object(
            int objectClass,
            std::string name,
            int level,
            int price,
            int quality
            );
    virtual ~Object();

    inline std::string testPrint() const {return this->name; }

    virtual Object* copy() const = 0;
    virtual std::string convert()const = 0;
    virtual std::string convertSaved() const = 0;

    inline const std::string& getName() const {return this->name; }
    inline const int& getLevel() const {return this-> level; }
    inline const int& getPrice() const {return this->price; }
    inline const int& getQuality() const {return this->quality; }
    inline const int& getObjectClass() const {return this->objectClass; }

    inline void setName(std::string name) {this-> name = name; }
};
enum quality{
    COMMON = 0,
    RARE
};
#endif //TESTGAME_OBJECT_H

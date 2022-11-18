//
// Created by Stephanie Agbim on 11/03/2022.
//

#ifndef TESTGAME_BOUNTYHUNT_H
#define TESTGAME_BOUNTYHUNT_H
#pragma once

#include "Object.h"
#include "Battle.h"
#include "ListBattle.h"
#include "battleArr.h"
#include "Manage.h"


#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

struct MyException : public std::exception  //here because of the error message; lbi++: terminating with uncaught exception of type char const*
{
protected:
    const char *errorDetected;
public:
    MyException (const char* str){
        errorDetected = str;
    }
    const char * what () throw ()
    {
        return errorDetected;
    }

};


class BountyHunt
{
private:
    std::string dialogue;
    std::vector<std::string> playerInput;
    int shipVolition; //choice/answer player picks will affect the outcome of mission
public:
    BountyHunt(std::string cody);
    virtual ~BountyHunt(); //determining the function that will be invoked at the runtime
    std::string getCcString();  //convert to string

    inline const int& getShipVoli()const {return this->shipVolition; }


};
#endif //TESTGAME_BOUNTYHUNT_H

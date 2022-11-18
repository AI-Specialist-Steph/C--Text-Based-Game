//
// Created by Stephanie Agbim on 27/02/2022.
//

#ifndef GAMESHIP_H
#define GAMESHIP_H


#include "mainCharacter.h"
//#include <string>
#include <iostream>
#include <iomanip> //manipulates output of c++ program
#include <ctime>
#include <vector>
#include "BountyHunt.h"
#include "Object.h"
#include "UnfortunateEvents.h"
#include "Battle.h"
#include "ListBattle.h"
#include "battleArr.h"
#include "Enemies.h"
#include "Manage.h"


using namespace std;

class Gameship
{
public:
    Gameship();
    virtual ~Gameship();


    //functions
    void mainInterface();
    void initGameship();
    void mission();
    void boost();
    void mainStart();







    //examine/getters
    inline bool getStart() const { return this->start; }



private:
    int choice; //players choice
    bool start;

    battleArr<Enemies> enemies;

    //mainCharacter
    mainCharacter maincharacter;







};

#endif

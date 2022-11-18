//
// Created by Stephanie Agbim on 27/02/2022.
//

#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <iostream>
#include <string>
#pragma once
#include <iomanip>
#include "Manage.h"
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>


#include "CrewManager.h"

class mainCharacter
{
public:
    mainCharacter();
    mainCharacter(std::string name, int missionCovered_dist, int creditAccount, int level, int exp,
    int strength, int statPoints, int hp, int speed, int intelligence);
    virtual ~mainCharacter();

    //functions

    void initialise (const std::string name);
    void printMaincStats() const;
    void levelUp();
    void  equipObject(unsigned index);
    void update();
    void addUpdate(int num, int stat);
    inline void resetHP() {this->hp = this->hpMax; }
    void addObject(const Object &object) {this->manage.addObject(object); }
    void removeObject(const int index);

    //const Object& getObject(const int index);




    //getters
    inline const int& getBrave() const {return this->brave; }
    inline const int& getBrave_m() const {return this->brave; }
    //inline const int& getImpact() const {return rand()% (this->brave_m + this->battle.getHpMax()) + (this->brave + this->battle.getHp()); }

    inline const int& getMissionCovered_dist() const {return this-> missionCovered_dist; }
    inline const std::string& getName() const{ return this->name;}  //ref to OOP
    inline const int& getLevel() const { return this->level; }
    inline const int& getStatPoints() const {return this->statPoints;}
    inline const int& getExp() const { return this->exp;}
    inline const int& getExpNext() const { return this->expNext;}
    inline const int& getHP() const { return this->hp;}
    inline const int& getHPMax() const { return this->hpMax;}
    inline const int& getBoost() const { return this->boost;}
    inline const bool isOn() {return this->hp > 0; }
    inline const int& getDefence() const { return this->defence;}
    inline const int& getProof() const {return this->defence; }
    //   getProof(adds to defence)
    inline const int getManageSize()const {return this->manage.size(); }
    inline const int& getCreditAccount() const{ return this-> creditAccount;}
    inline const int& getFighting() const {return this-> fighting; }

    //setters
    inline void setMissionCovered_dist(const int& distance){this->missionCovered_dist = distance; }
    inline void mission() {this->missionCovered_dist++; }
    inline void gainExp(const int exp) {this->exp += exp; }
    inline void gainCreditAccount(const int creditAccount) {this->creditAccount += creditAccount; }
    inline void pay(const int creditAccount) {this->creditAccount -=creditAccount; }
    void Die(const int impact);
    inline void setBattle(Battle battle) {this->battle = battle; }
    inline void setListBattleShip(ListBattle listBattle_ship) { this->listBattle_ship = listBattle_ship; }
    inline void setListBattleCrew(ListBattle listBattle_crew) { this->listBattle_ship = listBattle_crew; }
    inline void setListBattlePlayer(ListBattle listBattle_player) { this->listBattle_ship = listBattle_player; }





//getDefence for main character file amd getDefend for list battle file


private:
    std::string name; //user will get a chance to name the player
    int level; //as the name implies
    int exp; //experience point
    int expNext; //for next level
    int hp; //healthPoint will also act as damage received by player
    int hpMax; //health points can also act as medical points
    int boost; // This is a need for the player (oxygen tank, food, water etc ) and anything that's needed
    int defence; //quality of player


    int strength; //quality of player
    int intelligence; //quality of player
    int brave;  //brave enough to face off an attacker?
    int brave_m; //max of brave
    int speed; //qualities of player
    int resilient; //quality of player

    int navigation; //quality of player
    int shooting;  //quality of player
    int engineeringSkill;  //quality of player
    int fighting;  //quality of player
    int creditAccount; //player has 2 accounts-his current account which is called credit-implemented in crew manager
    //and his savings account creditAccount which he could use to get a boost or anything personal after protecting the ship


    int mainCharStatPoints;
    int statPoints;  //this is basically the sum of everything in the private attribute


    int missionCovered_dist; //Progression metre-kind of like the position of the player
    Manage manage;
    Battle battle; //weapons needed for combat-does not work how i expected it to
    ListBattle listBattle_crew;  //mainCharacter to inherit this during the actual game
    ListBattle listBattle_ship;
    ListBattle listBattle_player;





};

#endif
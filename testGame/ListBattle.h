//
// Created by Stephanie Agbim on 11/03/2022.
//

#ifndef TESTGAME_LISTBATTLE_H
#define TESTGAME_LISTBATTLE_H
#include "Object.h"
#include "battleArr.h"
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>


enum protection { SHIP = 0, CREW, PLAYER};

class ListBattle :
        public Object
{
private:
    int variety;
    std::string varietyStr;
    int defend;
public:
    ListBattle();
    ListBattle(
            int level,
            int quality
            );
    ListBattle(
            int variety,
            int defend,
            std::string name,
            int level,
            int price,
            int quality
            );
    virtual ~ListBattle();

    virtual ListBattle* copy()const;

    std::string convert()const;
    std::string convertSaved() const;

    inline int getDefend()const{return this->defend; }
    inline int getVariety()const{return this->variety; }



    static battleArr<std::string> call;
    static void initCall();


};
#endif //TESTGAME_LISTBATTLE_H

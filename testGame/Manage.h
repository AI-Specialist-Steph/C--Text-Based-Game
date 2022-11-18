//
// Created by Stephanie Agbim on 11/03/2022.
//

#ifndef TESTGAME_MANAGE_H
#define TESTGAME_MANAGE_H
#include "Battle.h"  //weapon
#include "Object.h" //item- weapons and stuff to survive in space"
#include "ListBattle.h"



class Manage{
private:
    int maximum;
    int items;
    Object **objectArr;
    void max();
    void initialise(const int from = 0);

public:
    Manage();
    ~Manage();
    Manage(const Manage &obj);
    inline int size()const { return this->items; }
    Object& operator[](const int index);
    void operator=(const Manage &obj);
    void addObject(const Object &object);
    void removeObject(int index);
    inline void testPrint() const
    {
        for (size_t i = 0; i < this->items; i++)
        {
            std::cout << this->objectArr[i]->testPrint() << std::endl;
        }
    }
};


#endif //TESTGAME_MANAGE_H

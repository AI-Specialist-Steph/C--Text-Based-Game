//
// Created by Stephanie Agbim on 11/03/2022.
//

//ACTS AS A CONTAINER FOR BATTLE AND LISTBATTLE FILES
#include "Manage.h"

Manage::Manage()
{
    this->maximum = 10;
    this->items = 0;
    this->objectArr = new Object*[maximum];
    this->initialise();
}

Manage::~Manage() {
    for (size_t i = 0; i < this->items; i++)
    {
        delete this->objectArr[i];
    }
    delete[] this->objectArr;

}
Manage::Manage(const Manage &obj)
{
    this->maximum = obj.maximum;
    this->items = obj.items;
    this->objectArr = new Object*[this->maximum];

    for (size_t i = 0; i < this->items; i++)
    {
        this->objectArr[i] = obj.objectArr[i]->copy();
    }
    initialise(this->items);
}
Object& Manage::operator[](const int index) {
    if (index < 0 || index >= this->items)
             throw("WRONG INPUT ! :( ");
    return *this->objectArr[index];
}

void Manage::operator=(const Manage &obj)
{
    for (size_t i = 0; i < this->items; i++)
    {
        delete this->objectArr[i];
    }
    delete[] this->objectArr;


    this->maximum = obj.maximum;
    this->items = obj.items;
    this->objectArr = new Object*[this->maximum];

    for (size_t i = 0; i< this->items; i++)
    {
        this->objectArr[i] = obj.objectArr[i]->copy();
    }
    initialise(this->items);

}
void Manage::max()
{
    this->maximum += 2;

    Object **temporary = new Object*[this->maximum];

    for (size_t i = 0; i< this->items; i++)
    {
        temporary[i] = this->objectArr[i];
    }

    delete[] this->objectArr;
    this->objectArr = temporary;
    this->initialise(this->items);

}
void Manage::initialise(const int from)
{
    for (size_t i = from; i< maximum; i++)
    {
        this->objectArr[i] = nullptr;
    }
}

void Manage::addObject(const Object &object) {
    if (this->items >= this->maximum)
    {
        max();
    }
    this->objectArr[this->items++] = object.copy();
}
void Manage::removeObject(int index) {
    if (index < 0 || index >= this->items)
        throw("Cannot recognize input, remove this object");

    delete this->objectArr[index];
    this->objectArr[index] = this->objectArr[this->items - 1];
    this->objectArr[--this->items] = nullptr;
}

